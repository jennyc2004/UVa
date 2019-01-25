#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[101][101];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (i > 0)
				a[i][j] += a[i - 1][j];
			if (j > 0)
				a[i][j] += a[i][j - 1];
			if (i > 0 && j > 0)
				a[i][j] -= a[i - 1][j - 1];
		}
	}

	int ans = -127 * 100 * 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = i; k < n; k++) {
				for (int l = j; l < n; l++) {
					int temp = a[k][l];
					if (i > 0)
						temp -= a[i - 1][l];
					if (j > 0)
						temp -= a[k][j - 1];
					if (i > 0 && j > 0)
						temp += a[i - 1][j - 1];

					if (temp > ans)
						ans = temp;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
/*
Input
The input consists of an N × N array of integers.
The input begins with a single positive integer N on a line by itself indicating the size of the square
two dimensional array. This is followed by N2
integers separated by white-space (newlines and spaces).
These N2
integers make up the array in row-major order (i.e., all numbers on the first row, left-to-right,
then all numbers on the second row, left-to-right, etc.). N may be as large as 100. The numbers in the
array will be in the range [−127, 127].
Output
The output is the sum of the maximal sub-rectangle.
Sample Input
4
0 -2 -7 0 9 2 -6 2
-4 1 -4 1 -1
8 0 -2
Sample Output
15
*/
