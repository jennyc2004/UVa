#include <bits/stdc++.h>
using namespace std;
string s;
int g[26][26], n, has;
char ans[26], used[26] = {};
void dfs(int Idx) {
    if(Idx == n) {
        has = 1;
        putchar(ans[0]);
        int i;
        for(i = 1; i < n; i++)
            printf(" %c", ans[i]);
        puts("");
        return ;
    }
    int i, j;
    for(i = 0; i < n; i++) {
        if(!used[i]) {
            for(j = 0; j < Idx; j++) {
                if(g[s[i]-'A'][ans[j]-'A'])
                    break;
            }
            if(j == Idx) {
                ans[Idx] = s[i];
                used[i] = 1;
                dfs(Idx+1);
                used[i] = 0;
            }
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    getchar();
    string line;
    while(t--) {
        getchar();
        getline(cin, line);
        stringstream sin;
        sin << line;
        s = "";
        while(sin >> line)  s += line;
        sort(s.begin(), s.end());
        getline(cin, line);
        memset(g, 0, sizeof(g));
        sin.clear();
        sin << line;
        while(sin >> line) {
            g[line[0]-'A'][line[2]-'A'] = 1;
        }
        n = s.length();
        has = 0;
        dfs(0);
        if(!has)
            puts("NO");
        if(t)
            puts("");
    }
    return 0;
}
/*
Input
The input begins with a single positive integer on a line by itself indicating the number
of the cases following, each of them as described below. This line is followed by a blank
line, and there is also a blank line between two consecutive inputs.
The input consists of two lines: a list of variables on one line followed by a list of constraints of the
form A < B on the next line. Variables and constraints are separated by single spaces.
All variables are single character, upper-case letters. There will be at least two variables, and no
more than 20 variables. There will be at least one constraint, and no more than 50 constraints. There
will be no more than 300 orderings consistent with the constraints in a specification.
Output
For each test case, the output must follow the description below. The outputs of two
consecutive cases will be separated by a blank line.
All orderings consistent with the constraints should be printed. Orderings are printed in alphabetical
order, one per line. Characters on a line are separated by a space. If no ordering is possible the output
is a single line with the word ‘NO’.
Sample Input
1
A B F G
A<B B<F
Sample Output
A B F G
A B G F
A G B F
G A B F
*/
