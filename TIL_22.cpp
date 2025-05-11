#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<cmath>
#include<utility>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

template<typename T>
using Vec = vector<T>;

//후위표기식 계산법 (ex.ABC+*)
/*왼쪽부터 차례로 읽어.

숫자가 나오면 스택에 넣어.

연산자가 나오면 스택에서 숫자 2개를 꺼내 연산하고, 결과를 다시 스택에 넣어.

끝나고 나면 스택에 최종 결과가 하나 남아있어.*/

//int change_priority(char ch) {
//	if (ch == '(' || ch == ')')
//		return 1;
//	else if (ch == '*')
//		return 2;
//	else if (ch == '/')
//		return 2;
//	else
//		return 3;
//}

//1트 - 5-6시간정도? 실패
//vector<char> change_brackets(string& str) {
//	//stack<pair<char, int>> Astr;
//	stack<int> rank_str;
//	vector<char> output;
//	stack<char> bracket;
//
//	output.push_back('(');
//	int flag = 0;
//
//	for (int i = 0;i<str.length();i++) {
//		/*if (str[i] == '(' && str[i + 2] == ')') {
//			output.push_back(str[i + 1]);
//			i += 2;
//			continue;
//		}
//		if (str[i] == '('){
//			rank_str.push(10);
//		}
//		if (str[i] == ')') {
//			rank_str.pop();
//			output.push_back(str[i]);
//			continue;
//		}
//
//		if (!rank_str.empty() && rank_str.top() == 10) {
//			output.push_back(str[i]);
//			continue;
//		}*/
//		if (str[i] == '(') {  // (A) -> 방지
//			if (str[i] == '(' && str[i + 2] == ')') {
//				flag = 1;
//				continue;
//			}
//			else {
//				bracket.push(i);
//			}
//		}
//		else if (str[i] == ')'){
//			if (str[i - 2] == '(' && str[i] == ')') {
//				flag = 0;
//				continue;
//			}
//			else
//				bracket.pop();
//		}
//
//
//		if (bracket.empty()) { //괄호가 없는 세상
//			if (i == 0) {
//			}
//			else if (str[i] >= 'A' && str[i] <= 'Z') {
//				if (str[i] == str.back()) {  //마지막엔 괄호 붙여주기
//					output.push_back(str[i]);
//					output.push_back(')');
//					continue;
//				}
//				else {
//					if (!flag && !rank_str.empty() && change_priority(str[i + 1]) < rank_str.top())
//						output.push_back('(');
//					else if (flag && !rank_str.empty() && change_priority(str[i + 2]) < rank_str.top())
//						output.push_back('(');
//					else {
//						output.push_back(str[i]);
//
//						while (!rank_str.empty()) {
//							output.push_back(')');
//							rank_str.pop();
//						}
//						continue;
//					}
//				}
//			}
//			else {
//				if (!flag)
//					rank_str.push(change_priority(str[i]));
//			}
//		}
//		else {  //괄호가 있는 세상
//			if (str[i] >= 'A' && str[i] <= 'Z') {
//
//			}
//			else {
//
//			}
//		}
//
//		//Astr.push({i,0 });
//
//		output.push_back(str[i]);
//	}
//
//
//	stack<char> test;
//
//	int flag1 = 0;
//
//	for (auto& i : output) {
//		if (i == '(')
//			test.push(i);
//		else if (i == ')') {
//			if (!test.empty())
//				test.pop();
//			else
//				flag1 = 1;
//		}
//	}
//	
//	if (flag1)
//		output.insert(output.begin() + 1, '(');
//	else if (!test.empty())
//		output.push_back(')');
//
//
//	return output;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	string str;
//	cin >> str;
//	stack<char> test;
//	//vector<char> main = change_brackets(str);
//
//	//for (auto& i : main) {
//	//	cout << i;
//	//}
//	//cout << '\n';
//
//	stack<char> bracket;
//	stack<char> account;
//	vector<char> output;
//
//	for (auto& i : main) {
//		if (i == '(' ) {
//			bracket.push(i);
//		}
//		else if (i == ')') {
//			bracket.pop();
//			int prev = 3;
//			
//			while (!account.empty()) {
//				char top =account.top();
//				if (change_priority(top) < prev)
//					break;
//				output.push_back(top);
//				account.pop();
//
//				prev = top;
//			}
//		}
//		else if (i >= 'A' && i <= 'Z') {
//			output.push_back(i);
//		}
//		else {
//			/*if (!account.empty() && (change_priority(account.top()) < change_priority(i))) {
//				output.push_back(account.top());
//				account.pop();
//			}*/  //이걸 쓰면 괄호를 무시하고 이걸 안쓰면? 
//			account.push(i);
//		}
//	}
//	while (!account.empty()) {
//		output.push_back(account.top());
//		account.pop();
//	}
//	for (auto& i : output) {
//		cout << i;
//	}
//
//
//	return 0;
//}

