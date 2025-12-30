#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <limits>
#include <cmath>
#include <queue>
#include <set>
#include<bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

// int D(int num){
//     return num*2%10000;
// }
// int S(int num){
//     if (num==0) return 9999;

//     return num-1;
// }
// int L(int num){
//     int number = num/1000%10;
//     for (int i=1;i<1000;i*=10){
//         int multi = i*10;
//         int div = i;
//         number += num/div%10 * multi;
//     }
//     return number;
// }
// int R(int num){
//     int number = num%10*1000;
//     for (int i=1;i<1000;i*=10){
//         int multi = i;
//         int div = i*10;
//         number += num/div%10 * multi;
//     }
//     return number;
// }

// string BFS(int num,int final){
//     vector<bool> visited(10000,false);
//     queue<pair<int,string>> q;
//     q.push({num,""});

//     visited[num] = true;
    
//     while(!q.empty()){
//         int current = q.front().first;
//         string str = q.front().second;
//         q.pop();
        
//         int next = D(current);
//         if (next == final) return str+"D";
//         if (!visited[next]){
//             visited[next] = true;
//             q.push({next,str+"D"});
//         }

//         next = S(current);
//         if (next == final) return str+"S";
//         if (!visited[next]){
//             visited[next] = true;
//             q.push({next,str+"S"});
//         }

//         next = L(current);
//         if (next == final) return str+"L";
//         if (!visited[next]){
//             visited[next] = true;
//             q.push({next,str+"L"});
//         }

//         next = R(current);
//         if (next == final) return str+"R";
//         if (!visited[next]){
//             visited[next] = true;
//             q.push({next,str+"R"});
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin>>n;

//     int str,fin;
//     FOR(i,0,n){
//         cin>>str>>fin;
//         cout<<BFS(str,fin)<<'\n';
//     }


//     return 0;
// }



//오버플로우 코드
// void BFS(int num,int final){
//     unordered_set<int> visited;
//     queue<pair<int,string>> q;
//     q.push({num,""});

//     visited.reserve(200000); //insert , count
//     visited.insert(num);

//     while(!q.empty()){
//         int current = q.front().first;
//         string str = q.front().second;
//         q.pop();
        
//         int next = current * current;
//         if (next == final) {cout<<str+"*";
//             return;}
//         if (!visited.count(next)){
//             visited.insert(next);
//             q.push({next,str+"*"});
//         }

//         next = current + current;
//         if (next == final) {cout<<str+"+";
//             return;}
//         if (!visited.count(next)){
//             visited.insert(next);
//             q.push({next,str+"+"});
//         }

//         next = 0;
//         if (next == final) {cout<<str+"-";
//             return;}
//         if (!visited.count(next)){
//             visited.insert(next);
//             q.push({next,str+"-"});
//         }
//         if (current!=0){
//         next = 1;
//         if (next == final) {cout<<str+"/";
//             return;}
//         if (!visited.count(next)){
//             visited.insert(next);
//             q.push({next,str+"/"});
//         }
//         }
//     }
//     cout<<"-1";
// }

//int -> long long , next 필터링 , count -> insert().second
void BFS(long long num, long long final) {
    unordered_set<long long> visited;
    visited.reserve(200000);
    
    visited.max_load_factor(0.7);

    queue<pair<long long, string>> q;
    q.push({num, ""});
    visited.insert(num);

    while (!q.empty()) {
        auto [current, str] = q.front();
        q.pop();

        // *
        long long next = current * current;
        if (next == final) { cout << str + "*"; return; }
        if (next <= 1000000000 && visited.insert(next).second)
            q.push({next, str + "*"});

        // +
        next = current + current;
        if (next == final) { cout << str + "+"; return; }
        if (next <= 1000000000 && visited.insert(next).second)
            q.push({next, str + "+"});

        // -
        next = 0;
        if (next == final) { cout << str + "-"; return; }
        if (visited.insert(next).second)
            q.push({next, str + "-"});

        // /
        if (current != 0) {
            next = 1;
            if (next == final) { cout << str + "/"; return; }
            if (visited.insert(next).second)
                q.push({next, str + "/"});
        }
    }

    cout << -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num , fin;
    cin>>num>>fin;
    if (num == fin){
        cout<<0;
        return 0;
    }

    BFS(num,fin);


    return 0;
}