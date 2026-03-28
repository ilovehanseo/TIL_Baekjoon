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

vector<int> arr;

void solve(int start,int end){
    //cout<<start<<" "<<end<<'\n';
    if (start>end) return;

    int root = arr[start];
    
    int idx = start+1;
    int flag = end+1;
    
    while(idx<=end){
        if (root<arr[idx]){
            flag = idx;
            break;
        }
        idx++;
    }
    
    solve(start+1 , flag-1);
    solve(flag,end);

    cout<<root<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while (cin >> x) {
        arr.push_back(x);
    }

    solve(0, arr.size() - 1);

    return 0;
}