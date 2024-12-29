#include "database.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <gtest/gtest.h>


namespace database {

static const std::string DB_NAME = "test_file";
static const std::filesystem::path DB_PATH = std::filesystem::current_path() / "data" / (DB_NAME + ".db");

class TestDatabase : public ::testing::Test {
protected:
    void TearDown() override {
        std::string filename = DB_NAME;
        std::filesystem::remove(DB_PATH); 
    }
};

    TEST_F(TestDatabase, TestCreateDB) {
        Database db;
        
        db.create_db(DB_NAME);
        std::ifstream file(DB_PATH);
        EXPECT_TRUE(file.is_open()); 
        file.close(); 
    }
}