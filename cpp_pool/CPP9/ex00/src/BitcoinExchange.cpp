#include "BitcoinExchange.hpp"


void	output_result(std::ifstream file, std::ifstream database) {
	std::stack	stack = fill_stack(file);
	std::string	data[] = extract_data(database);
	size_type	size = stack.size();
	
	for (size_type i = 0; i < size; i++) {
		try {
			std::string line = stack.top();
			std::string date;
			double value = check_line_format(trim(line, date));
			
			std::string formated = format_output(date, value, data);
			std::cout << formated << std::endl;
			
			stack.pop();
		} catch (exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

} 

std::string format_output(std::string date, double value, std::string[] data) {
	
	//TODO: iterate over the array of string (make it a hash map key/value)
	//if there is a date match, output the value as expected
	//else take the smallest closest date and output the value
	for ()
}

double	check_line_format(std::string line, std::string &date) {
	static bool	first_line = true;
	
	if (first_line) {
		first_line = false;
		if (line != "date | value") {
			throw IncorrectFormat::what();
		}
		return;
	}

	std::string::const_iterator iter = line.begin();
	if (atoi(std::string(iter).c_str()) < 2008 || atoi(std::string(iter).c_str()) > 2025) {
		throw InvalidDate::what();
	}
	while (iter != line.end() && *iter != '-') {
		iter++;
	}
	iter++;
	if (*iter == '0' && !isnum(*(iter + 1))) {
		throw InvalidDate::what();	
	} else if (*iter == '1' && (*(iter + 1) != '0' || *(iter + 1) != '1' || *(iter + 1) != '2'){
		throw InvalidDate::what();
	} else if (*iter != '1' || *iter != '0') {
		throw InvalidDate::what();
	}
	while (iter != line.end() && *iter != '-') {
		iter++;
	}
	iter++;
	if ((*iter == '0' || iter == '1' || *iter == '2') && !isnum(*(iter + 1))) {
		throw InvalidDate::what();
	} else if (*iter == '3' && (*(iter + 1) != '0' || *(iter + 1) != '1')) {
		throw InvalidDate::what();
	} else if (*iter != '0' || *iter != '1' || *iter != '2' || *iter != '3') {
		throw InvalidDate::what();
	}
	while (iter != line.end() && *iter != '|') {
		iter++;
	}
	date = std::string(line.begin(), iter - 1);
	iter++;
	double value = atof(std::string(iter).c_str());
	if (value < 0 || value > 1000) {
		throw InvalidValue::what();
	}
	return value;
}

std::string	trim(const std::string &s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isspace(*it)) {
		it++;
	}

	std::string::const_reverse_iterator rit = s.rbegin();
	while (rit.base() != it && isspace(*rit)) {
		rit++;
	}

	return std::string(it, rit.base());
}
