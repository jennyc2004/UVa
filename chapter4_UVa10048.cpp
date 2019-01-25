#include <bits/stdc++.h>
using namespace std;
#define oo 0xffffff
#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)>(y)?(x):(y))
int main() {
    int n, m, q, cases = 0;
    while(scanf("%d %d %d", &n, &m, &q) == 3) {
        if(n == 0)  break;
        int f[101][101], i, j, k, x, y, b;
        for(i = 1; i <= n; f[i][i] = 0, i++)
            for(j = 1; j <= n; j++)
                f[i][j] = oo;
        while(m--) {
            scanf("%d %d %d", &x, &y, &b);
            f[x][y] = min(f[x][y], b);
            f[y][x] = f[x][y];
        }
        for(k = 1; k <= n; k++)
            for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                    f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));
        if(cases)
            puts("");
        printf("Case #%d\n", ++cases);
        while(q--) {
            scanf("%d %d", &x, &y);
            if(f[x][y] != oo)
                printf("%d\n", f[x][y]);
            else
                puts("no path");
        }
    }
    return 0;
}
/*
Input
The input may contain multiple test cases.
The first line of each test case contains three integers C(≤ 100), S(≤ 1000) and Q(≤ 10000) where
C indicates the number of crossings (crossings are numbered using distinct integers ranging from 1 to
C), S represents the number of streets and Q is the number of queries.
Each of the next S lines contains three integers: c1, c2 and d indicating that the average sound
intensity level on the street connecting the crossings c1 and c2 (c1 ̸= c2) is d decibels.
Each of the next Q lines contains two integers c1 and c2 (c1 ̸= c2) asking for the minimum sound
intensity level you must be able to tolerate in order to get from crossing c1 to crossing c2.
The input will terminate with three zeros form C, S and Q.
Output
For each test case in the input first output the test case number (starting from 1) as shown in the
sample output. Then for each query in the input print a line giving the minimum sound intensity level
(in decibels) you must be able to tolerate in order to get from the first to the second crossing in the
query. If there exists no path between them just print the line “no path”.
Print a blank line between two consecutive test cases.
Sample Input
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0
Sample Output
Case #1
80
60
60
Case #2
40
no path
80
*/
