#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <limits>
#include <cmath>
#include <queue>
#include <set>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> meeting(n);
    FOR(i,0,n){
        cin>>meeting[i].second>>meeting[i].first;
    }
    sort(meeting.begin(),meeting.end());
    int earliest = 0;
    int selected = 0;

    for (int i=0;i<n;i++){
        int begin = meeting[i].second;
        int end = meeting[i].first;
        if (earliest<=begin){
            earliest = end;
            selected++;
        }
    }
    cout<<selected;
    return 0;
}