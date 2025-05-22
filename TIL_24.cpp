#include<iostream>
#include<vector>
#include<algorithm>

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
//�ݺ��Ǵ� ������ �߰�������, ��� + �޸������̼Ǻ��� �õ��غ�.
//�� �״��� ���Ҿ����� ����ȭ ����
//
//�׸���� �� �� ������, ��� ����� ������ �ʿ��ϸ� DP��.

const int mod = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	//vector<vector<long long>> DP(n+1, vector<long long>(10));

	vector<int> arr(n);
	vector<int> DP(n, 0);   //DP[i] -> i��° ���� �߰��� �ִ����.
	FOR(i, 0, n) {
		cin >> arr[i];
	}
	DP[0] = 1;

	int max = 1, cnt = 0;


	//������
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
					max_idx = i;  //���� ū �ε��� ���� �� �� ���� �ε������� ������
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