#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s, q, TC;
	cin >> TC;
	for (; TC > 0; TC--) {
		stack<int> carrier;
		queue<int> stationQueue[100];
		cin >> n >> s >> q;
		for (int i = 0; i < n; i++) {
			int nc;
			cin >> nc;
			for (int j = 0; j < nc; j++) {
				int target;
				cin >> target;
				stationQueue[i].push(target - 1);
			}
		}
		int currPos = 0, time = 0;
		while (true) {
            //unload
			while (!carrier.empty() && (carrier.top() == currPos || stationQueue[currPos].size() < q)) {
				if (carrier.top() != currPos) stationQueue[currPos].push(carrier.top());
				carrier.pop();
				time++;
			}
            //load
			while ((carrier.size() < s) && !stationQueue[currPos].empty()) {
				carrier.push(stationQueue[currPos].front());
				stationQueue[currPos].pop();
				time++;
			}
			bool clear = carrier.empty();
			for (int i = 0; i < n; i++) clear &= stationQueue[i].empty();
			if (clear) break;
			currPos = (currPos + 1) % n;
			time += 2;
		}
		cout << time << endl;
	}
	return 0;
}
/*
Input
The input contains several sets of input. The first line of the input file contains an integer SET, which
indicates how many sets of inputs are there. It is then followed by SET sets of inputs. In our sample
input the value of SET is 2.
The first line of the input contains three integers: N, S and Q. N (2 ≤ N ≤ 100) is the number
of stations in the ring. S (1 ≤ S ≤ 100) is the capacity of your cargo carrier, that is, the maximum
number of cargoes your carrier can carry. Q (1 ≤ Q ≤ 100) is the maximum number of cargoes the
queue in platform B can accommodate. All the queues in the system are assumed to have the same
capacity.
Then follow N lines. Assuming that these lines are numbered from 1 to N, for 1 ≤ i ≤ N, line i
contains an integer Qi (0 ≤ Qi ≤ Q) giving the number of cargoes queued at station i followed by Qi
integers giving the destination stations of the queued cargoes from front to rear. You may assume that
none of these Qi cargoes will have station i as their destination.
Output
For each set of input output the number of minutes it will take to finish the job in a separate line.
Sample Input
2
5 2 3
3 4 5 2
2 1 3
0
3 3 5 1
1 4
5 2 3
3 4 5 2
2 1 3
0
3 3 5 1
1 4
Sample Output
72
72
*/
