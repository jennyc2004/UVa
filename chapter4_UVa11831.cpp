#include <bits/stdc++.h>
using namespace std;
int n,m,len;
char a[110][110],ins[50100];
int u,v,orien;

int Process() {
    int x,y,k;
    int count=0;
    for (k=0;k<len;k++) {
        if (ins[k]=='D') {
            orien = (orien+1)%4;
        }
        else if (ins[k]=='E') {
            orien = orien-1;
            if (orien<0) orien = 3;
        }
        else {
            x=u; y=v;
            if (orien==0) x--;
            else if (orien==1) y++;
            else if (orien==2) x++;
            else y--;

            if (y<0 || y>=m || x<1 || x>n || a[x][y]=='#') continue;
            else {
                a[u][v]='.';
                if (a[x][y]=='*') count++;
                u=x; v=y;
            }
        }
    }
    return count;
}

main() {

    while (cin >> n >> m >> len) {
        if (n==0 && m==0 && len==0) break;
        scanf(" ");
        for (int i=1;i<=n;i++)
            gets(a[i]);
        gets(ins);

        int f = 1;
        for (u=1;u<=n;u++) {
            for (v=0;v<m;v++)
                if (a[u][v]!='.' && a[u][v]!='*' && a[u][v]!='#') {
                    f = 0;
                    break;
                }
            if (!f) break;
        }
        if (a[u][v]=='N') orien=0;
        else if (a[u][v]=='L') orien=1;
        else if (a[u][v]=='S') orien=2;
        else if (a[u][v]=='O') orien=3;

        cout << Process() << endl;
    }
}
/*
Input
The input contains several test cases. The first line of a test case contains three integers N, M and
S (1 ≤ N, M ≤ 100, 1 ≤ S ≤ 5 × 104
), separated by white spaces, indicating respectively the number
of rows, the number of columns of the arena and the number of instructions to the robot. Each of the
following N lines describes a cell line of the arena and contains a string with M characters. The first
line to appear in the description of the arena is the one more to the North, the first column to appear
in description of a cell line of the arena is the one more to the West.
Each cell in the arena is described by one of the following characters:
• ‘.’ — normal cell;
• ‘*’ — cell which contains a sticker;
• ‘#’ — cell which contains a pillar;
• ‘N’, ‘S’, ‘L’, ‘O’ — cell where the robot starts the rally (only one in the arena). The letter represents
the initial robot orientation (North, South, East and West, respectively).
The last line in the input contains a sequence of S characters among ‘D’, ‘E’ and ‘F’, representing
the instructions to the robot.
The last test case is followed by a line which contains only three numbers zero separated by a blank
space.
Output
For each rally described in the input your program must print a single line containing a single integer
indicating the number of stickers that the robot collected during the rally.
Sample Input
3 3 2
***
*N*
***
DE
4 4 5
...#
*#O.
*.*.
*.#.
FFEFF
10 10 20
....*.....
.......*..
.....*....
..*.#.....
...#N.*..*
...*......
..........
..........
..........
..........
FDFFFFFFEEFFFFFFEFDF
0 0 0
Sample Output
0
1
3
*/
