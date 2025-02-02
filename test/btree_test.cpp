#include "../src/btree.hpp"
#include <vector>
#include <iostream>
#include <gtest/gtest.h>

namespace database {
    
    // std::vector<char> mock_data;
    static const std::vector<char> mock_data = {1, 2, 3}; 
    static const Node mock_node(mock_data);

    TEST(TEST_BTREE, TEST_GET_NODE_TYPE) {
        BTree btree;
        char node_type = btree.get_node_type(mock_node);
        EXPECT_EQ(node_type, 1);
    }

    TEST(TEST_BTREE, TEST_N_KEYS) {
        BTree btree;
        uint16_t keys = btree.n_keys(mock_node);
        std::cout << keys << "keys /n";
        EXPECT_EQ(keys, 30272);
    }
}