#include <iostream>
#include <string>

constexpr unsigned int msb_mask = 1 << 31;
constexpr int int_bit_cnt = sizeof(int) * 8;
constexpr int r_shift_amount = int_bit_cnt - 1;

int main() {
	std::string input;
	int number;

	std::cout << "Input a number (or 'q' - for exit) and press Enter." << std::endl;
	while (std::cin >> input) {
		if (input == "q" || input == "Q")
			break;

		number = atoi(input.c_str());

		for (int i = 0; i < int_bit_cnt; ++i)
			std::cout << (((number << i) & msb_mask) >> r_shift_amount);

		std::cout << "\n\nInput a number (or 'q' - for exit) and press Enter." << std::endl;
	}

	return 0;
}
