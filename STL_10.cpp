#include<iostream>
#include<string>
#include<cmath>

using namespace std;

//시간 복잡도
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	//sum = pow(n, 3);  -> pow의 반환타입은 double이므로 부동소수점 근사값 반환 ( 부정확함 )
//	//sum = n * n * n;  -> 정확한 계산
//
//	//c++ 진법 변환
//	//static_cast<type>(value)
//
//	return 0;
//} 



//브루트 포스 알고리즘
//모든 경우를 무차별적으로 탐색
//brute force -> 무식한 힘 -> "브루트 포스는 느리지만, 때로는 유일한 해결책이다!"

bool end_judge(int n) {

	//int -> string으로 변경 = to_string
	//string -> int로 변경 = stoi

	//sol1) 정답
	string str = to_string(n);
	return str.find("666") != string::npos;

	//sol2) 시간초과
	/*int cnt = 0;
	while (n > 0) {
		if (n % 10 == 6) {
			cnt++;
			n /= 10;
		}
		else
			cnt = 0;
		if (cnt == 3)
			return true;
	}*/
}

bool multiple_Jug(int n) {
	for (int x = 0; x <= 2000; x++) {
		for (int y = 0; y <= 1000; y++) {
			if (3 * x + 5 * y == n) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//예제1
	//for (int i = 0; i < n; i++) {
	//	for (int j = i+1; j < n; j++) {
	//		for (int k = j+1; k < n; k++) {
	//			sum = arr[i] + arr[j] + arr[k];
	//			if (sum <= m && max<sum) {
	//				max = sum;
	//			}
	//		}
	//	}
	//}

	int n, cnt = 0;
	//cin >> n;
	
	/*for (int i = 3;; i += 3) {
		for (int j = 5;; j += 5) {

		}
	}*/

	cout << pow(2000,1000)<<pow(1000,2000);

	return 0;
}