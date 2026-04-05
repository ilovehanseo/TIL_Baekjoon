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

const long long MAX = 1000000001;

int MakeTree(int node,int left,int right){
    if (left == right){
        return tree[node] = arr[left];
    }

    int mid = (left + right) / 2;

    return tree[node] = min(MakeTree(node*2,left,mid) , MakeTree(node*2+1,mid+1,right));
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
    
    tree[node] = min(tree[node*2],tree[node*2+1]);
}

int sum(int node,int left,int right,int l,int r){
    if (r<left || l > right){
        return MAX;
    }

    if (left>=l && right<=r){
        return tree[node];
    }
    
    int mid = (left+right)/2;

    return min(sum(node*2,left,mid,l,r),sum(node*2+1,mid+1,right,l,r));
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n;
    
    tree.assign(n*4,MAX);
    arr.assign(n,0);

    FOR(i,0,n){
        cin>>arr[i];
    }

    MakeTree(1,0,n-1);

    cin>>m;
    FOR(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        if (a == 1){
            update(1,0,n-1,b-1,c);
        }
        else{
            cout<<sum(1,0,n-1,b-1,c-1)<<'\n';
        }
    }

    return 0;
}