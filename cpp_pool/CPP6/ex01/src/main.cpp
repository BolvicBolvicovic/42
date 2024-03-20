#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main() {
	Data *data			= new Data;
	uintptr_t raw		= Serializer::serialize(data);
	Data *deserialized	= Serializer::deserialize(raw);

	std::cout	<< "data: "			<< data			<< std::endl
				<< "deserialized: "	<< deserialized << std::endl;
	delete deserialized;
	return 0;
}
