#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<limits>
#include<cmath>
#include<queue>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n,m;
//     cin>>n>>m;

//     vector<vector<int>> adj(n,vector<int>(m,0));
//     vector<vector<bool>> visited(n,vector<bool>(m,false));
//     visited[0][0] = true;

//     FOR(i,0,n){
//         string s;
//         cin>>s;
//         FOR(j,0,m){
//             adj[i][j] = s[j]-'0';
//         }
//     }

//     const int dx[4] = {1,-1,0,0};
//     const int dy[4] = {0,0,1,-1};

//     queue<pair<pair<int,int>,int>> q;
//     q.push({{0,0},1});

//     while(!q.empty()){
//         int x = q.front().first.first;
//         int y = q.front().first.second;
//         int dist = q.front().second;
//         q.pop();

//         if (x == n-1 && y == m-1){
//             cout<<dist<<'\n';
//             return 0;
//         }

//         FOR(i,0,4){
//             int nx = x+dx[i];
//             int ny = y+dy[i];

//             if (nx>=0 && ny>=0 && nx<n &&ny<m && !visited[nx][ny] && adj[nx][ny]==1){
//                 visited[nx][ny] = true;
//                 q.push({{nx,ny},dist+1});
            
//             }
//         }
//     }
    

//     return 0;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;
    cin>>a>>b>>c;

    queue<pair<int,int>> q;
    q.push({a,b});

    vector<vector<bool>> visited(1501,vector<bool>(1501,false));
    visited[a][b] = true;

    int n,m;
    int total = a+b+c;

    while(!q.empty()){
        //first // rest 경우
        int X = q.front().first;
        int Y = q.front().second;
        int Z = total - X - Y;
        q.pop();
        
        if (X == Y && Y == Z){
            cout<<1<<'\n';
            return 0;
        }
        
        //X,Y를 고를 경우
        int small = min(X,Y);
        int large = max(X,Y);

        n = small + small;
        m = large - small;

        if (!visited[n][m]){
            q.push({n,m});
            visited[n][m] = true;
        }
        //Y,Z를 고를 경우
        small = min(Y,Z);
        large = max(Y,Z);

        n = small + small;
        m = large - small;

        if (!visited[n][m]){
            q.push({n,m});
            visited[n][m] = true;
        }

        //X,Z를 고를 경우
        small = min(X,Z);
        large = max(X,Z);
        n = small + small;
        m = large - small;
        if (!visited[n][m]){
            q.push({n,m});
            visited[n][m] = true;
        }

        
    }

    cout<<0<<'\n';

    return 0;
}