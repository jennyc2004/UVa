#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
  return a<b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;

    int salary[3];
    for (int i = 0; i < T; i++) {
        cin>>salary[0]>>salary[1]>>salary[2];
        sort(salary, salary + 3, cmp);
        cout<<"Case "<<i+1<<": "<<salary[1]<<endl;
    }

    return 0;
}
/*
Input
The first line of input is an integer T (T < 20) that indicates the number of test cases. Each case
consists of a line with 3 distinct positive integers. These 3 integers represent the salaries of the three
employees. All these integers will be in the range [1000, 10000].
Output
For each case, output the case number followed by the salary of the person who survives.
Sample Input
3
1000 2000 3000
3000 2500 1500
1500 1200 1800
Sample Output
Case 1: 2000
Case 2: 2500
Case 3: 1500
*/
