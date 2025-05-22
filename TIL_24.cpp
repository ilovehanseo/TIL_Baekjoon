#include<iostream>
#include<vector>
#include<algorithm>

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
//반복되는 구조를 발견했으면, 재귀 + 메모이제이션부터 시도해봐.
//→ 그다음 바텀업으로 최적화 가능
//
//그리디로 될 것 같지만, 모든 경우의 조합이 필요하면 DP다.

const int mod = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	//vector<vector<long long>> DP(n+1, vector<long long>(10));

	vector<int> arr(n);
	vector<int> DP(n, 0);   //DP[i] -> i번째 숫자 추가시 최대길이.
	FOR(i, 0, n) {
		cin >> arr[i];
	}
	DP[0] = 1;

	int max = 1, cnt = 0;


	//역추적
	vector<int> num(n, -1);

	int max_idx = 0;

	FOR(i, 0, n) {
		int flag = 1;
		for (int j = 0; j <= i; j++) {
			if (arr[i] > arr[j]) {
				if (DP[i] < DP[j] + 1) {
					DP[i] = DP[j] + 1;
					num[i] = j;
				}

				if (max < DP[i]) {
					max = DP[i];
					max_idx = i;  //가장 큰 인덱스 저장 후 그 다음 인덱스부터 역추적
				}

				flag = 0;
			}
		}
		if (flag) {
			DP[i] = 1;
		}
	}

	//FOR(i, 0, n)
	//	cout << DP[i] << '\n';
	cout << max << '\n';
	
	vector<int> tmp;
	while (max_idx!=-1) {
		tmp.push_back(arr[max_idx]);
		max_idx = num[max_idx];
	}

	sort(tmp.begin(), tmp.end());

	for (auto& i : tmp)
		cout << i << " ";


	return 0;
}