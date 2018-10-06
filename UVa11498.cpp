#include <bits/stdc++.h>
using namespace std;

int main() {
    int queries;
    int divx, divy;
    int homex, homey;
    cin >> queries;
    while (queries > 0) {
        cin >> divx >> divy;
        while (queries > 0) {
            cin >> homex >> homey;
            if (homex > divx && homey > divy)
                cout << "NE" << endl;
            else if (homex > divx && homey < divy) {
                cout << "SE" << endl;
            } else if (homex < divx && homey > divy) {
                cout << "NO" << endl;
            } else if (homex < divx && homey < divy) {
                cout << "SO" << endl;
            } else {
                cout << "divisa" << endl;
            }
            queries--;
        }
        cin >> queries;
    }
    return 0;
}
