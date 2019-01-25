#include <bits/stdc++.h>
using namespace std;
int p, q, r, s, t, u;

double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bisection() {
	double lo = 0, hi = 1;
	while (lo + (1e-7) < hi) {
		double x = (lo + hi) / 2;
		if (f(lo) * f(x) <= 0) {
			hi = x;
		} else {
			lo = x;
		}
	}
	return (lo + hi) / 2;
}

int main() {
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		if (f(0) * f(1) > 0) {
			printf("No solution\n");
		} else {
			printf("%.4lf\n", bisection());
		}
	}

	return 0;
}
/*
Input
Input consists of multiple test cases and terminated by an EOF. Each test case consists of 6 integers in
a single line: p, q, r, s, t and u (where 0 ≤ p, r ≤ 20 and −20 ≤ q, s, t ≤ 0). There will be maximum
2100 lines in the input file.
Output
For each set of input, there should be a line containing the value of x, correct up to 4 decimal places,
or the string ‘No solution’, whichever is applicable.
Sample Input
0 0 0 0 -2 1
1 0 0 0 -1 2
1 -1 1 -1 -1 1
Sample Output
0.7071
No solution
0.7554
*/
