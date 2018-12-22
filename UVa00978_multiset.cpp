#include <bits/stdc++.h>
using namespace std;
/*
Input
The first line of input contains a single number N, representing the number of test cases that follow
(1 ≤ N ≤ 100).
Each test case starts with a line with three space-separated integers, B, SG and SB, representing
respectively the number of battlefields available, the number of lemmings in the green army and the
number of lemmings in the blue army (1 ≤ B, SG, SB ≤ 100000).
Than follow exactly SG lines, each one with an integer indicating the power of one single lemming
of the green army, followed by SB lines, each one with an integer indicating the power of one single
lemming of the blue army. This power is a positive integer smaller than 101.
The lemmings in each army do not need to come in any particular order.
Output
For each test case you should print:
• ‘green and blue died’ if both races died in the same round
• ‘green wins’ if the green army won the Deadly War, followed by one line for each surviving
soldier (in descending order)
• ‘blue wins’ if the blue army won the Deadly War, followed by one line for each surviving soldier
(in descending order)
There should also be a blank line beetween test cases.
Sample Input
3
5 1 1
10
10
2 2 3
20
10
10
10
15
3 5 5
50
40
30
40
50
50
30
30
20
60
Sample Output
green and blue died
blue wins
5
green wins
10
10
*/
int t, b, ng, nb;
multiset<int> green, blue;
int main() {
    cin >> t;
    for(int tt=0; tt<t; tt++) {
        if(tt > 0) cout << '\n';
        green.clear();
        blue.clear();
        cin >> b >> ng >> nb;
        for(int i=0; i<ng; i++) {
            int x;
            cin >> x;
            green.insert(x);
        }
        for(int i=0; i<nb; i++) {
            int x;
            cin >> x;
            blue.insert(x);
        }
        while(!green.empty() && !blue.empty()) {
            vector<int> gw, bw;
            int fights = min(b, (int)min(green.size(), blue.size()));
            for(int i=0; i<fights; i++) {
                multiset<int>::iterator tg = green.end(), tb = blue.end();
                tg--; tb--;
                int gs = *tg, bs = *tb;
                green.erase(tg); blue.erase(tb);
                if(gs > bs) gw.push_back(gs-bs);
                else if(bs > gs) bw.push_back(bs-gs);
            }
            for(vector<int>::iterator it=gw.begin(); it !=gw.end();it++) green.insert(*it);
            for(vector<int>::iterator it=bw.begin(); it !=bw.end();it++) blue.insert(*it);
        }
        if(green.empty() && !blue.empty()) {
            cout << "blue wins\n";
            for(multiset<int>::reverse_iterator it=blue.rbegin(); it!=blue.rend(); it++)
            cout << *it << '\n';
        } else if(!green.empty() && blue.empty()) {
            cout << "green wins\n";
            for(multiset<int>::reverse_iterator it=green.rbegin(); it!=green.rend(); it++)
            cout << *it << '\n';
        } else cout << "green and blue died\n";
    }
}

