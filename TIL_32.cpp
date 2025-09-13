#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<limits>
#include<cmath>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;

int m,n;
vector<int> arr;
vector<int> output;
vector<bool> visited;
// 재귀함수의 push-pop 구조 -> 상태를 누적,기록해야할 때 사용 -> 벡터 전역변수로 사용
void recursion_4(int count, int num){
    if (count == m){
        for(auto & i:arr){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=num;i<=n;i++){  
        arr.push_back(i);
        recursion_4(count+1,i);
        arr.pop_back();
    }
}

void recursion_5(int count){
    if (count == m){
        for(auto & i:output){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        
       if (visited[i]){
        continue;
       }
        output.push_back(arr[i]);
        visited[i] = true;
        recursion_5(count+1);
        output.pop_back();
        visited[i] = false;
    }
}

void recursion_6(int count, int num){
    if (count == m){
        for(auto & i:output){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=num;i<n;i++){  
        output.push_back(arr[i]);
        recursion_6(count+1,i+1);
        output.pop_back();
    }
}
int main(){
    cin>>n>>m;
    arr.resize(n);
    FOR(i,0,n){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    visited.assign(n,false);

    recursion_6(0,0);
    //recursion_5(0);
    //recursion_4(0,1);
    
    
    
    return 0;

}