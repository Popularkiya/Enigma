#pragma once
#include <iostream>


struct permutation_struct {
	int relative_position_sub_to_alph;
	int relative_position_alph_to_sub;
};

class Mechanism {
protected:
	permutation_struct* relative_permutation;
	int* permutation;
	int amount_of_letters_in_abc;
	int shift_vector;

public:
	virtual permutation_struct* GetPermutation();
	virtual int GetAmountOfLettersInABC();
	virtual void SetPermutation();
	virtual void PastePermutation(permutation_struct* new_settings);
	virtual void AdjustAlphabetToPermutation();
	//virtual int GetSubstitute(int index);
	//virtual int GetAlphabetOriginal(int index);
	//virtual int FindIndexOf_AlphabetOriginal(int letter);
	virtual int FindIndexOf_AlphabetOriginal_UsingRelativePos(int index_of_permutation);
	virtual int FindIndexOf_Substitute(int letter);
	virtual int FindIndexOf_Substitute_UsingRelativePos(int index_of_permutation);
	void SetShiftVector(int vector);
	int GetShiftVector();

	virtual ~Mechanism();
};
