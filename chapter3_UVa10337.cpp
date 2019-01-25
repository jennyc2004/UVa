#include <bits/stdc++.h>
using namespace std;
int windSpd[10][1005];
int memo[10][1005];
int tc, x;

int fuel(int alt, int dist) {
	if (alt > 9 || alt < 0 || dist > x)
		return 1e9;
	if (dist == x) {
		if (alt == 0)
			return 0;
		else
			return 1e9;
	}

	if (memo[alt][dist] != -1)
		return memo[alt][dist];

	return memo[alt][dist] = min(
			60 - windSpd[alt][dist] + fuel(alt + 1, dist + 1),
			min(30 - windSpd[alt][dist] + fuel(alt, dist + 1),
					20 - windSpd[alt][dist] + fuel(alt - 1, dist + 1)));
}

int main() {
	scanf("%d", &tc);

	while (tc--) {
		scanf("%d", &x);
		x /= 100;

		for (int alt = 9; alt >= 0; alt--) {
			for (int dist = 0; dist < x; dist++) {
				scanf("%d", &windSpd[alt][dist]);
			}
		}

		memset(memo, -1, sizeof(memo));

		int ans = fuel(0, 0);
		printf("%d\n\n", ans);
	}

	return 0;
}
/*
Input
The first line of the input file contains the number N of test cases in the file. The first line of each test
case contains a single integer X, the distance to fly, with 1 ≤ X ≤ 100000 miles and X is a multiple
of 100. Notice that it’s not allowed to fly higher than 9 miles over zero and that you have to decide
whether to climb, hold your altitude or to sink only for every 100 miles.
For every mile of allowed altitude (starting at altitude 9 down to altitude 0) there follow X
100
windstrengths, starting with the windstrength at your current position up to the windstrength at
position X − 100 in steps of 100 miles. Test cases are separated by one or more blank lines.
Output
For each test case output the minimal amount of fuel used flying from your current position (at altitude
0) to X (also at altitude 0), followed by a blank line.
Sample Input
2
400
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 9 9 1
1 -9 -9 1
1000
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
7 7 7 7 7 7 7 7 7 7
-5 -5 -5 -5 -5 -5 -5 -5 -5 -5
-7 -3 -7 -7 -7 -7 -7 -7 -7 -7
-9 -9 -9 -9 -9 -9 -9 -9 -9 -9
Sample Output
120
354
*/
