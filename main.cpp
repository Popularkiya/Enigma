#include<iostream>
#include"Mechanism.h"
#include"Reflector.h"
#include"Rotor.h"
#include"Enigma.h"



Rotor* CopyRotor(Rotor* original) {
	int letters_in_abc = original->GetAmountOfLettersInABC();
	Rotor* copy = new Rotor(letters_in_abc);
	int *original_triggers=original->GetTriggerLettersArray();
	int amount_of_triggers= original->GetAmountOfTriggerLetters();

	int* triggers_copy = (int*)malloc((amount_of_triggers+1) * sizeof(int));

	for (int i = 0; i < (amount_of_triggers+1); i++) {
		triggers_copy[i] = original_triggers[i];
	}
	copy->PasteTriggerLetters(triggers_copy);

	
	permutation_struct* relative_permutation_copy = (permutation_struct*)malloc(letters_in_abc * sizeof(permutation_struct));
	permutation_struct* original_relative_permutation = original->GetPermutation();

	for (int i = 0; i < letters_in_abc; i++) {
		relative_permutation_copy[i] = original_relative_permutation[i];
	}

	copy->PastePermutation(relative_permutation_copy);

	return copy;
}


Reflector* CopyReflector(Reflector* original) {
	int letters_in_abc = original->GetAmountOfLettersInABC();
	Reflector* copy = new Reflector(letters_in_abc);
	permutation_struct* relative_permutation_copy = (permutation_struct*)malloc(letters_in_abc * sizeof(permutation_struct));
	permutation_struct* original_relative_permutation = original->GetPermutation();

	for (int i = 0; i < letters_in_abc; i++) {
		relative_permutation_copy[i] = original_relative_permutation[i];
	}

	copy->PastePermutation(relative_permutation_copy);

	return copy;
}



int main() {
	Reflector** reflectors_array;
	Rotor** rotors_array;
	int number_of_letters_in_alphabet, number_of_all_rotors, number_of_reflectors;
	scanf("%d", &number_of_letters_in_alphabet);
	scanf("%d ", &number_of_all_rotors);


	rotors_array = new Rotor*[number_of_all_rotors];
	for (int i = 0; i < number_of_all_rotors; i++) {
		rotors_array[i] = new Rotor(number_of_letters_in_alphabet);
		rotors_array[i]->SetPermutation();
		int triggers;
		scanf("%d", &triggers);
		rotors_array[i]->AddTriggerLetters(triggers);
	}

	scanf("%d", &number_of_reflectors);

	reflectors_array = new Reflector*[number_of_reflectors];
	for (int i = 0; i < number_of_reflectors; i++) {
		reflectors_array[i] = new Reflector(number_of_letters_in_alphabet);
		reflectors_array[i]->SetPermutation();
	}




	Mechanism** mechanism_array;
	Rotor** rotors_in_mechanism;
	int number_of_tasks, index_of_gear_in_main_array, number_of_rotors;
	scanf("%d ", &number_of_tasks);

	for (int j = 0; j < number_of_tasks; j++) {
		scanf("%d ", &number_of_rotors);

		mechanism_array = new Mechanism * [number_of_rotors+1];
		rotors_in_mechanism = new Rotor * [number_of_rotors];
		int rotors_position;
		for (int k = 0; k < number_of_rotors; k++) {
			scanf("%d ", &index_of_gear_in_main_array);
			rotors_in_mechanism[k]=CopyRotor(rotors_array[index_of_gear_in_main_array]);
			mechanism_array[k] = rotors_in_mechanism[k];

			scanf("%d ", &rotors_position);
			rotors_in_mechanism[k]->SetRotorsPosition(rotors_position);
		}

		scanf("%d ", &index_of_gear_in_main_array);
		mechanism_array[number_of_rotors] = CopyReflector(reflectors_array[index_of_gear_in_main_array]);

		Enigma enigma_machine (mechanism_array, rotors_in_mechanism, number_of_rotors);
		int letter;
		int count = 1;
		while (std::cin>>letter && letter != 0) {
			enigma_machine.Lever();
			printf("%d ", enigma_machine.Encrypt(letter-1)+1);
			count++;
		}

		for (int i = 0; i < number_of_rotors; i++) {
			delete rotors_in_mechanism[i];
			rotors_in_mechanism[i] = nullptr;
		}
		delete[] rotors_in_mechanism;
		rotors_in_mechanism = nullptr;
		delete mechanism_array[number_of_rotors];
		mechanism_array[number_of_rotors] = nullptr;
		delete[] mechanism_array;
		mechanism_array = nullptr;
	}

	for (int i = 0; i < number_of_all_rotors; i++) {
		delete rotors_array[i];
		rotors_array[i] = nullptr;
	}
	delete[] rotors_array;
	rotors_array = nullptr;
	for (int i = 0; i < number_of_reflectors; i++) {
		delete reflectors_array[i];
		reflectors_array[i] = nullptr;
	}
	delete[] reflectors_array;
	reflectors_array = nullptr;

	return 0;
}