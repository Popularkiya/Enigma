#pragma once
#include <iostream>

struct substiution_str {
	int substitute;
	int alphabet_original;
	int relative_position_sub_to_alph;
	int relative_position_alph_to_sub;
};

class Mechanism {
protected:
	substiution_str* permutation;
	int amount_of_letters_in_abc;

public:
	virtual substiution_str* GetPermutation();
	virtual int GetAmountOfLettersInABC();
	virtual void SetPermutation();
	virtual void PastePermutation(substiution_str* new_settings);
	virtual void AdjustAlphabetToPermutation();
	virtual int GetSubstitute(int index);
	virtual int GetAlphabetOriginal(int index);
	virtual int FindIndexOf_AlphabetOriginal(int letter);
	virtual int FindIndexOf_AlphabetOriginal_UsingRelativePos(int index_of_permutation);
	virtual int FindIndexOf_Substitute(int letter);
	virtual int FindIndexOf_Substitute_UsingRelativePos(int index_of_permutation);
	virtual ~Mechanism();
};
