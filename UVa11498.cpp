#include <bits/stdc++.h>
using namespace std;

int main() {
    int queries;
    int divx, divy;
    int homex, homey;
    cin >> queries;
    while (queries > 0) {
        cin >> divx >> divy;
        while (queries > 0) {
            cin >> homex >> homey;
            if (homex > divx && homey > divy)
                cout << "NE" << endl;
            else if (homex > divx && homey < divy) {
                cout << "SE" << endl;
            } else if (homex < divx && homey > divy) {
                cout << "NO" << endl;
            } else if (homex < divx && homey < divy) {
                cout << "SO" << endl;
            } else {
                cout << "divisa" << endl;
            }
            queries--;
        }
        cin >> queries;
    }
    return 0;
}
/*
Input
The input contains several test cases. The first line of a test case contains one integer K indicating
the number of queries that will be made (0 < K ≤ 103
). The second line of a test case contains two
integers N and M representing the coordinates of the division point (−104 < N, M < 104
). Each
of the K following lines contains two integers X and Y representing the coordinates of a residence
(−104 ≤ X, Y ≤ 104
).
The end of input is indicated by a line containing only the number zero.
Output
For each test case in the input your program must print one line containing:
• the word ‘divisa’ (means border in Portuguese) if the residence is on one of the border lines
(North-South or East-West);
• ‘NO’ (means NW in Portuguese) if the residence is in Northwestern Nlogonia;
• ‘NE’ if the residence is in Northeastern Nlogonia;
• ‘SE’ if the residence is in Southeastern Nlogonia;
• ‘SO’ (means SW in Portuguese) if the residence is in Southwestern Nlogonia.
Sample Input
3
2 1
10 10
-10 1
0 33
4
-1000 -1000
-1000 -1000
0 0
-2000 -10000
-999 -1001
0
Sample Output
NE
divisa
NO
divisa
NE
SO
SE
*/
