#include <bits/stdc++.h>
using namespace std;
typedef struct {
	int to, v;
} Arc;
typedef vector<Arc>::iterator it;
vector<Arc> link[1000];
queue<int> Q;
bool used[1000];
int dis[1000], inQu[1000];
int checkNegCycle(int n, int st) {
	int i;
	memset(used, 0, n);
	memset(inQu, 0, 4*n);
	memset(dis, 127, 4*n);
	for(it i = link[st].begin(); i != link[st].end(); i++) {
		if(dis[i->to] > i->v) {
			dis[i->to] = i->v;
			if(!used[i->to]) {
				used[i->to] = true;
				Q.push(i->to);
				inQu[i->to]++;
			}
		}
	}
	int tv;
	while(!Q.empty()) {
		tv = Q.front();
		Q.pop();
		used[tv] = false;
		for(it i = link[tv].begin(); i != link[tv].end(); i++) {
			if(dis[i->to] > dis[tv] + i->v) {
				dis[i->to] = dis[tv] + i->v;
				if(!used[i->to]) {
					used[i->to] = true;
					Q.push(i->to);
					inQu[i->to]++;
				}
				if(dis[st] < 0 || inQu[i->to] >= n)
					return 1;
			}
		}
	}
	return 0;
}
int main() {
	int t, n, m, i;
	int x, y, v;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) {
			link[i].clear();
		}
		Arc arc;
		while(m--) {
			scanf("%d %d %d", &x, &y, &v);
			arc.to = y, arc.v = v;
			link[x].push_back(arc);
		}
		int find = 0;
		for(i = 0; i < n; i++) {
			find = checkNegCycle(n, i);
			if(find)
				break;
		}
		if(find == 1)
			puts("possible");
		else
			puts("not possible");
	}
    return 0;
}
/*
Input
The input file starts with a line containing the number of cases c to be analysed. Each case starts with
a line with two numbers n and m. These indicate the number of star systems (1 ≤ n ≤ 1000) and
the number of wormholes (0 ≤ m ≤ 2000). The star systems are numbered from 0 (our solar system)
through n − 1 . For each wormhole a line containing three integer numbers x, y and t is given. These
numbers indicate that this wormhole allows someone to travel from the star system numbered x to the
star system numbered y, thereby ending up t (−1000 ≤ t ≤ 1000) years in the future.
Output
The output consists of c lines, one line for each case, containing the word ‘possible’ if it is indeed
possible to go back in time indefinitely, or ‘not possible’ if this is not possible with the given set of
star systems and wormholes.
Sample Input
2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60
Sample Output
possible
not possible
*/
