#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<limits>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;

//DP - 다이나믹 프로그래밍 알고리즘
//DP 감각
//항상 dp[i]가 무엇을 의미하는지를 한 문장으로 정의한다.
//예) “dp[i] = i원을 만들 때 최소 동전 수”
//
//작은 입력으로 손으로 직접 계산해본다.
//→ 이 과정에서 점화식을 유추할 수 있음
//
//반복되는 구조를 발견했으면, 재귀 + 메모이제이션부터 시도
//→ 그다음 바텀업으로 최적화 가능
//
//그리디로 될 것 같지만, 모든 경우의 조합이 필요하면 DP다.


const int mod = 10007;

const int maxValue = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> house(n + 1, vector<int>(3, 0));

    FOR(i, 1, n + 1) {
        FOR(j, 0, 3)
            cin >> house[i][j];
    }

    //vector<vector<vector<int>>> DP(n + 1, vector<vector<int>>(3, vector<int>(3, 0)));

    //DP[i][j] -> 0,1,2순서대로r,g,b , 현재 j컬러를 칠하면서 i번집까지 칠하는 최소 비용

   // //DP[i][j][k] -> 첫번째 선택한 색깔은 k.

    int output= maxValue;

    for (int first = 0; first < 3; first++) { //처음 뽑은 경우 0,1,2
        vector<vector<int>> DP(n + 1, vector<int>(3, maxValue));

        DP[1][first] = house[1][first];
        FOR(i, 2, n+1) {
            DP[i][0] = min(DP[i - 1][1] + house[i][0], DP[i - 1][2] + house[i][0]);
            DP[i][1] = min(DP[i - 1][0] + house[i][1], DP[i - 1][2] + house[i][1]);
            DP[i][2] = min(DP[i - 1][1] + house[i][2], DP[i - 1][0] + house[i][2]);
        }
        for (int last = 0; last < 3; ++last) {
            if (last != first) {
                output = min(output, DP[n][last]);
            }
        }
       /* if (first == 0) {
            DP[n][1] = min(DP[n - 1][0] + house[n][1], DP[n - 1][2] + house[n][1]);
            DP[n][2] = min(DP[n - 1][0] + house[n][2], DP[n - 1][1] + house[n][2]);
            output = min(DP[n][1], DP[n][2]);
        }
        else if (first == 1) {
            DP[n][0] = min(DP[n - 1][1] + house[n][0], DP[n - 1][2] + house[n][0]);
            DP[n][2] = min(DP[n - 1][0] + house[n][2], DP[n - 1][1] + house[n][2]);
            output = min(output, min(DP[n][0], DP[n][2]));
        }
        else {
            DP[n][0] = min(DP[n - 1][1] + house[n][0], DP[n - 1][2] + house[n][0]);
            DP[n][1] = min(DP[n - 1][2] + house[n][1], DP[n - 1][0] + house[n][1]);
          
            output = min(output, min(DP[n][0], DP[n][1]));

        }*/
    }

   /* DP[n][0][0] = min(DP[n - 1][1][2] + house[n][0], DP[n - 1][2][1] + house[n][0]);
    DP[n][0][1] = min(DP[n - 1][1][2] + house[n][0], DP[n - 1][2][0] + house[n][0]);
    DP[n][0][2] = min(DP[n - 1][1][1] + house[n][0], DP[n - 1][2][0] + house[n][0]);

    DP[n][1][0] = min(DP[n - 1][0][2] + house[n][1], DP[n - 1][2][1] + house[n][1]);
    DP[n][1][1] = min(DP[n - 1][0][2] + house[n][1], DP[n - 1][2][0] + house[n][1]);
    DP[n][1][2] = min(DP[n - 1][0][1] + house[n][1], DP[n - 1][2][0] + house[n][1]);

    DP[n][2][0] = min(DP[n - 1][0][2] + house[n][2], DP[n - 1][1][1] + house[n][2]);
    DP[n][2][1] = min(DP[n - 1][0][2] + house[n][2], DP[n - 1][1][0] + house[n][2]);
    DP[n][2][2] = min(DP[n - 1][0][1] + house[n][2], DP[n - 1][1][0] + house[n][2]);*/

    

    cout << output;

    return 0;
}
