#include <iostream>
#include <vector>
#include<queue>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

vector<vector<char>> map;
vector<vector<vector<vector<bool>>>> visited;

struct ball
{
    int Rx;
    int Ry;
    int Bx;
    int By;
    int depth;
};

queue<ball> q;

const int dx[5] = {0, 1, -1, 0, 0};   //동 서 남 북
const int dy[5] = {0, 0, 0, 1, -1};   //1 2 3 4

pair<int,int> move(int x,int y,int k){
    while(map[y + dy[k]][x + dx[k]] != '#'){
        x += dx[k];
        y += dy[k];
        if (map[y][x] == 'O') break;
    }
    return make_pair(x,y);
}

void East(int rx,int ry,int bx,int by,int depth){
    if (rx>bx){
        auto red = move(rx,ry,1);
        int tmpRX = red.first;
        int tmpRY = red.second;
        
        auto blue = move(bx,by,1);
        int tmpBX = blue.first;
        int tmpBY = blue.second;

        if (map[tmpBY][tmpBX] == 'O') return;

        if (tmpRX == tmpBX && tmpRY == tmpBY){
            tmpBX--;
        }
        if (!visited[tmpRY][tmpRX][tmpBY][tmpBX]){
            q.push({tmpRX,tmpRY,tmpBX,tmpBY,depth+1});
            visited[tmpRY][tmpRX][tmpBY][tmpBX] = true;
        }
    }
    else{
        auto blue = move(bx,by,1);
        int tmpBX = blue.first;
        int tmpBY = blue.second;

        if (map[tmpBY][tmpBX] == 'O') return;

        auto red = move(rx,ry,1);
        int tmpRX = red.first;
        int tmpRY = red.second;
        
        if (tmpRX == tmpBX && tmpRY == tmpBY){
            tmpRX--;
        }
        if (!visited[tmpRY][tmpRX][tmpBY][tmpBX]){
            q.push({tmpRX,tmpRY,tmpBX,tmpBY,depth+1});
            visited[tmpRY][tmpRX][tmpBY][tmpBX] = true;
        }
    }
}

void West(int rx,int ry,int bx,int by,int depth){
    if (rx<bx){
        auto red = move(rx,ry,2);
        int tmpRX = red.first;
        int tmpRY = red.second;
        
        auto blue = move(bx,by,2);
        int tmpBX = blue.first;
        int tmpBY = blue.second;
        
        if (map[tmpBY][tmpBX] == 'O') return;

        if (tmpRX == tmpBX && tmpRY == tmpBY){
            tmpBX++;
        }
        if (!visited[tmpRY][tmpRX][tmpBY][tmpBX]){
            q.push({tmpRX,tmpRY,tmpBX,tmpBY,depth+1});
            visited[tmpRY][tmpRX][tmpBY][tmpBX] = true;
        }
    }
    else{
        auto blue = move(bx,by,2);
        int tmpBX = blue.first;
        int tmpBY = blue.second;

        if (map[tmpBY][tmpBX] == 'O') return;

        auto red = move(rx,ry,2);
        int tmpRX = red.first;
        int tmpRY = red.second;
        
        if (tmpRX == tmpBX && tmpRY == tmpBY){
            tmpRX++;
        }
        if (!visited[tmpRY][tmpRX][tmpBY][tmpBX]){
            q.push({tmpRX,tmpRY,tmpBX,tmpBY,depth+1});
            visited[tmpRY][tmpRX][tmpBY][tmpBX] = true;
        }
    }
}

