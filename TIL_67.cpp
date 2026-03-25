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

vector<pair<int,int>> tree[1001];
vector<bool> visited;

int cnt=0;
int sum=0;

int bfs(int start,int end){
    queue<pair<int,int>> q;
    q.push({start,0});
    visited[start] = true;

    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (node == end) {
            return dist;
        }

        for (auto & i :tree[node]){
            int N = i.first;
            int D = i.second;

            if (!visited[N]){
                visited[N] = true;
                q.push({N,dist+D});
            }
        }
    }
    
    return 0;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,n1,n2,dist;

    cin>>n>>m;

    visited.assign(n+1,false);

    FOR(i,0,n-1){
        cin>>n1>>n2>>dist;
        tree[n1].push_back({n2,dist});
        tree[n2].push_back({n1,dist});
    }

    int m1,m2;
    
    FOR(i,0,m){
        cin>>m1>>m2;
        sum=0;
        FOR(i,1,n+1){
            visited[i] = false;
        }
        
        cout<<bfs(m1,m2)<<'\n';
    }

    return 0;
}