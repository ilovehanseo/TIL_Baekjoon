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

vector<int> postArr;
vector<int> inArr;

void solve(int inStart,int inEnd,int postStart,int postEnd){
    //cout<<start<<" "<<end<<'\n';
    if (inStart > inEnd || postStart > postEnd) return;  // 범위 체크 추가

    //if (rootCnt>n) return;
    int root = postArr[postEnd];
    
    int idx = inStart;
    int flag = inEnd+1;
    
    while(idx<=inEnd){
        if (root==inArr[idx]){
            flag = idx;
            break;
        }
        idx++;
    }
    int leftSize = flag - inStart;
    
    cout<<root<<" ";
    solve(inStart, flag-1,postStart,postStart+leftSize-1);
    solve(flag+1,inEnd,leftSize+postStart,postEnd-1);

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    
    cin>>n;

    postArr.resize(n+1);
    inArr.resize(n+1);

    FOR(j,0,n){
        cin>>inArr[j];  //root 얻기
    }
    FOR(j,0,n){
        cin>>postArr[j];   //구간 나누기
    }

    solve(0,n-1,0,n-1);
    

    return 0;
}