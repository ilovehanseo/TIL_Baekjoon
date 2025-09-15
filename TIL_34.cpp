#include<iostream>
#include<algorithm>
#include<vector>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;

Vec<char> pw; 
Vec<char> output;

bool IsPw(vector<char> output){
    int acnt=0,cnt=0;
    for (auto & i :output){
        if (i == 'a' || i =='e' || i == 'i' || i =='o' || i == 'u' ){ acnt++; }
        else{ cnt++; }
    }
    if (acnt && cnt>1){ return true; }

    return false;
}

void PossiblePw(int depth,int n,int m,int start){
    if (depth == n){
        if (IsPw(output)){
            for(auto & i :output){
                cout<<i;
            }
            cout<<'\n';
        }
        return;
    }

    for (int i=start;i<m;i++){
        output.push_back(pw[i]);
        PossiblePw(depth+1,n,m,i+1);
        output.pop_back();
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    pw.resize(m);

    FOR(i,0,m){
        cin>>pw[i];
    }

    sort(pw.begin(),pw.end());
    
    PossiblePw(0,n,m,0);

    return 0;
}
