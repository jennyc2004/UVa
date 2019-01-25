#include <bits/stdc++.h>
using namespace std;
typedef unsigned long       ul;
typedef unsigned long long ull;

typedef std::pair<int,int>  ii;
typedef std::pair<int,ii>  iii;
typedef std::vector<int>    vi;
typedef std::vector<ii>    vii;
typedef std::vector<iii>  viii;

void print (viii& p) {
    for (int i=0; i<p.size(); i++)
        printf (" %d  %d-%d\n", p[i].first, p[i].second.first, p[i].second.second);
    printf("---\n");
}
void print (vi& p, string s="") {
    if (!s.empty())
        printf ("%s\n", s.c_str());
    for (int i=0; i<p.size(); i++)
        printf ("[%d] %d\n", i, p[i]);
    printf(" ;\n");
}
const bool dbg=0;
int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-1260.txt", "r");
    }

    int TC;
    fscanf (fp, "%d", &TC);
    while (--TC >= 0) {
        int n;
        fscanf(fp, "%d", &n);
        int a[1001];
        for (int i=0; i<n; i++)
            fscanf (fp, "%d", a+i);

        int b[1001]={0};
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++)
                if (a[j]<=a[i])
                    b[i]++;
        }
        int sum = 0;
        for (int i=1; i<n; i++)
            sum += b[i];
        printf ("%d\n", sum);
    }

    return 0;
}
/*
Input
Your program is to read the input from standard input. The input consists of T test cases. The number
of test cases T is given in the first line of the input. Each test case starts with a line containing an
integer n (2 ≤ n ≤ 1, 000), which represents the size of the list A . In the following line, n integers are
given, each represents the daily sales amounts ai (1 ≤ ai ≤ 5, 000 and 1 ≤ i ≤ n) for the test case.
Output
Your program is to write to standard output. For each test case, print the sum of the n − 1 integers in
the list B which is obtained from the list A.
The following shows sample input and output for two test cases.
Sample Input
2
5
38 111 102 111 177
8
276 284 103 439 452 276 452 398
Sample Output
9
20
*/
