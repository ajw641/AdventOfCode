#include "..\AlexTemplate.h"

vi sentenceToWords(string *sentence)
{
	vi words;
	string input, word;
	stringstream s((*sentence));
	while (getline(s, word, '-'))
	{
		int x;
		sscanf(word.c_str(), "%d", &x);
		words.pb(int(x));
	}
	return words;
}

/* Read in the Integers from the puzzle into a vector*/
void readInput(string filename, vector<vs> *inputV)
{
	fstream f;
	f.open(filename);
	string x;
	vs words;
	int counter = 0;
	while (f >> x)
	{
		if (counter == 3)
		{
			(*inputV).pb(words);
			counter = 0;
			words.clear();
		}
		// strip the : for the letter ready for regex
		if (counter == 1)
		{
			words.pb(x.substr(0, 1));
		}
		else
		{
			words.pb(x);
		}
		counter++;
	}
}

bool isLetterPositionCorrect(char *p, int i, int j, char letter)
{
	bool passwordValid = false;
	if (p[i - 1] == letter and p[j - 1] != letter)
	{
		passwordValid = true;
	}
	if (p[i - 1] != letter and p[j - 1] == letter)
	{
		passwordValid = true;
	}
	return passwordValid;
}

pii checkAllPasswords(vector<vs>* fileLines)
{
	int posPasswordsA = 0;
	int posPasswordsB = 0;
	vector<vs>::iterator step;
	foreach(step, (*fileLines))
	{
		auto row = (*step);
		int lowerLimit = int(sentenceToWords(&row[0])[0]);
		int upperLimit = int(sentenceToWords(&row[0])[1]);
		char letter = row[1].c_str()[0];
		int plen = row[2].length();
		char password[plen];
		strcpy(password, row[2].c_str());

		int i;
		bool passwordValid = true;
		bool letterPositionCorrect;
		int letterCount = 0;
		for0(i, plen)
		{
			if (password[i] == letter)
			{
				letterCount++;
			}
			if (letterCount > upperLimit)
			{
				passwordValid = false;
				break;
			}
			letterPositionCorrect = isLetterPositionCorrect(password, lowerLimit, upperLimit, letter);
		}

		if (passwordValid and !(letterCount < lowerLimit)) posPasswordsA++;
		if (letterPositionCorrect) posPasswordsB++;
	}
	return pii(posPasswordsA, posPasswordsB);
}

int main()
{
	vector<vs> fileLines;
	readInput("puzzleInput.txt", &fileLines);
	pii results = checkAllPasswords(&fileLines);
	prnd(results.fi);
	prnd(results.se);
	return 0;
}
