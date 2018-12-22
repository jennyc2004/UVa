#include <bits/stdc++.h>
using namespace std;
/*
Input
The input begins with a single positive integer on a line by itself, indicating the number
of the cases following. This line is followed by a blank line, and there is also a blank line
between two consecutive inputs.
For each test case, the input must follow the description below.
1. The number of computers in the network (a strictly positive integer);
2. A list of pairs of the form:
(a) c computeri computerj , where computeri and computerj are integers from 1 to no of computers.
A pair of this form shows that computeri and computerj get interconnected.
(b) q computeri computerj , where computeri and computerj are integers from 1 to no of computers.
A pair of this form stands for the question:
is computeri interconnected with computerj ?
Each pair is on a separate line. Pairs can appear in any order, regardless of their type. The log is
updated after each pair of type (a) and each pair of type (b) is processed according to the current
network configuration.
Output
For each test case, the output must follow the description below. The outputs of two
consecutive cases will be separated by a blank line.
The program prints two integer numbers to the standard output on the same line, in the order:
‘successful answers, unsuccessful answers’, as shown in the sample output.
Note:
For example, the first input illustrated in the sample below corresponds to a network of 10 computers
and 7 pairs. There are ‘1’ successfully answered questions and ‘2’ unsuccessfully answered questions.
Sample Input
2
10
c 1 5
c 2 7
q 7 1
c 3 9
q 9 6
c 2 5
q 7 5
1
q 1 1
c 1 1
q 1 1
Sample Output
1,2
2,0
*/
class UFDS {
private:
	vector<int> p, rank, setSize;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSize.assign(N, 1);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[findSet(x)] += setSize[findSet(y)];
			} else {
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
				setSize[findSet(y)] += setSize[findSet(x)];
			}
			numSets--;
		}
	}
	int numDisjointSets() {
		return numSets;
	}
};
int main() {
	int tc, n, yes, no;
	char line[1000], q;
	int c1, c2;
	cin>>tc;
	while (tc--) {
		yes = no = 0;
		scanf("%d\n", &n);
		UFDS set(n);
		while (true) {
			gets(line);
			if (strcmp(line, "") == 0 || cin.eof()) break;
			sscanf(line, "%c %d %d", &q, &c1, &c2);
			c1--;
			c2--;
			if (q == 'c') set.unionSet(c1, c2);
			else if (q == 'q') {
				if (set.isSameSet(c1, c2)) yes++;
				else no++;
			}
		}
		cout<<yes<<","<<no<<endl;
		if (tc)cout<<endl;
	}
	return 0;
}
