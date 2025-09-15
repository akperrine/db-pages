#include "../src/btree.hpp"
#include <vector>
#include <iostream>
#include <gtest/gtest.h>

namespace database {
    
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

    TEST(TEST_BTREE, TEST_APPEND_KEY_VALUE) {
        const size_t BTREE_PAGE_SIZE = 4096;

        // Was getting flagged by compiler (incorectly) with () constructor
        // called Most Vexing Parse
        Node mock_node{std::vector<char>(BTREE_PAGE_SIZE)};
        // staying with string keys and values for now
        std::string mock_key = "1";
        std::string mock_val = "hi";

        std::vector<char> mock_key_bytes(mock_key.size());
        std::vector<char> mock_val_bytes(mock_val.size());

        std::memcpy(mock_key_bytes.data(), mock_key.data(), mock_key.size());
        std::memcpy(mock_val_bytes.data(), mock_val.data(), mock_val.size());

        uint16_t key_len = mock_key_bytes.size();
        uint16_t val_len = mock_val_bytes.size();

        
        std::cerr << "sizes: " << sizeof(mock_key) << " " << mock_val.size() << "\n";
        mock_node.node_append_kv(0, 0, mock_key_bytes, mock_val_bytes);
        auto key_bin = mock_node.get_key(0);
        auto val_bin = mock_node.get_val(0);
        // std::string key;
        std::string key(key_bin.begin(), key_bin.end());
        std::string val(val_bin.begin(), val_bin.end());

        EXPECT_EQ("1", key);
        EXPECT_EQ("hi", val);
    }
}