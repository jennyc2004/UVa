#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, cases = 0;
    while(cin >> n >> m) {
        if(!n && !m)
            break;
        if(cases)
            puts("");
        printf("Calling circles for data set %d:\n", ++cases);
        map<string, int> r;
        int size = 0, graph[26][26] = {}, i, j, k;
        int x, y, used[26] = {};
        string name[26], a, b;
        while(m--) {
            cin >> a >> b;
            x = r[a];
            if(x == 0)
                r[a] = ++size, x = size, name[size] = a;
            y = r[b];
            if(y == 0)
                r[b] = ++size, y = size, name[size] = b;
            graph[x][y] = 1;
        }
        for(i = 1; i <= size; i++)
            graph[i][i] = 1;
        for(k = 1; k <= size; k++) {
            for(i = 1; i <= size; i++) {
                for(j = 1; j <= size; j++) {
                    if(graph[i][k] == 1 && graph[k][j] == 1)
                        graph[i][j] = 1;
                }
            }
        }
        for(i = 1; i <= size; i++) {
            if(!used[i]) {
                int cnt = 0;
                for(j = 1; j <= size; j++) {
                    if((!used[j]) && graph[i][j] && graph[j][i]) {
                        used[j] = 1;
                        used[i] = 1;
                        if(cnt)
                            printf(", ");
                        printf("%s", name[j].c_str());
                        cnt++;
                    }
                }
                puts("");
            }
        }
    }
    return 0;
}
/*
Input
The input file will contain one or more data sets. Each data set begins with a line containing two
integers, n and m. The first integer, n, represents the number of different people who are in the data
set. The maximum value for n is 25. The remainder of the data set consists of m lines, each representing
a phone call. Each call is represented by two names, separated by a single space. Names are first names
only (unique within a data set), are case sensitive, and consist of only alphabetic characters; no name
is longer than 25 letters.
For example, if Ben called Dolly, it would be represented in the data file as
Ben Dolly
Input is terminated by values of zero (0) for n and m.
Output
For each input set, print a header line with the data set number, followed by a line for each calling
circle in that data set. Each calling circle line contains the names of all the people in any order within
the circle, separated by comma-space (a comma followed by a space). Output sets are separated by
blank lines.
Sample Input
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha
0 0
Sample Output
Calling circles for data set 1:
Ben, Alexander, Dolly, Benedict
Aaron
Calling circles for data set 2:
John, Betsy, Ringo, Dolly
Aaron
Benedict
Paul, George, Martha, Ben, Alexander, Stephen, Quincy, Patrick
*/
