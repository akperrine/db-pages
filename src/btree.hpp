#ifndef BTREE_HPP
#define BTREE_HPP

#include <vector>

namespace database {

class Node {
public:
    std::vector<char> data;

    Node() {};
    Node(const std::vector<char>& data) : data(data) {};

    char get_node_type();
    uint16_t n_keys();
    void set_header(char node_type, uint16_t n_keys);
    uint64_t get_ptr(uint16_t index);
    void set_ptr(uint16_t index, uint64_t val);
    uint16_t get_offset(uint16_t index);
    uint16_t get_kv_pos(uint16_t index);
    std::vector<char> get_key(uint16_t index);
    std::vector<char> get_val(uint16_t index);
    void node_append_kv(uint16_t index, uint64_t ptr, const std::vector<char>& key, const std::vector<char>& val);
    uint16_t get_node_size();
    
private:
};

class BTree {
public:
    long root;

    void leaf_insert(Node& old_node, uint16_t index, const std::vector<char>& key, const std::vector<char>& val);
    void node_append_range(Node& old_node, Node& new_node, uint16_t src_old, uint16_t dst_new, uint16_t iterations);
    void leaf_update(Node& old_node, uint16_t index, const std::vector<char>& key, const std::vector<char>& val);
    uint16_t node_lookup(Node& node, const std::vector<char>& key);
    void split_node_two(Node& l_node, Node& r_node, Node& old_node);
    void split_node_three(Node& l_node, Node& r_node, Node& old_node);
private:
};

};

#endif // BTREE_HPP