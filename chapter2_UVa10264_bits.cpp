#include <bits/stdc++.h>
using namespace std;
inline bool neighbors(int i, int j) {
    int n = i^j;
    return (n&(-n)) == n;
}
const int maxCorner = (1<<15);
int n, m;
int potencies[maxCorner];
int main() {
    while(cin >> n) {
        int corners = 1<<n;
        fill_n(potencies, corners, 0);
        m = 0;
        for(int i=0; i<corners; i++) {
            int x;
            cin >> x;
            for(int j=0; j<corners; j++) {
                if(neighbors(i, j) && i != j) potencies[j]+=x;
            }
        }
        for(int i=0; i<corners; i++) {
            for(int j=0; j<corners; j++) {
                if(!neighbors(i, j) || i == j) continue;
                m = max(m, potencies[i]+potencies[j]);
            }
        }
        cout << m << endl;
    }
    return 0;
}
/*
Input
The input will consist of several input blocks. Each input block begins with the integer N, the dimension
of the cube. Then there are weights of the corners, one per line in the natural order:
• the first line contains the weight of the corner (0,...0,0,0),
• the second one - the weight of (0,...,0,0,1),
• then there is the weight of (0,...,0,1,0), then (0,...,0,1,1), then (0,...,1,0,0),
• the penultimate line contains the weight of the corner (1,...,1,1,0),
• the last one - (1,...,1,1,1).
The input is terminated by ¡EOF¿.
Output
For each input block the output line should contain one number, the maximum potencies sum.
Sample Input
3
82
73
8
49
120
44
242
58
2
1
1
1
1
Sample Output
619
4
*/
