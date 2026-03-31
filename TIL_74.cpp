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
vector<int> human;
vector<int> arr;

void dfs(int next){
    DP[next][0] = 0;
    DP[next][1] = human[next];

    visited[next] = true;

    for (auto & i :tree[next]){
        if (!visited[i]){
            dfs(i);

            DP[next][0] += max(DP[i][1],DP[i][0]);
            DP[next][1] += DP[i][0];
        }
    }
}

void find(int node, int state)
{
    for (auto &i : tree[node])
    {
        if (!visited[i])
        {
            visited[i] = true;

            if (state == 0){ 
                find(i,1);
            }
            else{
                if (DP[i][0] < DP[i][1]){
                    arr.push_back(i);
                    find(i,0);
                }
                else{
                    find(i,1);
                }
            }
            // if (DP[i][0] < DP[i][1] && state == 1)
            // {
            //     arr.push_back(i);
            // }
            // else if (state == 0)
            // {
            //     state = 1;
            // }
            
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
    human.resize(n+1);

    FOR(i,1,n+1){
        cin>>human[i];
    }
    
    FOR(i,0,n-1){
        cin>>node1>>node2;
        tree[node1].emplace_back(node2);
        tree[node2].emplace_back(node1);
    }

    int r = 1;

    dfs(r);
    
    cout<<max(DP[r][0],DP[r][1])<<endl;

    visited.assign(n+1,false);
    visited[r] = true;

    if (DP[r][0] < DP[r][1]){
        arr.push_back(r);
        find(r , 0);
    }
    else{
        find(r , 1);
    }

    sort(arr.begin(),arr.end());
    
    for (auto & i : arr){
        cout<<i<<" ";
    }

    return 0;
}