#include <iostream>
#include <string>

#include "./database.hpp"

using namespace database;


int main() {
    std::cout << "printing main" << '\n';
    bool is_on = true;

    std::cout << "give a command\n";
    while (is_on) {
        std::string command;
        
        std::cin >> command;

        if (command == "create") {
            std::cout << "enter db name\n";
            std::string res;
            std::cin >> res;
            database::Database db;
            db.create_db(res);
        } else if (command == "drop") {
            std::cout << "enter db name\n";
            std::string res;
            std::cin >> res;
            database::Database db;
            db.drop_db(res);
        }

        if (command == "exit") {
            std::cout << "now exiting program ...\n";
            is_on = false;
        }
    }

    return 0;
}

