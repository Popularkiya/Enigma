#include "Rotor.h"
#include <iostream>


Rotor::Rotor(int amount_of_letters_in_abc)
{
	this->amount_of_letters_in_abc = amount_of_letters_in_abc;
	this->permutation = (substiution_str*)malloc(amount_of_letters_in_abc * sizeof(substiution_str));
	this->trigger_letters = NULL;
	this->lever = UNLOADED;
}


void Rotor::Rotate() {
	substiution_str first;
	first = this->permutation[0];
	for (int i = 0; i < this->amount_of_letters_in_abc-1; i++) {
		this->permutation[i] = this->permutation[i + 1];
	}
	this->permutation[amount_of_letters_in_abc - 1] = first;
}


void Rotor::SetRotorsPosition(int shift) {
	for (int i = 1; i < shift; i++) {
		this->Rotate();
	}
}



void Rotor::AddTriggerLetters(int how_many_triggger_letters){
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


int Rotor::GetLeverPosition() {
	return lever;
}


void Rotor::SetLeverPosition(int position) {
	lever = position;
}


int Rotor::LeverPush() {
	if (this->lever == LOADED) {
		this->Rotate();
		lever = UNLOADED;
		return PUSHED;
	}
	return NO_ACTION;
}


Rotor::~Rotor() {
	free(this->trigger_letters);
}
