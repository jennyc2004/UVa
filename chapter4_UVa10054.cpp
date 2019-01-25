#include <bits/stdc++.h>
using namespace std;
void euler_cycle(int u, list<pair<int, int>> &euler,
                 list<pair<int, int>>::iterator it,
                 vector<vector<pair<int, bool>>> &adj_list) {
    for (auto &edge : adj_list[u]) {
        if (edge.second) {
            int v = edge.first;
            edge.second = false;
            for (auto &bi_edge: adj_list[v])
                if (bi_edge.first == u && bi_edge.second) {
                    bi_edge.second = false;
                    break;
                }
            euler_cycle(v, euler, euler.insert(it, {v, u}), adj_list);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int cases = 0; cases < T; cases++) {
        if (cases)
            printf("\n");
        printf("Case #%d\n", cases + 1);

        int N;
        scanf("%d", &N);
        vector<vector<pair<int, bool>>> adj_list(50);
        vector<int> degree(50);

        for (int i = 0; i < N; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj_list[u - 1].push_back({v - 1, true});
            adj_list[v - 1].push_back({u - 1, true});
            degree[u - 1]++;
            degree[v - 1]++;
        }

        bool good = true;
        int start = -1;
        for (int i = 0; i < 50; i++) {
            if (degree[i] % 2) {
                good = false;
                break;
            }
            else if (degree[i] && start == -1)
                start = i;
        }

        if (!good) {
            printf("some beads may be lost\n");
            continue;
        }

        list<pair<int, int>> euler;
        euler_cycle(start, euler, euler.begin(), adj_list);

        for (const auto &item : euler)
            printf("%d %d\n", item.first + 1, item.second + 1);
    }
    return 0;
}
/*
Input
The input contains T test cases. The first line of the input contains the integer T.
The first line of each test case contains an integer N (5 ≤ N ≤ 1000) giving the number of beads
my sister was able to collect. Each of the next N lines contains two integers describing the colors of a
bead. Colors are represented by integers ranging from 1 to 50.
Output
For each test case in the input first output the test case number as shown in the sample output. Then
if you apprehend that some beads may be lost just print the sentence “some beads may be lost”
on a line by itself. Otherwise, print N lines with a single bead description on each line. Each bead
description consists of two integers giving the colors of its two ends. For 1 ≤ i ≤ N1, the second integer
on line i must be the same as the first integer on line i + 1. Additionally, the second integer on line
N must be equal to the first integer on line 1. Since there are many solutions, any one of them is
acceptable.
Print a blank line between two successive test cases.
Sample Input
2
5
1 2
2 3
3 4
4 5
5 6
5
2 1
2 2
3 4
3 1
2 4
Sample Output
Case #1
some beads may be lost
Case #2
2 1
1 3
3 4
4 2
2 2
*/
