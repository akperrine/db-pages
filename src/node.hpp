#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

namespace database {
class Node {
public:
    std::vector<char> data;

    Node() {};
    Node(std::vector<char> data) : data(data) {};

private:
};
}

#endif // NODE_HPP