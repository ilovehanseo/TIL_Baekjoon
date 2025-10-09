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


//조건에 맞는 입력은 모두 큐에 저장해놨다가 한번에 영역 전개하기 ( 토마토 7576번 )
// vector<vector<int>> dist;
// vector<vector<bool>> visited;
// vector<vector<int>> tomatoBox;

// const int aX[4] = {-1,0,1,0};
// const int aY[4] = {0,1,0,-1};

// int n,m;

// int result=0;

// queue<pair<int,int>> q;

// void bfs() {

//     while(!q.empty()){
//         int qX = q.front().first;
//         int qY = q.front().second;

//         q.pop();

//         FOR(i,0,4){
//             int tmpX = aX[i]+qX;
//             int tmpY = aY[i]+qY;

//             if (tmpX<0 || tmpX>=m ||tmpY<0 || tmpY>=n) continue; 

//             if (visited[tmpY][tmpX]) continue;

//             if (tomatoBox[tmpY][tmpX] ==-1 ||  tomatoBox[tmpY][tmpX] == 1) continue;

//             tomatoBox[tmpY][tmpX] = 1;
            
//             q.push({tmpX,tmpY});

//             visited[tmpY][tmpX] =true;

//             dist[tmpY][tmpX] = dist[qY][qX]+1;

//             result = max(dist[tmpY][tmpX],result);
//         }
    
        
//     }
// }


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin>>m>>n;  //가로 , 세로
//     //정점,간선

    
//     visited.resize(n,vector<bool>(m,0));
//     dist.resize(n,vector<int>(m,0));
//     tomatoBox.resize(n,vector<int>(m,0));

//     FOR(i,0,n){
//         FOR(j,0,m){#include<iostream>
// #include<algorithm>
// #include<vector>
// #include<utility>
// #include<memory>
// #include<queue>
// #define FOR(i, a, b) for (int i = (a); i < (b); ++i)

// using namespace std;

// template<typename T>
// using Vec = vector<T>;

// vector<vector<int>> dist;
// vector<vector<bool>> visited;
// vector<vector<int>> tomatoBox;

// const int aX[4] = {-1,0,1,0};
// const int aY[4] = {0,1,0,-1};

// int n,m;

// int result=0;

// queue<pair<int,int>> q;

// void bfs(int node) {
    
//     while(!q.empty()){
//         int qX = q.front().first;
//         int qY = q.front().second;

//         q.pop();

//         FOR(i,0,4){
//             int tmpX = aX[i]+qX;
//             int tmpY = aY[i]+qY;

//             if (tmpX<0 || tmpX>=m ||tmpY<0 || tmpY>=n) continue; 

//             if (visited[tmpY][tmpX]) continue;

//             if (tomatoBox[tmpY][tmpX] ==-1 ||  tomatoBox[tmpY][tmpX] == 1) continue;

//             tomatoBox[tmpY][tmpX] = 1;
            
//             q.push({tmpX,tmpY});

//             visited[tmpY][tmpX] =true;

//             dist[tmpY][tmpX] = dist[qY][qX]+1;

//             result = max(dist[tmpY][tmpX],result);
//         }
    
        
//     }
// }


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin>>m>>n;  //가로 , 세로
//     //정점,간선

    
//     visited.resize(n,vector<bool>(m,0));
//     dist.resize(n,vector<int>(m,0));
//     tomatoBox.resize(n,vector<int>(m,0));

//     FOR(i,0,n){
//         FOR(j,0,m){
//             cin>>tomatoBox[i][j];
//             if (tomatoBox[i][j] ==1){
//                 q.push({j,i});
//             }
//         }
//     }

//     bfs();


//     FOR(i,0,n){
//         FOR(j,0,m){
//             if (tomatoBox[i][j]==0){
//                 cout<<-1;
//                 return 0;
//             }
//         }
//     }

//     cout<<result;

//     return 0;
// }

//             cin>>tomatoBox[i][j];
//             if (tomatoBox[i][j] ==1){
//                 q.push({j,i});
//             }
//         }
//     }

//     bfs();


//     FOR(i,0,n){
//         FOR(j,0,m){
//             if (tomatoBox[i][j]==0){
//                 cout<<-1;
//                 return 0;
//             }
//         }
//     }

//     cout<<result;

//     return 0;
// }

vector<bool> visited;
vector<vector<int>> graph;
vector<int> input;
vector<int> arr;

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        arr.emplace_back(tmp);

        for (auto & i : graph[tmp]){
            if (!visited[i]){
                    q.push(i);
                    visited[i]=true;
                
                

            }
        }
    }
}

int main(){
    int n,a,b;
    cin>>n;

    visited.assign(n+1,false);
    graph.assign(n+1,{});
    input.assign(n,0);
    vector<int> pos(n+1,0);

    FOR(i,0,n-1){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    FOR(i,0,n){
        cin>>input[i];
        pos[input[i]] = i; //각 노드의 등장 순서를 저장
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(),
            [&](int a, int b) { return pos[a] < pos[b]; });
    }

    bfs(1);

    // for (auto & i : arr){
    //     cout<<i<<" ";
    // }
    //cout<<'\n';
        if (input == arr){
            cout<<1;
        }
        else{
            cout<<0;
        }

    

    return 0;
}