//2트 - 좀 더 하면 성공할거같은데 그전에 내 머리가 먼저 터질것같아서 실패
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	string str;
//	cin >> str;
//	stack<char> account;
//
//	vector<char> output;
//	stack<pair<char,int>>bracket_account;
//	stack<char> bracket;
//
//	
//
//	for (auto& i : str) {
//		if (i == '(') {
//			bracket.push(i);
//			continue;
//		}
//		else if (i == ')') {
//			
//			while (!bracket_account.first.empty() && bracket_account.second == bracket.size()) {
//				output.push_back(bracket_account.first.top());
//				bracket_account.first.pop();
//			}
//
//			bracket.pop();
//
//			continue;
//		}
//
//		if (!bracket.empty()) {    //괄호안
//			if (i >= 'A' && i <= 'Z') {
//				output.push_back(i);
//			}
//			else {
//				if (bracket_account.first.empty()) {
//					bracket_account.first.push(i);
//					bracket_account.second = bracket.size();
//				}
//				else {
//					char tmp_ch = bracket_account.first.top();
//					int tmp_int = bracket_account.second;
//					//기존에 있던게 우선순위가 더 높으면 ex) * -> +
//					if (tmp_int < bracket.size()) {
//						bracket_account.first.push(i);
//					}
//					else {
//						if (change_priority(tmp_ch) <= change_priority(i)) {
//							while (!bracket_account.first.empty()) {
//								output.push_back(bracket_account.first.top());
//								bracket_account.first.pop();
//							}
//							bracket_account.first.push(i);
//						}
//						else {
//							bracket_account.first.push(i);
//						}
//					}
//				}
//
//			}
//		}
//		else {
//			if (i >= 'A' && i <= 'Z') {
//				output.push_back(i);
//			}
//			else {
//				if (account.empty()) {
//					account.push(i);
//				}
//				else {
//					char tmp = account.top();
//					//기존에 있던게 우선순위가 더 높으면 ex) * -> +
//					if (change_priority(tmp) <= change_priority(i)) {
//						while (!account.empty()) {
//							output.push_back(account.top());
//							account.pop();
//						}
//						account.push(i);
//					}
//					else {
//						account.push(i);
//					}
//				}
//			}
//		}
//	}
//	
//	while (!account.empty()) {
//		output.push_back(account.top());
//		account.pop();
//	}
//	for (auto& i : output)
//		cout << i;
//	
//	return 0;
//}


//에라토스테네스의 체
const int MAX = 1000000;
vector<bool> Sieve(MAX + 1, true);

void sieve() {
	Sieve[0] = false;
	Sieve[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (Sieve[i]) {
			for (int j = i * i; j <= MAX; j += i)
				Sieve[j] = false;
		}
	}
}

int count_factor(int n, int k) {
	int count = 0;
	for (long long i = k; i <= n; i *= k) {
		count += n / i;
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	string a, b, c, d;

	cin >> a >> b >> c >> d;

	string num1 = a + b;
	string num2 = c + d;

	//런타임 에러 (int처리용)
	cout << stoi(num1) + stoi(num2);
	//(long long 처리)
	cout << stoll(num1) + stoll(num2);
	*/

	int n, r;
	cin >> n >> r;
	int cnt_2 = count_factor(n, 2) - count_factor(r, 2) - count_factor(n - r, 2);
	int cnt_5 = count_factor(n, 5) - count_factor(r, 5) - count_factor(n - r, 5);
	cout <<min(cnt_2, cnt_5);



	return 0;
}