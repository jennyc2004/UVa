#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, m;
    char c;
    while (cin >> h >> c >> m, h != 0 || m != 0)
    {
        double hAngle = (360.0 / 12) * h + ((360.0 / 12) / 60) * m;
        double mAngle = (360.0 / 60) * m;
        double angle = max(hAngle - mAngle, mAngle - hAngle);
        cout << setprecision(3)<< fixed<< min(angle, 360.0 - angle)<< endl;
    }
    return 0;
}

/*
Input
The input is a list of times in the form ‘H:M’, each on their own line, with 1 ≤ H ≤ 12 and
00 ≤ M ≤ 59. The input is terminated with the time ‘0:00’. Note that H may be represented with 1
or 2 digits (for 1–9 or 10–12, respectively); M is always represented with 2 digits (the input times are
what you typically see on a digital clock).
Output
The output displays the smallest positive angle in degrees between the hands for each time. The answer
should between 0 degrees and 180 degrees for all input times. Display each angle on a line by itself in
the same order as the input. The output should be rounded to the nearest 1/1000, i.e., three places
after the decimal point should be printed.
Sample Input
12:00
9:00
8:10
0:00
Sample Output
0.000
90.000
175.000
*/
