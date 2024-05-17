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

unsigned int Number_128bit::not_null_cells_in_number_as_array(){ //amount of digits in number
	unsigned int current_length = size_of_number;
	for (; number_as_array[current_length - 1] == 0; current_length--)
		if (current_length == 0)
			break;
	return current_length;
}

std::string convert_128number_to_hex(unsigned int* number_as_array) {

}