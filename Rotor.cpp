#include "Rotor.h"
#include <iostream>


Rotor::Rotor(int amount_of_letters_in_abc)
{
	this->amount_of_letters_in_abc = amount_of_letters_in_abc;
	this->permutation = (int*)malloc(amount_of_letters_in_abc * sizeof(int));
	this->relative_permutation = (permutation_struct*)malloc(amount_of_letters_in_abc * sizeof(permutation_struct));
	this->current_alphabet_letter = 1;
	this->moved = false;
	this->number_of_trigger_letters = 0;
	this->trigger_letters = NULL;
	this->lever = UNLOADED;
}


void Rotor::Rotate(int vector) {
	permutation_struct* first = (permutation_struct*)malloc(vector * sizeof(permutation_struct));
	for (int j = 0; j < vector; j++) {
		first[j] = this->relative_permutation[j];
	}
	for (int i = 0; i < (this->amount_of_letters_in_abc-vector); i++) {
		this->relative_permutation[i] = this->relative_permutation[i + vector];
	}
	for (int k = 0; k < vector; k++) {
		this->relative_permutation[amount_of_letters_in_abc - vector + k] = first[k];
	}

	this->current_alphabet_letter += vector;
	if (this->current_alphabet_letter > this->amount_of_letters_in_abc) {
		this->current_alphabet_letter -= this->amount_of_letters_in_abc;
	}

	free(first);
	first = nullptr;
}


void Rotor::SetRotorsPosition(int shift) {
		this->Rotate(shift-1);
}



int Rotor::GetCurrentAlphabetLetter() {
	return this->current_alphabet_letter;
}



void Rotor::AddTriggerLetters(int how_many_triggger_letters){
	this->number_of_trigger_letters = how_many_triggger_letters;
	if (how_many_triggger_letters > 0) {
		this->trigger_letters = (int*)malloc((how_many_triggger_letters + 1) * sizeof(int));
		for (int i = 0; i < (how_many_triggger_letters); i++) {
			scanf("%d", &trigger_letters[i]);
		}
	}
	else {
		this->trigger_letters = (int*)malloc(1 * sizeof(int));
	}
	trigger_letters[how_many_triggger_letters] = 0;
}


void Rotor::PasteTriggerLetters(int* new_trigges_array) {
	free(this->trigger_letters);
	this->trigger_letters = new_trigges_array;
}


int* Rotor::GetTriggerLettersArray() {
	return this->trigger_letters;
}


int Rotor::GetAmountOfTriggerLetters() {
	return this->number_of_trigger_letters;
}


int Rotor::GetLeverPosition() {
	return lever;
}


void Rotor::SetLeverPosition(int position) {
	lever = position;
}


int Rotor::LeverPush() {
	if (this->lever == LOADED) {
		this->Rotate(1);
		this->moved=true;
		lever = UNLOADED;
		return PUSHED;
	}
	return NO_ACTION;
}


Rotor::~Rotor() {
	if (this->relative_permutation != nullptr) {
		free(this->relative_permutation);
		this->relative_permutation = nullptr;
	}
	free(this->trigger_letters);
	this->trigger_letters = nullptr;
}
