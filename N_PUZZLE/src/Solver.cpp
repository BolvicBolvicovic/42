#include "Solver.hpp"
	
Solver::Solver( int N, int **Grid) : n(N), grid(Grid)	{}

Solver::~Solver()	{ delete grid; cout << "Solver deleted." << endl; }

array	*Solver::getGrid( void ) const	{ return this->grid; }

void					Solver::setCost( void )
{
	string	input;
	
	do
	{
		cout << "Uniform-cost search or greedy search <u/g> :";
		cin >> input;
	} while (input.compare("u") && input.compare("g"));
	if (input.compare("u"))
		this->cost = false;
	else
		this->cost = true;
}

void					Solver::runAlgo( void )
{
	continue ;
}
