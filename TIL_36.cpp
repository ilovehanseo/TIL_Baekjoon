#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<memory>
#include<queue>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;

//최단 거리 구하기 dist idea
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

Vec<Vec<bool>> visited;

int Max=0;
queue<pair<int,int>> q;

void bfs(int n,int m,Vec<Vec<int>>& tomatoBox) {

    vector<vector<int>> dist(m,vector<int>(n,0));
    
    while (!q.empty()) {
        int tmpX = q.front().first;
        int tmpY = q.front().second;
        q.pop();
        //cout << node << " ";
        FOR(i,0,4){
            int Ax = tmpX+dx[i];
            int Ay = tmpY+dy[i];
            if (Ax>=0 && Ay>=0 &&Ax<n &&Ay<m && !visited[Ay][Ax] && tomatoBox[Ay][Ax]==0){
                visited[Ay][Ax] = true;
                tomatoBox[Ay][Ax] = 1;
                q.push({Ax,Ay});
                dist[Ay][Ax] = dist[tmpY][tmpX]+1;
                Max = max(dist[Ay][Ax],Max);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;  // 가로,세로

    Vec<Vec<int>> tomatoBox(m,Vec<int>(n,0));
    visited.resize(m,Vec<bool>(n,0));

    FOR(i,0,m){
        FOR(j,0,n){
            cin>>tomatoBox[i][j];
            if (tomatoBox[i][j]==1){
                q.push({j,i});
                visited[i][j]=true;
            }
        }
    }
    
    bfs(n,m,tomatoBox);

    FOR(i,0,m){
        FOR(j,0,n){
            if (tomatoBox[i][j]==0){
                cout<<-1;
                return 0;
            }
        }
    }

    cout<<Max;


    return 0;
}