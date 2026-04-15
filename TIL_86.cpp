#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

const int MAX = 1e9;

vector<vector<pair<int,int>>> tree;
vector<int> dist;
vector<int> parent;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,startNode,endNode;

    cin>>n>>m;

    tree.resize(n+1);
    dist.assign(n+1,MAX);
    parent.assign(n+1,0);

    FOR(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        tree[a].push_back({b,w});
    }

    cin>>startNode>>endNode;

    priority_queue<pair<int,int>> pq;
    
    pq.push({0,startNode});
    dist[startNode] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost) continue;

        for (auto & i : tree[node]){
            int there = i.first;
            int nextDist = cost + i.second;
            
            if (dist[there] > nextDist){
                dist[there] = nextDist;
                parent[there] = node;
                pq.push(make_pair(-nextDist,there));
            }
        }
    }
    cout<<dist[endNode]<<'\n';
    
    vector<int> path;

    while(true){
        path.push_back(endNode);
        if (endNode == startNode) break;
        int node = parent[endNode];
        endNode = node;
    }
    cout<<path.size()<<'\n';
    
    reverse(path.begin(),path.end());

    for(auto & i :path){
        cout<<i<<" ";
    }

    return 0;
}