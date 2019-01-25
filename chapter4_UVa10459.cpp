#include <bits/stdc++.h>
using namespace std;
#define oo 0xfffffff
using namespace std;
vector<int> edge[5001];
int dp_down[5001][2], dp_up[5001];
int used[5001];
void dfs(int nd) {
    for(vector<int>::iterator i = edge[nd].begin(); i != edge[nd].end(); i++) {
        if(used[*i] == 0) {
            used[*i] = 1;
            dfs(*i);
            if(dp_down[*i][0]+1 > dp_down[nd][1])
                dp_down[nd][1] = dp_down[*i][0]+1;
            if(dp_down[nd][1] > dp_down[nd][0])
                swap(dp_down[nd][0], dp_down[nd][1]);
        }
    }
}
void dfs2(int nd, int v) {
    dp_up[nd] = v;
    for(vector<int>::iterator i = edge[nd].begin(); i != edge[nd].end(); i++) {
        if(used[*i] == 0) {
            used[*i] = 1;
            int hv;
            if(dp_down[*i][0]+1 != dp_down[nd][0])
                hv = dp_down[nd][0];
            else
                hv = dp_down[nd][1];
            hv = max(hv, dp_up[nd]);
            dfs2(*i, hv+1);
        }
    }
}
int main() {
    int n, m, i, y;
    while(scanf("%d", &n) == 1) {
        for(i = 1; i <= n; i++) {
            edge[i].clear();
            scanf("%d", &m);
            while(m--) {
                scanf("%d", &y);
                edge[i].push_back(y);
            }
            dp_down[i][0] = 0;
            dp_down[i][1] = 0;
            dp_up[i] = 0;
            used[i] = 0;
        }
        used[1] = 1;
        dfs(1);
        for(i = 1; i <= n; i++) used[i] = 0;
        used[1] = 1;
        dfs2(1, 0);
        int root[5001], best = oo, worst = 0;
        for(i = 1; i <= n; i++) {
            root[i] = max(max(dp_down[i][0], dp_down[i][1]), dp_up[i]);
            best = min(root[i], best);
            worst = max(root[i], worst);
        }
        printf("Best Roots  :");
        for(i = 1; i <= n; i++)
            if(root[i] == best)
                printf(" %d", i);
        printf("\nWorst Roots :");
        for(i = 1; i <= n; i++)
            if(root[i] == worst)
                printf(" %d", i);
        puts("");
    }
    return 0;
}
/*
Input
Each dataset starts with a positive integer N (3 ≤ N ≤ 5000), which is the number of nodes in the
tree. Each node in the tree has a unique id from 1 to N. Then successively for each i’th node there
will be a positive integer K[i] following id of K[i] nodes which are adjacent to i. Input is terminated
by EOF.
Output
For each dataset print two lines. In the 1st line show all the best roots in ascending order and in next
line show all worst roots in ascending order. See sample output for exact format.
Sample Input
7
2 2 3
3 1 6 7
3 1 4 5
1 3
1 3
1 2
1 2
Sample Output
Best Roots : 1
Worst Roots : 4 5 6 7
*/
