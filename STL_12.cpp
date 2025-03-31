#include<iostream>
#include<utility>
#include<tuple>
#include<algorithm>
#include<string>
#include<vector>

//pair에서 두 값을 한번에 바꾸는 swap함수 (utility에 내장)
	/*for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (code[j].first > code[j + 1].first) {
				swap(code[j], code[j + 1]);
			}
		}
	}*/

	//algorithm에 내장된 sort함수 (nlogN)
	//sort(code, code + n);

using namespace std;

//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n;
//	cin >> n;
//
//	pair <int, string>* p = new pair<int, string>[n];
//	
//	for (int i = 0; i < n; i++) {
//		cin >> p[i].second;
//		p[i].first = p[i].second.length();
//	}
//	//람다 함수 사용
//	sort(p, p + n, [](const auto& a, const auto& b) {
//		return a.second > b.second;
//		});
//
//	//중복제거
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		if (i==0 || p[i].second != p[i - 1].second ) { //i==0을 앞에써야 컴파일에러가 안남
//			p[cnt++] = p[i];
//		}
//	}
//	sort(p, p + cnt);
//
//	for (int i = 0; i < cnt; i++) {
//		if (p[i].second.empty())
//			continue;
//		cout << p[i].second << '\n';
//	}
//
//	delete[] p;
//
//	return 0;
//}

//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n;
//	cin >> n;
//
//	vector<tuple<int, string, int>> t(n);
//
//	for (int i = 0; i < n; i++) {
//		cin >> get<0>(t[i]) >> get<1>(t[i]);
//		get<2>(t[i]) = i;
//	}
//
//	sort(t.begin(), t.end(), [](const auto& a, const auto& b) {
//		if (get<0>(a) == get<0>(b))
//			return get<2>(a) < get<2>(b);
//		return get<0>(a) < get<0>(b);  //기본 정렬, 감마 함수 사용시 반드시 표기
//		});
//
//	for (const auto& elem : t) {
//		cout << get<0>(elem) << " " << get<1>(elem) << '\n';
//	}
//
//	return 0;
//}


//중복제거되지 않은 기준, target의 위치
int binary_Search(int arr[],int n,int target) {
	int l = 0;
	int r = n;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] < target) {
			l = mid + 1;
		}
		else
			r = mid;
	}

	return l;
}

//중복제거되지 않은 기준, target의 다음 위치
int Upper_binary_Search(int arr[], int n, int target) {
	int l = 0;
	int r = n;
	
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] <= target) {
			l = mid + 1;
		}
		else
			r = mid;
	}
	if (target == arr[r]) {
		l++;
	}
	return l;
}
