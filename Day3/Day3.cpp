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

int traverseMap(vector<ca>* treeMap, int right, int down)
{
    int numberOfTrees = 0;
    int column = 0;
    for0(row, (*treeMap).size())
    {
        char currentSpot = (*treeMap)[row].a[column];
        if(currentSpot == '#')
        {
            numberOfTrees ++;
        }
        column = (column + right) % 31;
        row = row + (down-1);
    }
    return numberOfTrees;
}

int main()
{
    vector<ca> treeMap;
    readInput("puzzleInput.txt", &treeMap);
    unsigned int slope1 = traverseMap(&treeMap, 1, 1);
    unsigned int slope2 = traverseMap(&treeMap, 3, 1);
    unsigned int slope3 = traverseMap(&treeMap, 5, 1);
    unsigned int slope4 = traverseMap(&treeMap, 7, 1);
    unsigned int slope5 = traverseMap(&treeMap, 1, 2);
    uint64 answer = slope1*slope2*slope3*slope4*slope5;
    printf("%lld\n", answer);
    return 0;
}