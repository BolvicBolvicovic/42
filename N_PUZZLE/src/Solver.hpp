#pragma once

#include <iostream>
#include <string>
#include <array>
#include <tuple>

using namespace std;

class Solver
{
private:
	static int				n;
	int						**grid;
	bool					cost; // false is uniform-cost search and true is greedy cost search.
	
public:
	Solver( int N, int	**grid);
	~Solver();

	int						**getGrid( void ) const;

	void					setCost( void );
	void					runAlgo( void );
};
