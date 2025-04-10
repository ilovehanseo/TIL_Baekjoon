#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>

using namespace std;

//유클리드 호제법 - 최대공배수 구하는 함수
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

//빠른 소수 판별
bool sosu(long long n) {
	if (n == 1)
		return false;
	for (long long i = 2; i*i <=n; i++) {
		if (n % i == 0)   
			return false;
	}
	return true;
}

//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, cnt = 0;
//	
//	//에라토스테네스의 체
//	while (true) {
//		vector<bool> Sieve(123456 * 2+1, true);
//		Sieve[1] = false;
//
//		cnt = 0;
//		cin >> n;
//		if (n == 0)
//			return 0;
//		/*for (int i = n+1; i <= 2*n; i++) {
//			if (i == 1)
//				continue;
//			if (sosu(i))
//				cnt++;
//		}*/
//
//		for (int i = 2; i * i <= 2 * n; i++) {
//			for (int j = i * i; j <= 2 * n; j+=i){
//				Sieve[j] = false;
//			}
//		}
//
//		for (int i = n + 1; i <= 2 * n; i++) {
//			if (Sieve[i])
//				cnt++;
//		}
//
//		cout << cnt << '\n';
//	}
//	
//
//	return 0;
//}

//골드바흐 파티션
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, num;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> num;
//		int cnt = 0;
//		int half = num / 2;
//		if (sosu(half))
//			cnt++;
//		vector<bool> Sieve(num + 1, true);
//		Sieve[1] = false;
//		for (int i = 2; i * i <= num; i++) {
//			for (int j = i * i; j <= num; j += i) {
//				Sieve[j] = false;
//			}
//		}
//		for (int i = half+1; i <= num; i++) {
//			if (Sieve[i]) {
//				int aN = num - i;
//				if (aN!=1 && Sieve[aN])
//					cnt++;
//			}
//		}
//		cout << cnt << '\n';
//	}
//
//
//	return 0;
//}
#include<cmath>
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, num;
	cin >> n;
	//int(약수의 개수)가 홀수면 열려있음(true)
	//vector<pair<bool, int>> window(n + 1, { true,1 });

	int cnt = 0;
	for (int i = 1; i*i <= n; i++) {
		
		cnt++;
		
	}
	cout << cnt;
	

	return 0;
}