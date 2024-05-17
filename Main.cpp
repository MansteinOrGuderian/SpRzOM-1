#include "Header.h"

int main() {
	
	std::string number_one("1");
	Number_128bit ONE(number_one);
	for (int i = 0; i < 128; i++)
			std::cout << Number_128bit::convert_128number_from_hex(number_one)[i] << ' ';
	std::cout << '\n';
	std::cout << ONE.not_null_cells_in_number_as_array();
}

