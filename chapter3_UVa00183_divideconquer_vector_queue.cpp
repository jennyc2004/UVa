#include <bits/stdc++.h>
using namespace std;
void BtoD(int i1, int i2, int j1, int j2, vector<vector<char>> &v,
          string &ans) {
    char flag = v[i1][j1];
    for (int i = i1; i < i2; i++) {
        for (int j = j1; j < j2; j++) {
            if (v[i][j] != flag) {
                flag = 'D';
                break;
            }
        }
        if (flag == 'D') break;
    }
    ans += flag;
    if (flag != 'D') return;
    int mi = (i2 - i1 + 1) / 2, mj = (j2 - j1 + 1) / 2;
    BtoD(i1, i1 + mi, j1, j1 + mj, v, ans);
    if (j2 - j1 > 1) BtoD(i1, i1 + mi, j1 + mj, j2, v, ans);
    if (i2 - i1 > 1) {
        BtoD(i1 + mi, i2, j1, j1 + mj, v, ans);
        if (j2 - j1 > 1) BtoD(i1 + mi, i2, j1 + mj, j2, v, ans);
    }
}

void DtoB(int i1, int i2, int j1, int j2, queue<char> &q,
          vector<vector<char>> &ans) {
    char flag = q.front();
    q.pop();
    if (flag != 'D') {
        for (int i = i1; i < i2; i++) {
            for (int j = j1; j < j2; j++) {
                ans[i][j] = flag;
            }
        }
        return;
    }

    int mi = (i2 - i1 + 1) / 2, mj = (j2 - j1 + 1) / 2;
    DtoB(i1, i1 + mi, j1, j1 + mj, q, ans);
    if (j2 - j1 > 1) DtoB(i1, i1 + mi, j1 + mj, j2, q, ans);
    if (i2 - i1 > 1) {
        DtoB(i1 + mi, i2, j1, j1 + mj, q, ans);
        if (j2 - j1 > 1) DtoB(i1 + mi, i2, j1 + mj, j2, q, ans);
    }
}

int main() {
    char f;
    int n, m;
    while (cin >> f, f != '#') {
        cin >> n >> m;
        if (f == 'B') {
            vector<vector<char>> v(n, vector<char>(m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    char tmp = cin.get();
                    if (tmp == '\n') tmp = cin.get();
                    v[i][j] = tmp;
                }
            }
            string ans = "";
            BtoD(0, n, 0, m, v, ans);
            int cnt = 0;
            cout << "D" << right << setw(4) << n << right << setw(4) << m
                 << endl;
            for (auto &&i : ans) {
                cnt++;
                cout << i;
                if (cnt == 50) {
                    cnt = 0;
                    cout << endl;
                }
            }
            if (cnt != 0) cout << endl;
        } else {
            queue<char> q;
            char tmp;
            while (tmp = cin.get(), tmp != '#') {
                if (cin.peek() == ' ') {
                    cin.putback(tmp);
                    break;
                }
                if (tmp == '\n') continue;
                q.push(tmp);
            }
            vector<vector<char>> ans(n, vector<char>(m));
            DtoB(0, n, 0, m, q, ans);
            int cnt = 0;
            cout << "B" << right << setw(4) << n << right << setw(4) << m
                 << endl;
            for (auto &&i : ans) {
                for (auto &&j : i) {
                    cnt++;
                    cout << j;
                    if (cnt == 50) {
                        cnt = 0;
                        cout << endl;
                    }
                }
            }
            if (cnt != 0) cout << endl;
            if (tmp == '#') break;
        }
    }
}
/*
Input
Input will consist of a series of bit maps. Each bit map begins with a line giving its format (‘B’ or ‘D’)
and its dimensions (rows and columns). Neither dimension will be greater than 200. There will be at
least one space between each of the items of information. Following this line will be one or more lines
containing the sequence of ‘1’, ‘0’ and ‘D’ characters that represent the bit map, with no intervening
spaces. Each line (except the last, which may be shorter) will contain 50 characters. A ‘B’ type bitmap
will be written left to right, top to bottom.
The file will be terminated by a line consisting of a single ‘#’.
Output
Output will consist of a series of bitmaps, one for each bit map of the input. Output of each bit map
begins on a new line and will be in the same format as the input. The width and height are to be
output right justified in fields of width four.
Sample Input
B 3 4
001000011011
D 2 3
DD10111
#
Sample Output
D 3 4
D0D1001D101
B 2 3
10111
*/
