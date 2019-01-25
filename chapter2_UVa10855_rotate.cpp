#include <bits/stdc++.h>
using namespace std;
char big[500][500], small[500][500];
int find(int n, int m) {
    int ans = 0, i, j, k, l;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i+m <= n && j+m <= n) {
                int cnt = 0;
                for(k = 0; k < m; k++) {
                    for(l = 0; l < m; l++) {
                        if(big[i+k][j+l] == small[k][l])
                            cnt++;
                    }
                }
                if(cnt == m*m)
                    ans++;
            }
        }
    }
    return ans;
}
void rotate(int n) {
    char tmp[n][n];
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            tmp[i][j] = small[n-j-1][i];
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
           small[i][j] = tmp[i][j];
    }
}
int main() {
    int n, m, i;
    while(scanf("%d %d", &n, &m) == 2) {
        if(n == 0 && m == 0) break;
        for(i = 0; i < n; i++) cin>>big[i];
        for(i = 0; i < m; i++) cin>>small[i];
        for(i = 0; i < 4; i++) {
            if(i) cout<<" ";
            printf("%d", find(n, m));
            rotate(m);
        }
        cout<<endl;
    }
    return 0;
}
/*
Input
The input will consist of a series of problems, with each problem in a series of lines. In the first line,
the dimension of the two squares, N and n (with 0 < n ≤ N), is indicated by two integer numbers
separated by a space. The N lines of the first square appear in the following N lines of the input,
and then the n lines of the second square appear in the following n lines. The characters in a line are
one after another, without spaces. The end of the sequence of problems is indicated with a case where
N = 0 and n = 0.
Output
The solutions of the different problems appear in successive lines. For each problem the output consists
of a line with four integers, which are the number of times each rotation of the small square appears in
the big square. The first number corresponds to the number of appearances of the small square without
rotations, the second to the appearances of the square rotated 90 degrees (clockwise), the third to the
square rotated 180 degrees, and the fourth to the square rotated 270 degrees.
Sample Input
4 2
ABBA
ABBB
BAAA
BABB
AB
BB
6 2
ABCDCD
BCDCBD
BACDDC
DCBDCA
DCBABD
ABCDBA
BC
CD
0 0
Sample Output
0 1 0 0
1 0 1 0
*/
