#include <bits/stdc++.h>
using namespace std;
/*
Input
Your program will be given a series of inputs regarding the status of a game. All input will be in lower
case. The first line of each section will contain a number to indicate which round of the game is being
played; the next line will be the solution to the puzzle; the last line is a sequence of the guesses made
by the contestant. A round number of ‘-1’ would indicate the end of all games (and input).
Output
The output of your program is to indicate which round of the game the contestant is currently playing
as well as the result of the game. There are three possible results:
You win.
You lose.
You chickened out.
Sample Input
1
cheese
chese
2
cheese
abcdefg
3
cheese
abcdefgij
-1
Sample Output
Round 1
You win.
Round 2
You chickened out.
Round 3
You lose.
*/
int main()
{
    bool notPicked[26], guessed[26];
    int numDiff, wrong;

    int t;
    string word, input;
    while (cin >> t, t != -1)
    {
        for (int i(0); i < 26; ++i)
            notPicked[i] = guessed[i] = false;
        numDiff = wrong = 0;
        cin >> word >> input;
        for (string::iterator iter = word.begin(); iter != word.end(); ++iter)
        {
            if (!notPicked[*iter - 'a'])
            {
                notPicked[*iter - 'a'] = true;
                ++numDiff;
            }
        }
        for (string::iterator iter = input.begin(); iter != input.end() && wrong < 7 && numDiff; ++iter)
        {
            if (notPicked[*iter - 'a'])
            {
                notPicked[*iter - 'a'] = false;
                guessed[*iter - 'a'] = true;
                --numDiff;
            }
            else if (!guessed[*iter - 'a'])
            {
                guessed[*iter - 'a'] = true;
                ++wrong;
            }
        }
        cout << "Round " << t << '\n';
        if (!numDiff)
            cout << "You win.\n";
        else if (wrong == 7)
            cout << "You lose.\n";
        else
            cout << "You chickened out.\n";
    }
}

