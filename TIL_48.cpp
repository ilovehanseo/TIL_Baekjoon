#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<limits>
#include<cmath>
#include<queue>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

// bool match(const string & w, const string & s){
//     int pos = 0;
//     while(pos < s.size() && pos < w.size() && w[pos] == '?' || w[pos] == s[pos]){ pos++; }
    
//     if (pos == w.size()){ return pos == s.size(); }

//     if (w[pos]=='*'){
//         for (int skip =0;pos+skip<=s.size();++skip){
//             if (match(w.substr(pos+1),s.substr(pos+skip))) return true;
//         }
//     }
//     return false;
// }

vector<bool> visited;
vector<int> ladder;
vector<int> snack;

// int n,sum=0,Max,cnt=0;

// void dfs(int before,int depth){
//     if (depth == n){
//         Max = max(sum,Max);
//         return;
//     }
//     visited[before]=true;
//     FOR(i,0,n){
//         if (!visited[i]){
//             sum+=abs(arr[before]-arr[i]);
//             dfs(i,depth+1);
//             sum-=abs(arr[before]-arr[i]);
//            // cnt++;
//         }
//     }   
//     visited[before] = false;
// }

void BFS(int node){
    queue<pair<int,int>> q;
    q.push({node,0});
    visited[node]=true;

    while(!q.empty()){
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();


        if (num==100){
            cout<<cnt;
            return;
        }

        FOR(i,1,7){
            if (i+num>100){
                continue;
            }
            if (ladder[i+num] && !visited[ladder[i+num]]){
                q.push({ladder[i+num],cnt+1});
                visited[ladder[i+num]] = true;
                //visited[i+num]=true;
            }

            if (snack[i+num] && !visited[snack[i+num]]){
                q.push({snack[i+num],cnt+1});
                visited[snack[i+num]]=true;
            }

            if (!visited[num+i] && !snack[num+i] && !ladder[i+num] ){
                q.push({i+num,cnt+1});
                visited[i+num]=true;
            }

        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    
    visited.assign(101,false);
    ladder.assign(101,0);
    snack.assign(101,0);
    
    int ladderInfo1,ladderInfo2,snackInfo1,snackInfo2;
    FOR(i,0,n){
        cin>>ladderInfo1>>ladderInfo2;
        ladder[ladderInfo1] = ladderInfo2;
    }
    FOR(i,0,m){
        cin>>snackInfo1>>snackInfo2;
        snack[snackInfo1] = snackInfo2;
    }

    BFS(1);

    return 0;

}