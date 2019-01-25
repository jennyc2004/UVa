#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Edge
{
    int r, c;
    int cost;
    bool operator>(const Edge &e) const
    {
        return this->cost > e.cost;
    }
};

int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        int N, M;
        cin >> N >> M;

        vector<vector<int> > maze(N, vector<int>(M));

        for (int r = 0; r < N; ++r)
            for (int c = 0; c < M; ++c)
                cin >> maze[r][c];

        priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
        vector<vector<int> > cost(N, vector<int>(M, -1));
        Edge e;
        e.r = 0;
        e.c = 0;
        e.cost = maze[0][0];
        pq.push(e);
        cost[0][0] = e.cost;
        while (!pq.empty())
        {
            Edge u = pq.top();
            pq.pop();
            for (int i = 0; i < 4; ++i)
            {
                int r = u.r + dx[i];
                int c = u.c + dy[i];
                if (r < 0 || r >= N || c < 0 || c >= M)
                    continue;
                if (cost[r][c] == -1
                    || cost[u.r][u.c] + maze[r][c] < cost[r][c])
                {
                    cost[r][c] = cost[u.r][u.c] + maze[r][c];
                    e.r = r;
                    e.c = c;
                    e.cost = cost[r][c];
                    pq.push(e);
                }
            }
        }
        cout << cost[N - 1][M - 1] << endl;
    }
    return 0;
}
/*
Input
The input file contains several mazes. The first input line contains a positive integer defining the
number of mazes that follow. Each maze is defined by: one line with the number of rows, N; one
line with the number of columns, M; and N lines, one per each row of the maze, containing the maze
numbers separated by spaces.
Output
For each maze, output one line with the required minimum value.
Sample Input
2
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5
Sample Output
24
15
*/
