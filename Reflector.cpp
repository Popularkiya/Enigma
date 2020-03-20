#include "Reflector.h"
#include <iostream>

Reflector::Reflector(int amount_of_letters_in_abc)
{
	this->amount_of_letters_in_abc = amount_of_letters_in_abc;
	this->permutation = (substiution_str*)malloc(amount_of_letters_in_abc * sizeof(substiution_str));
}


Reflector::~Reflector() {}