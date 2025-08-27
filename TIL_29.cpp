#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

#define FOR(i,a,b) for(int i=(a); i<(b); ++i) 

int main(){
    //백준 1018 : 체스판 다시 칠하기
    // string Fir_chessmap[8] = {
    // "WBWBWBWB",
    // "BWBWBWBW",
    // "WBWBWBWB",
    // "BWBWBWBW",
    // "WBWBWBWB",
    // "BWBWBWBW",
    // "WBWBWBWB",
    // "BWBWBWBW"
    // };

    // string Sec_chessmap[8]{
    // "BWBWBWBW",
    // "WBWBWBWB",
    // "BWBWBWBW",
    // "WBWBWBWB",
    // "BWBWBWBW",
    // "WBWBWBWB",
    // "BWBWBWBW",
    // "WBWBWBWB"
    // };

    // int n,m;

    // cin>>n>>m;
    // vector<string> Map(n);
    // FOR(i,0,n){
    //     cin>>Map[i];
    // }

    // int Min=__INT_MAX__;
    // int FIR_count =0;
    // int SEC_count=0;

    // FOR(i,0,n-7){
    //     FOR(j,0,m-7){ 
    //         FIR_count=0;
    //         SEC_count=0;
    //         for (int a = i;a<i+8;a++){
    //             for (int b = j;b<j+8;b++){
    //                 if (Map[a][b]!=Fir_chessmap[a-i][b-j]){
    //                     FIR_count++;
    //                 }
    //                 if (Map[a][b]!=Sec_chessmap[a-i][b-j]){
    //                     SEC_count++;
    //                 }
    //             }
    //         }
    //         Min = min(Min,min(FIR_count,SEC_count));
    //     }
    //     //cout<<"for문 진입"<<'\n';
    // }

    // cout<<Min;
    


    //백준 2839 : 설탕 배달
    int n;
    cin>>n;

    int Max_five = n/5;
    int Max_three = n/3;

    int Min=__INT_MAX__,count=0;

    for(int i=0;i<=Max_five;i++){
        for(int j=0;j<=Max_three;j++){
            int num = i*5+j*3;
            if (num == n){
                count = i+j;
                Min = min(count,Min);
            }
        }
    }
    if (Min==__INT_MAX__){
        cout<<-1;
    }
    else{
        cout<<Min;
    }

    return 0;

}