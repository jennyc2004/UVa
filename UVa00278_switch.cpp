#include <bits/stdc++.h>
using namespace std;
/*
Input
The first line of input contains the number of problems. A problem is stated on one line and consists of
one character from the following set ‘r’, ‘k’, ‘Q’, ‘K’, meaning respectively the chesspieces Rook, Knight,
Queen or King. The character is followed by the integers m (4 ≤ m ≤ 10) and n (4 ≤ n ≤ 10), meaning
the number of rows and the number of columns or the board.
Output
For each problem specification in the input your program should output the maximum number of
chesspieces which can be put on a board with the given formats so they are not in position to take any
other piece.
Note: The bottom left square is 1, 1.
Sample Input
2
r 6 7
k 8 8
Sample Output
6
32
*/
int main() {
    int t, n, m;
    char s[2];
    int temp;
    cin>>t;
    while (t--) {
        cin>>s>>n>>m;
        switch(s[0]){
            case 'r':
                temp = min(n, m);
                break;
            case 'k':
                if (n == 1) temp = m;
                if (m == 1) temp = n;
                if (n == 2)
                    temp = (m / 2 * 2 + m % 2 * 2);
                if (m == 2)
                    temp = (n / 2 * 2 + n % 2 * 2);
                temp = (n * m + 1) / 2;
                break;
            case 'Q':
                temp = min(n, m);
                break;
            case 'K':
                temp = (n + 1) / 2 * ((m + 1) / 2);
                break;
            default:
                break;
        }
        cout<<temp<<endl;
    }
    return 0;
}

