#include "Header.h"
Number_2048bit::Number_2048bit(const std::string& number_as_hex_string) {
	unsigned int* array_of_properly_numbers = convert_128number_from_hex(number_as_hex_string);
	int i = 0; while (i < size_of_number) { number_as_array[i] = array_of_properly_numbers[i]; i++; }
}

unsigned int* Number_2048bit::convert_128number_from_hex(const std::string number_as_hex_string) {
	unsigned int* array_of_properly_numbers = new unsigned int[size_of_number] {0};
	std::string number_as_hex_string_reversed = number_as_hex_string;
	reverse(number_as_hex_string_reversed.begin(), number_as_hex_string_reversed.end());
	int index_of_cell = -1; // index out of range
	unsigned int string_current_position = 0; // starting from "last tail" of string 
	while (string_current_position < number_as_hex_string_reversed.length()) {
		unsigned int index_to_control_8charbit = (string_current_position % 8); // to control 8 "digit" of string
		if (index_to_control_8charbit == 0)
			index_of_cell++; //jump to next cell
		unsigned int position_of_char_digit = (1 << (4 * index_to_control_8charbit)); // multiplier number
		unsigned number_digit_equvalent_to_hex_digit = 0;
		if ((char)number_as_hex_string_reversed[string_current_position] >= '0' && (char)number_as_hex_string_reversed[string_current_position] <= '9')
			number_digit_equvalent_to_hex_digit = (unsigned int)((char)number_as_hex_string_reversed[string_current_position] - '0');
		else // convert hex digit to int digit
			number_digit_equvalent_to_hex_digit = (unsigned int)((char)number_as_hex_string_reversed[string_current_position] - 'a' + 10);
		array_of_properly_numbers[index_of_cell] += position_of_char_digit * number_digit_equvalent_to_hex_digit; // increase number in current cell
		string_current_position++;
	}
	return array_of_properly_numbers;
}

std::string Number_2048bit::convert_128number_to_hex(unsigned int* number_as_array) { 
	unsigned int* logic_order_number_as_array = new unsigned int[size_of_number];
	int current_position = size_of_number - 1;
	while (current_position >= 0) {
		logic_order_number_as_array[current_position] = number_as_array[size_of_number - current_position - 1];
		current_position--;
	}
	std::string number_as_hex_string_result;
	//current_position = 0;
	unsigned int string_current_position = 0;
	//std::string current_8bitnumber_in_hex;
	while (string_current_position < size_of_number) {
		std::string current_8bitnumber_in_hex;
		unsigned index_to_control_8charbit = 0;
		while (index_to_control_8charbit < 8) {
			unsigned int position_of_char_digit = (1 << (4 * index_to_control_8charbit));
			unsigned int number_of_char_symbol = (logic_order_number_as_array[string_current_position] / position_of_char_digit) % 16;
			if (number_of_char_symbol >= 0 && number_of_char_symbol <= 10)
				current_8bitnumber_in_hex += (char)(number_of_char_symbol + '0');
			else
				current_8bitnumber_in_hex += (char)(number_of_char_symbol + 'a' - 10);
			index_to_control_8charbit++;
		}
		std::reverse(current_8bitnumber_in_hex.begin(), current_8bitnumber_in_hex.end());
		number_as_hex_string_result += current_8bitnumber_in_hex;
		string_current_position++;
		//current_8bitnumber_in_hex.clear();
	}
	unsigned int index_of_first_significant_digit = number_as_hex_string_result.find_first_not_of('0'); // index, before which delete all 0
	if (index_of_first_significant_digit != -1) // if not empty string
		number_as_hex_string_result.erase(number_as_hex_string_result.begin(), number_as_hex_string_result.begin() + index_of_first_significant_digit);
		//number_as_hex_string_result = number_as_hex_string_result.substr(index_of_first_significant_digit);
	else
		number_as_hex_string_result = "0";
	return number_as_hex_string_result;
}

std::string Number_2048bit::convert_128number_to_binary(const Number_2048bit& Number_to_binary) { // to use with power function
	std::string number_in_binary_representation;
	int current_position = size_of_number - 1;
	while (current_position >= 0) { //copying number, in reverse order, to ease convertation
		unsigned int number_in_current_cell = Number_to_binary.number_as_array[current_position];
		int current_bit = 31;
		while (current_bit >= 0) {
			unsigned int binary_current_digit = (number_in_current_cell >> current_bit) & 1; // formula from internet
			number_in_binary_representation += std::to_string(binary_current_digit);
			current_bit--;
		}
		current_position--;
	}
	unsigned int index_of_first_significant_digit = number_in_binary_representation.find_first_not_of('0'); // index, before which delete 0
	if (index_of_first_significant_digit != -1) // if not empty string
		number_in_binary_representation.erase(number_in_binary_representation.begin(), number_in_binary_representation.begin() + index_of_first_significant_digit);
	else
		number_in_binary_representation = "0";
	return number_in_binary_representation;
}

