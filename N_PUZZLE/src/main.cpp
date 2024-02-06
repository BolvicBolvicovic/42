#include "Solver.hpp"
#include "Parser.hpp"

int	main (int argc, char **argv)
{
	Parser		parse(argc, argv);
	Solver		aStar(parse.getN(), parse.getGrid());

	aStar.setCost();
	aStar.runAlgo();
	return (EXIT_SUCCESS);
}
