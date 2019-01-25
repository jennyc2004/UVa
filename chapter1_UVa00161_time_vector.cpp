#include <bits/stdc++.h>
using namespace std;
/*
Input
Input will consist of a series of scenarios. Data for each scenario will consist of a series of integers
representing the cycle times of the traffic lights, possibly spread over many lines, with no line being
longer than 100 characters. Each number represents the cycle time of a single signal. The cycle time is
the time that traffic may move in one direction; note that the last 5 seconds of a green cycle is actually
orange.
Thus the number 25 means a signal that (for a particular direction) will spend 20 seconds green,
5 seconds orange and 25 seconds red. Cycle times will not be less than 10 seconds, nor more than 90
seconds. There will always be at least two signals in a scenario and never more than 100. Each scenario
will be terminated by a zero (0).
The file will be terminated by a line consisting of three zeroes (0 0 0).
Output
Output will consist of a series of lines, one for each scenario in the input. Each line will consist of the
time in hours, minutes and seconds that it takes for all the signals to show green again after at least
one of them changes to orange. Follow the format shown in the examples. Time is measured from the
instant they all turn green simultaneously. If it takes more than five hours before they all show green
simultaneously, the message ‘Signals fail to synchronise in 5 hours’ should be written instead.
Sample Input
19 20 0
30
25 35 0
0 0 0
Sample Output
00:00:40
00:05:00
*/
const int perMin = 60;
const int perHr = 60 * perMin;
const int maxTime = 5 * perHr;
const int orangeTime = 5;

bool isGreen(vector<int> times, vector<int> doubleTimes, int currentTime)
{
    for (int i = 0; i < times.size(); ++i)
    {
        if (! (currentTime % doubleTimes[i] < times[i] - orangeTime))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int firstLight;
    while (cin>>firstLight, firstLight)
    {
        // init 2 vectors, green time only, green + red times total.
        vector<int> times(1, firstLight);
        vector<int> doubleTimes(1, firstLight * 2);
        int num;
        int min = firstLight;
        while (cin>>num, num)
        {
            times.push_back(num);
            doubleTimes.push_back(num * 2);
            if (num < min)
                min = num;
        }
        int currentTime = min * 2;
        bool allGreen;

        while (!(allGreen = isGreen(times, doubleTimes, currentTime)) && currentTime <= maxTime)
        {
            ++currentTime;
        }

        if (allGreen)
        {
            int hour = currentTime / perHr;
            int minute = (currentTime - hour * perHr) / perMin;
            int second = currentTime % perMin;

            printf("%02d:%02d:%02d\n", hour, minute, second);
        }

        else
        {
            cout<<"Signals fail to synchronise in 5 hours"<<endl;
        }
    }
}

