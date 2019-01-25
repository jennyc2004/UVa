#include <bits/stdc++.h>
using namespace std;
#define SIZE 30001

unsigned long long ways[30001];
int changeTypes[] = {1, 5, 10, 25, 50};

int main()
{
    ways[0] = 1;
    for (int c = 0; c < 5; ++c)
    {
        for (int i = changeTypes[c]; i < SIZE; ++i)
        {
            ways[i] += ways[i - changeTypes[c]];
        }
    }
    int cents;
    while (cin >> cents)
    {
        if (ways[cents] == 1)
            cout << "There is only 1 way to produce " << cents << " cents change.\n";
        else
            cout << "There are " << ways[cents] << " ways to produce " << cents << " cents change.\n";
    }
}
/*
Input
The input will consist of a set of numbers between 0 and 30000 inclusive, one per line in the input file.
Output
The output will consist of the appropriate statement from the selection below on a single line in the
output file for each input value. The number m is the number your program computes, n is the input
value.
There are m ways to produce n cents change.
There is only 1 way to produce n cents change.
Sample input
17
11
4
Sample output
There are 6 ways to produce 17 cents change.
There are 4 ways to produce 11 cents change.
There is only 1 way to produce 4 cents change.
*/
