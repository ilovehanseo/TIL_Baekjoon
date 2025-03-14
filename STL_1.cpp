#include<iostream>
using namespace std;
//함수 오버로딩
//메서드의 이름은 같고 매개변수의 유형과 개수가 다르도록 하는 것
//함수 오버라이딩
//상속받은 메서드의 내용만 변경하는 것

//템플릿
template <class Any>
Any sum(Any, Any);

int main() {
	int a = 3;
	int b = 4;

	cout << sum(a, b) << endl;

	float c = 3.14;
	float d = 5.14;

	cout << sum(c, d) << endl;
	//error
	//cout << sum(a, c) << endl;

	cout << "github test" << endl;
	//참조
	//미리 정의된 변수의 실제 이름 대신 사용할 수 있는 대용 이름
	cout << divide(a, b) << endl;

	return 0;
}

template<class Any>
Any sum(Any a, Any b) {
	return a + b;
}

template<class Few>
Few divide(Few a, Few b) {
	if (a > 0 && b > 0)
		return a / b;
	else
		cout << "잘못된 입력" << endl;
}