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


//연속된 단어 체크 좀 잘 푼듯?

bool Group_Word(string);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, cnt = 0;
	cin >> n;

	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (Group_Word(str))
			cnt++;
	}

	cout << cnt;

	return 0;
}

bool Group_Word(string str) {
	int alpha[26] = { 0 };
	size_t size = str.length();

	for (char ch : str) { //알파벳의 개수
		alpha[ch - 'a']++;
	}

	for (int i = 0; i < size;) {
		int eng_cnt = alpha[str[i] - 'a'];
		for (int j = i; j < i + eng_cnt; j++) { //개수만큼 이동
			if (str[i] != str[j]) {
				//cout << "연속하지 않습니다" << endl;
				return false;
			}
		}
		i += eng_cnt;
	}
	return true;


}
