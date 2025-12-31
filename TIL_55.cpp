#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <limits>
#include <cmath>
#include <queue>
#include <set>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

// int n;
// vector<vector<char>> board;
// vector<vector<bool>> visited;

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

// //BFS안의 cnt -> 이동의 기록
// //BFS밖의 cnt -> 탐색의 개수

// void bfs(int x, int y, bool blind) {
//     queue<pair<int,int>> q;
//     q.push({x, y});
//     visited[x][y] = true;

//     char color = board[x][y];

//     while(!q.empty()) {
//         auto [cx, cy] = q.front();
//         q.pop();

//         for(int d = 0; d < 4; d++) {
//             int nx = cx + dx[d];
//             int ny = cy + dy[d];

//             if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//             if(visited[nx][ny]) continue;

//             // 정상인
//             if(!blind) {
//                 if(board[nx][ny] == color) {
//                     visited[nx][ny] = true;
//                     q.push({nx, ny});
//                 }
//             }
//             // 적록색약
//             else {
//                 if(color == 'B') {
//                     if(board[nx][ny] == 'B') {
//                         visited[nx][ny] = true;
//                         q.push({nx, ny});
//                     }
//                 } else { // R or G
//                     if(board[nx][ny] == 'R' || board[nx][ny] == 'G') {
//                         visited[nx][ny] = true;
//                         q.push({nx, ny});
//                     }
//                 }
//             }
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n;
//     board.assign(n, vector<char>(n));
    
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cin >> board[i][j];
//         }
//     }

//     // 정상인
//     visited.assign(n, vector<bool>(n, false));
//     int normal = 0;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             if(!visited[i][j]) {
//                 bfs(i, j, false);
//                 normal++;
//             }
//         }
//     }

//     // 적록색약
//     visited.assign(n, vector<bool>(n, false));
//     int blind = 0;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             if(!visited[i][j]) {
//                 bfs(i, j, true);
//                 blind++;
//             }
//         }
//     }

//     cout << normal << " " << blind << "\n";
//     return 0;
// }


vector<bool> Sieve(10001,false);
vector<bool> visited(10001,false);

void IsPrime(){
    for (int i=2;i*i<=10000;i++){
        for (int j=i*i;j<=10000;j+=i){
            Sieve[j]= true;
        }
    }
}

void BFS(int num, int fin){
    queue<pair<int,int>> q;
    visited[num] = true;
    q.push({num,0});
    while(!q.empty()){
        int number = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (number == fin){
            cout<<cnt<<'\n';
            return;
        }
        int tmp = number;

        int a = tmp/1000;
        int b = tmp/100%10;
        int c = tmp/10%10;
        int d = tmp%10;
        
        tmp = number-d;
        FOR(i,0,10){
            if (i == d) continue;
            if (tmp + i <1000 ) continue;
            if (!Sieve[tmp+i] && !visited[tmp+i]){
                q.push({tmp+i,cnt+1});
                visited[tmp+i]= true;
            }
        }

        tmp = number-c*10;
        for (int i=0;i<100;i+=10){
            if (c*10 == i) continue;
            if (tmp + i <1000 ) continue;
            if (!Sieve[tmp+i] && !visited[tmp+i]){
                q.push({tmp+i,cnt+1});
                visited[tmp+i] = true;
            }
        }

        tmp = number-b*100;
        for (int i=0;i<1000;i+=100){
            if (b*100 == i) continue;
            if (tmp + i <1000 ) continue;
            if (!Sieve[tmp+i] && !visited[tmp+i]){
                q.push({tmp+i,cnt+1});
                visited[tmp+i] = true;
            }
        }

        tmp = number-a*1000;
        for (int i=1000;i<10000;i+=1000){
            if (a*1000 == i) continue;
            if (tmp + i <1000 ) continue;
            if (!Sieve[tmp+i] && !visited[tmp+i]){
                q.push({tmp+i,cnt+1});
                visited[tmp+i] = true;
            }
        }
    }
    cout<<"Impossible"<<'\n';
}

int main(){
    int n;
    cin>>n;

    int num,fin;
    IsPrime();

    FOR(i,0,n){
        cin>>num>>fin;
        fill(visited.begin(), visited.end(), false); //visited 초기화 해주기
        BFS(num,fin);
    }
    return 0;
}