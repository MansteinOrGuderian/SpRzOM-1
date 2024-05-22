#include "Header.h"

int main() {


	/*std::string number_one = "c2d1e0f1efed847dccb876543210fedcba9876543210fedcba9876543210fedcba9876d2c3b4a5e1d2a32edb098fa7f5e4d3c2b1a0f9e8d7c6b5a4f3e2d1c0b9a8f7e6d5c4b3a2f1e0d9c8b7";
	std::string number_two = "6b5a4f3d7c6b5a97786a5b4c3d2e1f0e1d28586977c3b4a858697786a5b4c3d2e1f0e1d2c3b8e1f4a5968778695a4b3c2d1e0f86a5b4c3d2e1f0e1d2c3b4a86a5b4c3d24f3977c3b4a0e1d2586";
	std::string number_three = "f4a5b6c7d8e9f0a1b2c3d4e5f7af890bde23a2d852d1e0a4b3c7793f42d3c4b5a68a4b3c2d1e0f1e2d3c4b5a68f0e1d2c3b4a5968778695a4f1e8b3c2d1e0bafecabfefcabcabcabcacab7d8e9f0a1b2c3d4e5f7af890bde23a2d1e5a4b3c2d6789abcdef0123456789abcdef01cabca01";
	std::string number_four = "fed847da5e1d2a32edb098fa7f5e4d3c2b1a0f1e0f1e2d3c4b5a68a5b6c7d8e9f0aa5e1d2a32edb098fa7f5e4d3c2b1a0f1e0f1e2d3c4b5a68a5b6c7d8e9f0a46bec3";

	Number_2048bit ONE(number_one);
	Number_2048bit TWO(number_two);
	Number_2048bit THREE(number_three);
	Number_2048bit FOUR(number_four);*/
	std::string one = "f5aa1bd307eedf96db133a218aa605a0edb6de4fa9d43d100cd75990b3c9b72347ff83796c2f886b4a58f312b8bdbdbcaf500790eee9add7165837032d2bd268e9a73cb50dca7a065abb515a18f8783c9f1bdaa5400a2b2f06cc42a2b38f41599d5bab219aaff407f6c283d479de944f8d039233709e21e30aa380b98026ac33";
	std::string two = "658ec5e5d8f126d692936c196bc1be68fdbc7483d7f1035c8e636c36ed5d4d0f0f69a0fa8158f4d0967e3ebd23aa4081f14540fb4f4724140e38ab2a40d33e807028b2f40b1e5362c392348d7cd81dde9ec6a79e1f4abb8b706ea0d63d30f0663a2ca1ff673d8889bc315853fca663a2c05f46c87657f0fea4ec2aafe8bbf3ac";
	std::string three = "d33e807028b2f40b1e5362c392348d7cd81dde9ec6a79e1f4abb8b706ea0d63d30f0663a2ca1ff673d8889bc315853fca663a2c05f46c87657f0fea4ec2aafe8bbf3ac";
	
	Number_2048bit ONE(one);
	Number_2048bit TWO(two);
	Number_2048bit THREE(three);


	Number_2048bit GCD = ONE.greatest_common_divisor(TWO); // +
	std::cout << Number_2048bit::convert_128number_to_hex(GCD.return_number_as_array()) << "\n\n";
	Number_2048bit LCM = ONE.least_common_multiple(TWO); // +
	std::cout << Number_2048bit::convert_128number_to_hex(LCM.return_number_as_array()) << "\n\n";

	Number_2048bit sum = ONE.sum_with_Barrett(TWO, THREE); // +
	std::cout << Number_2048bit::convert_128number_to_hex(sum.return_number_as_array()) << "\n\n";
	Number_2048bit difference = TWO.substact_with_Barrett(ONE, THREE); // +
	std::cout << Number_2048bit::convert_128number_to_hex(difference.return_number_as_array()) << "\n\n";
	Number_2048bit mult = ONE.multiply_with_Barrett(TWO, THREE); // +
	std::cout << Number_2048bit::convert_128number_to_hex(mult.return_number_as_array()) << "\n\n";
	Number_2048bit degree =TWO.power_to_degree_with_Barrett(ONE, THREE); // +
	std::cout << Number_2048bit::convert_128number_to_hex(degree.return_number_as_array()) << "\n\n";


	//std::cout << "Check the properties of numbers:\n";
	//std::cout << "First property:\t\t(a+b)*c = c*(a+b) = a*c + b*c (mod n)\n";
	//Number_2048bit a_sum_b = ONE.sum_with_Barrett(TWO, FOUR);
	//Number_2048bit a_sum_b_mult_c = a_sum_b.multiply_with_Barrett(THREE, FOUR);  
	//Number_2048bit c_mult_a_sum_b = THREE.multiply_with_Barrett(a_sum_b, FOUR);
	//Number_2048bit a_mult_c = ONE.multiply_with_Barrett(THREE, FOUR);
	//Number_2048bit b_mult_c = TWO.multiply_with_Barrett(THREE, FOUR);
	//Number_2048bit sum_of_mults = a_mult_c.sum_with_Barrett(b_mult_c, FOUR);
	//std::cout << Number_2048bit::convert_128number_to_hex(a_sum_b_mult_c.return_number_as_array()) << "\n\n";
	//std::cout << Number_2048bit::convert_128number_to_hex(c_mult_a_sum_b.return_number_as_array()) << "\n\n";
	//std::cout << Number_2048bit::convert_128number_to_hex(sum_of_mults.return_number_as_array()) << "\n\n";
	//
	//std::cout << "Second property:\ta + ... + a = a*m (mod n)\n";
	//Number_2048bit a_sum_n_times;
	//for (int i = 0; i < 200; i++)
	//	a_sum_n_times = a_sum_n_times.sum_with_Barrett(ONE, FOUR);
	//unsigned int amounts_of_adds = 200;
	//Number_2048bit a_mult = (ONE * amounts_of_adds).clear_Barrett_reduction(FOUR);
	//std::cout << Number_2048bit::convert_128number_to_hex(a_sum_n_times.return_number_as_array()) << "\n\n";
	//std::cout << Number_2048bit::convert_128number_to_hex(a_mult.return_number_as_array()) << "\n\n";
	//
	//std::cout << "Third property:\ta^phi(3^k) = a^(2*3^(k-1)) = 1 mod 3^k\n";
	//Number_2048bit a("3");
	//std::cout << "GCD a and FOUR is:\t" << Number_2048bit::convert_128number_to_hex(a.greatest_common_divisor(FOUR).return_number_as_array()) << '\n';
	//Number_2048bit j("1");
	//Number_2048bit k("2");
	//Number_2048bit h("3");
	//Number_2048bit left_mod = a.power_function(k); 
	//Number_2048bit phi = k * h.power_function(k - j); 
	//Number_2048bit a_in_degree_phi_mod = FOUR.power_function(phi) % left_mod;
	//(a_in_degree_phi_mod == Number_2048bit("1")) ? std::cout << "Yes, property is correct\n" : std::cout << "No, property is false\n";
	//
	//Number_2048bit GCD_of_ONE_and_TWO = ONE.greatest_common_divisor(TWO); // +
	//std::cout << "GCD is:\t" << Number_2048bit::convert_128number_to_hex(GCD_of_ONE_and_TWO.return_number_as_array()) << '\n';
	//Number_2048bit LCM_of_ONE_and_TWO = ONE.least_common_multiple(TWO); // +
	//std::cout << "LCM is:\t" << Number_2048bit::convert_128number_to_hex(LCM_of_ONE_and_TWO.return_number_as_array()) << '\n';
	//Number_2048bit sum_of_ONE_and_TWO_mod_FOUR = ONE.sum_with_Barrett(TWO, FOUR); // +
	//std::cout << "SUM is:\t" << Number_2048bit::convert_128number_to_hex(sum_of_ONE_and_TWO_mod_FOUR.return_number_as_array()) << '\n';
	//Number_2048bit difference_of_TWO_and_ONE_mod_FOUR = TWO.substact_with_Barrett(ONE, FOUR);
	//std::cout << "Difference is:\t" << Number_2048bit::convert_128number_to_hex(difference_of_TWO_and_ONE_mod_FOUR.return_number_as_array()) << '\n';
	//Number_2048bit multiply_of_ONE_and_TWO_mod_FOUR = ONE.multiply_with_Barrett(TWO, FOUR); // +
	//std::cout << "Multiply is:\t" << Number_2048bit::convert_128number_to_hex(multiply_of_ONE_and_TWO_mod_FOUR.return_number_as_array()) << '\n';
	//Number_2048bit power_ONE_to_degree_TWO_mod_FOUR = ONE.power_to_degree_with_Barrett(TWO, FOUR); // +
	//std::cout << "Power is:\t" << Number_2048bit::convert_128number_to_hex(power_ONE_to_degree_TWO_mod_FOUR.return_number_as_array()) << '\n';
}