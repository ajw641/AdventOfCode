#include "..\AlexTemplate.h"


/* Read in the Integers from the puzzle into a vector*/
void readInputInts(string filename, vi* inputV)
{
	fstream f;
	f.open(filename);
	int x;
	while(f>>x)
	{
		(*inputV).pb(x);
	}
}

/* Remove all integers in the vector that are > target which arent valid*/
void removeInvalidEntries(vi* numbers, int target)
{
	(*numbers).erase(remove((*numbers).begin(), (*numbers).end(), target), (*numbers).end());
	return;
}

/* Get the pair of integers in the puzzle that multiply to the correct target*/
pii findPair(vi* numbers, int target)
{
	sort((*numbers).begin(), (*numbers).end());
	vi::iterator it;
	foreach(it, (*numbers))
	{
		int value = *it;
		if(binary_search(it + 1, (*numbers).end(), target - value))
		{
			pii newPair(value, target - value); 
			return newPair;
		}
	}
	return pii();

}

vi findTriple(vi* numbers, int target)
{
	sort((*numbers).begin(), (*numbers).end());
	vi::iterator it;
	foreach(it, (*numbers))
	{
		int value = *it;
		vi sub(it+1, (*numbers).end());
		pii possiblePair = findPair(&sub, target - value);
		if (possiblePair != pii())
		{
			vi answers{value, possiblePair.first, possiblePair.second};
			return answers;
		}
	}
}

/* Gets the pair that sum to target and multiplies them*/
pii solvePuzzle(vi* numbers, int target)
{
	removeInvalidEntries(numbers, target);
	pii pairAnswers = findPair(numbers, target);
	vi tripleAnswers = findTriple(numbers, target);
	int pairAnswer = pairAnswers.first * pairAnswers.second;
	int tripleAnswer = (tripleAnswers[0] * tripleAnswers[1] * tripleAnswers[2]);
	pii answerPair(pairAnswer, tripleAnswer);
	return answerPair;
}

/* Main Function*/
int main()
{
	vi puzzleNumbers;
	readInputInts("puzzleInput.txt", &puzzleNumbers);
	pii puzzleAnswer = solvePuzzle(&puzzleNumbers, 2020);
	prnd(puzzleAnswer.first);
	prnd(puzzleAnswer.second);
	return 0;
}