unsigned int Number_2048bit::first_significant_not_null_cell_in_number_as_array() { //cell, where first significant digit stored
	unsigned int current_length = size_of_number;
	while (number_as_array[current_length - 1] == 0 && current_length--)
		if (current_length == 0)
			break;
	return current_length;
}

Number_2048bit Number_2048bit::operator- (const Number_2048bit& Right_number) {
	unsigned int bit_borrow = 0;
	Number_2048bit result_of_subtraction;
	unsigned int current_index_position = 0;
	while (current_index_position < size_of_number) {
		long long int temp = ((unsigned long long int)number_as_array[current_index_position]) - ((unsigned long long int)result_of_subtraction.number_as_array[current_index_position]) - ((unsigned long long int)bit_borrow);
		if (temp >= 0) {
			result_of_subtraction.number_as_array[current_index_position] = ((unsigned int)temp);
			bit_borrow = 0;
		}
		else {
			result_of_subtraction.number_as_array[current_index_position] = ((unsigned int)(temp + 0xFFFFFFFF + 1)); // (2^32 - 1) = 4294967295 -> 2^32 = 4294967295 + 1
			bit_borrow = 1;
		}
		current_index_position++;
	}
	if (bit_borrow == 1) {
		throw std::exception("Error happend!\nResult less then 0. Negative number isn't supported");
	}
	return result_of_subtraction;
}

Number_2048bit Number_2048bit::operator+ (const Number_2048bit& Right_number) {
	unsigned int bit_carry = 0;
	Number_2048bit result_of_summing;
	unsigned int current_index_position = 0;
	while (current_index_position < size_of_number) {
		unsigned long long int temp = ((unsigned long long int)number_as_array[current_index_position]) + ((unsigned long long int)result_of_summing.number_as_array[current_index_position]) + ((unsigned long long int)bit_carry); // allocate more memory, because number can increase up 1 digit
		result_of_summing.number_as_array[current_index_position] = ((unsigned int)(temp & 0xFFFFFFFF)); // or bitwiseAND with 4294967295 = (2^32 - 1), like modulo
		bit_carry = ((unsigned int)(bit_carry >> 32));// implementation for 32-bit system
		current_index_position++;
	}
	//result_of_summing.number_as_array[size_of_number] = carry; //fixed length of number, so didn't saved
	return result_of_summing;
}

Number_2048bit Number_2048bit::operator* (unsigned int number_on_which_multiply) {
	unsigned int bit_carry = 0;
	Number_2048bit result_of_multiplication;
	unsigned int current_index_position = 0;
	while (current_index_position < size_of_number) {
		unsigned long long int temp = ((unsigned long long int)number_as_array[current_index_position]) * ((unsigned long long int)number_on_which_multiply) + ((unsigned long long int)bit_carry); // allocate more memory, because number can increase up to 2 times
		result_of_multiplication.number_as_array[current_index_position] = ((unsigned int)(temp & 0xFFFFFFFF)); // or bitwiseAND with 4294967295 = (2^32 - 1), like modulo (cut first's most significant bits)
		bit_carry = ((unsigned int)(bit_carry >> 32));// implementation for 32-bit system
		current_index_position++;
	}
	result_of_multiplication.number_as_array[size_of_number - 1] = bit_carry; //here saved number, last "digit" (cell) of result.number_as_array
	return result_of_multiplication;
}

Number_2048bit Number_2048bit::operator>> (int number_of_right_shift_cells) {
	Number_2048bit result_of_right_shift(*this); // inputed number will be edit
	unsigned int current_position = 0;
	while (current_position < size_of_number) {
		if ((current_position + number_of_right_shift_cells) < size_of_number) //shift number_cells in number_as_array, in new place, which defined by number_of_right_shift_cells
			result_of_right_shift.number_as_array[current_position] = result_of_right_shift.number_as_array[current_position + number_of_right_shift_cells];
		else // overwrite data in begin of array
			result_of_right_shift.number_as_array[current_position] = 0;
		current_position++;
	}
	return result_of_right_shift;
}

Number_2048bit Number_2048bit::operator<< (int number_of_left_shift_cells) {
	Number_2048bit result_of_left_shift(*this); // inputed number will be edit
	int current_position = size_of_number - 1;
	while (current_position >= 0) { // !!! significant numbers are in reverse order
		if ((current_position - number_of_left_shift_cells) >= 0) // shift number_cells in number_as_array, until first significant met
			result_of_left_shift.number_as_array[current_position] = result_of_left_shift.number_as_array[current_position - number_of_left_shift_cells];
		else // if met, and still must shifting -> overwrite cell with nulls
			result_of_left_shift.number_as_array[current_position] = 0;
		current_position--;
	}
	return result_of_left_shift;
}

