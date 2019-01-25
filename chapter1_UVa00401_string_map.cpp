#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
/*
Input
Input consists of strings (one per line) each of which will consist of one to twenty valid characters.
There will be no invalid characters in any of the strings. Your program should read to the end of file.
Output
For each input string, you should print the string starting in column 1 immediately followed by exactly
one of the following strings.
STRING CRITERIA
‘ -- is not a palindrome.’ if the string is not a palindrome and is not a mirrored string
‘ -- is a regular palindrome.’ if the string is a palindrome and is not a mirrored string
‘ -- is a mirrored string.’ if the string is not a palindrome and is a mirrored string
‘ -- is a mirrored palindrome.’ if the string is a palindrome and is a mirrored string
Note that the output line is to include the ‘-’s and spacing exactly as shown in the table above and
demonstrated in the Sample Output below.
In addition, after each output line, you must print an empty line.
Sample Input
NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA
Sample Output
NOTAPALINDROME -- is not a palindrome.
ISAPALINILAPASI -- is a regular palindrome.
2A3MEAS -- is a mirrored string.
ATOYOTA -- is a mirrored palindrome.
*/
static map<char, char> mirror;

bool isPalindrome(string s)
{
    string reverseS(s);
    reverse(reverseS.begin(), reverseS.end());
    return s == reverseS;
}
bool isMirrored(string s)
{
    string::reverse_iterator r_iter(s.rbegin());
    for (string::const_iterator iter = s.begin() ; iter < s.begin() + (s.size() + 1) / 2; ++iter, ++r_iter)
        if (!mirror.count(*iter) || mirror[*iter] != *r_iter)
            return false;
    return true;
}
int main()
{
    char from[] = {'A', 'E', 'H', 'I', 'J', 'L',
                   'M', 'O', 'S', 'T', 'U', 'V',
                   'W', 'X', 'Y', 'Z', '1', '2',
                   '3', '5', '8'};
    char to[]   = {'A', '3', 'H', 'I', 'L', 'J',
                   'M', 'O', '2', 'T', 'U', 'V',
                   'W', 'X', 'Y', '5', '1', 'S',
                   'E', 'Z', '8'};
    for (int i = 0; i < sizeof(from) / sizeof(char); ++i)
        mirror[from[i]] = to[i];
    string s;
    while (cin >> s)
    {
        bool isPalin = isPalindrome(s);
        bool isMir = isMirrored(s);
        cout << s << " -- ";
        if (!isPalin && !isMir)
            cout << "is not a palindrome." << endl;
        else if (isPalin && !isMir)
            cout << "is a regular palindrome." << endl;
        else if (!isPalin && isMir)
            cout << "is a mirrored string." << endl;
        else
            cout << "is a mirrored palindrome." << endl;
        cout << endl;
    }
    return 0;
}

