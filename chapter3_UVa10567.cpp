#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  string S;
  string SS;
  int Q;
  int match, start, index;
  vector<vector<int> > v(256);
  vector<int>::iterator it;

  cin >> S;
  for (int i = 0; i < S.size(); i++)
    v[S[i]].push_back(i);
  scanf("%d", &Q);
  while (Q--) {
    cin >> SS;
    match = 1;
    index = -1;
    for (int i = 0; i < SS.size(); i++) {
      it = upper_bound(v[SS[i]].begin(), v[SS[i]].end(), index);
      if (it == v[SS[i]].end()) {
        match = 0;
        break;
      }
      index = it - v[SS[i]].begin();
      index = v[SS[i]][index];
      if (!i) start = index;
    }
    if (!match) printf("Not matched\n");
    else printf("Matched %d %d\n", start, index);
  }
  return 0;
}
/*
Input
The input file contains only one set of input. First line of the input file contains a string S containing
only alphabets. The length of this string is at most 1000000. The next line contains an integer Q
(0 < Q < 3501) which indicates the number of queries. Each of the next Q lines contain one string SS
of length less than 101. These strings are the strings written by Fill Bates.
Output
For each query you should output one line. If candidates are not found in the order written by Fill
Bates then you should output a string ‘Not matched’ (Without the quotes), otherwise you should print
‘Matched’ (Note that an space is printed after ‘Matched’) and then the serial of the first candidate in
the subsequence and the serial of the last candidate of the subsequence. These two integers should be
separated by a single space. If there is more than one such subsequence then choose the one which has
smallest starting serial number. If there is a tie choose the one with the smallest ending serial number.
Sample Input
aaaaaaaaaaaaaabbbbbbbbbdddddddddddccccccccccccc
3
aaaaaaaaaaaaaaaaaaa
aaaaaaaaaaabbbbbbbbbbbc
abccc
Sample Output
Not matched
Not matched
Matched 0 36
*/
