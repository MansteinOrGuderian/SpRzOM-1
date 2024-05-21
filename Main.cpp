#include "Header.h"

int main() {

	std::string number_one = "c2d1e0f1efed847dccb876543210fedcba9876543210fedcba9876543210fedcba9876d2c3b4a5e1d2a32edb098fa7f5e4d3c2b1a0f9e8d7c6b5a4f3e2d1c0b9a8f7e6d5c4b3a2f1e0d9c8b7";
	std::string number_two = "6b5a4f3d7c6b5a97786a5b4c3d2e1f0e1d28586977c3b4a858697786a5b4c3d2e1f0e1d2c3b8e1f4a5968778695a4b3c2d1e0f86a5b4c3d2e1f0e1d2c3b4a86a5b4c3d24f3977c3b4a0e1d2586";
	std::string number_three = "f4a5b6c7d8e9f0a1b2c3d4e5f7af890bde23a2d852d1e0a4b3c7793f42d3c4b5a68a4b3c2d1e0f1e2d3c4b5a68f0e1d2c3b4a5968778695a4f1e8b3c2d1e0bafecabfefcabcabcabcacab7d8e9f0a1b2c3d4e5f7af890bde23a2d1e5a4b3c2d6789abcdef0123456789abcdef01cabca01";
	Number_2048bit ONE(number_one);
	Number_2048bit TWO(number_two);
	Number_2048bit THREE(number_three);
	//std::cout << ONE << "\n\n";
	//std::cout << TWO << "\n\n";
	//std::cout << (ONE > TWO) << ' ' << (ONE < TWO) << '\n'; // 0   1
	/*std::cout << "Check the properties of numbers:\n";
	std::cout << "First property:\t\ta*b + a*c = a*(b+c)\n";
	Number_2048bit a_mult_b = ONE * TWO;
	Number_2048bit a_mult_c = ONE * THREE;
	Number_2048bit sum_of_mults = a_mult_b + a_mult_c;
	Number_2048bit b_sum_c = TWO + THREE;
	Number_2048bit a_mult_sum = ONE * b_sum_c;
	std::cout << Number_2048bit::convert_128number_to_hex(sum_of_mults.return_number_as_array()) <<"\n\n";
	std::cout << Number_2048bit::convert_128number_to_hex(a_mult_sum.return_number_as_array()) <<"\n\n";
	std::cout << "Second property:\ta + ... + a = a*n\n";
	Number_2048bit a_sum_n_times;
	for (int i = 0; i < 200; i++) {
		a_sum_n_times = a_sum_n_times + ONE;
	}
	Number_2048bit a_mult = ONE * 200;
	std::cout << Number_2048bit::convert_128number_to_hex(a_sum_n_times.return_number_as_array()) << "\n\n";
	std::cout << Number_2048bit::convert_128number_to_hex(a_mult.return_number_as_array()) << "\n\n";*/

	std::string number_mod = "75bcfcaefbca";
	Number_2048bit Number_mod(number_one);
	std::string number2 = "ab43897bfeccd983e";
	Number_2048bit Number2(number_two);
	//std::cout << Number.greatest_common_divisor(Number2);
	std::cout << Number_2048bit::convert_128number_to_hex(Number2.clear_Barrett_reduction(Number_mod).return_number_as_array());
}

 