#include "Parser.hpp"

Parser::Parser(int argc, char **argv)	: argc(argc), argv(argv), grid(NULL)
{ this->fillArray(); this->verifyArray(); }
Parser::~Parser()						{}
	
void	Parser::fillArray( void )
{
	string		line;
	ifstream	file(argv[1]);
	int			count;

	count = 0;
	if (this->argc != 2)
	{
		cerr << "Need only one input file." << endl;
		exit(EXIT_FAILURE);
	}
	if (file.is_open())
	{
		if (getline(file, line))
			this->n = atol(line.c_str());
		if (this->n < 1)
		{
			cerr << "Negative number not accepted." << endl;
			exit(EXIT_FAILURE);
		}
		while (getline(file, line))
		{
			grid[count] = new int*;
			for (int i = 0; line.at(i) && line.at(i) != '#'; i++)
			{
				if (!isspace(line.at(i)) && !isdigit(line.at(i)))
				{
					cerr << "Character is not a digit nor a whitespace nor part of a comment." << endl;
					exit(EXIT_FAILURE);
				}
				else if (isdigit(line.at(i)) && count < this->n)
					this->grid[count][i] = atol(&line.at(i));
			}		
			count++;
		}
		if (count != this->n)
		{
			cerr << "Number of rows invalid." << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << "Unable to open file." << endl;
		exit(EXIT_FAILURE);
	}
}
void	Parser::verifyArray( void )
{
	bool	isDouble;

	for (int i = 0; i < this->n; i++)
	{
		isDouble = false;
		for (int j = 0; j < this->n; j++)
		{
			continue ;
		}
	}


}

int						**Parser::getGrid( void ) const	{ return this->grid; }
int						&Parser::getN( void ) const		{ return this->n; }
