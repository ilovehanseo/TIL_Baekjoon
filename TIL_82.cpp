#include <iostream>
#include <vector>
#include<queue>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

vector<vector<int>> map;
vector<vector<vector<bool>>> visited;

struct Monkey
{
    int x;
    int y;
    int k;
    int dist;
};

queue<Monkey> q;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int hx[8] = {-2,-1,1,2,-2,-1,1,2};
const int hy[8] = {-1,-2,-2,-1,1,2,2,1};

int BFS(int n,int m){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int k = q.front().k;
        int dist = q.front().dist;
        q.pop();

        if (x == m-1 && y == n-1){
            return dist;
        }

        if (k != 0)
        {
            int tmp = k-1;
            FOR(i, 0, 8)
            {
                int ax = x + hx[i];
                int ay = y + hy[i];
                if (ax >= m || ax < 0 || ay >= n || ay < 0)
                    continue;

                if (map[ay][ax] == 1 || visited[ay][ax][tmp])
                    continue;

                visited[ay][ax][tmp] = true;
                q.push({ax, ay, tmp , dist + 1});
            }
        }

        FOR(i,0,4){
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax>=m || ax<0 || ay>=n || ay<0) continue;

            if (map[ay][ax] == 1 || visited[ay][ax][k]) continue;

            visited[ay][ax][k] = true;
            q.push({ax,ay,k,dist+1});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;

    cin >> k;
    
    cin>>m>>n;  //m이 가로 , n이 세로

    map.assign(n,vector<int>(m,0));
    visited.assign(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
    
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>map[i][j];
        }
    }

    q.push({0,0,k,0});
    visited[0][0][k] = true;

    cout<<BFS(n,m);

    return 0;
}