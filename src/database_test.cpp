#include "database.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <gtest/gtest.h>


namespace database {
    TEST(TestDatabase, TestCreateDB) {
        std::string filename = "test_file"; 
        Database db;
        
        db.create_db(filename);
        std::ifstream file(std::filesystem::current_path() / "data" / (filename + ".db"));
        EXPECT_TRUE(file.is_open()); 
        file.close(); 
    }
}