#ifndef MASTER_HPP
# define MASTER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>

//Errors handling
void	check_args(int argc, char **argv);
void	ft_error(std::string str);

//F*ck sed, I am no loser
void	handle_file(std::string filename,std::string s1, std::string s2);

#endif
