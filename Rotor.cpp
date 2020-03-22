#include "Rotor.h"
#include <iostream>


Rotor::Rotor(int amount_of_letters_in_abc)
{
	this->amount_of_letters_in_abc = amount_of_letters_in_abc;
	this->permutation = (int*)malloc(amount_of_letters_in_abc * sizeof(int));
	this->relative_permutation = (permutation_struct*)malloc(amount_of_letters_in_abc * sizeof(permutation_struct));
	this->current_alphabet_letter = 1;
	this->shift_vector = 0;
	this->moved = false;
	this->number_of_trigger_letters = 0;
	this->trigger_letters = NULL;
	this->lever = UNLOADED;
}


void Rotor::Rotate(int vector) {
	int new_vector = (this->GetShiftVector() + vector) % this->amount_of_letters_in_abc;
	SetShiftVector(new_vector);

	this->current_alphabet_letter += vector;
	if (this->current_alphabet_letter > this->amount_of_letters_in_abc) {
		this->current_alphabet_letter -= this->amount_of_letters_in_abc;
	}
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
