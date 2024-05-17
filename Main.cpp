#include "Header.h"

int main() {

	std::string number_one("ffffffffffffff932");
	//std::string number_one("1000000");

	Number_128bit ONE(number_one);
	for (int i = 0; i < 128; i++)
		std::cout << Number_128bit::convert_128number_from_hex(number_one)[i] << ' ';
	std::cout << '\n';
	//unsigned int *arr = number_one.return_number_as_array();
	std::cout << Number_128bit::convert_128number_to_hex(ONE.return_number_as_array()) << '\n';
	//std::cout << ONE.not_null_cells_in_number_as_array();


	/*std::string number_as_hex_string_result = "LunkerZang";
	int index_of_first_significant_digit = 5;
	number_as_hex_string_result.erase(number_as_hex_string_result.begin(), number_as_hex_string_result.end() - index_of_first_significant_digit);
	std::cout << number_as_hex_string_result;*/
}

