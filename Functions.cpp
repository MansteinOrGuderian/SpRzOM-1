#include "Header.h"
Number_128bit::Number_128bit(const std::string& number_as_hex_string) {
	unsigned int* array_of_properly_numbers = convert_128number_from_hex(number_as_hex_string);
	int i = 0; while (i < size_of_number) { number_as_array[i] = array_of_properly_numbers[i]; i++; }
}

unsigned int* Number_128bit::convert_128number_from_hex(const std::string number_as_hex_string) {
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

std::string Number_128bit::convert_128number_to_hex(unsigned int* number_as_array) { 
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
	unsigned int index_of_first_significant_digit = number_as_hex_string_result.find_first_not_of('0'); // index, before which delete 0
	std::cout << index_of_first_significant_digit;
	if (index_of_first_significant_digit != -1) // if not empty string
		number_as_hex_string_result.erase(number_as_hex_string_result.begin(), number_as_hex_string_result.begin() + index_of_first_significant_digit);
		//number_as_hex_string_result = number_as_hex_string_result.substr(index_of_first_significant_digit);
	else
		number_as_hex_string_result = "0";
	std::cout << '\n' << index_of_first_significant_digit << '\n';
	return number_as_hex_string_result;
}

std::string Number_128bit::convert_128number_to_binary(const Number_128bit& Number_to_binary) {
	for (int i = 0; i < size_of_number - 1; i++)
		std::cout << Number_to_binary.number_as_array[i] << ' ';
	std::cout << "\n\n";
	unsigned int current_position = size_of_number - 1;
	while (current_position >= 0) { //copying number
		unsigned int number_in_current_cell = Number_to_binary.number_as_array[current_position];
		std::cout << number_in_current_cell << ' ';
		current_position--;
	}
}

unsigned int Number_128bit::not_null_cells_in_number_as_array() { //amount of significant digits in number
	unsigned int current_length = size_of_number;
	while (number_as_array[current_length - 1] == 0 && current_length--)
		if (current_length == 0)
			break;
	return current_length;
}

