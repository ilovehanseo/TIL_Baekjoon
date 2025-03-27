#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;
//
//char Stack[20];
//
////10柳过 -> n柳过
//int BinarySystem(int num,int B) {
//	int cnt = 0;
//	while (num>0) {
//		if (num % B >= 10)
//			Stack[cnt++] = (char)(num % B - 10) + 'A';
//		else
//			Stack[cnt++] = num % B + '0';
//		num /= B;
//		/*if (num < B) {
//			if (num % B >= 10)
//				Stack[cnt] = (char)(num % B - 10) + 'A';
//			else
//				Stack[cnt] = (char)(num + '0');
//			break;
//		}*/
//	}
//	return cnt - 1;
//}
//
////n柳过 -> 10柳过
////int binarySystem(string str, int B) {
////	int sum = 0;
////	size_t size = str.length();
////	for (int i = 0; i < size; i++) {
////		int digit = size - i - 1;
////		if (str[digit] >= 'A' && str[digit] <= 'Z')
////			sum += (str[digit] - 'A' + 10) * pow(B, i);
////		else
////			sum += (str[digit] - '0') * pow(B, i);
////	}
////	return sum;
////}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n, b,cnt;
//	cin >> n >> b;
//	
//	cnt = BinarySystem(n, b);
//	
//	for (int i = cnt; i >=0; i--)
//		cout << Stack[i];
//
//
//	return 0;
//}

// 4 + 5 - 1 -> 8
// 3 / 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, z;
	int big=0, flag = 0;
	while (true) {
		cin >> x >> y >> z;

		if (x == 0 && y == 0 && z == 0)
			return 0;

	
		big = max(x, max(y, z));
		
		if (big == x)
			if (big >= y + z)
				flag = 1;
		if (big == y)
			if (big >= x + z)
				flag = 1;
		if (big == z)
			if (big >= x + y)
				flag = 1;


		if (!flag) {
			if (x == y && y == z)
				cout << "Equilateral"<<endl;
			else if (x != y && y != z && x != z)
				cout << "Scalene" << endl;
			else
				cout << "Isosceles" << endl;
		}
		else
			cout << "Invalid" << endl;
	}

	return 0;
}