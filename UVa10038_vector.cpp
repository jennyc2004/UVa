#include <bits/stdc++.h>
using namespace std;

int main(){
	int input;
	int i;
	int last, next, result;
	bool flag;
	while (cin >> input){
		vector <bool> place(3005);
		flag = true;
		cin >> last;
		for (i = 1; i < input; i++){
			cin >> next;
			result = abs(last - next);
			place[result] = true;
			last = next;
		}
		for (i = 1; i < input; i++){
			if (!place[i]){
				flag = false;
				break;
			}
		}
		if (flag) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	return 0;
}
/*
Input
Each line of input contains an integer n ≤ 3000 followed by n integers representing the sequence.
Output
For each line of input, generate a line of output saying ‘Jolly’ or ‘Not jolly’.
Sample Input
4 1 4 2 3
5 1 4 2 -1 6
Sample Output
Jolly
Not jolly
*/
