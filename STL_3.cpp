#include<iostream>
using namespace std;

//int main() {
//
//	//성능 향상, c문법 사용 불가능
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int a = 1, b = 1;
//
//	while (1) {
//		cin >> a >> b;
//		if (cin.eof()) break;   //end of file -> 더 이상 읽을 데이터가 없을 때 발생
//		cout << a + b << "\n";
//	}
//
//	return 0;
//
//}

//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	
//	int n,v,cnt=0;
//	int arr[100];
//	fill(arr, arr + 100, 101); //초기화를 원하는 시작위치, 끝위치, 원하는 초기화 값
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	cin >> v;
//
//	for (int i : arr) {
//		if (v == i)
//			cnt++;
//	}
//
//	cout << cnt << endl;
//
//	return 0;
//}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long n;
	long long max, min;
	cin >> n;

	int flag = 0;

	long long* arr = new long long[n];
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		if (!flag) {
			max = arr[i];
			min = arr[i];
		}
		flag++;

	}

	for (long long i = 0; i < n; i++) {
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	cout << min <<" " << max << endl;

	delete[] arr;

	return 0;
}