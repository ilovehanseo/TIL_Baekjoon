#include<iostream>
using namespace std;

//세로읽기
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//		
//	string str[15];
//	int size[15];
//	int max = 0;
//
//	for (int i = 0; i < 5; i++) {
//		cin >> str[i];
//		size[i] = str[i].length();
//		if (max < size[i])
//			max = size[i];
//	}
//
//	for (int i = 0; i < max; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (i<str[j].length())  //해당 문자열의 길이를 넘지 않는 경우만 출력
//				cout << str[j][i];
//		}
//	}
//
//
//	return 0;
//}

//25 10 5 1
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	int rest_M[4] = { 0 };
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				rest_M[i] = m / 25;
				m = m % 25;
			}
			else if (i == 1) {
				rest_M[i] = m / 10;
				m = m % 10;
			}
			else if (i == 2) {
				rest_M[i] = m / 5;
				m = m % 5;
			}
			else {
				rest_M[i] = m;
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << rest_M[i] << " ";
		}
		cout << endl;
	}

	return 0;
}

