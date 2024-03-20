#pragma once

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
	Serializer();
public:
	Serializer(Serializer &ref);
	~Serializer();
	Serializer	&operator=(Serializer &ref);

	static uintptr_t	serialize(Data *ptr);
	static Data				*deserialize(uintptr_t raw);
};
