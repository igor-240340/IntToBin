#include <iostream>
#include <map>

const std::string message = "Enter a number (or 'q' for exit) and press Enter.";
const std::map<unsigned char, std::string> hexToBin = {
    {0, "0000"},
    {1, "0001"},
    {2, "0010"},
    {3, "0011"},
    {4, "0100"},
    {5, "0101"},
    {6, "0110"},
    {7, "0111"},
    {8, "1000"},
    {9, "1001"},
    {10, "1010"},
    {11, "1011"},
    {12, "1100"},
    {13, "1101"},
    {14, "1110"},
    {15, "1111"},
};

int main()
{
    int number;
    std::string input;
    std::string bits;

    std::cout << message << std::endl;
    while (std::cin >> input) {
        if (input == "q")
            exit(0);

        number = atoi(input.c_str());

        // Если число отрицательное, то представим его в дополнительном коде в разрядной сетке int, то есть в 32 битах.
        // [number]доп = 2^32 - |number| = (2^32 - 1) - |number| + 1.
        // UINT_MAX = (2^32 - 1).
        // number < 0 => UINT_MAX + number = UINT_MAX - |number|.
        unsigned int q = number < 0 ? UINT_MAX + number + 1 : number;
        unsigned char r;

        bits = "";
        do {
            r = q % 16;
            q = q / 16;
            bits = hexToBin.at(r) + " " + bits;
        } while (q != 0);

        std::cout << bits << std::endl;

        std::cout << std::endl << message << std::endl;
    }
}
