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

//DP - ���̳��� ���α׷��� �˰���
//DP ����
//�׻� dp[i]�� ������ �ǹ��ϴ����� �� �������� �����Ѵ�.
//��) ��dp[i] = i���� ���� �� �ּ� ���� ����
//
//���� �Է����� ������ ���� ����غ���.
//�� �� �������� ��ȭ���� ������ �� ����
//
//�ݺ��Ǵ� ������ �߰�������, ��� + �޸������̼Ǻ��� �õ�
//�� �״��� ���Ҿ����� ����ȭ ����
//
//�׸���� �� �� ������, ��� ����� ������ �ʿ��ϸ� DP��.


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

    //DP[i][j] -> 0,1,2�������r,g,b , ���� j�÷��� ĥ�ϸ鼭 i�������� ĥ�ϴ� �ּ� ���

   // //DP[i][j][k] -> ù��° ������ ������ k.

    int output= maxValue;

    for (int first = 0; first < 3; first++) { //ó�� ���� ��� 0,1,2
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
