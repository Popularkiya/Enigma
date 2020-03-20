#pragma once
#include "Mechanism.h"
#include <iostream>

class Reflector : public Mechanism {
public:
	Reflector(int amount_of_letters_in_abc);

	~Reflector() override;
};
