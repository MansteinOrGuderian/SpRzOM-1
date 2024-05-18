#include "Header.h"

int main() {

	std::string number_one("f"); // 15 ~ 1111
	////std::string number_one("1000000");

	Number_128bit ONE(number_one);
	for (int i = 0; i < 128; i++)
		std::cout << Number_128bit::convert_128number_from_hex(number_one)[i] << ' ';
	//std::cout << '\n';
	////unsigned int *arr = number_one.return_number_as_array();
	//std::cout << Number_128bit::convert_128number_to_hex(ONE.return_number_as_array()) << '\n';
	////std::cout << ONE.not_null_cells_in_number_as_array();
	/*std::cout << "\n\n";
	std::string a = Number_128bit::convert_128number_to_binary(ONE);
	std::cout << a;*/
	//std::string b = "1111 1111 1111 1111 1111 1111 1111 1111 1111";
	std::cout << "\n\n";
	int shift_left = 1;
	ONE = (ONE << 1);
	std::cout << ONE;
	std::cout << "\n\n";
	std::cout << Number_128bit::convert_128number_to_hex(ONE.return_number_as_array()) << '\n';
	//std::cout << "\n\n";
	
	//std::string b = Number_128bit::convert_128number_to_binary( (ONE << shift_left) ); // 
	//std::cout << b;
	//
	//std::string binaryString = "11110000000000000000000000000000000000000000000000000000000000000000";
	//
	//std::cout << "\n\n";
	//int c = 40; // 101000 ~ 40
	//std::cout << (c >> 1); // 10100 ~ 20    // 1010000 ~ 80
	//std::cout << "\n\n";
	//std::cout << (c >> 2); // 1010 ~ 10
	//std::cout << "\n\n";

}

