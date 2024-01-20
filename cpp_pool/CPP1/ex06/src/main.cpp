#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "One complaint at a time!\n";
		return (1);
	}

	std::string	input = argv[1];
	Harl		harl;
	int		i = harl.getIndex(input);
	switch (i)
	{
		case 0:
			harl.complain("DEBUG");
			i++;
			// intentional fallthrough
		case 1:
			harl.complain("INFO");
			i++;
			// intentional fallthrough
		case 2:
			harl.complain("WARNING");
			i++;
			// intentional fallthrough
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "Some unimportant complaint...\n";
	}
	return (0);
}
