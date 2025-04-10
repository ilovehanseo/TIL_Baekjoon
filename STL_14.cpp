#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n,m;
//	cin >> n >> m;
//	
//	map<string, int> pocketmon;
//	vector<string> nickname(n + 1);
//
//	string name;
//	int num;
//	
//	for (int i = 0; i < n; i++) {
//		cin >> name;
//		//만약 중복되면 key값을 덮어씀
//		//pocketmon[name] = i + 1;
//
//		//만약 중복되면 무시
//		//pocketmon.insert({ name,i + 1 });
//
//		pocketmon[name] = i + 1;
//
//		nickname[i + 1] = name;
//	}
//	
//	string info;
//
//	for (int i = 0; i < m; i++) {
//		cin >> info;
//		//isdigit 함수 : 문자가 숫자인지 확인해주는 함수
//		if (isdigit(info[0])) {
//			int aNum = stoi(info);
//			cout << nickname[aNum] << '\n';
//		}
//		else
//			cout << pocketmon[info]<<'\n';
//	}
//
//	return 0;
//}

//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m;
//	
//	cin >> n >> m;
//
//	set<string> noListen;
//	set<string> noWatch;
//	vector<string> a;
//	vector<string> b;
//
//	string name;
//	for (int i = 0; i < n; i++) {
//		cin >> name;
//		noListen.insert(name);
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> name;
//		noWatch.insert(name);
//	}
//
//	//iterator(스마트 포인터 느낌)는 원소를 가리키는 역할 -> 포인터 사용!
//	for (auto i = noListen.begin(); i != noListen.end(); ++i) {
//		if (noWatch.find(*i)==noWatch.end()) {
//			a.push_back(*i);
//		}
//	}
//
//	//c++ STL 반복문에선 ++i 전위연산자 사용
//	for (auto i = noWatch.begin(); i != noWatch.end(); ++i) {
//		if (noListen.find(*i) == noListen.end()) {
//			b.push_back(*i);
//		}
//	}
//
//	cout << a.size() + b.size();
//
//	return 0;
//}


//부분집합의 개수 구하기!
int main() {
	string str;
	cin >> str;
	
	set<string> subset;
	
	string word;

	int i = 0;
	size_t size = str.length();

	for (int i = 0; i < size; i++) {
		word = "";
		for (int j = i; j < size; j++) {
			word += str[j];
			subset.insert(word);
		}
	}

	cout << subset.size();

	

	return 0;
}