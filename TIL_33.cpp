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

void recursion_7(int count){
    if (count == m){
        for(auto & i:output){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        output.push_back(arr[i]);
        recursion_7(count+1);
        output.pop_back();
    }
}

void recursion_8(int count, int num){
    if (count == m){
        for(auto & i:output){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=num;i<n;i++){  
        output.push_back(arr[i]);
        recursion_8(count+1,i);
        output.pop_back();
    }
}

void recursion_9(int count){
    if (count == m){
        for(auto & i:output){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    int tmp = -10001;
    for(int i=0;i<n;i++){  
        if (visited[i]){ continue; }
        if (tmp == arr[i]){
            continue;
        }
        tmp = arr[i];   

        output.push_back(arr[i]);
        visited[i] = true;

        recursion_9(count+1);
        output.pop_back();
        visited[i] = false;
        
    }
}

void recursion_10(int count,int num){
    if (count == m){
        for(auto & i:output){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    int tmp = -10001;  //tmp는 현재 깊이에서의 사용한 값
    for(int i=num;i<n;i++){  
        if (visited[i]){ continue; }
        if (tmp == arr[i]){
            continue;
        }

        tmp = arr[i];   

        output.push_back(arr[i]);
        visited[i] = true;

        recursion_10(count+1,i+1);
        output.pop_back();
        visited[i] = false;
        
    }
}

void recursion_11(int count){
    if (count == m){
        for(auto & i:output){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    int tmp = -10001;
    for(int i=0;i<n;i++){  
        if (tmp == arr[i]){
            continue;
        }
        output.push_back(arr[i]);
        recursion_11(count+1);
        output.pop_back();
        tmp = arr[i];   

    }
}

void recursion_12(int count,int num){
    if (count == m){
        for(auto & i:output){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    int tmp = -10001;
    for(int i=num;i<n;i++){  
        if (tmp == arr[i]){
            continue;
        }
        output.push_back(arr[i]);
        recursion_12(count+1,i);
        output.pop_back();
        tmp = arr[i];   
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

    //중복 제거 시간복잡도 O(N)
   // arr.erase(unique(arr.begin(),arr.end()),arr.end());

   // int size = arr.size();

    //visited.assign(n,false)
    
    recursion_12(0,0);

   
    
    return 0;

}