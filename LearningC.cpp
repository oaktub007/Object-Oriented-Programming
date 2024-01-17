#include <iostream>

int main() {
    // Your program logic goes here

    std::cout << "Hello, this program won't close immediately!\n";

    // Adding a pause before exiting
    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}