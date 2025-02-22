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
    int offset_pos(Node bNode, int index);
private:
};

class BTree {
public:
    long root;
    
private:
};

};

#endif // BTREE_HPP