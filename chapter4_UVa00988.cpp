#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int first = 0;
    while(scanf("%d", &n) == 1) {
        int i, j, k;
        int indeg[1000] = {}, outdeg[1000];
        vector<int> g[1000];
        for(i = 0; i < n; i++) {
            scanf("%d", &outdeg[i]);
            for(j = 0; j < outdeg[i]; j++)
                scanf("%d", &k), g[i].push_back(k), indeg[k]++;
        }
        int dp[1000] = {};
        dp[0] = 1;
        queue<int> Q;
        Q.push(0);
        while(!Q.empty()) {
            k = Q.front();
            Q.pop();
            for(i = 0; i < g[k].size(); i++) {
                dp[g[k][i]] += dp[k];
                indeg[g[k][i]]--;
                if(indeg[g[k][i]] == 0)
                    Q.push(g[k][i]);
            }
        }
        int ans = 0;
        for(i = 0; i < n; i++)
            if(outdeg[i] == 0)
                ans += dp[i];
        if(first)   puts("");
        first = 1;
        printf("%d\n", ans);
    }
    return 0;
}
/*
Input
Input contains several test cases separated by a blank line. The first number in the each test case is the
number of events. It is followed by a list of events. Each event is described by a number, n, (possibly
0) of choices. For every one of the n possible choices, follows a list of the next event (with sequence
number larger than the present event) that will happen when that choice is picked. An event with no
choices (n = 0) represents a death. It has no further events in life. The first event, event number 0,
represents birth.
Output
The output for each test case is simply an integer that represents how many different ways it is possible
to live that particular life. This number will always be less than 2 to the 30th. Print a blank line
between test cases.
Sample Input
6
3 1 2 5
3 2 3 4
2 3 4
0
1 5
0
Sample Output
7
*/
