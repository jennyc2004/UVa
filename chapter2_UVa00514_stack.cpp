#include <bits/stdc++.h>
using namespace std;
/*
Input
The input file consists of blocks of lines. Each block except the last describes one train and possibly
more requirements for its reorganization. In the first line of the block there is the integer N described
above. In each of the next lines of the block there is a permutation of 1, 2, . . . , N. The last line of the
block contains just ‘0’.
The last block consists of just one line containing ‘0’.
Output
The output file contains the lines corresponding to the lines with permutations in the input file. A line
of the output file contains ‘Yes’ if it is possible to marshal the coaches in the order required on the
corresponding line of the input file. Otherwise it contains ‘No’. In addition, there is one empty line after
the lines corresponding to one block of the input file. There is no line in the output file corresponding
to the last “null” block of the input file.
Sample Input
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
Sample Output
Yes
No
Yes
*/
int main() {
	int n, target[1000];
	int i;
	while (true) {
		cin >> n;
		if (n == 0) break;
		while (true) {
			cin >> target[0];
			if (target[0] == 0){
				cout << endl;
				break;
			}
			for (i = 1; i < n; i++) {
				cin >> target[i];
			}
			int currCoach = 1, targetIndex = 0;
			stack<int> station;
			while(currCoach<=n){
				station.push(currCoach);
				while(!station.empty() && station.top() == target[targetIndex]){
					station.pop();
					targetIndex++;
					if(targetIndex>=n) break;
				}
				currCoach++;
			}
			if(station.empty()) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}

