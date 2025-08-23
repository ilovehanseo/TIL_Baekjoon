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

// vector<bool> digital(10,true);

// bool Possible(int channel){
//     int tmp = channel;

//     if (tmp == 0){ return digital[0]; }

//     while(tmp){
//         if (digital[tmp%10]){
//             tmp/=10;
//         }
//         else{
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     FOR(i,0,m){
//         int b;
//         cin>>b;
//         digital[b] =false;
//     }

//     int PM_value = abs(n-100);
//     int output=100000000;

//     FOR(i,0,1000000){ //0번부터 1000000-1번 채널까지 입력가능한 모든 경우의수 + +-로 입력하는 모든 경우의 수
//         if (Possible(i)){
//             int press_cnt = to_string(i).size(); 
//             int numcase = abs(n-i)+press_cnt;
//             output = min(numcase,output);
//         }
//     }
//     output = min(output,PM_value);

//     cout<<output;

    // 고생했다;; 내 방법은 너무 예외가 많음
    // int n,an,flag=0,aflag=0,count=0,Acount=0,Max,Min;
    // string num,digital_num,Adigital_num;    

    // int first_num=0;

    // cin>>num>>n;
     
    // int num_size = num.size();
    
    // int Anum=stoi(num);

    // if (Anum>100){
    //     first_num = Anum-100;
    // }
    // else{
    //     first_num = 100-Anum;
    // }
    // //cout<<"fisrt_num = "<<first_num<<'\n';

    // digital_num.reserve(num_size);
    // Adigital_num.reserve(num_size);
    
    // FOR(i,0,n){
    //     cin>>an;
    //     digital[an]=false;        
    // }
    // if (n!=10){
    // FOR(i,0,10){
    //     if (digital[i]){ Min = i; 
    //         break;}
    // }
    // for(int i=9;i>=0;i--){
    //     if (digital[i]){
    //         Max=i;
    //         break;
    //     }
    // }
    // }
    // //int digital_size=0;

    // for(auto&i:num){
    //      if (flag || aflag){ break ;} 

    //     //digital_size++;

    //     if (digital[i-'0']){
    //         digital_num.push_back(i);
    //         Adigital_num.push_back(i);
    //         count++;
    //         Acount++;
    //     }
    //     else{
    //         int j=0;
    //         while(true){
    //             j++;
    //             int plus = i-'0'+j;
    //             int mins = i-'0'-j;

    //             if (!flag && plus<10 && digital[plus]){
    //                 digital_num.push_back(plus+'0');
    //                 count++;
    //                 flag=1;
    //             }
    //             if (!aflag && mins>=0 && digital[mins]){
    //                 Adigital_num.push_back(mins+'0');
    //                 Acount++;
    //                 aflag=1;
    //             }

    //             if (plus>=10 && mins<0){  break;  }

    //             if (flag && aflag){ break; }
                
    //           //  if (flag && mins<0) { break; }
                
    //             //if (plus>=10 && aflag) { break; }

    //         }

    //     }
    // }
    // int tmp;
    // //big_digital을 만드는 함수 하나 해야될듯 -> num_size보다 1큰 즉, 0이 아닌 min인 앞자리수 나머진(num_size)크기의 min 수
    // //small_digital을 만드는 함수 하나 해야될듯 -> 이건 상관없나?
    // if (n!=10){
    // string big_digital;
    // string small_digital;

    // FOR(i,0,num_size+1){
    //     if (i==0){
    //          if (Min==0){
    //              big_digital.push_back(Min+'0'+1);
    //          }
    //         else{
    //              big_digital.push_back(Min+'0');
    //         }
    //     }
    //     else
    //         big_digital.push_back(Min+'0');
    // }
    // FOR(i,0,num_size-1){
    //     small_digital.push_back(Max+'0');
    // }

    // if (!small_digital.empty()){
    //     tmp = min(stoi(big_digital)-Anum+num_size+1,Anum-stoi(small_digital)+num_size-1);
    // }
    // else{
    //     tmp = stoi(big_digital)-Anum+num_size+1;
    // }
    // }
    // //cout<<tmp<<'\n';  // num과 같은 자리수가 아닌 수 중에서 작은 값
    // for (int i = digital_num.size(); i<num_size;i++ ){ 
    //       digital_num.push_back(Min+'0');
    //       count++;
    // }

    // for (int i = Adigital_num.size(); i<num_size;i++ ){ 
    //       Adigital_num.push_back(Min+'0');
    //       Acount++;
    // }

    // // for (int i=digital_size;i<num_size;i++){
    // //     if (flag){
    // //         digital_num.push_back(Min+'0');
    // //         count++;
    // //     }
    // //     if (aflag){
    // //         Adigital_num.push_back(Max+'0');
    // //         Acount++;
    // //     }
    // // } 

    //  cout<<"digital_num = "<<digital_num<<'\n';
    //  cout<<"Adigital_num = "<<Adigital_num<<'\n';

    // int result=0;
    // int plus_num = 10000000;
    // int mins_num = 10000000;
    // if (!digital_num.empty()){
    //     plus_num = stoi(digital_num) - Anum+count;
    // }
    // if (!Adigital_num.empty()){
    //     mins_num = Anum - stoi(Adigital_num)+Acount;
    // }

    // cout<<"Plus_num = "<<plus_num<<'\n';
    // cout<<"Mins_num = "<<mins_num<<'\n';

    // // if (flag && aflag){
    // //     result = min(min(plus_num,mins_num),first_num);
    // // }
    // // else if(flag){
    // //     result = min(plus_num,first_num);
    // // }
    // // else if(aflag){
    // //     result = min(mins_num,first_num);
    // // }
    // // else{
    // //     result = first_num;
    // // }
    // if (n!=10)
    // result = min(tmp,min(min(plus_num,mins_num),first_num));
    // else
    //         result = min(min(plus_num,mins_num),first_num);
    

    // cout<<result;

//     return 0;
// }

//백준 14500번
// bool poly_check(int a,int b,int c){
//     if ()
// }

// int main(){
//     int n,m;
//     cin>>n>>m;

//     vector<vector<int>> map(n,vector<int> (m,0));
    
//     FOR(i,0,n){
//         FOR(j,0,m){
//             cin>>map[i][j];
//         }
//     }

//     int output =0;


//     FOR(i,0,n){
//         FOR(j,0,m){   //i행 j열
//             // int sum= map[i][j];
//             // FOR(a,0,4){
//             //     FOR(b,0,4){
//             //         FOR(c,0,4){
//             //             if (poly_check(a,b,c)){
                            
//             //             }
//             //         }

//             //     }
//             // }
            
//         }
//     }


    
    
//     return 0;



// }