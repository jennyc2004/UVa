#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int i, j, v;
} E;
E D[1000000];
int R[1005], P[1005];
int cmp(const void *i, const void *j) {
    static E *a, *b;
    a = (E *)i, b = (E *)j;
    return a->v - b->v;
}
void init(int n) {
    int i;
    for(i = 0; i < n; i++)
        R[i] = 1, P[i] = i;
}
int findp(int x) {
    return P[x] == x ? x : P[x]=findp(P[x]);
}
int joint(int x, int y) {
    x = findp(x), y = findp(y);
    if(x != y) {
        if(R[x] > R[y])
            R[x] += R[y], P[y] = x;
        else
            R[y] += R[x], P[x] = y;
        return 1;
    }
    return 0;
}
int main() {
    int t, n, m, r, i, j, cases = 0;
    int x[1005], y[1005];
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &r);
        for(i = 0; i < n; i++)
            scanf("%d %d", &x[i], &y[i]);
        init(n);
        m = 0;
        for(i = 0; i < n; i++) {
            for(j = i+1; j < n; j++) {
                D[m].i = i, D[m].j = j;
                D[m].v = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                m++;
            }
        }
        qsort(D, m, sizeof(E), cmp);
        int ac = 0, state = 1;
        double road = 0, rail = 0;
        r = r*r;
        for(i = 0; i < m; i++) {
            if(joint(D[i].i, D[i].j)) {
                if(D[i].v > r) {
                    rail += sqrt(D[i].v), state ++;
                } else {
                    road += sqrt(D[i].v);
                }
                ac++;
                if(ac == n-1)   break;
            }
        }
        printf("Case #%d: %d %.lf %.lf\n", ++cases, state, road, rail);
    }
    return 0;
}
/*
Input
The first line of input gives the number of cases, T (1 ≤ T ≤ 20). T test cases follow. On the first
line of each test case, there will be two integers, n (1 ≤ n ≤ 1000), the number of cities that comprise
Graphland, and r (0 ≤ r ≤ 40000), the threshold value to determine if two cities are in the same state.
On the following n lines, there will be a list of x − y (−10000 ≤ x, y ≤ 10000) integer coordinates in
the plan for each city in Graphland.
Output
The output is comprised of one line for each input data set. The line identifies the data set with a
number (starting from one and incrementing at each new data set), followed by the number of states
in Graphland and the minimum extension (rounded to the nearest integer) of both roads and railroads
that must be built to satisfy the conditions of the project.
Note: Notice that, by the definition, if A and B are in the same state, and B and C are in the same
state, then A and C are also in the same state.
Sample Input
3
3 100
0 0
1 0
2 0
3 1
0 0
100 0
200 0
4 20
0 0
40 30
30 30
10 10
Sample Output
Case #1: 1 2 0
Case #2: 3 0 200
Case #3: 2 24 28
*/
