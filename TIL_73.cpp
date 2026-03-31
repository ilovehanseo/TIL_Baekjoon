#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
#include <queue>
#include <cmath>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template <typename T>
using Vec = vector<T>;

vector<vector<int>> tree;
vector<vector<int>> DP;
vector<bool> visited;

void dfs(int next){
    DP[next][0] = 0;
    DP[next][1] = 1;

    visited[next] = true;

    for (auto & i :tree[next]){
        if (!visited[i]){
            dfs(i);

            DP[next][0] += DP[i][1];
            DP[next][1] += min(DP[i][0],DP[i][1]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,node1,node2;
    cin>>n;

    tree.resize(n+1);
    DP.resize(n+1,vector<int>(2));
    visited.assign(n+1,false);
    
    FOR(i,0,n-1){
        cin>>node1>>node2;
        tree[node1].emplace_back(node2);
        tree[node2].emplace_back(node1);
    }

    int r = 1;

    dfs(r);
    
    cout<<min(DP[1][0],DP[1][1]);

    return 0;
}