#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <limits>
#include <cmath>
#include <queue>
#include <set>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

int n;
vector<vector<int>> adj;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

typedef struct info
{
    int x;
    int y;
    int dist;
} info;

pair<int, int> sharkPoint;

int BFS(int xx, int yy, int fishSize)
{ // 가장 가까운 , 먹을 수 있는 물고기 찾기 상어의 위치
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    vector<info> Fish;
    q.push({xx, yy});
    dist[xx][yy] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        FOR(i, 0, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1)
            { // 잡아먹는 경우 , 그냥 지나가는 경우
                int state = adj[nx][ny];
                if (state <= fishSize)
                {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;

                    if (state > 0 && state < fishSize)
                    {
                        Fish.push_back({nx, ny, dist[nx][ny]});
                    }
                }
            }
        }
    }

    if (Fish.empty())
    {
        return -1;
    }

    sort(Fish.begin(), Fish.end(),
         [](auto &a, auto &b)
         {
             if (a.dist != b.dist)
                 return a.dist < b.dist;
             if (a.x != b.x)
                 return a.x < b.x;
             return a.y < b.y;
         });

    sharkPoint.first = Fish[0].x;
    sharkPoint.second = Fish[0].y;

    return Fish[0].dist;
}

int main()
{
    cin >> n;
    adj.assign(n, vector<int>(n));
    int input, xx, yy;
    FOR(i, 0, n)
    {
        FOR(j, 0, n)
        {
            cin >> input;
            if (input == 9)
            {
                xx = i;
                yy = j;
                input =0;
            }
            adj[i][j] = input;
        }
    }
    int fishSize = 2, time = 0, eatCnt = 0;

    while (true)
    {
        int a = BFS(xx, yy, fishSize); // 거리가 가장 가까운 물고기
        if (a == -1)
            break;

        time += a;
        eatCnt++;
        if (fishSize == eatCnt)
        {
            eatCnt = 0;
            fishSize++;
        }
        xx = sharkPoint.first;
        yy = sharkPoint.second;
        adj[xx][yy] = 0;
    }

    cout << time;

    return 0;

}