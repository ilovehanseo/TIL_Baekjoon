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

int leafNode=0;

void BFS(int root,int deleteNode){
    int childNode=0;
    
    for (int next : tree[root]){
        if (next == deleteNode) continue;
        BFS(next,deleteNode);
        childNode++;
    }

    if (childNode == 0){
        leafNode++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,root,deleteNode;

    cin>>n;
    
    tree.resize(n);

    vector<int> parent(n);
    
    FOR(i,0,n){
        cin>>parent[i];
        if (parent[i] == -1){
            root = i;
        }
        else{
            tree[parent[i]].push_back(i);
        }
    }
    cin>>deleteNode;

    if (deleteNode == root){
        cout<<0;
        return 0;
    }

    BFS(root,deleteNode);

    cout<<leafNode;

    return 0;
}