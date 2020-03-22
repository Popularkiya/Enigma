#include "Reflector.h"
#include <iostream>

Reflector::Reflector(int amount_of_letters_in_abc)
{
	this->amount_of_letters_in_abc = amount_of_letters_in_abc;
	this->permutation = (int*)malloc(amount_of_letters_in_abc * sizeof(int));
	this->relative_permutation = (permutation_struct*)malloc(amount_of_letters_in_abc * sizeof(permutation_struct));
}


Reflector::~Reflector() {
	if (this->relative_permutation != nullptr) {
		free(this->relative_permutation);
		this->relative_permutation = nullptr;
	}
}