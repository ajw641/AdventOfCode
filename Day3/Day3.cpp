#include "..\AlexTemplate.h"

struct ca
{
    char a[32];
};

/* Read in the Integers from the puzzle into a vector*/
void readInput(string filename, vector<ca>* inputV)
{
	fstream f;
	f.open(filename);
    char x[32];
    ca newLine;
	while(f>>x)
	{
        strncpy(newLine.a, x, 32);
		(*inputV).pb(newLine);
	}
}

int traverseMap(vector<ca>* treeMap)
{
    int numberOfTrees = 0;
    int column = 0;
    for0(row, (*treeMap).size())
    {
        char currentSpot = (*treeMap)[row].a[column];
        if(row<12)
        {
        prnc(currentSpot);
        }
        if(currentSpot == '#')
        {
            numberOfTrees ++;
        }
        column = (column + 3) % 31;
    }
    return numberOfTrees;
}

int main()
{
    vector<ca> treeMap;
    readInput("puzzleInput.txt", &treeMap);
    int result = traverseMap(&treeMap);
    prnd(result);
    return 0;
}