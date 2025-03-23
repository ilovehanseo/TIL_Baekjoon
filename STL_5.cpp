#include<iostream>

using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string str;
//	cin >> str;
//	
//	sol1) 시간 초과
//	size_t len = str.length();
//
//	int max = 0;
//	int flag = 0;
//	char tmp = ' ';
//	for (char& ch : str) {
//		if (ch >= 'a' && ch <= 'z') {
//			ch -= 32;
//		}
//	}
//	for (int i=0;i<len;i++) {
//		int cnt = 0;
//		for (int j = i; j < len;j++) {
//			if (str[i] == str[j]) {
//				cnt++;
//			}
//		}
//		if (max <= cnt) {
//			if (max == cnt) {
//				cout << '?';
//				return 0;
//			}
//			max = cnt;
//			tmp = str[i];
//		}
//	
//	cout << tmp;
//
//	sol2) 알파벳 배열 활용 
//	int alpha[26] = { 0 };
//	int max = 0;
//	int tmp = 0;
//
//	for (char ch : str) {
//		if (ch >= 'A' && ch <= 'Z') {
//			alpha[ch - 'A']++;
//		}
//		else if (ch >= 'a' && ch <= 'z') {
//			alpha[ch - 'a']++;
//		}
//	}
//	
//	for (int i = 0; i < 26; i++) {
//		if (alpha[i] > max) {
//			max = alpha[i];
//			tmp = i;
//		}
//	}
//	for (int i = 0; i < 26; i++) {
//		if (max == alpha[i] && tmp != i) {
//			cout << '?';
//			return 0;
//		}
//	}
//	cout << (char)(tmp + 'A');
//
//	return 0;
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string Cro_alhap[8] = { "c=","c-"
	,"dz=","d-","lj","nj","s=","z=" };
	
	string str;
	int cnt = 0;
	cin >> str;


	for (int i = 0; i < 8; i++) {
	
		while (true) {
			size_t pos = str.find(Cro_alhap[i]);
			if (pos == string::npos) {
				break;
			}
			if (i != 2) {
				str.replace(pos, 2, "/");
			}
			else {
				str.replace(pos, 3, "/");
			}
			cnt++;
		}
		
	}
	int tmp = 0;

	for (char ch : str) {
		if (ch != '/') {
			tmp++;
		}
	}
	cout << cnt + tmp;





	return 0;
}