#include <iostream>
#include <vector>
#include<queue>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

vector<vector<int>> map;
vector<vector<int>> land;
vector<vector<bool>> visited;
vector<vector<vector<bool>>> owner;


queue<pair<int,int>> q;
queue<pair<pair<int,int>,int>> qq;

int n,output = 100000000;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int cnt){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        FOR(i,0,4){
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax>=n || ax<0 || ay>=n || ay<0) continue;

            if (map[ay][ax] == 0 || visited[ay][ax]) continue;

            land[ay][ax] = cnt;
            visited[ay][ax] = true;
            q.push({ax,ay});
        }
    }
}

void dfs(int x, int y, int depth) {
    int landNum = land[y][x];

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if (visited[ny][nx]) continue;

        if (landNum !=land[ny][nx] && land[ny][nx]){
            output = min(output,depth);
            return;
        }
        visited[ny][nx] = true;
        dfs(nx,ny,depth+1);
    }
}


void BFS2(){
    while(!qq.empty()){
        int x = qq.front().first.first;
        int y = qq.front().first.second;
        int dist = qq.front().second;
        int landnum = land[y][x];
        owner[landnum][y][x] = true;
        qq.pop();

        FOR(i,0,4){
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax>=n || ax<0 || ay>=n || ay<0) continue;

            if (owner[landnum][ay][ax]) continue;

            if (land[ay][ax] == land[y][x]) continue;

            if (land[ay][ax] && land[ay][ax] != land[y][x]){  //다른 섬과 연결되었을 때
                cout<<dist+1;
                return;
            }

            qq.push({{ax,ay},dist+1});
            owner[landnum][ay][ax] = true;

        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    map.assign(n,vector<int>(n,0));
    land.assign(n,vector<int>(n,0));
    visited.assign(n,vector<bool>(n,false));
    
    int cnt =0;

    FOR(i,0,n){
        FOR(j,0,n){
            cin>>map[i][j];
            if (map[i][j]){
                qq.push({{i,j},0});
            }
        }
    }

    FOR(i,0,n){
        FOR(j,0,n){
            if (map[i][j] == 1 && !visited[i][j]){
                cnt++;
                q.push({j,i});
                visited[i][j] = true;
                BFS(cnt);
            }
        }
    }

    owner.assign(cnt,vector<vector<bool>>(n,vector<bool>(n,false)));

    BFS2();

    return 0;
}