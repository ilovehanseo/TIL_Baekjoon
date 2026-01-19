#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

void changeMatrix(int i, int j, vector<vector<int>> &A){
    FOR(y, i, i+3){
        FOR(x, j, j+3){
            A[y][x] = 1 - A[y][x];
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m));

    FOR(i, 0, n){
        FOR(j, 0, m){
            char c;
            cin >> c;
            A[i][j] = c - '0';
        }
    }

    FOR(i, 0, n){
        FOR(j, 0, m){
            char c;
            cin >> c;
            B[i][j] = c - '0';
        }
    }

    int cnt = 0;
    FOR(i, 0, n-2){
        FOR(j, 0, m-2){
            if (A[i][j] != B[i][j]){
                changeMatrix(i, j, A);
                cnt++;
            }
        }
    }

    FOR(i, 0, n){
        FOR(j, 0, m){
            if (A[i][j] != B[i][j]){
                cout << -1;
                return 0;
            }
        }
    }

    cout << cnt;
}
