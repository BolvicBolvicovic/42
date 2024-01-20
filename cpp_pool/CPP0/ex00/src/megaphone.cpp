#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	switch (argc)
	{
		case 1:
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
			break ;
		default:
			for (int i = 1; argv[i]; i++)
				for (int j = 0; argv[i][j]; j++)
					std::cout << (char)toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
