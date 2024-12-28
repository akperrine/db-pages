#include "database.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <gtest/gtest.h>


namespace database {

static const std::string DB_NAME = "test_file";

class TestDatabase : public ::testing::Test {
protected:
    void TearDown() override {
        std::string filename = DB_NAME;
        std::filesystem::remove(std::filesystem::current_path() / "data" / (DB_NAME + ".db")); 
    }
};

    TEST_F(TestDatabase, TestCreateDB) {
        std::string filename = DB_NAME; 
        Database db;
        
        try {

        db.create_db(filename);
        std::ifstream file(std::filesystem::current_path() / "data" / (DB_NAME + ".db"));
        EXPECT_TRUE(file.is_open()); 
        file.close(); 
        } catch (...) {
            // std::filesystem::remove(std::filesystem::current_path() / "data" / (filename + ".db")); 
        }

    //     std::filesystem::remove(std::filesystem::current_path() / "data" / (filename + ".db")); 
    }
}