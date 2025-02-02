#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

namespace database {

struct Node {
        std::vector<char> data;

        Node(std::vector<char> data) : data(data) {};
    };

class BTree {
public:
    long root;
    
    std::vector<char> get_page(long);
    long new_page(std::vector<char>);
    void del_page(long);

    char get_node_type(Node node);
    uint16_t n_keys(Node node);
    
private:
};

};

#endif // NODE_HPP