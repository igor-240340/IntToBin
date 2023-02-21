#include <iostream>
#include <map>

static const std::string MESSAGE = "Input a number (or 'q' - for exit) and press Enter.";

static const std::map<unsigned char, std::string> hexToBin = {
    {0, "0000"}, {1, "0001"},
    {2, "0010"}, {3, "0011"},
    {4, "0100"}, {5, "0101"},
    {6, "0110"}, {7, "0111"},
    {8, "1000"}, {9, "1001"},
    {10, "1010"}, {11, "1011"},
    {12, "1100"}, {13, "1101"},
    {14, "1110"}, {15, "1111"},
};

static std::string GetBinaryRepresentation(int number);

int main() {
    std::string input;
    int number;

    std::cout << MESSAGE << std::endl;
    while (std::cin >> input) {
        if (input == "q" || input == "Q")
            break;

        number = atoi(input.c_str());
        std::cout << GetBinaryRepresentation(number) << std::endl;
        std::cout << std::endl << MESSAGE << std::endl;
    }

    return 0;
}

// Отрицательное число будем представлять в дополнительном коде в разрядной сетке int, то есть в 32 битах.
// [number]доп = 2^32 - |number| = (2^32 - 1) - |number| + 1.
// UINT_MAX = 2^32 - 1.
// number < 0 => UINT_MAX + number = UINT_MAX - |number|.
std::string GetBinaryRepresentation(int number) {
    unsigned int q = (number < 0) ? (UINT_MAX + number + 1) : number;
    unsigned char r;
    std::string bin = "";

    do {
        r = q % 16;
        q = q / 16;
        bin = hexToBin.at(r) + " " + bin;
    } while (q != 0);

    return bin;
}
