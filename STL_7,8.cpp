#include<iostream>
#include<cmath>
using namespace std;
//1 -> 1         
//2 ~ 8 -> 2       
//8 ~ 20 -> 3    
// 20 ~ 38 -> 4  
// 38 ~ 62 -> 5 
//a1 = 2 , a2 = a1+ 6 , a3 = a2 + 12 ,
//계차수열 일반항 구하기
//int num(int n) {
//	if (n == 1)
//		return 2;
//	return num(n - 1) + 6 * (n - 1);
//}

//수학도둑 달팽이 문제
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, v, cnt = 1;
	cin >> a >> b >> v;

	
	//시간초과
	/*while (1) {
		v -= a;
		if (v <= 0) {
			cout << cnt << endl;
			break;
		}

		v += b;
		cnt++;
	}*/
	if (v - a > a - b) {
		cnt = (v - a) / (a - b);
		if ((v-a) % (a - b) != 0)
			cnt++;

		cout << cnt + 1 << endl;
	}
	else {
		if (v == a) {
			cout << 1;
			return 0;
		}
		else
			cout << 2;
	}
	return 0;
}
//10 9 10