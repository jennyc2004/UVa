#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
	int V, E, u, v;
	vector<vi> AdjList;

	while (scanf("%d", &V), V) {
		AdjList.assign(V, vi());
		scanf("%d", &E);

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		queue<int> q;
		q.push(0);
		vi color(V, 1e9);
		color[0] = 0;
		bool isBipartite = true;
		while (!q.empty() && isBipartite) {
			int u = q.front();
			q.pop();
			for (int j = 0; j < (int) AdjList[u].size(); j++) {
				int v = AdjList[u][j];
				if (color[v] == 1e9) {
					color[v] = 1 - color[u];
					q.push(v);
				} else if (color[v] == color[u]) {
					isBipartite = false;
					break;
				}
			}
		}

		if (isBipartite)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}

	return 0;
}
/*
Input
The input consists of several test cases. Each test case starts with a line containing the number n
(1 < n < 200) of different nodes. The second line contains the number of edges l. After this, l lines will
follow, each containing two numbers that specify an edge between the two nodes that they represent.
A node in the graph will be labeled using a number a (0 ≤ a < n).
An input with n = 0 will mark the end of the input and is not to be processed.
Output
You have to decide whether the input graph can be bicolored or not, and print it as shown below.
Sample Input
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0
Sample Output
NOT BICOLORABLE.
BICOLORABLE.
BICOLORABLE.
*/
