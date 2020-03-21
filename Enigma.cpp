#include "Enigma.h"

Enigma::Enigma(Mechanism** mechanism_array, Rotor** rotors_in_mechanism, int number_of_rotors)
{
	this->mechanism_array = mechanism_array;
	this->number_of_rotors = number_of_rotors;
	this->rotors_in_mechanism = rotors_in_mechanism;
}


int Enigma::Encrypt(int letter) {
	static int count = 0;
	letter = this->mechanism_array[count]->FindIndexOf_AlphabetOriginal_UsingRelativePos(letter);
	if (count == number_of_rotors) { return letter; }
	count++;
	letter=this->Encrypt(letter);
	count--;
	if (count != number_of_rotors) {
		letter = this->mechanism_array[count]->FindIndexOf_Substitute_UsingRelativePos(letter);
	}
	return letter;
}


void Enigma::Lever() {
	for (int i = 0; i < this->number_of_rotors; i++) {
		if (this->rotors_in_mechanism[i]->GetLeverPosition() == BEFORE_LOADED) {
			this->rotors_in_mechanism[i]->SetLeverPosition(LOADED);
		}
	}
	rotors_in_mechanism[0]->SetLeverPosition(LOADED);
	int rotatable_rotors = this->number_of_rotors;
	if (rotatable_rotors > 3) {
		rotatable_rotors = 3;
	}
	int rotation = NO_ACTION;
	while (rotation == NO_ACTION) {
		rotation = this->rotors_in_mechanism[--rotatable_rotors]->LeverPush();
		if (rotation == PUSHED && rotatable_rotors != 0) {
			for (int j = rotatable_rotors - 1; j >= 0; j--) {
				this->rotors_in_mechanism[j]->SetLeverPosition(LOADED);
				this->rotors_in_mechanism[j]->LeverPush();
			}
		}
	}
	if (this->number_of_rotors>1) {
		int* trigger_letters;
		int rotors_that_can_trigger = this->number_of_rotors;
		if (rotors_that_can_trigger > 3) {
			rotors_that_can_trigger = 3;
		}
		for (int i = 0; i < rotors_that_can_trigger; i++) {
			trigger_letters = this->rotors_in_mechanism[i]->GetTriggerLettersArray();
				int j = 0;
				while (trigger_letters[j] != 0) {
					int checked_letter;
					checked_letter = trigger_letters[j];

					checked_letter -= 1;
					if (checked_letter == 0) {
						checked_letter = rotors_in_mechanism[i]->GetAmountOfLettersInABC();
					}
					if (checked_letter == rotors_in_mechanism[i]->GetCurrentAlphabetLetter() && (i + 1) != this->number_of_rotors) {
						rotors_in_mechanism[i + 1]->SetLeverPosition(BEFORE_LOADED);
					}
					j++;
				}
		}
	}
}


Enigma::~Enigma(){}