#include<iostream>
#include<string>

using namespace std;

//stack클래스
class Stack
{
public:
	Stack();
	~Stack();
	void push(int element) {
		if (top == capacity - 1) {
			//cout << "Stack overflow" << '\n';
			resize();
		}
		arr[++top] = element;

	}
	int pop() {
		if (top == -1) {
			//cout << "Stack underflow" << '\n';
			return 0;
		}
		return arr[top--];
	}
	void print() {
		cout << "---Print---" << '\n';
		for (int i = top; i >= 0; i--)
			cout << arr[i] << '\n';
		cout << "---end---" << '\n';
	}
	int Size() const {
		return top + 1;
	}
	bool isEmpty() const {
		return (top == -1);
	}

	void clear() {
		top = -1;
	}

private:
	void resize();

	int* arr;
	int capacity;
	int top;
};
Stack::Stack()
{
	capacity = 4;
	arr = new int[capacity];
	top = -1;
}
Stack::~Stack()
{
	delete[]arr;
}

void Stack::resize() {
	int newCapacity = capacity * 2;
	int* newArr = new int[newCapacity];
	for (int i = 0; i <= top; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	capacity = newCapacity;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Stack line;
	Stack leftLine;

	int n, num, t = 1;
	cin >> n;
	bool flag = true;
	int arr[1000];

	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;

	}

	for (int i = n - 1; i >= 0; i--) {
		line.push(arr[i]);
	}
	//line.print();
	/*for (int i = 0; i < n; i++) {
		int tmp = line.pop();
		if (tmp == t) {
			t++;
			continue;
		}
		else {
			leftLine.push(tmp);
		}
	}*/
	for (int i = 0; ; i++) {
		int tmp = line.pop();
		if (tmp != 0) {
			if (tmp == t) {
				t++;
				continue;
			}
			else {
				int ttmp = leftLine.pop();
				if (ttmp == 0) {
					leftLine.push(tmp);
					continue;
				}
				else {
					if (ttmp == t) {
						t++;
						continue;
					}
					else {
						leftLine.push(tmp);
					}
				}
			}
		}
		else {
			int ttmp = leftLine.pop();
			if (ttmp == 0) {
				break;
			}
			else {
				if (ttmp == t) {
					t++;
					continue;
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (t - n == 1)
			break;
	}
	
	if (flag)
		cout << "Nice";
	else
		cout << "Sad";







	return 0;
}