#include "Header.h"

int main() {
	
	std::string number_one("7af890bde23a4c56789abc0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0122");
	//Number_128bit ONE(number_one);
	std::cout << "First = " << Number_128bit::convert_128number_from_hex(number_one) << '\n';
	for (int i = 0; i < 128; i++)
			std::cout << Number_128bit::convert_128number_from_hex(number_one)[i] << ' ';
}

