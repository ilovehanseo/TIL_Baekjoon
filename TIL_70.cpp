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

vector<vector<int>> box;
int white = 0 , blue = 0;

void slice(int length , int left , int right , int up , int down)
{
    //종료 조건 
    if (length<=0){
        return;
    }
    
    int cnt=0;
    FOR(i,up,down){
        FOR(j,left,right){
            if (!box[i][j])
                cnt++;
        }
    }
    if (cnt == length*length){
        cout<<0;
        return;
    }
    if (cnt==0){
        cout<<1;
        return;
    }


    int size = length/2;

    cout<<'(';
    slice(size,left,right-size,up,down-size);
    slice(size,left+size,right,up,down-size);
    slice(size,left,right-size,up+size,down);
    slice(size,left+size,right,up+size,down);
    cout<<')';
}


int main(){
    int n;
    cin>>n;
    
    box.resize(n,vector<int>(n));

    FOR(i, 0, n) {
        string row;
        cin >> row;
        FOR(j, 0, n)
            box[i][j] = row[j] - '0'; 
    }

    slice(n,0,n,0,n);


    return 0;
}