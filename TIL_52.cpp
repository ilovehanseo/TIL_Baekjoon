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

typedef struct sq{
    int x;
    int y;
    int cnt;
    int day; //낮과 밤
}sq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> adj(n,vector<int>(m,0));
    //vector<vector<vector<vector<int>>>> dist(n,vector<vector<vector<int>>>(m,vector<vector<int>>(k+1,vector<int>(2,0)))); // x / y / 벽 / 낮과 밤 -> 메모리 초과 문제
    static int dist[1000][1000][11][2];

    dist[0][0][0][1] = 1; //1일땐 낮, 0일땐 

    FOR(i,0,n){
        string str;
        cin>>str;
        for (int j=0;j<m;j++){
            adj[i][j] = str[j]-'0';
        }
    }
    

    queue<sq> q;
    q.push({0,0,0,1});

    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt =q.front().cnt;
        int day = q.front().day;
        q.pop();        

        if (n-1 == x && m-1 == y){
            cout<<dist[x][y][cnt][day]<<'\n';
            return 0;
        }


        int tmpday = 1 - day;

        if (!day && dist[x][y][cnt][tmpday] == 0){  //밤일 경우 낮일때까지 기다리는 경우의 수
            dist[x][y][cnt][tmpday] = dist[x][y][cnt][day] +1;
            q.push({x,y,cnt,tmpday});            
        }

        FOR(i,0,4){
            int nx = x + dx[i];
            int ny = y + dy[i];

            

            if (nx >=0  && ny>=0 && nx<n && ny<m){
                if (adj[nx][ny] == 1){  //벽에 막힘
                    if (day){  //낮일 경우
                    if (cnt<k && dist[nx][ny][cnt+1][tmpday] == 0){ //벽을 부순적이 없고 방문한적이 없는 경우
                        dist[nx][ny][cnt+1][tmpday] = dist[x][y][cnt][day] +1;
                        q.push({nx,ny,cnt+1,tmpday});
                    }
                    }
                    // else{  //밤일 경우 낮일때까지 기다리는 경우의 수
                    //     if (dist[x][y][cnt][tmpday] == 0){
                    //         dist[x][y][cnt][tmpday] = dist[x][y][cnt][day] +1;
                    //         q.push({x,y,cnt,tmpday});
                    //     }
                    // }
                }
                if(adj[nx][ny] == 0){      //벽이 안막힌 경우
                    if (dist[nx][ny][cnt][tmpday] == 0){ //벽을 부순적이 있는지 없는지에 따라 방문처리
                        dist[nx][ny][cnt][tmpday] = dist[x][y][cnt][day] +1;
                        q.push({nx,ny,cnt,tmpday});
                    }
                }
            } 
        }
        
    }

    cout<<-1<<'\n';

    return 0;

}
