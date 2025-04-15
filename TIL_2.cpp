#include<iostream>
#include<string>

using namespace std;

//int main() {	
//	int a, b,c;
//	cout.precision(9);  //출력되는 숫자의 총 유효 숫자 개수를 9개로 제한
//	cout << fixed;      //소수점 이하 자릿수가 9개로 고정됨
//
//	cin >> a >> b;
//	cout << static_cast<double>(a)/ static_cast<double>(b) << endl;
//	return 0;
//}

//int main() {
//	int num1, num2;
//	int digit[3];
//
//	cin >> num1 >> num2;
//
//	for (int i = 0,  j = 1; i < 3; i++, j *= 10) {
//		digit[i] = num2 / j % 10;
//	}
//
//	for (int i : digit) {   //범위 기반 for문 (단, 동적할당에서는 작용하지 않는다 (c++11이상)
//		cout << num1 * i << endl;
//	}
//
//	cout << num1 * num2 << endl;
//
//
//	return 0;
//
//}

//int main() {
//	cout << "\\    /\\" << endl;  //역슬레시를 출력하고 싶을땐 \\ 두개를 붙인다.
//	cout << " )  ( ')" << endl;
//	cout << "(  /  )"<< endl;
//	cout << " \\(__)|"<< endl;
//
//
//
//	return 0;
//}

int main() {
	cout << "|\\_/|" << endl;  // \" -> "문자열 시작과 끝의 의미를 투명하게 하여 출력
	cout << "|q p|   /}" << endl;
	cout << "( 0 )" << "\"\"\"\\" << endl;
	cout << "|\"^\"`    |" << endl;
	cout << "||_/=\\\\__|" << endl;


	return 0;
}
