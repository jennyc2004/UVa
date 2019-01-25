#include <bits/stdc++.h>
using namespace std;

int tapeLen, n, trackLen[20];
int ans, nearestTotal;

void choose(int total, int mask, int p) {
	if (total > tapeLen)
		return;
	if (total > nearestTotal) {
		nearestTotal = total;
		ans = mask;
	}
	if (p >= n)
		return;

	choose(total + trackLen[p], mask | (1 << p), p + 1);
	choose(total, mask, p + 1);
}

int main() {
	while (scanf("%d %d", &tapeLen, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &trackLen[i]);
		}

		ans = -1;
		nearestTotal = -1;
		choose(0, 0, 0);

		for (int i = 0; i < n; i++) {
			if ((ans >> i) % 2)
				printf("%d ", trackLen[i]);
		}
		printf("sum:%d\n", nearestTotal);
	}

	return 0;
}
/*
Input
Any number of lines. Each one contains value N, (after space) number of tracks and durations of the
tracks. For example from first line in sample data: N = 5, number of tracks=3, first track lasts for 1
minute, second one 3 minutes, next one 4 minutes
Output
Set of tracks (and durations) which are the correct solutions and string ‘sum:’ and sum of duration
times.
Sample Input
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2
Sample Output
1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
4 10 12 9 8 2 sum:45
*/
