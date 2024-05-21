#include <iostream>
#include <string>
#include <chrono> // for tracking time 
#include <functional> // for tracking time
#include <vector> // for tracking time
double MeasureTime(std::function<void()> operation, unsigned int amount_of_measurements);

struct Number_2048bit{
private:
	static const int size_of_number = 128; // or make it global variable
	unsigned int number_as_array[size_of_number]; //  == unsigned int
public:
	Number_2048bit() { int i = 0; while (i < size_of_number) { number_as_array[i] = 0; i++; } }; //default constructor number
	Number_2048bit(const std::string&); //create 128-bit number (constuctor)

	static unsigned int* convert_128number_from_hex(const std::string);
	static std::string convert_128number_to_hex(unsigned int* number_as_array);
	static std::string convert_128number_to_binary(const Number_2048bit&); // to use with power function
	unsigned int* return_number_as_array() { return number_as_array; } // return pointer to first cell of number_as_array

	unsigned int first_significant_not_null_cell_in_number_as_array();
	Number_2048bit operator- (const Number_2048bit&);
	Number_2048bit operator+ (const Number_2048bit&) ;
	Number_2048bit operator* (unsigned int ) ;
	Number_2048bit operator>> (int n); // shift n cells of number_as_array right
	Number_2048bit operator<< (int n); // shift n cells of number_as_array left
	Number_2048bit operator* (const Number_2048bit&);
	Number_2048bit square_128bit_Number();
	Number_2048bit power_function(const Number_2048bit&);
	Number_2048bit operator/ (const Number_2048bit&);
	Number_2048bit shift_higher_bits_in_number(long int n) const; // shift n bit in whole number to higher bits (multiply on 2^pow)
	Number_2048bit shift_lower_bits_in_number(long int n) const; // shift n bit in whole number to lower bits (divide on 2^pow)
	bool operator== (const Number_2048bit&) const;
	bool operator!= (const Number_2048bit&) const;
	bool operator> (const Number_2048bit&) const;
	bool operator< (const Number_2048bit&) const;
	unsigned int length_of_number_in_bits() const; // amount of digits in binary representation
	bool operator>= (const Number_2048bit&) const;
	bool operator<= (const Number_2048bit&) const;
	Number_2048bit operator% (const Number_2048bit&);

	friend std::ostream& operator<<(std::ostream&, const Number_2048bit&); // output number as it stored

	bool if_number_even(); // check if number is even
	Number_2048bit greatest_common_divisor(const Number_2048bit&);
	Number_2048bit least_common_multiple(const Number_2048bit&);
	Number_2048bit precalculated_value_of_mu();
	Number_2048bit clear_Barrett_reduction(Number_2048bit& n_mod_number);

};
