#include <bits/stdc++.h>
using namespace std;
struct computer
{
    int x, y;
};

double dist(const computer &a, const computer &b)
{
    return 16.0 + sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    int T = 1;
    int N;
    while (cin >> N, N > 0)
    {
        vector<computer> computers;
        vector<int> computerIndexes;
        for (int i = 1; i <= N; ++i)
        {
            computer com;
            cin >> com.x >> com.y;
            computers.push_back(com);
            computerIndexes.push_back(i - 1);
        }
        vector<int> network;
        double minimumCable = numeric_limits<double>::max();
        do {
            double cable = 0;
            for (int i = 0; i < N - 1; ++i)
                cable += dist(computers[computerIndexes[i]], computers[computerIndexes[i + 1]]);

            if (cable < minimumCable)
            {
                minimumCable = cable;
                network = computerIndexes;
            }
        } while (next_permutation(computerIndexes.begin(), computerIndexes.end()));

        cout << "**********************************************************" << endl;
        cout << "Network #" << T++ << endl;
        for (int i = 0; i < N - 1; ++i)
            cout << "Cable requirement to connect "
                 << "("
                 << computers[network[i]].x
                 << ","
                 << computers[network[i]].y
                 << ") to ("
                 << computers[network[i + 1]].x
                 << ","
                 << computers[network[i + 1]].y
                 << ") is "
                 << setprecision(2)
                 << setiosflags(ios::fixed)
                 << dist(computers[network[i]], computers[network[i + 1]])
                 << " feet."
                 << endl;
        cout << "Number of feet of cable required is "
             << setprecision(2)
             << setiosflags(ios::fixed)
             << minimumCable
             << "."
             << endl;
    }
    return 0;
}
/*
Input
The input file will consist of a series of data sets. Each data set will begin with a line consisting of a
single number indicating the number of computers in a network. Each network has at least 2 and at
most 8 computers. A value of 0 for the number of computers indicates the end of input.
After the initial line in a data set specifying the number of computers in a network, each additional
line in the data set will give the coordinates of a computer in the network. These coordinates will be
integers in the range 0 to 150. No two computers are at identical locations and each computer will be
listed once.
Output
The output for each network should include a line which tells the number of the network (as determined
by its position in the input data), and one line for each length of cable to be cut to connect each adjacent
pair of computers in the network. The final line should be a sentence indicating the total amount of
cable used.
In listing the lengths of cable to be cut, traverse the network from one end to the
other. (It makes no difference at which end you start.) Use a format similar to the one shown in the
sample output, with a line of asterisks separating output for different networks and with distances in
feet printed to 2 decimal places.
Sample Input
6
5 19
55 28
38 101
28 62
111 84
43 116
5
11 27
84 99
142 81
88 30
95 38
3
132 73
49 86
72 111
0
Sample Output
**********************************************************
Network #1
Cable requirement to connect (5,19) to (55,28) is 66.80 feet.
Cable requirement to connect (55,28) to (28,62) is 59.42 feet.
Cable requirement to connect (28,62) to (38,101) is 56.26 feet.
Cable requirement to connect (38,101) to (43,116) is 31.81 feet.
Cable requirement to connect (43,116) to (111,84) is 91.15 feet.
Number of feet of cable required is 305.45.
**********************************************************
Network #2
Cable requirement to connect (11,27) to (88,30) is 93.06 feet.
Cable requirement to connect (88,30) to (95,38) is 26.63 feet.
Cable requirement to connect (95,38) to (84,99) is 77.98 feet.
Cable requirement to connect (84,99) to (142,81) is 76.73 feet.
Number of feet of cable required is 274.40.
**********************************************************
Network #3
Cable requirement to connect (132,73) to (72,111) is 87.02 feet.
Cable requirement to connect (72,111) to (49,86) is 49.97 feet.
Number of feet of cable required is 136.99.
*/
