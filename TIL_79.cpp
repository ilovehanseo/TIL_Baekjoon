#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<memory>
#include<queue>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;


vector<vector<bool>> visited;
vector<vector<char>> tetrix;
queue<pair<int,int>> group;
queue<pair<int,int>> q;

int result = 0;

const int aX[4] = {-1,0,1,0};
const int aY[4] = {0,1,0,-1};

void init(){
    tetrix.assign(12,vector<char>(6,' '));
    visited.assign(12,vector<bool>(6,false));
}

void Gravity(){
    while(!group.empty()){
        int x = group.front().first;
        int y = group.front().second;
        group.pop();

        tetrix[y][x] = '.';
        for (int i = y;i>0;i--){
            tetrix[i][x] = tetrix[i-1][x];
        }
        tetrix[0][x] ='.';
    }
}

void clear(int x,int y){
    visited[y][x] = true;
    q.push({x,y});
    group.push({x,y});
    result=1;
}

void bfs() {
    while(!q.empty()){
        int qX = q.front().first;
        int qY = q.front().second;
        q.pop();

        FOR(i,0,4){
            int tmpX = aX[i]+qX;
            int tmpY = aY[i]+qY;

            if (tmpX<0 || tmpX>=6 ||tmpY<0 || tmpY>=12) continue; 

            if (visited[tmpY][tmpX]) continue;

            if (tetrix[qY][qX] != tetrix[tmpY][tmpX]) continue;
            
            q.push({tmpX,tmpY});
            group.push({tmpX,tmpY});
            visited[tmpY][tmpX] =true;
            result++;
        }    
        
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int output = 0;

    init();

    FOR(i,0,12){
        FOR(j,0,6){
            cin>>tetrix[i][j];
        }
    }
    while (true)
    {
        bool check = false;
        visited.assign(12,vector<bool>(6,false));

        FOR(i, 0, 12)
        {
            FOR(j, 0, 6)
            {
                if (!visited[i][j] && tetrix[i][j] != '.')
                {
                    clear(j, i);
                    bfs();
                    if (result >= 4)
                    {
                        Gravity();
                        check = true;
                    }
                    else
                    {
                        group = queue<pair<int, int>>();
                    }
                }
            }
        }
        if (check){
            output++;
        }
        else{
            break;
        }
    }

    cout<<output;

    return 0;
}


