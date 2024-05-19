#include "Header.h"

int main() {

	std::string number_one("fffffffff"); // 15 ~ 1111
	////std::string number_one("1000000");

	Number_2048bit ONE(number_one);
	for (int i = 0; i < 128; i++)
		std::cout << Number_2048bit::convert_128number_from_hex(number_one)[i] << ' ';
	//std::cout << '\n';
	////unsigned int *arr = number_one.return_number_as_array();
	//std::cout << Number_2048bit::convert_128number_to_hex(ONE.return_number_as_array()) << '\n';
	////std::cout << ONE.not_null_cells_in_number_as_array();
	/*std::cout << "\n\n";
	std::string a = Number_2048bit::convert_128number_to_binary(ONE);
	std::cout << a;*/
	//std::string b = "1111 1111 1111 1111 1111 1111 1111 1111 1111";

	//std::cout << '\n';
	//std::cout << ONE.first_significant_not_null_cell_in_number_as_array();

	//std::cout << "\n\n";
	//int shift_left = 1;
	//ONE = (ONE << 1);
	//std::cout << ONE;
	//std::cout << "\n\n";
	//std::cout << Number_2048bit::convert_128number_to_hex(ONE.return_number_as_array()) << '\n';
	//std::cout << "\n\n";

	std::cout << "\n\n";
	//unsigned long long int a = 4294967296; //1 0000 0000 0000 0000 0000 0000 0000 0000
	//std::cout << (a & 4294967295); // a & 1111 1111 1111 1111 1111 1111 1111 1111 = 0
	//Number_2048bit a;
	//std::cout << a << '\n';
	//Number_2048bit b("0");
	//std::cout << b << '\n';
	
	//4294967295 15 0 ... 0 ~ ffff fffff 
	// iter 1:
	//result_of_shifting.number_as_array[current_position] = (number_as_array[current_position] << amount_of_remainder_bit) + bit_carry; // edit(shift left) number in each cell
	// 0 =  (4294967295 << 1) + 0   //    4294967294 ~ ffffffffe 
	//bit_carry = number_as_array[current_position] >> (32 - amount_of_remainder_bit);
	// 0 =  (4294967295 >> (32-1)) = 1 -> bit_carry = 1
	// iter 2:
	// 0 = (15 << 1) + 1 -> 30 + 1 = 31 ~ 1f
	// 1 = (15 >> 31) -> bit_carry = 0
	// iter 3: ... to size_of number 
	// 0 = (0 << 1) + 0 = 0 (like in prev iter)
	// result: 1fffffffffe == 2 * fffffffff
}

