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

//존재하면 1
// bool check(int x){
//     if(s & (1<<x)){
//         return true;
//     }
//     return false;
// }

// void add (int x){
//     if(!(s & (1<<x))){
//         s|=(1<<x);
//     }
// }

// void remove(int x){
//     if (s & (1<<x)){
//         s-=(1<<x);
//     }
// }

// void toggle(int x){
//     if (s & (1<<x)){
//         s-=(1<<x);
//     }
//     else{
//         s|=(1<<x);
//     }
// }

// void all(){
//     s = (1<<21)-1;
// }

// void empty(){
//     s = 0;
// }
void reCurit(vector<int> arr,int m,int count){
    if (count == m){
        cout<<'\n';
        return;
    }
    for (int i=count;i<arr.size();i++){
        cout<<arr[i]<<" ";
        reCurit(arr,m,count++);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    vector<int> arr(n);
    cin>>n>>m;
    FOR(i,0,n){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    reCurit(arr,m,0);



    
    return 0;

}
