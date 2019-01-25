#include <bits/stdc++.h>
using namespace std;
/*
Input
Input will consist of a series of lines each containing a string representing a code. The entire file will
be terminated by a line consisting of a single ‘#’.
Output
Output will consist of one line for each code read containing the successor code or the words ‘No
Successor’.
Sample Input
abaacb
cbbaa
#
Sample Output
ababac
No Successor
*/
int main()
{
    vector<char> line;
    while (!cin.eof()){
        char c = cin.get();
        if (c != '\r' && c != '\n'){
            if (c == '#')break;
            line.push_back(c);
        }
        else{
            if (next_permutation(line.begin(), line.end())){
                for (vector<char>::iterator i = line.begin(); i != line.end(); i++)cout << *i;
                cout << endl;
            }
            else cout << "No Successor" << endl;
            line.clear();
        }
    }
    return 0;
}

