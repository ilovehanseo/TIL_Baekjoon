#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;

vector<bool> visited;

const int Max = 200001;

int wrap(int n,int i){
    if (i==1){
        return n-1;
    }    
    else if (i==2){
        return n+1;
    }
    else{
        return n*2;
    }
}

void BFS(int start,int end){
    queue<pair<int,int>> q;
    q.push({start,0});
    visited[start]=true;

    vector<int> parent(Max,0);

    while(!q.empty()){
        //3가지 가중치가 0인 그래프 탐색
        int tmp = q.front().first;
        int dist =q.front().second;

        q.pop();

        if (tmp == end){
            cout<<dist<<endl;
            vector<int> output;
            output.emplace_back(tmp);
            while(tmp!=start){
                output.emplace_back(parent[tmp]);
                tmp = parent[tmp];  //parent[17] = 18 parent[18] = 9
                //cout<<tmp<<" ";
            }
            //auto & 는 안되고 auto -> vector<int>::reverse_iterator 대체가능
            //Non-const 참조: 수정 가능 → 임시 객체에 위험 → ❌ 불가
            //Const 참조: 읽기만 → 수명 연장 → ✅ 가능
            //const auto & i 가능 , auto & i 불가능 , auto i 가능 -> 임시 객체에는 수정이 의미없다(컴파일러의 의미)
            for(vector<int>::reverse_iterator num=output.rbegin();num!=output.rend();num++){ //iterator는 포인터
                cout<<*num<<" ";
            }
            return;
        }


        FOR(i,1,4){
            int num = wrap(tmp,i);

            if (num>=0 && num<Max && !visited[num]){
                parent[num]=tmp; // parent[4] = 5 전의 값 저장 

                q.push({num,dist+1});
                visited[num]=true;
            }
        }


    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    
    visited.assign(Max,false);
    
    BFS(n,k);
    
    
    return 0;
}