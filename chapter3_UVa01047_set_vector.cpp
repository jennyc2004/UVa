#include <bits/stdc++.h>
using namespace std;
int n, b;
vector<pair<vector<int>, int> > v;
vector<pair<vector<int>, int> >::iterator it;
vector<int> ans;
vector<int> cur;
int sum;
int maxx;
int tower[25];
void dfs(int size, int index) {
    if (size == b) {
        int tmpSum = sum;
        vector<int> tmp = cur;
        sort(tmp.begin(), tmp.end());
        for (it = v.begin(); it < v.end(); it++) {
        vector<int> inter;
        set_intersection(tmp.begin(), tmp.end(), it->first.begin(), it->first.end(), back_inserter(inter));
        if (inter.size() > 1)
            tmpSum -= (inter.size()-1)*it->second;
        }
        if (tmpSum > maxx) {
            ans = cur;
            maxx = tmpSum;
        }
    }
    for (;index < n; index++) {
        cur.push_back(index);
        sum += tower[index];
        dfs(size+1, index+1);
        cur.pop_back();
        sum -= tower[index];
    }
    return ;
}
int main(void)
{
    int m, t, tmp, customers;
    int cnt = 1;
    while (EOF != scanf("%d %d", &n, &b) && (n || b)) {
        v.clear();
        for (int i = 0; i < n; i++)
            scanf("%d", &tower[i]);
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &t);
            vector<int> vTmp;
            for (int i = 0; i < t; i++) {
                scanf("%d", &tmp);
                vTmp.push_back(tmp-1);
            }
            sort(vTmp.begin(), vTmp.end());
            scanf("%d", &customers);
            v.push_back(pair<vector<int>, int> (vTmp, customers));
        }
        sum = 0, maxx = 0;
        dfs(0, 0);
        printf("Case Number  %d\n", cnt++);
        printf("Number of Customers: %d\n", maxx);
        printf("Locations recommended:");
        for (int i = 0; i < ans.size(); i++)
            printf(" %d", ans[i]+1);
        puts("");
        puts("");
    }
    return 0;
}
/*
Input
The input file contains several test cases. The first line of each test case contains two positive integers:
the number n (n ≤ 20) of towers planned, and the number of towers to be actually built. The next
line contains n numbers, each giving the number of customers served by a planned tower. (The first
number refers to the first tower, and so on.) No tower serves more than a million people. The next
line contains the number m (m ≤ 10) of common service areas. Each of the next m lines contains the
description of a common service area. Such a line starts with the number t (t > 1) of towers for which
this is a common service area, followed by the t numbers of the towers. The last number on the line is
the number of customers in the common service area. The last line of the input file consists of the two
integers ‘0 0’.
Output
For each test case, display the number of customers served and the best choice for the location of the
towers. Follow the format of the sample output. Print a blank line after each test case.
Sample Input
5 3
15 20 25 30 24
5
2 1 2 7
3 1 2 3 3
2 2 3 2
2 3 4 5
2 4 5 6
5 3
25 25 25 25 25
4
2 1 2 5
2 2 3 5
2 3 4 5
2 4 5 5
5 3
25 25 25 25 25
0
0 0
Sample Output
Case Number 1
Number of Customers: 68
Locations recommended: 2 4 5
Case Number 2
Number of Customers: 75
Locations recommended: 1 3 5
Case Number 3
Number of Customers: 75
Locations recommended: 1 2 3
*/
