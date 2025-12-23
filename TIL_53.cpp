#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <limits>
#include <cmath>
#include <queue>
#include <set>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> box(n, vector<int>(m, 0));
    vector<int> boxValue(n*m+1, 0);
    
    FOR(i, 0, n) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            adj[i][j] = str[j] - '0';
        }
    }
    
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    int id = 1;
    
    // 0으로 이루어진 연결된 영역 찾기
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (adj[i][j] == 0 && !visited[i][j]) {
                queue<pair<int, int>> q;  // 각 BFS마다 새 큐 사용
                q.push({i, j});
                visited[i][j] = true;
                box[i][j] = id;
                int dist = 1;
                
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    FOR(k, 0, 4) {  // i 대신 k 사용
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && 
                            !visited[nx][ny] && adj[nx][ny] == 0) {
                            box[nx][ny] = id;
                            visited[nx][ny] = true;  // bool 타입이므로 true
                            dist++;
                            q.push({nx, ny});  // ★ 이게 빠져있었음!
                        }
                    }
                }
                boxValue[id] = dist;
                id++;
            }
        }
    }
    
    // 각 1 셀에 대해 결과 계산
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (adj[i][j] == 1) {
                set<int> s;  // 'set' 대신 's' 사용 (std::set과 구분)
                int dist = 1;
                
                FOR(k, 0, 4) {  // i 대신 k 사용
                    int x = i + dx[k];  // dx[i] + i가 아님!
                    int y = j + dy[k];  // dy[i] + j가 아님!
                    if (x >= 0 && y >= 0 && x < n && y < m && 
                        adj[x][y] == 0) {  // == 1이 아니라 == 0
                        s.insert(box[x][y]);
                    }
                }
                
                for (auto it = s.begin(); it != s.end(); it++) {
                    dist += boxValue[*it];
                }
                cout << dist % 10;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
    }
    
    return 0;
}