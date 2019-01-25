#include <bits/stdc++.h>
using namespace std;
int main() {
	int k, S[12], count = 0;
	while (scanf("%d", &k), k) {
		if (count++)
			printf("\n");
		for (int i = 0; i < k; i++)
			scanf("%d", &S[i]);

		for (int a = 0; a < k - 5; a++)
			for (int b = a + 1; b < k - 4; b++)
				for (int c = b + 1; c < k - 3; c++)
					for (int d = c + 1; d < k - 2; d++)
						for (int e = d + 1; e < k - 1; e++)
							for (int f = e + 1; f < k; f++)
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c],
										S[d], S[e], S[f]);
	}

	return 0;
}
/*
Input
The input file will contain one or more test cases.
Each test case consists of one line containing several integers separated from each other by spaces.
The first integer on the line will be the number k (6 < k < 13). Then k integers, specifying the set S,
will follow in ascending order.
Input will be terminated by a value of zero (0) for k.
Output
For each test case, print all possible games, each game on one line.
The numbers of each game have to be sorted in ascending order and separated from each other by
exactly one space. The games themselves have to be sorted lexicographically, that means sorted by the
lowest number first, then by the second lowest and so on, as demonstrated in the sample output below.
The test cases have to be separated from each other by exactly one blank line. Do not put a blank
line after the last test case.
Sample Input
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0
Sample Output
1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7
1 2 3 5 8 13
1 2 3 5 8 21
1 2 3 5 8 34
1 2 3 5 13 21
1 2 3 5 13 34
1 2 3 5 21 34
1 2 3 8 13 21
1 2 3 8 13 34
1 2 3 8 21 34
1 2 3 13 21 34
1 2 5 8 13 21
1 2 5 8 13 34
1 2 5 8 21 34
1 2 5 13 21 34
1 2 8 13 21 34
1 3 5 8 13 21
1 3 5 8 13 34
1 3 5 8 21 34
1 3 5 13 21 34
1 3 8 13 21 34
1 5 8 13 21 34
2 3 5 8 13 21
2 3 5 8 13 34
2 3 5 8 21 34
2 3 5 13 21 34
2 3 8 13 21 34
2 5 8 13 21 34
3 5 8 13 21 34
*/
