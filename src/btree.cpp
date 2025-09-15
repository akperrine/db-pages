#include "./btree.hpp"
#include <vector>
#include <cassert>
#include <cstdint>

namespace database {

static constexpr int header = 3;

static constexpr int btree_page_size = 4096;
static constexpr int btree_max_key_size = 1000;
static constexpr int btree_max_val_size = 3000;

static constexpr int bnode_node = 1;
static constexpr int bnode_leaf = 2;


// | type | nkeys |  pointers  |   offsets  | key-values | unused |
// |  1B  |   2B  | nkeys * 8B | nkeys * 2B |     ...    |        |
// | klen | vlen | key | val |
// |  2B  |  2B  | ... | ... |

char Node::get_node_type() {
    assert(data.size() > 3);
    int node_type = data[0];
    
    return node_type;
}

uint16_t Node::n_keys() {
    assert(data.size() > 3);
    uint16_t n_keys;
    memcpy(&n_keys, &data[1], sizeof(uint16_t));
    return n_keys;
}

void Node::set_header(char node_type, uint16_t n_keys) {
    char* keys_as_bytes = static_cast<char*>(static_cast<void*>(&n_keys));
    data.push_back(node_type);
    data.push_back(keys_as_bytes[0]);
    data.push_back(keys_as_bytes[1]);
}

// Not Tested
// 8 bytes to accomodate standard 64-bit operating system mem address
uint64_t Node::get_ptr(uint16_t index) {
    assert(index < n_keys());
    auto pos  = header + 8 * index;
    uint64_t child_ptr;
    memcpy(&child_ptr, &data[pos], sizeof(uint64_t));

    return child_ptr;
}

// Not Tested
void Node::set_ptr(uint16_t index, uint64_t ptr) {
    assert(index < n_keys());
    uint16_t position = header + 8 * index;

    assert(position + sizeof(uint64_t) > data.size());
    char* destination_ptr = data.data() + position;
    memcpy(destination_ptr, &ptr, sizeof(uint64_t));
}


// Not Tested
uint16_t Node::get_offset(uint16_t index) {
    if (index == 0) {
        return 0;
    }
    // skip header + all pointers to index (-1 since will start at 0)
    uint16_t offset_pos = header + 8 * n_keys() + 2 *(index-1);
    return offset_pos;
}

// Not Tested
uint16_t Node::get_kv_pos(uint16_t index) {
    if (index == 0) {
        return 0;
    }
    uint16_t kv_pos = header + 8 * n_keys() + 2 * n_keys() + get_offset(index);
    return kv_pos;
}

// Not Tested
std::vector<char> Node::get_key(uint16_t index) {
    assert(index < n_keys());
    uint16_t position = get_kv_pos(index);
    uint16_t k_length;
    memcpy(&k_length, &data[position], sizeof(uint16_t));
    // + 4 to skip the 2B key len and 2B val ken
    char* k_start = data.data() + (position + 4);
    return std::vector<char>(k_start, k_start + k_length);
}

// Not Tested (likely needs review too)
std::vector<char> Node::get_val(uint16_t index) {
    assert(index < n_keys());
    uint16_t position = get_kv_pos(index);
    // Must find key length also to know where to start val read
    uint16_t k_length;
    uint16_t v_length;
    memcpy(&k_length, &data[position], sizeof(uint16_t));
    memcpy(&v_length, &data[position + 2], sizeof(uint16_t));

    char* v_start = data.data() + (position + 4 + k_length);
    return std::vector<char>(v_start, v_start + v_length);
}

// Think there is a version of this where index is created internally with n_keys() + 1 -> will see in the future
void Node::node_append_kv(uint16_t index, uint64_t ptr, const std::vector<char>& key, const std::vector<char>& val) {
    this->set_ptr(index, ptr);
    // index = no uint16_t index = node.n_keys(); (future option)

    auto pos = this->get_kv_pos(index);

    uint16_t k_len = static_cast<uint16_t>(key.size());
    uint16_t v_len = static_cast<uint16_t>(val.size());

    // write the key_size uint16 and val_size uint16
    memcpy(this->data.data() + pos, &k_len, sizeof(uint16_t));
    memcpy(this->data.data() + pos + 2, &v_len, sizeof(uint16_t));
    
    // write key and value
    memcpy(this->data.data() + pos + 4, key.data(), k_len);
    memcpy(this->data.data() + pos + 4 + k_len, val.data(), v_len);
}

}
// namespace database