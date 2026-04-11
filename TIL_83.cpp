#include <iostream>
#include <vector>
#include<queue>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

vector<vector<int>> map;
vector<vector<vector<bool>>> visited;

struct Robot
{
    int x;
    int y;
    int k;
    int command;
};

queue<Robot> q;

const int dx[5] = {0, 1, -1, 0, 0};   //동 서 남 북
const int dy[5] = {0, 0, 0, 1, -1};

void BFS(int n,int m,int endX,int endY,int way){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int k = q.front().k;
        int command = q.front().command;
        q.pop();

        if ((x == endX-1 && y == endY-1) && way == k){
            cout<<command;
            return;
        }

        FOR(i,1,4){ // 명령 1
            int ax = x + dx[k]*i;
            int ay = y + dy[k]*i;
            if (ax>=m || ax<0 || ay>=n || ay<0) break;

            if (map[ay][ax] == 1) break;

            if (visited[ay][ax][k]) continue;

            visited[ay][ax][k] = true;
            q.push({ax,ay,k,command+1});
        }
        //명령 2 , turn left,right
        int tmpk1,tmpk2;
        if (k==1 || k==2){
            tmpk1 = 4;
            
            tmpk2 = 3;
        }
        else{
            tmpk1 = 1;
            
            tmpk2= 2;
        }

        if (!visited[y][x][tmpk1]){            
            visited[y][x][tmpk1] = true;
            q.push({x,y,tmpk1,command+1});
        }
        if (!visited[y][x][tmpk2]){            
            visited[y][x][tmpk2] = true;
            q.push({x,y,tmpk2,command+1});
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;  //세로길이, 가로길이

    map.assign(n,vector<int>(m,0));
    visited.assign(n,vector<vector<bool>>(m,vector<bool>(5,false)));
    
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>map[i][j];
        }
    }
    int a,b,k; // 행 열 방향
    cin>>a>>b>>k;
    q.push({b-1,a-1,k,0});
    visited[a-1][b-1][k] = true;

    cin>>a>>b>>k;

    BFS(n,m,b,a,k);
    
    return 0;
}