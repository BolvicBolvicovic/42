#include "master.hpp"

void	replace(std::string &line, std::string s1, std::string s2, size_t index)
{
	line.erase(index, s1.length());
	line.insert(index, s2);
}

void	edit_new_file(std::ifstream &file, std::ofstream &new_file, std::string s1, std::string s2)
{
	std::string	line;
	int		index = 0;

	while (std::getline(file, line))
	{
		while ((index = line.find(s1, index)) >= 0)
			replace(line, s1, s2, index);
		new_file << line << '\n';
		index = 0;
	}
}

void	handle_file(std::string filename,std::string s1, std::string s2)
{
	std::string	new_name = filename + ".replace";	
	std::ifstream	file(filename.c_str());
	std::ofstream	new_file(new_name.c_str());

	if (file.is_open() && new_file.is_open())
		edit_new_file(file, new_file, s1, s2);
	else
	{
		file.close();
		new_file.close();
		remove(new_name.c_str());
		ft_error("Could not open/create the file.");
	}
	file.close();
	new_file.close();
}
