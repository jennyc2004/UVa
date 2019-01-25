#include <bits/stdc++.h>
using namespace std;
long long A[201], DP[201][16][21];
void solve(int N, int M, int D) {
	memset(DP, 0, sizeof(DP));
	int i, j, k;
	long long tmp;
	DP[0][0][0] = 1;
	for(i = 1; i <= N; i++) {
		for(j = 0; j <= M; j++) {
			for(k = 0; k < D; k++) {
				tmp = (k+A[i])%D;
				if(tmp < 0) tmp += D;
				DP[i][j][k] += DP[i-1][j][k];
				if(j) {
					DP[i][j][k] += DP[i-1][j-1][tmp];
				}
			}
		}
	}
	printf("%lld\n", DP[N][M][0]);
}
int main() {
	int N, Q, D, M, i;
	int Case = 0;
	while(scanf("%d %d", &N, &Q) == 2) {
		if(N == 0 && Q == 0)	break;
		for(i = 1; i <= N; i++)
			scanf("%lld", &A[i]);
		printf("SET %d:\n", ++Case);
		for(i = 1; i <= Q; i++) {
			scanf("%d %d", &D, &M);
			printf("QUERY %d: ", i);
			solve(N, M, D);
		}
	}
    return 0;
}
/*
Input
The input file contains maximum ten sets of inputs. The description of each set is given below.
The first line of each set contains two integers N (0 < N ≤ 200) and Q (0 < Q ≤ 10). Here N
indicates how many numbers are there and Q is the total no of query. Each of the next N lines contains
one 32 bit signed integer. Our queries will have to be answered based on these N numbers. Next Q
lines contain Q queries. Each query contains two integers D (0 < D ≤ 20) and M (0 < M ≤ 10) whose
meanings are explained in the first paragraph.
Input is terminated by a case whose N = 0 and Q = 0. This case should not be processed.
Output
For each set of input, print the set number. Then for each query in the set print the query number
followed by the number of desired groups. See sample output to know the exact output format.
Sample Input
10 2
1
2
3
4
5
6
7
8
9
10
5 1
5 2
5 1
2
3
4
5
6
6 2
0 0
Sample Output
SET 1:
QUERY 1: 2
QUERY 2: 9
SET 2:
QUERY 1: 1
*/
