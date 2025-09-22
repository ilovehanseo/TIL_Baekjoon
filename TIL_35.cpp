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

//Vec<Vec<int>> board;

//const Vec<Vec<Vec<bool>>> Shape(5,vector<int>(4),vector<vector<bool>>(4,0));
// const Vec<Vec<bool>> Shape2(4,vector<bool>(4,0));
// const Vec<Vec<bool>> Shape3(4,vector<bool>(4,0));
// const Vec<Vec<bool>> Shape4(4,vector<bool>(4,0));
// const Vec<Vec<bool>> Shape5(4,vector<bool>(4,0));

// const int Shape1[2][4][4]= { 
//     {{0,0} , {0,1} , {0,2}, {0,3}},
//     {{0,0} , {1,0},{2,0},{3,0}}
// };
// const int Shape2[1][4][4]= { 
//     {{0,0} , {0,1} , {1,0}, {1,1}}
// };
// const int Shape3[5][4][4]= { 
//     {{0,0} , {1,0} , {2,0}, {2,1}},
//     {{0,0} , {0,1} , {0,2}, {1,2}},
//     {{0,0} , {0,1} , {0,2}, {1,0}},
//     {{0,0} , {0,1} , {1,1}, {2,1}},
//     {{0,0} , {0,1} , {1,0}, {2,0}}
// };
// const int Shape4[2][4][4]= { 
//     {{0,0} , {1,0} , {1,1}, {2,1}},
//     {{0,0} , {0,1},{1,1},{1,2}}
// };
// const int Shape5[2][4][4]= { 
//     {{0,0} , {0,1} , {0,2}, {1,1}},
//     {{0,0} , {1,0},{2,0},{1,1}}
// };

// int Sum=0,Max=0;
// vector<int> output;

// void getMaxProfit(int count,int n,vector<pair<int,int>> schedule){
//     if (count >= n){
//         if (count>n){
//             output.pop_back();
//         }
//         for(auto & i :output){
//             Sum+=i;
//         }
//         Max = max(Sum,Max);
//         return;
//     }
//     for(int i=count;i<=n;i++){
//         output.push_back(schedule[i].first);
//         getMaxProfit(count+schedule[i].second,n,schedule);
//         output.pop_back();
//     }
// }

//위에건 무시하셈

vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<vector<bool>> Map;

// void dfs(int node) {
//     visited[node] = true;
//     //cout << node << " ";  // 방문 확인용 출력

//     for (auto& next : graph[node]) {
//         if (!visited[next]) {
//             dfs(next);
//         }
//     }
// }



// 단지번호 붙이기 BFS
// const int dx[4] = {0,1,0,-1};
// const int dy[4] = {1,0,-1,0};

// int bfs(int x,int y,int size) {
//     queue<pair<int,int>> q;
//     visited[x][y] = true;
//     q.push({x,y});

//     int cnt=1;

//     while (!q.empty()) {
//         int tmpX = q.front().first;
//         int tmpY = q.front().second;
//         q.pop();
//         //cout << node << " ";

//         FOR(i,0,4){
//             int Ax = tmpX+dx[i];
//             int Ay = tmpY+dy[i];
//             if (Ax>=0 && Ay>=0 &&Ax<size &&Ay<size && !visited[Ax][Ay] && Map[Ax][Ay]){
//                 visited[Ax][Ay] = true;
//                 q.push({Ax,Ay});
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }


//나이트 옮기기 BFS
// const int dx[8] = {-2,-1,1,2,-2,-1,1,2};
// const int dy[8] = {1,2,2,1,-1,-2,-2,-1};

// int bfs(int x,int y,int size,int Ax,int Ay) {
//     vector<vector<bool>> visited(size,vector<bool>(size,false));  

//     queue<pair<pair<int,int>,int>> q;
//     visited[x][y] = true;
//     q.push({{x,y},0});

//     while (!q.empty()) {
//         int x = q.front().first.first;
//         int y = q.front().first.second;
//         int dist = q.front().second;
//         q.pop();
//        // cout << node << " ";   // 탐색 순서 출력
//         if (Ax == x && Ay == y){
//                 return dist;
//         }

//         FOR(i,0,8){
//             int tmpX = x+dx[i];
//             int tmpY = y+dy[i];

//             if (tmpX>=0 && tmpY>=0 && tmpX<size && tmpY<size && !visited[tmpX][tmpY]){
//                 visited[tmpX][tmpY] = true;
//                 q.push({{tmpX,tmpY},dist+1});
//             }
//         }
//         // for (auto& next : graph[node]) {
//         //     if (!visited[next]) {
//         //         visited[next] = true;
//         //         q.push(next);
//         //     }
//         // }
//     }
//     return -1;
// }

//섬의 개수 DFS
// const int dx[8] = {-1,0,1,1,1,0,-1,-1};
// const int dy[8] = {1,1,1,0,-1,-1,-1,0};
// void dfs(int h,int w,int hSize,int wSize) {
//     visited[h][w] = true;
//     //cout << node << " ";  // 방문 확인용 출력

//     FOR(i,0,8){
//         int tmpX = w+dx[i];
//         int tmpY = h+dy[i];
//         if (tmpX>=0 && tmpY>=0 &&tmpX<wSize &&tmpY<hSize && !visited[tmpY][tmpX] && Map[tmpY][tmpX] ){
//             dfs(tmpY,tmpX,hSize,wSize);
//         }
//     }
// }

//최단 거리 구하기 dist idea
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

int bfs(int y,int x) {
    queue<pair<int,int>> q;
    visited[0][0] = true;
    q.push({0,0});

    vector<vector<int>> dist(y,vector<int>(x,1));


    while (!q.empty()) {
        int tmpX = q.front().first;
        int tmpY = q.front().second;
        q.pop();
        if (tmpX == x-1 && tmpY == y-1){ return dist[tmpY][tmpX]; }
        //cout << node << " ";
        FOR(i,0,4){
            int Ax = tmpX+dx[i];
            int Ay = tmpY+dy[i];
            if (Ax>=0 && Ay>=0 &&Ax<x &&Ay<y && !visited[Ay][Ax] && Map[Ay][Ax]){
                visited[Ay][Ax] = true;
                q.push({Ax,Ay});
                dist[Ay][Ax] = dist[tmpY][tmpX]+1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;  // n->세로 , m -> 가로

    Map.resize(n,vector<bool>(m,false));
    visited.resize(n,vector<bool>(m,false));

    FOR(i,0,n){
        string str;
        cin>>str;
        FOR(j,0,m){
            Map[i][j] = str[j] -'0';
        }
    }
    cout<<bfs(n,m);
    // FOR(i,0,m){
    //     cin>>a>>b;
    //     graph[a].push_back(b);
    //     graph[b].push_back(a);
    // }
    // FOR(i,1,n+1){
    //     sort(graph[i].begin(),graph[i].end());
    // }

    

    return 0;
}
