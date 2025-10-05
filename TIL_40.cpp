#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
#include <queue>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template <typename T>
using Vec = vector<T>;

// 최단 거리 구하기 dist idea
// const int dx[4] = {0, 1, 0, -1};
// const int dy[4] = {1, 0, -1, 0};

// queue<pair<int,int>> q; //q[y][x]

//int xsize, ysize;

//DFS 부모 노드 활용, continue로 먼저 조건 제거후 bfs탐색

//항상 전체 탐색인지, 초반 0,0만 탐색하는지 구분하기
// void dfs(int n, int m, int parentN, int parentM, char color, Vec<Vec<char>> &gameBoard)
// {
//     visited[m][n] = true;
//     // cout << node << " ";  // 방문 확인용 출력

//     // if (depth == 4)
//     // {
//     //     check = true;
//     //     return;
//     // }

//     for (int i = 0; i < 4; i++)
//     {
//         if (check)
//             return;
//         int nextX = dx[i] + n;
//         int nextY = dy[i] + m;

//         if (nextX < 0 || nextX >= xsize || nextY < 0 || nextY >= ysize)
//             continue;

//         char c = gameBoard[nextY][nextX];

//         if (color != c)
//             continue;

//         if (parentN == nextX && parentM == nextY)
//             continue;

//         if (!visited[nextY][nextX])
//         {
//             dfs(nextX, nextY, n, m, c, gameBoard);
//         }
//         else
//         { // 사이클 발견
//             check = true;
//             return;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> ysize >> xsize; // 세로,가로

//     Vec<Vec<char>> gameBoard(ysize, Vec<char>(xsize));
//     visited.resize(ysize, Vec<bool>(xsize, false));

//     FOR(i, 0, ysize)
//     {
//         FOR(j, 0, xsize)
//         {
//             cin >> gameBoard[i][j];
//         }
//     }

//     FOR(i, 0, ysize)  //전체 탐색
//     {
//         FOR(j, 0, xsize)
//         {
//             if (!visited[i][j] && !check)
//             {
//                 dfs(j, i, -1, -1, gameBoard[i][j], gameBoard);
//             }
//         }
//     }

//     if (check)
//     {
//         cout << "Yes";
//     }
//     else
//     {
//         cout << "No";
//     }

//     return 0;
// }
// 1 - 2 - 3 - 4 - 6
vector<vector<int>> graph;
vector<bool> IncycleNode;
vector<bool> visited;
vector<int> parent;

//사이클에 속한 노드들을 true로 만들기
void IsInCycle(int node,int parentNode){
    visited[node]=true;
    parent[node] = parentNode; 

    for(auto &i :graph[node]){
        if (parentNode == i ) continue;

        if (visited[i]) { 
            int curr = node;
            IncycleNode[i]=true;
           while(true){
            if (curr == i || curr==-1){
                break;
            }
            IncycleNode[curr] = true;
            curr = parent[curr];
           }
        }
        else{
            IsInCycle(i,node);
        }
    }
}


int bfs(int node){
    if (IncycleNode[node]) return 0;  //순환 그래프 안에 있으면 
    queue<pair<int,int>> q;
    vector<bool> visited(graph.size(),false);
    q.push({node,0});
    visited[node]=true;

    while(!q.empty()){
        int station = q.front().first;
        int dist = q.front().second;
        q.pop();

        for(auto& i : graph[station]){
            if (visited[i]) continue;
            if (IncycleNode[i]){
                return dist+1;
            }    
            visited[i]=true;
            q.push({i,dist+1});
        }
    }

    return 0;
}

int main(){
    int n;
    cin>>n;

    int a,b;

    graph.resize(n+1);
    visited.assign(n+1,false);
    parent.assign(n+1,-1);
    IncycleNode.assign(n+1,false);

    FOR(i,0,n){
        cin>>a>>b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    IsInCycle(1,-1);
    

    FOR(i,1,n+1){
        cout<<bfs(i)<<" ";
    }
    


    return 0;
}