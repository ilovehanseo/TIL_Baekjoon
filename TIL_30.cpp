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

int changeYear(int m,int n,int x,int y){
    int myear=0,nyear=0,realYear=0;;

    while(true){
        myear = (myear) % m + 1;
        nyear = (nyear) % n + 1;
        realYear++;
        if (myear == x && nyear == y){ return realYear; }
        if (myear == m && nyear ==n){ return -1; }
    }
} 8 6
int main(){
    //부분합 - 1182번 보류
//    int n,s;
//    cin>>n>>s;

//    vector<int> arr(n,0);
//    vector<int> arrSum(n,0);
//     FOR(i,0,n){
//         cin>>arr[i];
//         if (i==0){            
//             arrSum[i] = arr[i];
//         }
//         else{
//             arrSum[i] = arrSum[i-1]+arr[i];
//         }
//     }
//     // cout<<"arrSUM의 값"<<'\n';
//     // FOR(i,0,n){  // 5, -5  //-8 -2 -7
//     //     cout<<arrSum[i]<<" ";
//     // }  
//     //cout<<'\n';
//     int count=0;
//     FOR(i,0,n){
//         for (int j=0;j<=i;j++){
//             int Sum =0;
//             if (i == j){
//                 Sum = arrSum[i];
//             }
//             else{
//                  Sum = arrSum[i]-arrSum[j];
//             }
//              if (Sum == s){ count++; }
//         }
//     }

//     cout<<count;
    int T;
    int m,n,x,y;
    cin>>T;
    FOR(i,0,T){
        cin>>m>>n>>x>>y;
        cout<<changeYear(m,n,x,y)<<'\n';
    }




    return 0;
}