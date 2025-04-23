#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstdbool>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;


int N, cnt = 0;
vector<vector<int>> Chess;
vector<int> Achess;

//2차원 배열ver
void backtrack(int depth) {
    if (depth > N)
        return;

    if (depth == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (Chess[depth][i]==0) {
            FOR(j, 0, N) {
                FOR(k, 0, N) {
                    if (j == depth || k == i || (j - k) == (depth - i) || (j + k) == (depth + i))
                        Chess[j][k] += 1;
                }
            }

            backtrack(depth + 1); // 다음 깊이로

            FOR(j, 0, N) {
                FOR(k, 0, N) {
                    if (j == depth || k == i || (j - k) == (depth - i) || (j + k) == (depth + i))
                        Chess[j][k] -= 1;
                }
            }
        }
    }

}
//1차원 배열ver
void Abacktrack(int depth) {
    if (depth > N)
        return;

    if (depth == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; ++i) {
        int flag = 1;
        FOR(j, 0, depth) {
            int col = Achess[j];  //(j,col), now (depth,i)
            if (Achess[j] == i || (i == (depth+col-j)) || (i == (j-depth + col))) {
                flag = 0;
                break;
            }

        }
        if (flag) {
            Achess[depth] = i;

            Abacktrack(depth + 1); // 다음 깊이로

            Achess[depth] = -1;

        }
    }
}

vector<vector<int>> square(9, vector<int>(9, 0));
bool END = false;

void Soduku(int i, int j) {
    if (j >= 9) {
        Soduku(i + 1, 0);
        return;
    }
    if (i == 9) {
        END = true;
        return;
    }
    if (square[i][j] != 0) {
        if ((j + 1) < 9)
            Soduku(i, j + 1);
        else if ((i+1)<9) {
            Soduku(i + 1, 0);
        }
        return;
    }
    int row = i / 3;
    int col = j / 3;
    FOR(num, 1, 10) {
        int flag = 0;
        for (int a = row * 3; a < row * 3 + 3; a++) {
            for (int b = col * 3; b < col * 3 + 3; b++) {
                if (num == square[a][b]) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        FOR(k, 0, 9) {
            if (num == square[i][k] || num == square[k][j]) {
                flag = 1;
                break;
            }
        }
     
        square[i][j] = num;
        if (!flag) {
            Soduku(i, j + 1);
        }
        if (END)
            return;
        square[i][j] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
   
   /* Chess = vector<vector<int>>(N, vector<int>(N, 0));
    Achess = vector<int>(N, -1);
    Abacktrack(0);*/

    FOR(i, 0, 9) {
        FOR(j, 0, 9) {
            cin >> square[i][j];
        }
    }

    Soduku(0, 0);

    FOR(i, 0, 9) {
        FOR(j, 0, 9) {
            cout << square[i][j]<<" ";
        }
        cout << '\n';
    }
    return 0;

}