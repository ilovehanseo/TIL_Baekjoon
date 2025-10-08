#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

vector<vector<int>> graph;
vector<bool> visited;
//그래프 복습 (13023)

bool check=false;

// void dfs(int node,int depth){
//     visited[node] =true;

//     //  cout<<"depth = "<<depth<<'\n';
//     // cout<<"node = "<<node<<'\n';

//     if (depth>4){ check = true;
//         return;
//     }
   
//     for(auto & next : graph[node]){
//         if (check) { break; }
//         if (visited[next]) continue;
//         dfs(next,depth+1);
//     }
//     visited[node]=false;
// }

//그래프 복습 (1707)
//color 종류 1,0,-1
//1은 한 영역 표시 -1은 다른 영역, 0 은 색깔 칠해져있지 않음.

vector<int> color;

void dfs(int node){
    visited[node]=true;
    int NodeColor = color[node];
    for (auto & i : graph[node]){
        if (check) return;
        if (!visited[i]){ 
            color[i] = -color[node];
            dfs(i);
        }
        if (visited[i] && NodeColor == color[i]){
            check = true;
            return;
        }
    }
}

int main(){
    int testCnt;
    cin>>testCnt;
    int n,m;

    FOR(i,0,testCnt){
        check = false;
        cin>>n>>m;

        //FOR(i, 1, n + 1) graph[i].clear();
        visited.assign(n+1,false);
        color.assign(n+1,0);
        graph.assign(n+1,{});
        
        int a,b;

        for(int i=0;i<m;i++){
            cin>>a>>b;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
    
        FOR(i,1,n+1){
            if (!visited[i]) {
                color[i] = 1;
                dfs(i);
            }
        }

        if (check) {cout<<"NO"<<'\n';}
        else cout<<"YES"<<'\n';

    }

    return 0;
}