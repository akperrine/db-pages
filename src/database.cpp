#include "database.hpp"
#include <fstream>
#include <iostream>
#include <cassert>

namespace database {
    void Database::create_db(std::string db_name) {
        std::filesystem::path db_file_path = std::filesystem::current_path() / "data" / (db_name + ".db");
        std::filesystem::create_directories(db_file_path.parent_path());
        assert(std::filesystem::exists(db_file_path));

        std::cout << std::filesystem::current_path() << '\n';
        std::cout << db_file_path << '\n';
        std::ofstream db_file(db_file_path);

        if (!db_file.is_open()) {
            std::cerr << "Error while creating db file at " << db_name << "\n";
        }
        std::cout << db_name << "Writing to a file in C++." << '\n';
    }

    void Database::drop_db() {}
}