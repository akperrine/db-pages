#include "../src/btree.hpp"
#include <vector>
#include <iostream>
#include <gtest/gtest.h>

namespace database {
    
    // std::vector<char> mock_data;
    static const std::vector<char> mock_data = {1, 2, 3}; 
    static const Node mock_node(mock_data);

    TEST(TEST_BTREE, TEST_GET_NODE_TYPE) {
        std::vector<char> mock_data = {1, 2, 3}; 
        Node mock_node(mock_data);
        char node_type = mock_node.get_node_type();
        EXPECT_EQ(node_type, 1);
    }

    TEST(TEST_BTREE, TEST_N_KEYS) {
        std::vector<char> mock_data = {1, 2, 3}; 
        Node mock_node(mock_data);
        // BTree btree;
        uint16_t keys = mock_node.n_keys();
        std::cout << keys << "keys /n";
        EXPECT_EQ(keys, 770);
    }

    TEST(TEST_BTREE, TEST_SET_HEADER) {
        Node mock_node;
        uint16_t mock_n_keys = 10;
        mock_node.set_header(1, mock_n_keys);

        uint16_t keys = mock_node.n_keys();
        char node_type = mock_node.get_node_type();

        EXPECT_EQ(node_type, 1);
        EXPECT_EQ(keys, 10);
    }
}