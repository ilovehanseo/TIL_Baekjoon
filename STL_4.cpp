#include<iostream>
#include<string>

using namespace std;

//int main() {       //출석 확인 문제 아이디어 좋은듯
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	
//	bool sign[30] = { 0 };
//	int student[28];
//
//	for (int i = 0; i < 28; i++) {
//		cin >> student[i];
//		sign[student[i] - 1] = true;
//	}
//	for (int i = 0; i < 30; i++) {
//		if (!sign[i]) {
//			cout << i + 1 << endl;
//		}
//	}
//
//	return 0;
//}


//문자열 입력 -> getline
//cin.getline(변수명 , 최대크기)
//cin.getline(str, 1000);  -> char[] 타입만 사용 가능
// //getline(cin, str);  string 공백포함 입력받는방법

//size_t -> 배열의 크기, 메모리 할당 크기, 문자열 길이에 사용
//음수가 아닌 수 표현, 시스템에 따라 크기가 달라짐 - > 호환성 증가

//string + strin (가능)
//string + char (가능)
//char + char (불가능)

//알파벳 찾기 문제
//int main() {
//	
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n, sum=0;
//
//	string str;
//	cin >> str;
//	
//	size_t len = str.length();
//
//	for (int i = 0; i < 26; i++) {
//		size_t pos = str.find(i + 97);
//		if (pos == string::npos)  //string::npos = size_t 타입의 최대값
//			cout << -1 << " ";
//		else
//			cout << pos << " ";
//
//	}
//	//a = 97
//
//
//
//	return 0;
//}

//cin은 공백으로 입력을 분리하는 역할을 함. 
//' ' 공백의 아스키코드값은 32

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	while (1) {
		getline(cin, str);
		if (cin.eof())
			break;
		cout << str << endl;
	}
	

	return 0;

}