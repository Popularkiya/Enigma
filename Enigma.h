#pragma once
#include <iostream>
#include"Mechanism.h"
#include"Reflector.h"
#include"Rotor.h"

class Enigma {
protected:
	Mechanism** mechanism_array;
	Rotor** rotors_in_mechanism;
	int number_of_rotors;
public:
	Enigma(Mechanism** mechanism_array, Rotor** rotors_in_mechanism,int number_of_rotors);

	void Lever();
	int Encrypt(int letter);

	~Enigma();

};