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
vector<vector<int>> tree;
vector<bool> visited;
vector<vector<int>> Bparent;

int MaxDepth = 18;

void binaryParent(int node){
    for (int i = MaxDepth ; i>0;i--){
        Bparent[node][i] = Bparent[Bparent[node][i-1]][i-1];
    }
}

void CountDepth(int root){
    queue<pair<int,int>> q;
    q.push({root,0});
    visited[root] = true;
    depth[root] = 0;

    while(!q.empty()){
        int node = q.front().first;
        int dep = q.front().second;
        q.pop();
        
        for(auto & i :tree[node]){
            if (!visited[i]){
                visited[i] = true;
                q.push({i,dep+1});
                depth[i] = dep+1;
                Bparent[i][0] = node;
                //binaryParent(i);
            }
        }
    }
}

int LCA(int node1,int node2){
    if (depth[node1] < depth[node2]){
        swap(node1,node2);
    }

    int diff = depth[node1] - depth[node2];   //depth 길이 맞추기
    FOR(i,0,MaxDepth){
        if (diff%2==1){
            node1 = Bparent[node1][i];
        }
        diff/=2;
    }

    if (node1 == node2){
        return node1;
    }

    for (int i = MaxDepth ; i>=0;i--){  //하
        if (Bparent[node1][i]!=Bparent[node2][i]){
            node1 = Bparent[node1][i];
            node2 = Bparent[node2][i];
        }
    }
    
    return Bparent[node1][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,node1,node2;
    cin>>n;

    tree.resize(n+1);
    visited.assign(n+1,false);
    depth.assign(n+1,0);
    Bparent.assign(n+1,vector<int>(MaxDepth+1,0));

    FOR(i,0,n-1){
        int n1,n2;
        cin>>n1>>n2;
        tree[n1].push_back({n2});
        tree[n2].push_back({n1});
    }

    CountDepth(1);

    for (int k = 1; k <= MaxDepth; k++) {
        for (int v = 1; v <= n; v++) {
            Bparent[v][k] = Bparent[Bparent[v][k-1]][k-1];
        }
    }
    cin>>m;

    FOR(i,0,m){
        cin>>node1>>node2;
        cout<<LCA(node1,node2)<<'\n';
    }

    return 0;
}
