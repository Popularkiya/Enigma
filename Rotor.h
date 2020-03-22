#pragma once
#include "Mechanism.h"
#include <iostream>

#define LOADED 2
#define UNLOADED 0
#define BEFORE_LOADED 1
#define NO_ACTION -1
#define PUSHED 3

class Rotor : public Mechanism {
private:
	int* trigger_letters;
	int number_of_trigger_letters;
	int lever;
	int current_alphabet_letter;
public:
	Rotor(int amount_of_letters_in_abc);
	bool moved;
	int count_down_to_full_rotation;
	void SetRotorsPosition(int shift);
	void AddTriggerLetters(int how_many_triggger_letters);
	void PasteTriggerLetters(int* new_trigges_array);
	int GetCurrentAlphabetLetter();
	int* GetTriggerLettersArray();
	int GetLeverPosition();
	int GetAmountOfTriggerLetters();
	void SetLeverPosition(int position);
	void Rotate(int vector);
	int LeverPush();

	~Rotor() override;
};