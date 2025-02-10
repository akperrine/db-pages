#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

namespace database {

struct Node {
        std::vector<char> data;

        Node() {};
        Node(std::vector<char> data) : data(data) {};
    };

class BTree {
public:
    long root;

    char get_node_type(Node node);
    uint16_t n_keys(Node node);
    Node set_header(char node_type, uint16_t n_keys);
    
private:
};

};

#endif // NODE_HPP