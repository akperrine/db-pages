#ifndef BTREE_HPP
#define BTREE_HPP

#include <vector>
#include "./node.hpp"

namespace database {

class BTree {
public:
    long root;

    char get_node_type(Node node);
    uint16_t n_keys(Node node);
    Node set_header(char node_type, uint16_t n_keys);
    int offset_pos(Node bNode, int index);
    
private:
};

};

#endif // BTREE_HPP