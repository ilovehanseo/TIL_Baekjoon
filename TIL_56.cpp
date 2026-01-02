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

vector<vector<char>> adj;
vector<vector<bool>> visited;

queue<pair<int,int>> water;
queue<pair<int,int>> dochi;
queue<pair<int,int>> nextWater;

queue<int> q;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int n,m;

void fillWater(){
    while(!water.empty()){
        int x = water.front().first;
        int y = water.front().second;
        water.pop();

        FOR(i,0,4){
            int waterX = x+dx[i];
            int waterY = y+dy[i];
            if (waterX>=0 && waterX<n && waterY>=0 && waterY<m){
                if (!visited[waterX][waterY] && adj[waterX][waterY]!='D'){
                    visited[waterX][waterY] = true;
                    nextWater.push({waterX,waterY});
                }
            }
        }
    }
}

void BFS(int goalX,int goalY){
    while(!dochi.empty()){
        fillWater();
        water = nextWater;
        nextWater = queue<pair<int,int>>();

        int x = dochi.front().first;
        int y = dochi.front().second;
        int cnt = q.front();
        if (x == goalX && y == goalY){
            cout<<cnt<<'\n';

            return;
        }

        FOR(i,0,4){
            int dochiX = x+dx[i];
            int dochiY = y+dy[i];
            if (dochiX>=0 && dochiX<n && dochiY>=0 && dochiY<m){
                if (!visited[dochiX][dochiY]){
                    visited[dochiX][dochiY] = true;
                    dochi.push({dochiX,dochiY});
                    q.push(cnt+1);
                }
            }

        }
    }
    cout<<"KAKTUS"<<'\n';
}

int main(){
    cin>>n>>m;
    adj.assign(n,vector<char>(m));
    visited.assign(n,vector<bool>(m,false));
    char input;
    int tmpX,tmpY;
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>input;
            adj[i][j] = input;
            if (input == 'X'){
                visited[i][j]= true;
            }
            if (input == 'S'){
                dochi.push({i,j});
                visited[i][j] = true;
            }
            if (input == '*'){
                water.push({i,j});
                visited[i][j] = true;
            }
            if (input == 'D'){
                tmpX = i;
                tmpY = j;
            }
        }
    }
    BFS(tmpX,tmpY);

    return 0;
}


//visited 분리버전

vector<vector<char>> adj;
vector<vector<bool>> waterVisited;
vector<vector<bool>> dochiVisited;

queue<pair<int,int>> water;
queue<pair<int,int>> dochi;
queue<pair<int,int>> nextWater;
queue<int> q;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int n,m;

void fillWater(){
    while(!water.empty()){
        auto [x,y] = water.front();
        water.pop(); 

        FOR(i,0,4){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(!waterVisited[nx][ny] && adj[nx][ny]=='.'){
                    waterVisited[nx][ny] = true;
                    nextWater.push({nx,ny});
                }
            }
        }
    }
}

void BFS(int goalX,int goalY){
    while(!dochi.empty()){
        // 1️⃣ 물 먼저 확장
        fillWater();
        water = nextWater;
        nextWater = queue<pair<int,int>>();

        int sz = dochi.size();
        while(sz--){
            int x = dochi.front().first;
            int y = dochi.front().second;
            int cnt = q.front();
            dochi.pop();
            q.pop();

            if(x == goalX && y == goalY){
                cout << cnt << '\n';
                return;
            }

            FOR(i,0,4){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(!dochiVisited[nx][ny] &&
                       !waterVisited[nx][ny] &&
                       (adj[nx][ny]=='.' || adj[nx][ny]=='D')){
                        dochiVisited[nx][ny] = true;
                        dochi.push({nx,ny});
                        q.push(cnt+1);
                    }
                }
            }
        }
    }
    cout << "KAKTUS\n";
}

int main(){
    cin >> n >> m;

    adj.assign(n, vector<char>(m));
    waterVisited.assign(n, vector<bool>(m,false));
    dochiVisited.assign(n, vector<bool>(m,false));

    int goalX, goalY;

    FOR(i,0,n){
        FOR(j,0,m){
            cin >> adj[i][j];

            if(adj[i][j] == 'X'){
                waterVisited[i][j] = true;
                dochiVisited[i][j] = true;
            }
            else if(adj[i][j] == '*'){
                water.push({i,j});
                waterVisited[i][j] = true;
            }
            else if(adj[i][j] == 'S'){
                dochi.push({i,j});
                q.push(0);
                dochiVisited[i][j] = true;
                adj[i][j] = '.'; //
            }
            else if(adj[i][j] == 'D'){
                goalX = i;
                goalY = j;
            }
        }
    }

    BFS(goalX, goalY);
    return 0;
}

// int n;
// vector<vector<int>> adj;
// vector<int> fish(7,0);

// typedef struct st{
//     int x;
//     int y;
//     int fishSize;
//     int dist;
//     int eatCnt;
// }st;

// const int dx[4] = {1,-1,0,0};
// const int dy[4] = {0,0,1,-1};

// bool check(int fishSize){
//     for (int i = fishSize;i>0;i--){
//         if (fish[i]!=0) return false;
//     }
//     return true;
// }

// void BFS(int xx,int yy){
//     queue<st> q;
//     q.push({xx,yy,2,0,0});
    

//     while(!q.empty()){
//         int x = q.front().x;
//         int y = q.front().y;
//         int fishSize = q.front().fishSize;
//         int dist = q.front().dist;
//         int eatCnt = q.front().eatCnt;
//         q.pop();

//         if (check(fishSize)){
//             cout<<dist;
//             return;
//         }

//         if (fishSize == eatCnt){
//             fishSize++;
//         }
    
//         FOR(i,0,4){
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if(nx>=0 && nx<n && ny>=0 && ny<n){  //잡아먹는 경우 , 그냥 지나가는 경우
//                 if(adj[nx][ny]<fishSize && adj[nx][ny] >=1 && adj[nx][ny]<=6){
//                     fish[adj[nx][ny]]--;
//                     q.push({nx,ny,fishSize,dist+1,eatCnt+1});
//                 }
//                 else if (adj[nx][ny] == fishSize || adj[nx][ny] == 0){
//                     q.push({nx,ny,fishSize,dist+1,eatCnt});
//                 }
//             }
//         }
//     }
// }


// int main(){
//     cin>>n;
//     adj.assign(n,vector<int>(n));
//     int input,xx,yy;
//     FOR(i,0,n){
//         FOR(j,0,n){
//             cin>>input;
//             if (input>=1 && input<=6){
//                 fish[input]++;
//             }
//             if (input == 9){
//                 xx = i;
//                 yy =j;
//             }
//             adj[i][j] = input;
//         }
//     }
//     BFS(xx,yy);

//     return 0;
// }
