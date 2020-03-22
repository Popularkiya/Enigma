#include "Mechanism.h"
#include <iostream>


void Mechanism::SetPermutation() {
	for (int i = 0; i < this->amount_of_letters_in_abc; i++) {
		scanf("%i", &this->permutation[i]);
		int relative_pos = (this->permutation[i] - (i + 1));
		if (relative_pos < 0) { relative_pos = this->amount_of_letters_in_abc + relative_pos; }//bo apparently -1%4 to nadal -1
		this->relative_permutation[i].relative_position_sub_to_alph = relative_pos;
	}
	this->AdjustAlphabetToPermutation();
}


void Mechanism::PastePermutation(permutation_struct* new_settings) {
	free(this->relative_permutation);
	this->relative_permutation = new_settings;
}


permutation_struct* Mechanism::GetPermutation() {
	return relative_permutation;
}


void Mechanism::AdjustAlphabetToPermutation() {
	int a_to_s;
	int index_s;
	for (int i = 0; i < amount_of_letters_in_abc; i++) {

		index_s =this->FindIndexOf_Substitute(i + 1);
		a_to_s = i - index_s;
		if (a_to_s < 0) {
			a_to_s *= -1;
		}
		if (i > index_s) {
			a_to_s = this->amount_of_letters_in_abc - a_to_s;
		}
		this->relative_permutation[i].relative_position_alph_to_sub = a_to_s;
	}
	free(this->permutation);
	this->permutation = nullptr;
}


/*int Mechanism::GetSubstitute(int index) {
	return this->permutation[index];
}*/


int  Mechanism::GetAmountOfLettersInABC() {
	return this->amount_of_letters_in_abc;
}


/*int Mechanism::GetAlphabetOriginal(int index) {
	return this->permutation[index].alphabet_original;
}


int Mechanism::FindIndexOf_AlphabetOriginal(int letter) {
	int found = 0;
	int i = 0;
	while (found != letter) {
		found = permutation[i++].alphabet_original;
	}
	return --i;
}*/


int Mechanism::FindIndexOf_AlphabetOriginal_UsingRelativePos(int index_of_permutation) {
	int amount_of_transitions = this->relative_permutation[(index_of_permutation + this->shift_vector) % this->amount_of_letters_in_abc].relative_position_sub_to_alph;
	int index_of_alph = (index_of_permutation + amount_of_transitions) % this->amount_of_letters_in_abc;
	return index_of_alph;
}


int Mechanism::FindIndexOf_Substitute(int letter) {
	int found = 0;
	int i = 0;
	while (found != letter) {
		found = permutation[i++];
	}
	return --i;
}


int Mechanism::FindIndexOf_Substitute_UsingRelativePos(int index_of_permutation) {
	int amount_of_transitions = this->relative_permutation[(index_of_permutation + this->shift_vector) % this->amount_of_letters_in_abc].relative_position_alph_to_sub;
	int index_of_sub = (index_of_permutation + amount_of_transitions) % this->amount_of_letters_in_abc;
	return index_of_sub;
}


void Mechanism::SetShiftVector(int vector) {
	this->shift_vector = vector;
}



int Mechanism::GetShiftVector() {
	return this->shift_vector;
}


Mechanism::~Mechanism() {
	if (this->relative_permutation != nullptr) {
		free(this->relative_permutation);
		this->relative_permutation = nullptr;
	}
	if (this->permutation != nullptr) {
		free(this->permutation);
		this->permutation = nullptr;
	}
}