#include <iostream>
#include <string>

int main() {
    std::cout << "printing main" << '\n';
    bool is_on = true;

    std::cout << "give a command\n";
    while (is_on) {
        std::string command;
        
        std::cin >> command;

        if (command == "exit") {
            std::cout << "now exiting program ...\n";
            is_on = false;
        }
    }

    return 0;
}

