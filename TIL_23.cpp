#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<cmath>
#include<utility>
#include<queue>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;

////-2진법 변환
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int num;
//	cin >> num;
//	
//
//	/*vector<int> output;
//	
//	while (true) {
//		int rest = num % -2;
//		num = num / -2;
//		if (rest == -1) {
//			rest += 2;
//			num += 1;
//		}
//		output.push_back(rest);
//		if (num == 1 || num == 0)
//			break;
//	}
//	if (num == 1)
//		output.push_back(num);
//	for (auto i = output.crbegin(); i < output.crend(); i++)
//		cout << *i;*/
//	
//
//	return 0;
//}

int TO_10(int base,vector<int> arr,int size) {
	int sum = 0;
	int cnt = 1;

	for (int i=size-1;i>=0;i--) {
		sum += cnt * arr[i];
		cnt *= base;
	}
	return sum;
}
