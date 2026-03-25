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

//vector<pair<char,char>> tree;
vector<int> depth;
vector<vector<pair<int,int>>> tree;
vector<bool> visited;
vector<int> parent;
vector<int> Dist;

void CountDepth(int root){
    queue<pair<int,int>> q;
    q.push({root,0});
    visited[root] = true;
    depth[root] = 0;

    while(!q.empty()){
        int node = q.front().first;
        int dep = q.front().second;
        q.pop();
        
        for(auto & [next,dist] :tree[node]){
            if (!visited[next]){
                visited[next] = true;
                q.push({next,dep+1});
                depth[next] = dep+1;
                parent[next] = node;
                Dist[next] = dist + Dist[parent[next]]; // Dist[next] = dist + Dist[node]; 이게 더 깔끔한듯
            }
        }
    }
}

int LCA(int node1,int node2){
    while(depth[node1]!=depth[node2]){
        if (depth[node1]>depth[node2]){
            node1 = parent[node1];
            continue;
        }
        node2 = parent[node2];
    }

    while(node1!=node2){
        node1 = parent[node1];
        node2 = parent[node2];
    }
    return node1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,dist;

    cin>>n;

    tree.resize(n+1);
    visited.assign(n+1,false);
    depth.assign(n+1,0);
    parent.assign(n+1,0);
    Dist.assign(n+1,0); //루트부터의 거리

    FOR(i,0,n-1){
        int n1,n2;
        cin>>n1>>n2>>dist;
        tree[n1].push_back({n2,dist});
        tree[n2].push_back({n1,dist});
    }

    CountDepth(1);
    // FOR(i,1,n+1){
    //     cout<<i<<" = "<<Dist[i]<<endl;
    // }

    int m1,m2;
    
    cin>>m;
    FOR(i,0,m){
        cin>>m1>>m2;
        int lca = LCA(m1,m2);
        int output = Dist[m1] + Dist[m2] - Dist[lca]*2;
        cout<<output<<'\n';
    }

    return 0;
}