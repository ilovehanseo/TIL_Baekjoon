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

vector<pair<int,int>> tree;

//vector<int> parent;
//map<int, vector<pair<int,int>>> tree;

vector<pair<int,int>> columecol;
int cnt=0;

void countInorder(int node,int depth){
    if (node == -1) return;
    countInorder(tree[node].first,depth+1);
    //colume[node] = ++cnt;
    cnt++;
    if (columecol[depth].first == 0){
        columecol[depth].first = cnt;
    }
    columecol[depth].second = cnt;

    countInorder(tree[node].second,depth+1);
}


// int height(int root, int node){
//     queue<pair<int,int>> q;
//     q.push({root,1});

//     nodeInfo[root]=1;

//     visited[root]=true;

//     while(!q.empty()){
//         int node = q.front().first;
//         int level = q.front().second;
//         q.pop();
        
//         int left = tree[node].first;
//         int right = tree[node].second;

//         if (left == node || right == node) return level;

//         if (left!=-1 && !visited[left]){
//             visited[left]=true;
//             q.push({left,level+1});
//             nodeInfo[left]=level+1;

//         }
//         if (right!=-1 && !visited[right]){
//             visited[right]=true;
//             q.push({right,level+1});
//             nodeInfo[right]=level+1;
//         }
//     }
// }

//map tree 사용
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,node,left,right;

    cin>>n;
    
    tree.resize(n+1);
    columecol.resize(n+1);

//자식으로 등장하지 않는 노드가 루트노드
    vector<bool> findRootNode(n+1,false);

    FOR(i,0,n){
        cin>>node>>left>>right;
        tree[node].first = left;
        tree[node].second= right;
        if (left!=-1) findRootNode[left]=true;
        if (right!=-1) findRootNode[right]=true;
    }
    
    auto it = find_if(findRootNode.begin()+1,findRootNode.end(),
    [](bool value) { return value==false; }
);

    int root = distance(findRootNode.begin(),it);

    countInorder(root,1);

    int Max=0;
    int dep=0;

    FOR(i,1,n+1){
        if (columecol[i].first == 0) break;

        int width = columecol[i].second - columecol[i].first + 1;

        if (Max<width){
            Max = width;
            dep = i;
        }
    }

    cout<<dep<<" "<<Max;

    return 0;
}

