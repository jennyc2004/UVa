#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, v;
    char line[100], h[2];
    scanf("%d ", &t);
    while(t--) {
        int map[26][26] = {}, day[26] = {}, mt[26] = {};
        int i, j, done[26] = {};
        while(gets(line)) {
            if(line[0] == '\0')
                break;
            sscanf(line, "%s %d", h, &v);
            j = h[0]-'A', done[j] = 1;
            day[j] = v;
            for(i = strlen(line)-1; i >= 0; i--) {
                if(line[i] < 'A' || line[i] > 'Z')
                    break;
                map[j][mt[j]++] = line[i]-'A';
            }
        }
        int fin[26] = {}, used[26] = {};
        int max, ans = 0;
        while(1) {
            int flag = 0;
            for(i = 0; i < 26; i++) {
                if(used[i] == 0 && done[i] == 1) {
                    max = 0;
                    for(j = 0; j < mt[i]; j++) {
                        if(used[map[i][j]] == 0)
                            break;
                        if(fin[map[i][j]] > max)
                            max = fin[map[i][j]];
                    }
                    if(j == mt[i]) {
                        fin[i] = max+day[i];
                        if(fin[i] > ans)
                            ans = fin[i];
                        used[i] = 1;
                        flag = 1;
                    }
                }
            }
            if(flag == 0)
                break;
        }
        printf("%d\n", ans);
        if(t)
            puts("");
    }
    return 0;
}
/*
Input
The input begins with a single positive integer on a line by itself indicating the number of the cases
following, each of them as described below.
This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
Input will be from 1 to 27 lines, each corresponding to a different task. Each line will contain:
1. A single upper case letter serving as the name of a task. On the final line of input, this will be
blank and the rest of that line is ignored.
2. An integer indicating the number of days required to complete that task.
3. 0-26 additional uppercase letters, each indicating another task that must complete before this
one can begin.
Output
For each test case, the output must follow the description below. The outputs of two consecutive cases
will be separated by a blank line.
The output is a single integer indicating the amount of time that will pass before all tasks can
complete.
Sample Input
2
A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC
A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC
Sample Output
16
16
*/
