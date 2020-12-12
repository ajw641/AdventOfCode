#include "Day1.h"


/* Read in the Integers from the puzzle into a vector*/
void readInputInts(string filename, VI* inputV)
{
	fstream f;
	f.open(filename);
	int x;
	while(f>>x)
	{
		(*inputV).PB(x);
	}
}

/* Remove all integers in the vector that are > target which arent valid*/
void removeInvalidEntries(VI* numbers, int target)
{
	(*numbers).erase(remove((*numbers).begin(), (*numbers).end(), target), (*numbers).end());
	return;
}

/* Get the pair of integers in the puzzle that multiply to the correct target*/
PII findPair(VI* numbers, int target)
{
	sort((*numbers).begin(), (*numbers).end());
	VI::iterator it;
	FOREACH(it, (*numbers))
	{
		int value = *it;
		if(binary_search(it + 1, (*numbers).end(), target - value))
		{
			PII newPair(value, target - value); 
			return newPair;
		}
	}
	return PII();

}

/* Gets the pair that sum to target and multiplies them*/
int solvePuzzle(VI* numbers, int target)
{
	removeInvalidEntries(numbers, target);
	PII answers = findPair(numbers, target);
	return answers.first * answers.second;
}

/* Main Function*/
int main()
{
	VI puzzleNumbers;
	readInputInts("puzzleInput.txt", &puzzleNumbers);
	int puzzleAnswer = solvePuzzle(&puzzleNumbers, 2020);
	PRN(puzzleAnswer);
	return 0;
}