void South(int rx,int ry,int bx,int by,int depth){
    if (ry>by){
        auto red = move(rx,ry,3);
        int tmpRX = red.first;
        int tmpRY = red.second;
        
        auto blue = move(bx,by,3);
        int tmpBX = blue.first;
        int tmpBY = blue.second;

        if (map[tmpBY][tmpBX] == 'O') return;

        if (tmpRX == tmpBX && tmpRY == tmpBY){
            tmpBY--;
        }
        if (!visited[tmpRY][tmpRX][tmpBY][tmpBX]){
            q.push({tmpRX,tmpRY,tmpBX,tmpBY,depth+1});
            visited[tmpRY][tmpRX][tmpBY][tmpBX] = true;
        }
    }
    else{
        auto blue = move(bx,by,3);
        int tmpBX = blue.first;
        int tmpBY = blue.second;

        if (map[tmpBY][tmpBX] == 'O') return;

        auto red = move(rx,ry,3);
        int tmpRX = red.first;
        int tmpRY = red.second;
        
        if (tmpRX == tmpBX && tmpRY == tmpBY){
            tmpRY--;
        }
        if (!visited[tmpRY][tmpRX][tmpBY][tmpBX]){
            q.push({tmpRX,tmpRY,tmpBX,tmpBY,depth+1});
            visited[tmpRY][tmpRX][tmpBY][tmpBX] = true;
        }
    }
}

void North(int rx,int ry,int bx,int by,int depth){
    if (ry<by){
        auto red = move(rx,ry,4);
        int tmpRX = red.first;
        int tmpRY = red.second;
        
        auto blue = move(bx,by,4);
        int tmpBX = blue.first;
        int tmpBY = blue.second;

        if (map[tmpBY][tmpBX] == 'O') return;
        
        if (tmpRX == tmpBX && tmpRY == tmpBY){
            tmpBY++;
        }
        if (!visited[tmpRY][tmpRX][tmpBY][tmpBX]){
            q.push({tmpRX,tmpRY,tmpBX,tmpBY,depth+1});
            visited[tmpRY][tmpRX][tmpBY][tmpBX] = true;
        }
    }
    else{
        auto blue = move(bx,by,4);
        int tmpBX = blue.first;
        int tmpBY = blue.second;

        if (map[tmpBY][tmpBX] == 'O') return;

        auto red = move(rx,ry,4);
        int tmpRX = red.first;
        int tmpRY = red.second;
        
        if (tmpRX == tmpBX && tmpRY == tmpBY){
            tmpRY++;
        }
        if (!visited[tmpRY][tmpRX][tmpBY][tmpBX]){
            q.push({tmpRX,tmpRY,tmpBX,tmpBY,depth+1});
            visited[tmpRY][tmpRX][tmpBY][tmpBX] = true;
        }
    }
}

void BFS(int endX,int endY){
    while(!q.empty()){
        int Rx = q.front().Rx;
        int Ry = q.front().Ry;
        int Bx = q.front().Bx;
        int By = q.front().By;
        int depth = q.front().depth;
        q.pop();

        if (depth>10){
            cout<<-1;
            return;
        }

        if (Bx == endX && By == endY) continue; //blue가 0에 빠진 경우 -1출력이 아닌 스킵을 하는 이유?

        if (Rx == endX && Ry == endY){
            if (Bx !=endX || By!=endY){
                cout<<depth;
                return;
            }
            else{
                cout<<-1;
                return;
            }
        }

        East(Rx,Ry,Bx,By,depth);
        West(Rx,Ry,Bx,By,depth);
        South(Rx,Ry,Bx,By,depth);
        North(Rx,Ry,Bx,By,depth);
    }
    cout<<-1;
}

//구현을 빠뜨린 것 : move 통합 / 벽 직전 , 구멍에서 push / blue가 구멍에 빠진 경우 스킵 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,endX,endY,tmpRx,tmpRy,tmpBx,tmpBy;
    cin>>n>>m;  //세로길이, 가로길이

    map.assign(n,vector<char>(m,0));
    visited.assign(n,vector<vector<vector<bool>>>(m,
        vector<vector<bool>>(n,vector<bool>(m,false))));
    
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>map[i][j];
            if (map[i][j] == 'R'){
                tmpRx = j;
                tmpRy = i;
            }
            else if (map[i][j] == 'B'){
                tmpBx = j;
                tmpBy = i;
            }
            else if (map[i][j] == 'O'){
                endX = j;
                endY = i;
            }
        }
    }
    q.push({tmpRx,tmpRy,tmpBx,tmpBy,0});

    BFS(endX,endY);
    
    return 0;
}