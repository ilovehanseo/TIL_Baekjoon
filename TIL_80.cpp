#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<vector<char>> board;
vector<bool> alphabet(26, false);

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int Max = 0;

void dfs(int x, int y, int depth) {
    Max = max(Max, depth);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;

        int idx = board[ny][nx] - 'A';

        if (!alphabet[idx]) {
            alphabet[idx] = true;
            dfs(nx, ny, depth + 1);
            alphabet[idx] = false; // 백트래킹
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    board.assign(R, vector<char>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    // 시작점 (0,0)
    alphabet[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << Max;
}