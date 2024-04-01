#include "BitcoinExchange.cpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Panic: Program must take one argument!" << std::endl;
		return 1;
	}
	
	std::ifstream	file(av[1]);
	std::ifstream	database("data.csv");

	output_result(file, database);

	return 0;
}
