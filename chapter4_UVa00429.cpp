#include <bits/stdc++.h>
using namespace std;
#define N 201
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    int T;
    char str[N][15];
    vector<int> adj_list[N];
    scanf("%d ", &T);
    while (T--)
    {

        int idx = 1;
        while (fgets(str[idx], 15, stdin) && str[idx][0] != '*')
        {
            str[idx][strlen(str[idx]) - 1] = '\0';
            ++idx;
        }

        for (int i = 1; i < idx; ++i)
        {
            for (int j = i + 1; j < idx; ++j)
            {
                int diff = 0;
                for (int k = 0; diff < 2 && str[i][k] && str[j][k]; ++k)
                    if (str[i][k] != str[j][k])
                        ++diff;

                if (diff < 2)
                {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }

        char tmp[30], a[15], b[15];
        int step[N] = {};
        while (fgets(tmp, 30, stdin) && tmp[0] != '\n')
        {
            int i, j, a_id, b_id;

            for (i = 0; tmp[i] != ' '; ++i)
                a[i] = tmp[i];
            a[i++] = '\0';
            for (j = 0; tmp[i] != '\n'; ++i, ++j)
                b[j] = tmp[i];
            b[j] = '\0';

            for (i = 1; i < idx; ++i)
                if (!strcmp(a, str[i]))
                {
                    a_id = i;
                    break;
                }

            for (i = 1; i < idx; ++i)
                if (!strcmp(b, str[i]))
                {
                    b_id = i;
                    break;
                }

            //BFS
            queue<int> Q;
            Q.push(a_id);
            step[a_id] = 1;
            while (!Q.empty() && !step[b_id])
            {
                int now = Q.front();
                Q.pop();
                for (int i : adj_list[now])
                {
                    if (!step[i])
                    {
                        step[i] = step[now] + 1;
                        if (i == b_id)
                            break;
                        Q.push(i);
                    }
                }
            }

            printf("%s %s %d\n", a, b, step[b_id] - 1);
            memset(step, 0, sizeof step);
        }

        if (T)
            putchar('\n');

        for (int i = 0; i < idx; ++i)
            adj_list[i].clear();
    }

    return 0;
}
/*
Input
The first line of the input is an integer N, indicating the number of test set that your correct program
should test followed by a blank line.
Each test set will have two sections. The first section will be the dictionary of available words with
one word per line, terminated by a line containing an asterisk (*) rather than a word. There can be
up to 200 words in the dictionary; all words will be alphabetic and in lower case, and no word will be
longer than ten characters. Words can appear in the dictionary in any order.
Following the dictionary are pairs of words, one pair per line, with the words in the pair separated
by a single space. These pairs represent the starting and ending words in a transformation. All pairs
are guaranteed to have a transformation using the dictionary given. The starting and ending words
will appear in the dictionary.
Two consecutive input set will separated by a blank line.
Output
The output should contain one line per word pair for each test set, and must include the starting word,
the ending word, and the number of steps in the shortest possible transformation, separated by single
spaces.
Two consecutive output set will be separated by a blank line.
Sample Input
1
dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod
Sample Output
spice stock 4
may pod 3
*/
