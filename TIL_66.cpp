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

vector<vector<int>> tree;
vector<bool> visited;
vector<int> arr;
vector<int> leafNode;

void BFS(int root){ //레벨별로 출력
    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for (auto & i :tree[node]){
            cout<<i<<" ";
            q.push(i);
        }
        cout<<'\n';
    }
}

void solve(int l, int r, int depth){
    if(l > r) return;

    int mid = (l + r) / 2;

    // level[depth]에 값 넣기
    tree[depth].emplace_back(arr[mid]);

    solve(l, mid - 1, depth + 1); //왼쪽
    solve(mid + 1, r, depth + 1); //오른쪽
}

int cnt=0;

void dfs(int node,int depth){
    int next = node;
    bool isLeaf = true;
    visited[next] = true;

    for (auto & i : tree[next]){
        if (!visited[i]){
            isLeaf = false;
            dfs(i,depth+1);
        }
    }

    if (isLeaf){
        cnt += depth;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,n1,n2;

    cin>>n;
    
    tree.resize(n+1);
    arr.assign(n+1,0);
    visited.assign(n+1,false);
    
    FOR(i,0,n-1){
        cin>>n1>>n2;
        tree[n1].emplace_back(n2);
        tree[n2].emplace_back(n1);
    }
    
    dfs(1,0);

    //cout<<cnt;

    if (cnt%2==0){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }

    return 0;
}