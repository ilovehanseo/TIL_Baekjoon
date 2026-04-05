#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
#include <queue>
#include <cmath>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long

using namespace std;

template <typename T>
using Vec = vector<T>;

vector<int> tree;
vector<int> arr;
int n;
int boxSize=1000000;

void update(int node , int left , int right , int newIdx,int newValue){
    if (newIdx < left || newIdx > right) return;

    if (left == right){
        tree[node] += newValue;
        return;
    }    

    int mid = (left+right)/2;

    if (left <= newIdx && mid >= newIdx){
        update(node*2,left,mid,newIdx,newValue);
    }
    else{
        update(node*2+1,mid+1,right,newIdx,newValue);
    }
    
    tree[node] = tree[node*2]+tree[node*2+1];
}

int find(int node,int left,int right,int k){

    if (left == right){
        update(1,0,boxSize-1,left,-1);
        return left+1;
    }
    
    int mid = (left+right)/2;

    int leftNode = tree[node*2];

    if (leftNode>=k){   //왼쪽탐색
        return find(node*2,left,mid,k);
    }
    else{
        return find(node*2+1,mid+1,right,k-leftNode);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    
    tree.assign(boxSize*4,0);

    FOR(i,0,n){
        int a,b,c;
        cin>>a;
        if (a == 2){
            cin>>b>>c;
            update(1,0,boxSize-1,b-1,c);
        }
        else{
            cin>>b;
            cout<<find(1,0,boxSize-1,b)<<'\n';
        }
    }

    return 0;
}