Number_2048bit Number_2048bit::operator* (const Number_2048bit& Right_number) {
	Number_2048bit result_of_multiplication("0");
	unsigned int current_cell_index_right_number = 0;
	while (current_cell_index_right_number < size_of_number) {
		Number_2048bit temp = *this * Right_number.number_as_array[current_cell_index_right_number]; // multiplication on int will be soon
		temp = temp << current_cell_index_right_number; // left shift == multiplication on degree of 2
		result_of_multiplication = result_of_multiplication + temp; // adding operator will be overloaded soon
		current_cell_index_right_number++;
	}
	return result_of_multiplication;
}

Number_2048bit Number_2048bit::square_128bit_Number() {
	return *this * *this;
}

Number_2048bit Number_2048bit::power_function(const Number_2048bit& power_number) { // using Gorner algorithm
	std::string degree_number_as_binary = convert_128number_to_binary(power_number);
	Number_2048bit result("1");
	Number_2048bit base_number = *this;
	int current_index_of_power = degree_number_as_binary.length() - 1; // from highest to lowest
	while (current_index_of_power >= 0) {
		if (degree_number_as_binary[current_index_of_power] == '1')
			result = result * base_number; 
		if (current_index_of_power > 0)
			base_number = base_number.square_128bit_Number();
		
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const Number_2048bit& Data) {
	for (int i = 0; i < Data.size_of_number; i++)
		out << Data.number_as_array[i] << ' ';
	return out;
}

bool Number_2048bit::operator> (const Number_2048bit& Right_number) {
	int current_position = size_of_number - 1;
	while (current_position >= 0) {
		if (number_as_array[current_position] > Right_number.number_as_array[current_position])
			return true;
		current_position--;
	}
	return false; 
}

bool Number_2048bit::operator< (const Number_2048bit& Right_number) {
	int current_position = size_of_number - 1;
	while (current_position >= 0) {
		if (number_as_array[current_position] < Right_number.number_as_array[current_position])
			return true;
		current_position--;
	}
	return false;
}


bool Number_2048bit::operator!= (const Number_2048bit& Right_number) {
	return !(*this == Right_number);
}

bool Number_2048bit::operator== (const Number_2048bit& Right_number) {
	int current_position = size_of_number - 1;
	while (current_position >= 0) {
		if (number_as_array[current_position] != Right_number.number_as_array[current_position])
			return false;
		current_position--;
	}
	return true;
}

//Number_2048bit Number_2048bit::operator/ (const Number_2048bit& Divisor_number) {
//	Number_2048bit result_of_division;
//	if (Divisor_number > *this)
//		return result_of_division; // don't work with fractional numbers
//	if (Divisor_number == Number_2048bit("0"))
//		return Number_2048bit("0");
//	return result_of_division;
//}

Number_2048bit Number_2048bit::shift_higher_bits_in_number(long int number_of_left_shift_bits) {
	Number_2048bit result_of_shifting; // number is 0 == array filled with nulls
	if (number_of_left_shift_bits >= 32 * size_of_number)
		return result_of_shifting;
	else if (number_of_left_shift_bits <= 0) { // undefined behavior
		return *this;  // return current value(for example) OR   // throw std::exception("Error happend!\nCannot shift on negative value."); 
	}
	long int amount_of_full_integer_bit_cells = number_of_left_shift_bits / 32; //because we have 32bit system
	long int amount_of_remainder_bit = number_of_left_shift_bits % 32;
	unsigned int bit_carry = 0;
	if (amount_of_remainder_bit == 0) {
		int current_position = size_of_number - 1;
		while (current_position >= amount_of_full_integer_bit_cells) {
			result_of_shifting.number_as_array[current_position] = number_as_array[current_position - amount_of_full_integer_bit_cells]; //shifting values left
			current_position--; 
		}
		current_position = 0;
		while (current_position < amount_of_full_integer_bit_cells) {
			result_of_shifting.number_as_array[current_position] = 0; // fill "lower" cells with nulls
			current_position++;
		}
	}
	else {
		int current_position = 0;
		while (current_position < size_of_number) {
			result_of_shifting.number_as_array[current_position] = (number_as_array[current_position] << amount_of_remainder_bit) + bit_carry; // edit(shift left) number in each cell
			bit_carry = number_as_array[current_position] >> (32 - amount_of_remainder_bit); // caluculate number, that should be added to next cell
			current_position++;
		}
		current_position = size_of_number - 1;
		while (current_position >= amount_of_full_integer_bit_cells) {
			result_of_shifting.number_as_array[current_position] = result_of_shifting.number_as_array[current_position - amount_of_full_integer_bit_cells]; //shifting values left
			current_position--;
		}
		current_position = 0;
		while (current_position < amount_of_full_integer_bit_cells) {
			result_of_shifting.number_as_array[current_position] = 0; // fill "lower" cells with nulls
			current_position++;
		}

	}
	return result_of_shifting;
}