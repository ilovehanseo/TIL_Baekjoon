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

int main(){
    int num;
    cin>>num;

    if (num>=1 && num<10){
        cout<<num;
        return 0;
    }

    int cnt=0;
    int ten=1;
    int tmp=num;

    while(tmp){
        tmp/=10;
        cnt++;
        ten*=10;    
    }
    ten/=10;
    //cout<<ten<<'\n'<<cnt<<'\n';

    long long result=0;

    result = (num-ten+1)*cnt;
    //if 120 -> cnt = 3
    //cout<<result<<'\n';

    while(cnt){
        cnt--;
        result+=pow(10,(cnt-1)) * 9*cnt;
       // cout<<result<<'\n';
    }
    
    //일의 자리수 + 십의 자리수 + 백의 자리수+ ...
    //모든수 + 10이상의 수 + 100이상의 수 지린다;

   cout<<result;
   


    return 0;
}