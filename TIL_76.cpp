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

void MakeTree(int node,int left,int right){
    if (left == right){
        tree[node] = arr[left];
        return;
    }

    int mid = (left + right) / 2;

    MakeTree(node*2,left,mid);
    MakeTree(node*2+1,mid+1,right);

    tree[node] = (tree[node*2] * tree[node*2+1])%1000000007;
}

void update(int node , int left , int right , int newIdx,int newValue){
    if (newIdx < left || newIdx > right) return;

    if (left == right){
        tree[node] = newValue;
        return;
    }    

    int mid = (left+right)/2;

    if (left <= newIdx && mid >= newIdx){
        update(node*2,left,mid,newIdx,newValue);
    }
    else{
        update(node*2+1,mid+1,right,newIdx,newValue);
    }
    
    tree[node] = (tree[node*2] * tree[node*2+1])%1000000007;
    return;
}

int find(int node,int left,int right,int l,int r){
    if (r<left || l > right){
        return 1;
    }

    if (left>=l && right<=r){
        return tree[node];
    }
    
    int mid = (left+right)/2;

    return (find(node*2,left,mid,l,r) * find(node*2+1,mid+1,right,l,r))%1000000007;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,a,b,m,r,l;
    cin>>n>>a>>b;
    
    tree.assign(n*4+1,1);
    arr.assign(n+1,0);

    FOR(i,0,n){
        cin>>arr[i];
    }

    MakeTree(1,0,n-1);

    FOR(i,0,a+b){
        cin>>m>>r>>l;
        if (m == 1){
            update(1,0,n-1,r-1,l);
        }
        else{
            cout<<find(1,0,n-1,r-1,l-1)<<'\n';
        }
    }

    return 0;
}