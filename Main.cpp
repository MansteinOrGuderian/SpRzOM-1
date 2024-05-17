#include "Header.h"

int main() {

	std::string number_one("fffffffff");
	////std::string number_one("1000000");

	Number_128bit ONE(number_one);
	//for (int i = 0; i < 128; i++)
	//	std::cout << Number_128bit::convert_128number_from_hex(number_one)[i] << ' ';
	//std::cout << '\n';
	////unsigned int *arr = number_one.return_number_as_array();
	//std::cout << Number_128bit::convert_128number_to_hex(ONE.return_number_as_array()) << '\n';
	////std::cout << ONE.not_null_cells_in_number_as_array();
	std::string a = Number_128bit::convert_128number_to_binary(ONE);
	std::cout << a.size();
	std::string b = "1111 1111 1111 1111 1111 1111 1111 1111 1111";
}

