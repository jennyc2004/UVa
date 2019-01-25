#include <bits/stdc++.h>
using namespace std;

int main() {
	char line[100001];
	while (scanf("%s", line) != EOF) {
		list<char> l;
		int len = strlen(line);
		list<char>::iterator it = l.begin();

		for (int i = 0; i < len; i++) {
			if (line[i] == '[') {
				it = l.begin();
			} else if (line[i] == ']') {
				it = l.end();
			} else {
				l.insert(it, line[i]);
			}
		}

		for (it = l.begin(); it != l.end(); it++) {
			printf("%c", *it);
		}
		printf("\n");

	}

	return 0;
}
/*
Input
There are several test cases. Each test case is a single line containing at least one and at most 100,000
letters, underscores and two special characters ‘[’ and ‘]’. ‘[’ means the “Home” key is pressed
internally, and ‘]’ means the “End” key is pressed internally. The input is terminated by end-of-file
(EOF).
Output
For each case, print the Beiju text on the screen.
Sample Input
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
Sample Output
BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University
*/
