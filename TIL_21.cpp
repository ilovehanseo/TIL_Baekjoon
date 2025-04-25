#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, an, prev = 0;
//	cin >> n;
//	an = n;
//
//	stack<int> oks;
//	stack<int> oks_tmp;
//	vector<int> output(n);
//	vector<int> arr(n);
//
//	FOR(i, 0, n) {
//		cin >> arr[i];
//	}
//
//	//O(n**2)의 시간 복잡도
//	//while (true) {
//	//	if (oks.empty())
//	//		break;
//	//	int tmp = oks.top();
//	//	oks.pop();
//
//	//	if (prev) {
//	//		if (prev > tmp) { 
//	//			output[--an] = prev;
//	//			oks_tmp.push(prev);
//	//		}
//	//		else if (oks_tmp.empty()) { 
//	//			output[--an] = -1;
//	//		}
//	//		else {           
//	//			int top = oks_tmp.top();
//	//			if (top > tmp) {
//	//				output[--an] = top;
//	//				oks_tmp.pop();
//	//			}
//	//			/*else if (oks_tmp.size() > 1) {
//	//				stack<int> storage;
//	//				storage = oks_tmp;
//	//				int flag = 0;
//	//				while (true) {
//	//					oks_tmp.pop();
//	//					if (oks_tmp.empty())
//	//						break;
//	//					top = oks_tmp.top();
//	//					if (top > tmp) {
//	//						output[--an] = top;
//	//						flag = 1;
//	//						break;
//	//					}
//	//				}
//	//				oks_tmp = storage;
//
//	//				if (!flag) {
//	//					output[--an] = -1;
//	//				}
//	//			}*/
//	//			else
//	//				output[--an] = -1;
//	//		}
//	//	}
//	//	else {
//	//		output[--an] = -1;
//	//	}
//	//	prev = tmp;
//	//}
//	
//	//O(n)의 시간 복잡도 : 단조 스택
//	for (int i = n - 1; i >= 0; i--) {
//		if (oks.empty()) {
//			oks.push(arr[i]);
//			output[i] = -1;
//		}
//		else {
//			int top = oks.top();
//			if (top > arr[i]) {
//				oks.push(arr[i]);
//				output[i] = top;
//			}
//			else {
//				while (true) {
//					oks.pop();
//					if (oks.empty()) {
//						oks.push(arr[i]);
//						output[i] = -1;
//						break;
//					}
//					int top = oks.top();
//					if (top > arr[i]) {
//						oks.push(arr[i]);
//						output[i] = top;
//						break;
//					}
//				}
//			}
//		}
//	}
//
//
//	for (auto& i : output) {
//		cout << i << " ";
//	}
//
//
//	return 0;
//}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	stack<pair<int, int>> oks;

	vector<int> output(n);
	vector<int> arr(n);
	vector<int> cnt(1000001, 0);

	FOR(i, 0, n) {
		cin >> arr[i];
	}
	
	FOR(i, 0, n) {
		cnt[arr[i]]++;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (oks.empty()) {
			oks.push({ cnt[arr[i]],arr[i] });
			output[i] = -1;
		}
		else {
			int top = oks.top().first;
			int atop = oks.top().second;
			if (top > cnt[arr[i]]) {
				oks.push({ cnt[arr[i]],arr[i]});
				output[i] = atop;
			}
			else {
				while (true) {
					oks.pop();
					if (oks.empty()) {
						oks.push({ cnt[arr[i]],arr[i] });
						output[i] = -1;
						break;
					}
					int top = oks.top().first;
					int atop = oks.top().second;

					if (top > cnt[arr[i]]) {
						oks.push({ cnt[arr[i]],arr[i] });
						output[i] = atop;
						break;
					}
				}
			}
		}
	}


	for (auto& i : output) {
		cout << i << " ";
	}
	return 0;
}