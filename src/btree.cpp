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
    memcpy(&n_keys, &data[1], sizeof(u_int16_t));
    return n_keys;
}

void Node::set_header(char node_type, uint16_t n_keys) {
    char* keys_as_bytes = static_cast<char*>(static_cast<void*>(&n_keys));
    data.push_back(node_type);
    data.push_back(keys_as_bytes[0]);
    data.push_back(keys_as_bytes[1]);
}

uint64_t Node::get_ptr(uint16_t index) {
    assert(index < n_keys());
    auto pos  = header + 8 * index;
    uint64_t child_ptr;
    memcpy(&child_ptr, &data[pos], sizeof(uint64_t));

    return child_ptr;
}

void Node::set_ptr(uint16_t index, uint64_t ptr) {

}

uint16_t Node::offset_pos(Node bNode, uint16_t index) {
    assert(1 <= index && index <= n_keys());
    uint16_t offset = header + 2 *(index - 1);
    return offset;
}

int get_offset(int index) {
    if (index == 0) {
        return 0;
    }
    return 1;
}
// func (node BNode) getOffset(idx uint16) uint16 {
//     if idx == 0 {
//         return 0
//     }
//     return binary.LittleEndian.Uint16(node[offsetPos(node, idx):])
// }
void set_offset(int index, int offset) {
    //TODO:
}
// func (node BNode) setOffset(idx uint16, offset uint16)


// kvPos returns the position of the nth KV pair relative to the whole node.
int kv_pos(int index) {
    //TODO:
    return 1;
}
// // key-values
// func (node BNode) kvPos(idx uint16) uint16 {
//     assert(idx <= node.nkeys())
//     return HEADER + 8*node.nkeys() + 2*node.nkeys() + node.getOffset(idx)
// }
std::vector<char> get_key(int index) {
    //TODO:
    std::vector<char> val;
    return val;  
}
// func (node BNode) getKey(idx uint16) []byte {
//     assert(idx < node.nkeys())
//     pos := node.kvPos(idx)
//     klen := binary.LittleEndian.Uint16(node[pos:])
//     return node[pos+4:][:klen]
// }
std::vector<char> get_val(int index) {
    //TODO:
    std::vector<char> val;
    return val;   
}
// func (node BNode) getVal(idx uint16) []byte

// It also conveniently returns the node size (used space) with an off-by-one lookup.
int n_bytes(Node node) {
    //TODO:
    return 1;
}
// // node size in bytes
// func (node BNode) nbytes() uint16 {
//     return node.kvPos(node.nkeys())
// }
// returns the first kid node whose range intersects the key. (kid[i] <= key)
// TODO: binary search
int node_lookup(Node node, std::vector<char> key) {
    //TODO:
    return 1;
}
// func nodeLookupLE(node BNode, key []byte) uint16 {
//     nkeys := node.nkeys()
//     found := uint16(0)
//     // the first key is a copy from the parent node,
//     // thus it's always less than or equal to the key.
//     for i := uint16(1); i < nkeys; i++ {
//         cmp := bytes.Compare(node.getKey(i), key)
//         if cmp <= 0 {
//             found = i
//         }
//         if cmp >= 0 {
//             break
//         }
//     }
//     return found
// }
}
