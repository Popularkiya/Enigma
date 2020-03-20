#include "Mechanism.h"
#include <iostream>


void Mechanism::SetPermutation() {
	for (int i = 0; i < this->amount_of_letters_in_abc; i++) {
		scanf("%i", &this->permutation[i].substitute);
		int relative_pos = (this->permutation[i].substitute - (i + 1));
		if (relative_pos < 0) { relative_pos = this->amount_of_letters_in_abc + relative_pos; }//bo apparently -1%4 to nadal -1
		this->permutation[i].relative_position_sub_to_alph = relative_pos;
	}
	this->AdjustAlphabetToPermutation();
}


void Mechanism::PastePermutation(substiution_str* new_settings) {
	free(this->permutation);
	this->permutation = new_settings;
}


substiution_str* Mechanism::GetPermutation() {
	return permutation;
}


void Mechanism::AdjustAlphabetToPermutation() {
	int a_to_s;
	int index_s;
	for (int i = 0; i < amount_of_letters_in_abc; i++) {
		this->permutation[i].alphabet_original = i+1;

		index_s =this->FindIndexOf_Substitute(i + 1);
		a_to_s = i - index_s;
		if (a_to_s < 0) {
			a_to_s *= -1;
		}
		if (i > index_s) {
			a_to_s = this->amount_of_letters_in_abc - a_to_s;
		}
		this->permutation[i].relative_position_alph_to_sub = a_to_s;
	}
}


int Mechanism::GetSubstitute(int index) {
	return this->permutation[index].substitute;
}


int  Mechanism::GetAmountOfLettersInABC() {
	return this->amount_of_letters_in_abc;
}


int Mechanism::GetAlphabetOriginal(int index) {
	return this->permutation[index].alphabet_original;
}


int Mechanism::FindIndexOf_AlphabetOriginal(int letter) {
	int found = 0;
	int i = 0;
	while (found != letter) {
		found = permutation[i++].alphabet_original;
	}
	return --i;
}


int Mechanism::FindIndexOf_AlphabetOriginal_UsingRelativePos(int index_of_permutation) {
	int amount_of_transitions = this->permutation[index_of_permutation].relative_position_sub_to_alph;
	int index_of_alph = (index_of_permutation + amount_of_transitions) % this->amount_of_letters_in_abc;
	return index_of_alph;
}


int Mechanism::FindIndexOf_Substitute(int letter) {
	int found = 0;
	int i = 0;
	while (found != letter) {
		found = permutation[i++].substitute;
	}
	return --i;
}


int Mechanism::FindIndexOf_Substitute_UsingRelativePos(int index_of_permutation) {
	int amount_of_transitions = this->permutation[index_of_permutation].relative_position_alph_to_sub;
	int index_of_sub = (index_of_permutation + amount_of_transitions) % this->amount_of_letters_in_abc;
	return index_of_sub;
}


Mechanism::~Mechanism() {
	free(this->permutation);
}