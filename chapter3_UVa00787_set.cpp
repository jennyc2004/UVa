#include <bits/stdc++.h>
#include <utility>
using namespace std;
class Big {
    vector<int> c;
    bool n;
public:
    Big(int v) {
        set(v);
    }

    Big(const Big& a) {
        c = a.c;
        n = a.n;
    }

    void set(int v) {
        n = v < 0;
        c.clear();
        c.push_back(abs(v));
    }

    bool operator < (const Big& a) const {
        if (n != a.n) return n;
        if (c.size() != a.c.size()) return c.size() < a.c.size();
        for (int i = c.size() - 1; i >= 0; i--) {
            if (c[i] != a.c[i]) return c[i] < a.c[i];
        }
        return false;
    }

    void mult(int a) {
        n = (n ^ (a < 0)) && (a != 0);
        a = abs(a);
        for (int i = 0; i < c.size(); i++){
            int &t = c[i];
            t *= a;
        }
        for (int i = 0; i < c.size() - 1; i++) {
            c[i + 1] += c[i] / 1000;
            c[i] %= 1000;
        }
        while (c.back() >= 1000) {
            int t = c.back();
            c.back() = t % 1000;
            c.push_back(t / 1000);
        }
        while (c.size() > 1 && c.back() == 0) c.erase(c.end() - 1);
    }

    void print() {
        if (n) putchar('-');
        printf("%d", c.back());
        for (int i = c.size() - 2; i >= 0; i--) {
            printf("%03d", c[i]);
        }
    }
};



int main() {
    long long v[200];
    while (scanf("%lld", v) == 1) {
        int n = 1;
        while (true) {
            scanf("%lld", v + n);
            if (v[n] == -999999) break;
            n++;
        }
        Big m(v[0]);
        Big p(1);
        for (int i = 0; i < n; i++) {
            p.mult(v[i]);
            m = max(m, p);
            if (v[i] == 0) p.set(1);
        }
        p.set(1);
        for (int i = n - 1; i >= 0; i--) {
            p.mult(v[i]);
            m = max(m, p);
            if (v[i] == 0) p.set(1);
        }
        m.print();
        printf("\n");
    }
}
/*
Input
The input file contains sequences of numbers. Each number will have at most 5 digits. There will be at
most 100 numbers in each sequence. Each sequence starts on a new line and may continue on several
subsequent lines. Each sequence ends with the number -999999 (which is not part of the sequence).
Output
The maximum sub-sequence product for each sequence must be written on the standard output, on a
different line. A simple example is illustrated in the sample below.
Sample Input
1 2 3 -999999
-5 -2 2 -30 -999999
-8 -999999
-1 0 -2 -999999
Sample Output
6
120
-8
0
*/
