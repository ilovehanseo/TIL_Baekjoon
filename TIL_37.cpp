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


vector<vector<int>> graph;
vector<bool> visited;
vector<vector<bool>> Map;

bool check=false;

void dfs(int node,int depth) {
    visited[node] = true;
    //cout << node << " ";  // 방문 확인용 출력

    if (depth == 5){
        check=true;
        return;
    }

    for (auto& next : graph[node]) {
        if (check){
            return;
        }
         if (!visited[next]) {
             dfs(next,depth+1);
         }
    }
    visited[node]=false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b;
    cin>>n>>m;  
    //정점,간선
    vector<int> tmp;
    graph.resize(n);
    visited.resize(n,false);

    FOR(i,0,m){
        cin>>a>>b;
        tmp.emplace_back(a);
        tmp.emplace_back(b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    sort(tmp.begin(),tmp.end());
    // for(auto& i :tmp){
    //     cout<<i<<" ";
    // }

    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());  //중복제거 STL

    for(auto& i :tmp){
       // visited.assign(n,false); -> 빽트래킹으로 초기화
        dfs(i,1);
        if (check){ 
            cout<<1;
            return 0;
        }
    }

    cout<<0;
    

    return 0;
}
