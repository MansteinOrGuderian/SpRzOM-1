#include <iostream>
#include <string>

struct Number_128bit{
private:
	static const int size_of_number = 128; // or make it global variable
	unsigned int number_as_array[size_of_number]; //  == unsigned int
public:
	Number_128bit() { int i = 0; while (i < size_of_number) { number_as_array[i] = 0; i++; } }; //default constructor number
	Number_128bit(const std::string&); //create 128-bit number (constuctor)

	static unsigned int* convert_128number_from_hex(const std::string);
	std::string convert_128number_to_hex(unsigned int* number_as_array);

	unsigned int* return_number_as_array() { return number_as_array; }

	unsigned int not_null_cells_in_number_as_array();

};

