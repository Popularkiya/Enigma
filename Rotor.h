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
	int lever;
public:
	Rotor(int amount_of_letters_in_abc);

	void SetRotorsPosition(int shift);

	void AddTriggerLetters(int how_many_triggger_letters);

	void PasteTriggerLetters(int* new_trigges_array);

	int* GetTriggerLettersArray();

	int GetLeverPosition();

	void SetLeverPosition(int position);

	void Rotate();

	int LeverPush();

	~Rotor() override;
};