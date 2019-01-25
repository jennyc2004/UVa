#include <bits/stdc++.h>
using namespace std;
int AdjMat[105][105];
bool on[105];

int main() {
	int u, v, count = 1;

	while (true) {
		memset(AdjMat, 63, sizeof AdjMat);
		memset(on, false, sizeof on);

		scanf("%d %d", &u, &v);
		if (u == 0 && v == 0)
			break;

		while (true) {
			on[u] = true;
			on[v] = true;
			AdjMat[u][v] = 1;

			scanf("%d %d", &u, &v);
			if (u == 0 && v == 0)
				break;
		}

		for (int k = 0; k < 105; k++)
			for (int i = 0; i < 105; i++)
				for (int j = 0; j < 105; j++)
					AdjMat[i][j] = min(AdjMat[i][j],
							AdjMat[i][k] + AdjMat[k][j]);

		double ans = 0, nans = 0;
		for (int i = 0; i < 105; i++) {
			for (int j = 0; j < 105; j++) {
				if (i == j)
					continue;
				if (on[i] && on[j]) {
					ans += AdjMat[i][j];
					nans++;
				}
			}
		}

		printf("Case %d: average length between pages = %.3lf clicks\n",
				count++, ans / nans);
	}

	return 0;
}
/*
Input
The input data will contain multiple test cases. Each test case will consist of an arbitrary number of
pairs of integers, a and b, each representing a link from a page numbered a to a page numbered b. Page
numbers will always be in the range 1 to 100. The input for each test case will be terminated with a
pair of zeroes, which are not to be treated as page numbers. An additional pair of zeroes will follow
the last test case, effectively representing a test case with no links, which is not to be processed. The
graph will not include self-referential links (that is, there will be no direct link from a node to itself),
and at least one path will exist from each node in the graph to every other node in the graph.
Output
For each test case, determine the average shortest path length between every pair of nodes, accurate to
three fractional digits. Display this length and the test case identifier (theyre numbered sequentially
starting with 1) in a form similar to that shown in the sample output below.
Sample Input
1 2 2 4 1 3 3 1 4 3 0 0
1 2 1 4 4 2 2 7 7 1 0 0
0 0
Sample Output
Case 1: average length between pages = 1.833 clicks
Case 2: average length between pages = 1.750 clicks
*/
