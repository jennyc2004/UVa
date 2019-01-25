#include <bits/stdc++.h>
using namespace std;
#define oo 1000
int link[100][100], n;
int depth[100], low[100];
int used[100], cut;
int DFS(int node, int d, int parent) {
    int i, back = oo, son = 0, tmp, flag = 0;
    depth[node] = d;
    for(i = 1; i <= n; i++) {
    if(link[node][i] == 1) {
        if(used[i] == 0) {
        used[i] = 1;
        tmp = DFS(i, d+1, node);
        if(tmp >= d) flag = 1;
        back = back < tmp ? back : tmp;
        son++;
        } else {
            if(i != parent)
            back = back < depth[i] ? back : depth[i];
        }
    }
    }
    low[node] = back;
    if(node == 1) {
    if(son > 1)
        cut++;
    } else {
        cut += flag;
    }
    return low[node];
}
int main() {
    int x, y;
    char c;
    while(scanf("%d", &n) == 1 && n) {
        memset(link, 0, sizeof(link));
        memset(depth, 0, sizeof(depth));
        memset(low, 0, sizeof(low));
        memset(used, 0, sizeof(used));
    while(scanf("%d", &x) == 1 && x) {
    while(scanf("%d%c", &y, &c) == 2) {
        link[x][y] = 1;
        link[y][x] = 1;
        if(c == '\n') break;
    }
    }
    used[1] = 1;
    cut = 0;
    DFS(1, 1, 0);
    printf("%d\n", cut);
    }
    return 0;
}
/*
Input
The input file consists of several blocks of lines. Each block describes one network. In the first line
of each block there is the number of places N < 100. Each of the next at most N lines contains the
number of a place followed by the numbers of some places to which there is a direct line from this place.
These at most N lines completely describe the network, i.e., each direct connection of two places in
the network is contained at least in one row. All numbers in one line are separated by one space. Each
block ends with a line containing just ‘0’. The last block has only one line with N = 0.
Output
The output contains for each block except the last in the input file one line containing the number of
critical places.
Sample Input
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0
Sample Output
1
2
*/
