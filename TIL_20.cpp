#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstdbool>
#include<queue>
#include<deque>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;

int main() {
	int n,m;
	cin >> n >> m;

	queue<int> q;
	queue<int> q_tmp;
	
	FOR(i, 1, n + 1) {
		q.push(i);
	}

	int cnt = 0, flag = 0;
	cout << "<";

	//원형 큐 구현
	//sol1) 매우 비효율적
	//while (true) {
	//	cnt++;
	//	
	//	if (cnt % m!=0) {
	//		q_tmp.push(q.front());
	//		q.pop();
	//	}
	//	else{
	//		
	//		if (flag)
	//			cout << ", ";
	//		cout << q.front();
	//		q.pop();
	//		flag++;
	//	}
	//	if (q.empty()) {
	//		q = q_tmp;
	//		/*while (true) {
	//			if (q_tmp.empty())
	//				break;
	//			else
	//				q_tmp.pop();
	//		}*/
	//		q_tmp = queue<int>();

	//		cnt %= 3;
	//	}
	//	if (q.empty() && q_tmp.empty())
	//		break;
	//	/*if (q.size() < n && q_tmp.empty())
	//		break;*/
	//}

	
	//sol2) 효율적
	/*while (true) {
		cnt++;
		if (cnt % m!=0) {
			q.push(q.front());
			q.pop();
		}
		else{
			if (flag)
				cout << ", ";
			cout << q.front();
			q.pop();
			flag++;
		}

		if (q.empty())
			break;
		
	}*/

	cout << ">";
	
	return 0;
}