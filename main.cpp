#include <iostream>

const std::string message = "Enter a number or 'q' for exit.";

int main()
{
    std::string input;

    std::cout << message << std::endl;
    while (std::cin >> input) {
        if (input == "q")
            exit(0);

        std::cout << "You entered: " << input << std::endl << std::endl;
        std::cout << message << std::endl;
    }
}
