#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<memory>
#include<queue>
#include<deque>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;


#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<memory>
#include<queue>
#include<deque>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;

// int threeChoice(int num, int choice){
//     if (choice == 0){
//         return num + 1;
//     }
//     else if (choice == 1){
//         return num - 1;
//     }
//     else{
//         return num * 2;
//     }
// }


// // 0-1 BFS (1)
// int bfs(int final, int n) {
//     const int MAXSIZE = 200001;
//     vector<int> visited(MAXSIZE, -1);

//     deque<int> dq;

//     dq.push_front(n);
//     visited[n] = 0;
    
//     while (!dq.empty()) {
//         int tmp = dq.front();
//         dq.pop_front();

//         if (tmp == final) {
//             return visited[final];
//         }
        
//         // 곱하기 2 (비용 0)
//         int next = tmp * 2;
//         if (next >= 0 && next < MAXSIZE && visited[next] == -1) {
//             visited[next] = visited[tmp];
//             dq.push_front(next);
//         }
        
//         // 더하기 1 (비용 1)
//         next = tmp + 1;
//         if (next >= 0 && next < MAXSIZE && visited[next] == -1) {
//             visited[next] = visited[tmp] + 1;
//             dq.push_back(next);
//         }
        
//         // 빼기 1 (비용 1)
//         next = tmp - 1;
//         if (next >= 0 && next < MAXSIZE && visited[next] == -1) {
//             visited[next] = visited[tmp] + 1;
//             dq.push_back(next);
//         }
//     } 
//     return -1;
// }


//이차원 BFS
// int bfs(int s) {
//   // visited[화면개수][클립보드개수] = 최소 시간
//     vector<vector<int>> visited(1001, vector<int>(1001, -1));
//     queue<pair<pair<int,int>, int>> q;  // ((화면개수, 클립보드개수), 시간)
    
//     visited[1][0]=0;
//     q.push({{1,0},0});    

//     while (!q.empty()) {
//         int time = q.front().second;
//         int screen = q.front().first.first;
//         int clipBoard = q.front().first.second;

//         q.pop();

//         if (screen == s){
//             return visited[screen][clipBoard];
//         }
        
//         FOR(i,1,4){
//             if (i==1 && visited[screen][clipBoard+screen]==-1){
//                q.push({{screen,screen},time+1});
//                visited[screen][screen] = time+1;
//             }
//             else if (i==2 && screen+clipBoard<=1000 && visited[screen+clipBoard][clipBoard]==-1){
//                 q.push({{screen+clipBoard,clipBoard},time+1});
//                 visited[screen+clipBoard][clipBoard] = time+1;
//             }
//             else if (i==3 && screen-1>0 && visited[screen-1][clipBoard]==-1){
//                 q.push({{screen-1,clipBoard},time+1});
//                 visited[screen-1][clipBoard] = time+1;
//             }
//         }
//     } 

//     return -1;
// }

//0-1 BFS (2)
// const int dx[4] = {1,0,-1,0};
// const int dy[4] = {0,1,0,-1};

// int bfs(int x,int y,int roadX,int roadY,Vec<Vec<char>> Map) {
//     Vec<Vec<bool>> visited(roadY,Vec<bool>(roadX,false));

//     deque<pair<pair<int,int>,int>> q;
//     visited[y][x] = true;
//     q.push_front({{x,y},0});


//     while (!q.empty()) {
//         int tmpX = q.front().first.first;
//         int tmpY = q.front().first.second;
//         int dist = q.front().second;

//         q.pop_front();

//         if (tmpX == roadX-1 && tmpY==roadY-1){ return dist; }


//         FOR(i,0,4){
//             int nextX = tmpX+dx[i];
//             int nextY = tmpY+dy[i];
//             if (nextX>=0 && nextY>=0 &&nextX<roadX &&nextY<roadY && !visited[nextY][nextX]){
//                 if (Map[nextY][nextX]== '1'){
//                     q.push_back({{nextX,nextY},dist+1});
//                 }
//                 else{
//                     q.push_front({{nextX,nextY},dist});
//                 }
//                 visited[nextY][nextX] = true;
//                 //Map[nextY][nextX] = '0';

//                 //cout<<"dist = "<<dist<<endl;
//             }
//         }
//     }
//     return -1;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    string str;

    Vec<Vec<char>> Miro(m,Vec<char>(n)); 

    FOR(i,0,m){
        cin>>str;    
        FOR(j,0,n){
             Miro[i][j] = str[j];
        }
    }

    cout<<bfs(0,0,n,m,Miro);
    //reverse(output.begin(),output.end());
    
    // for(auto&i:output){
    //     cout<<i<<" ";
    // }
   // cout<<m;
    return 0;
}
