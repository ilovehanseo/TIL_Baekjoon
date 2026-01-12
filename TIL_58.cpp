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

// int dx[9] = {0, 0, 1, -1, 0, 1, 1, -1, -1};
// int dy[9] = {1, -1, 0, 0, 0, 1, -1, 1, -1};

// vector<string> board(8);
// bool visited[8][8];

// void wallDown()
// {
//     for (int i = 7; i > 0; i--)
//     {
//         board[i] = board[i - 1];
//     }
//     board[0] = "........";
// }

// int main()
// {
//     for (int i = 0; i < 8; i++)
//         cin >> board[i];

//     queue<pair<int, int>> q;
//     q.push({7, 0});
//     visited[7][0] = true;

//     int time = 0;

//     while (!q.empty())
//     { // 레벨별 BFS 돌리는 방법
//         int sz = q.size();

//         // 현재 시간대 BFS
//         while (sz--)
//         {
//             auto [x, y] = q.front();
//             q.pop();

//             if (board[x][y] == '#')
//                 continue;
//             if (x == 0 && y == 7)
//             {
//                 cout << 1;
//                 return 0;
//             }

//             for (int d = 0; d < 9; d++)
//             {
//                 int nx = x + dx[d];
//                 int ny = y + dy[d];

//                 if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
//                     continue;
//                 if (board[nx][ny] == '#')
//                     continue;
//                 if (nx > 0 && board[nx - 1][ny] == '#')
//                     continue;

//                 if (!visited[nx][ny])
//                 {
//                     visited[nx][ny] = true;
//                     q.push({nx, ny});
//                 }
//             }
//         }

//         wallDown(); // 벽 이동

//         memset(visited, false, sizeof(visited));
//         time++;

//         if (time >= 8)
//         {
//             cout << 1;
//             return 0;
//         }
//     }

//     cout << 0;
//     return 0;
// }
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

typedef struct qu{
    int x;
    int y;
    char direct;
    int cnt;
}qu;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int main(){
    int n,m;
    char current;
    cin>>n>>m;

    vector<vector<char>> adj(n,vector<char>(m));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<int> output;
    queue<qu> q;

    FOR(i,0,n){
        FOR(j,0,m){
            cin>>adj[i][j];
            if (adj[i][j] == 'C'){
                q.push({i,j,'u',0});
                visited[i][j] = true;
            }
        }
    }
    
    int goalX = q.front().x;
    int goalY = q.front().y;
    visited[goalX][goalY] = false;
    q.pop();

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        char direct = q.front().direct;
        int cnt = q.front().cnt;
        q.pop();

        if (x == goalX && y == goalY){
            output.push_back(cnt);
            continue;
        }

        FOR(i,0,4){
            int nx = x+dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (visited[nx][ny] || adj[nx][ny] == '*') continue;
            if (i==0 || i==1){
                current = y;
                if (direct!=current) cnt++;
            }
            if (i==2 || i==3){
                current = x;
                if (direct!=current) cnt++;
            }
            if (direct == 'u') cnt--;

            q.push({nx,ny,current,cnt});
            visited[nx][ny] = true;
        }
    }
    sort(output.begin(),output.end());
    cout<<output[0];
    
    return 0;
}
