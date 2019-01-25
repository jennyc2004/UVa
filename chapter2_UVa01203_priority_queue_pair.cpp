#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pipii pair<int, pii>
int main() {
	char s[20];
	int qnum, p, n;
	priority_queue<pipii, vector<pipii>, greater<pipii> > pq;
	while (scanf("%s", s), strcmp("#", s)) {
		scanf("%d %d", &qnum, &p);
		pq.push(pipii(p, pii(qnum, p)));
	}
	scanf("%d", &n);
	while (n--) {
		pipii pr = pq.top();
		pq.pop();
		printf("%d\n", pr.second.first);
		pr.first += pr.second.second;
		pq.push(pr);
	}
	return 0;
}
/*
Input
The first part of the input are the register instructions to Argus, one instruction per line. You can
assume the number of the instructions will not exceed 1000, and all these instructions are executed at
the same time. This part is ended with a line of ‘#’.
The second part is your task. This part contains only one line, which is one positive integer K
(≤ 10000).
Output
You should output the Q num of the first K queries to return the results, one number per line.
Sample Input
Register 2004 200
Register 2005 300
#
5
Sample Output
2004
2005
2004
2004
2005
*/
