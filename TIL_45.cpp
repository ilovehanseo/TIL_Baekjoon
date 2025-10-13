#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
#include <queue>
#include <cmath>
#include <map>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template <typename T>
using Vec = vector<T>;

//vector<vector<pair<int,int>>> tree;

//vector<vector<int>> tree;

//vector<int> parent;
vector<bool> visited;
map<int, vector<pair<int,int>>> tree;

int longest=0;
int longestNode=0;

void BFS(int node,int d){
    queue<pair<int,int>> q;
    q.push({node,d});
    visited[node]=true;

    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;

        q.pop();

        if (longest<dist){
            longest = dist;
            longestNode = node;
        }

        for (auto & i :tree[node]){
            if (!visited[i.first]){
                visited[i.first]=true;
                q.push({i.first,i.second+dist});
            }
        }
    }
    
}

// void DFS(int node,int dist){
//     longest = max(longest,dist);
    
//     for (auto & i : tree[node]){
//         DFS(i.first,i.second+dist);
//     }
// }

//map tree 사용
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,parent,child,weight;

    cin>>n;
    
    // tree.resize(n+1);
    // tree.shrink_to_fit();
    visited.assign(n+1,false);

    FOR(i,0,n){
        cin>>parent;
        while(true){
            cin>>child;
            if (child == -1) break;
            cin>>weight;
            
            tree[parent].emplace_back(child,weight);
            tree[child].emplace_back(parent,weight);
        }
    }

    BFS(1,0);

    //cout<<longest<<endl;
    //cout<<longestNode<<endl;

    visited.assign(n+1,false);
    longest=0;

    BFS(longestNode,0);

    cout<<longest;

    return 0;
}

