#include<bits/stdc++.h>
using namespace std;

int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};

bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int steps(vector<int> knight, vector<int> target, int n)
{
    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));

    queue<vector<int>> q;
    q.push(knight);

    visited[knight[0]][knight[1]] = 0;

    while (!q.empty())
    {
        vector<int> t = q.front();
        q.pop();

        if(t[0] == target[0] && t[1] == target[1])
            return visited[t[0]][t[1]];

        for (int i = 0; i < 8; i++)
        {
            int x = t[0] + moves[i][0];
            int y = t[1] + moves[i][1];

            if(isInside(x, y, n) && !visited[x][y])
            {
                visited[x][y] = visited[t[0]][t[1]] + 1;
                q.push({x, y});
            }
        }
    }
}

int main()
{
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<int> knight = {x1, y1};
    vector<int> target = {x2, y2};
    cout << steps(knight, target, n) << endl;
    return 0;
}
