#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
#include <queue>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template <typename T>
using Vec = vector<T>;

// 이분 그래프 찾기
//  vector<vector<int>> graph;
//  vector<int> color;
//  bool check = true;

// void dfs(int node, int c)
// {
//     color[node] = c;

//     for (auto &next : graph[node])
//     {
//         if (color[next] == 0)
//         {                     // 색이 칠해지지않는 경우
//             dfs(next, 3 - c); // 반대색으로 칠하기
//         }
//         else if (color[next] == color[node])
//         { // 칠한 경우 색이 같음
//             check = false;
//             return;
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int num;
//     cin >> num;
//     int n, m, a, b;

//     FOR(i, 0, num)
//     {
//         check = true;
//         cin >> n >> m;
//         // 정점,간선
//         graph.assign(n + 1, {}); // 이차원 assgin 방법
//         color.assign(n + 1, 0);

//         FOR(i, 0, m)
//         {
//             cin >> a >> b;
//             graph[a].push_back(b);
//             graph[b].push_back(a);
//         }

//         // dfs
//         FOR(i, 0, n)
//         {
//             if (color[i] == 0)
//             {
//                 dfs(i, 1);
//             }
//         }

//         if (check)
//         {
//             cout << "YES";
//         }
//         else
//         {
//             cout << "NO";
//         }
//         cout << '\n';
//     }

//     return 0;
// }
bool isSquare(int n)
{
    int num = sqrt(n);
    if (num * num == n)
    {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string str;
    vector<vector<char>> arr(n, vector<char>(m, 0));
    int size = max(n, m);

    int answer = -1;
    // if (isSquare(0)) cout<<"hanseo";
    FOR(i, 0, n)
    {
        cin >> str;
        FOR(j, 0, m)
        {
            arr[i][j] = str[j];
        }
    }


    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        { // 모든 수 탐색
            for (int dc = -n; dc < n; dc++)
            { // 행 공차
                for (int dr = -m; dr < m; dr++)
                { // 열 공차
                    if (dc ==0 && dr ==0){ continue; }
                    int c = i, r = j;
                    string str = "";

                    while (c < n && r < m && r>=0 &&  c>=0)
                    {
                        str += arr[c][r];
                        if (isSquare(stoi(str)))
                     {
                        answer = max(answer, stoi(str));
                        }
                        c += dc;
                        r += dr;
                    }
                }
            }

            // FOR(d, 1, size)
            // {
            //     for (int Columplus = 0; plus < size; Columplus += d)
            //     {
            //         for (int Rowplus = 0; Rowplus < size; Rowplus += d)
            //         { // 범위 내의 조건 추가
            //             if (j + Columplus < m)
            //                 strNum[0] += arr[i][j + Columplus];
            //             if (i + Columplus < n)
            //                 strNum[1] += arr[i + pluColumpluss][j];
            //             if (j + plus < m && i + plus < n)
            //                 strNum[2] += arr[i + plus][j + plus];
            //             if (j - plus >= 0)
            //                 strNum[3] += arr[i][j - plus];
            //             if (i - plus >= 0)
            //                 strNum[4] += arr[i - plus][j];
            //             if (j - plus >= 0 && i - plus >= 0)
            //                 strNum[5] += arr[i - plus][j - plus];

            //             FOR(i, 0, 6)
            //             {
            //                 int num = stoi(strNum[i]);
            //                 if (isSquare(num))
            //                 {
            //                     answer = max(num, answer);
            //                 }
            //             }

            //             FOR(i, 0, 6)
            //             {
            //                 strNum[i] = " ";
            //             }
            //         }
            //     }
            // }
        }
    }

    cout << answer;

    return 0;
}