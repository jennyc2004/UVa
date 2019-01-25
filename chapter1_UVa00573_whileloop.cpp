#include <bits/stdc++.h>
using namespace std;
/*
Input
The input file contains one or more test cases, each on a line by itself. Each line contains four integers
H, U, D, and F, separated by a single space. If H = 0 it signals the end of the input; otherwise,
all four numbers will be between 1 and 100, inclusive. H is the height of the well in feet, U is the
distance in feet that the snail can climb during the day, D is the distance in feet that the snail slides
down during the night, and F is the fatigue factor expressed as a percentage. The snail never climbs
a negative distance. If the fatigue factor drops the snail’s climbing distance below zero, the snail does
not climb at all that day. Regardless of how far the snail climbed, it always slides D feet at night.
Output
For each test case, output a line indicating whether the snail succeeded (left the well) or failed (slid
back to the bottom) and on what day. Format the output exactly as shown in the example.
Sample Input
6 3 1 10
10 2 1 50
50 5 3 14
50 6 4 1
50 6 3 1
1 1 1 1
0 0 0 0
Sample Output
success on day 3
failure on day 4
failure on day 7
failure on day 68
success on day 20
failure on day 2
*/
int main() {
    int h, u, d, f;
    while (cin >> h >> u >> d >> f, h!= 0)
    {
        double well_height = h;
        double slide_height = d;
        double strength = u;
        double current_height = 0;
        double fatigue = f / 100.0 * strength;
        int day = 0;
        while (true)
        {
            day++;
            current_height += strength;
            if (current_height > well_height)
            {
                cout << "success on day " << day << endl;
                break;
            }
            current_height -= slide_height;
            if (current_height < 0)
            {
                cout << "failure on day " << day << endl;
                break;
            }
            strength -= fatigue;
            if (strength < 0)
            {
                strength = 0;
            }
        }
    }
    return 0;
}

