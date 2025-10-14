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
template <typename T>
using Tree = vector<pair<T, T>>;

//10972 - 시간 초과 
// vector<bool> visited;
// vector<int> result;
// vector<int> input;

// int n;

// bool check = false;

// void dfs(int depth){
//     if (depth == n) {
    
//         if (check){
//             for (auto & i : result){ cout<<i<<" "; }
//             check=false;
//         }
        
//         if (input == result){ check = true; }

//         return;
//     }

//     FOR(i, 1, n+1){
//         if (!visited[i]){
//             visited[i] = true;
//             result.emplace_back(i);
//             dfs(depth+1); 
//             visited[i] = false;
//             result.pop_back();
//         }
//     }
// }

// int main(){
//     int m;
//     cin >> n;
//     visited.assign(n+1, false);
    
//     FOR(i,0,n){
//         cin>>m;
//         input.emplace_back(m);
//     }
    
//     dfs(0);

    

//     return 0;
// }

vector<bool> visited;
vector<vector<int>> W;
int n,sum=0,after,result= 10000001 ,tmp;


void dfs(int before,int depth){

    if (depth == n ){
        if (W[before][tmp]==0) return;
        sum += W[before][tmp]; // 다시 처음으로 돌아오는 비용
        result = min(sum,result); 
        sum-=W[before][tmp];

        return;
    }

    FOR(i,0,n){
        if (!visited[i] && W[before][i]!=0){
            visited[i] = true;

            sum+=W[before][i];

            dfs(i , depth+1);

            visited[i]=false;

            sum-=W[before][i];
        }
    }
}

int main(){
    cin>>n;
    W.resize(n,vector<int>(n));
    visited.assign(n,false);

    FOR(i,0,n){
        FOR(j,0,n){
            cin>>W[i][j];
        }
    }

    FOR(i,0,n){
        visited[i] = true;
        tmp=i;
        dfs(i,1);
        visited[i]=false;
    }

    cout<<result;

    return 0;
}