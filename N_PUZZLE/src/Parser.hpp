#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <tuple>

using namespace std;

class Parser
{
private:
	int						argc;
	char					**argv;
	static int				n;
	int						**grid;

	void	fillArray( void );
	void	verifyArray( void );
public:
	Parser(int argc, char **argv);
	~Parser();
	
	int						**getGrid( void ) const;
	int						&getN( void ) const;
};
