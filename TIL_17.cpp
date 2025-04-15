//#include<iostream>
//
//using namespace std;
//
//long long factorial(int n) {
//    long long result = 1;
//    for (int i = 2; i <= n; i++) {
//        result *= i;
//    }
//    return result;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, k;
//    cin >> n >> k;
//
//    // nCk = n! / (k! * (n-k)!)
//    long long output = factorial(n) / (factorial(k) * factorial(n - k));
//
//    cout << output;
//
//    return 0;
//}


#include<iostream>

using namespace std;

long long combination(int n, int k) {
    if (k > n - k) k = n - k;  // 대칭 성질 활용

    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;

    cin >> num;
    for (int i = 0; i < num; i++) {
        int n, k;
        cin >> k >> n;

        cout << combination(n, k) << "\n";
    }

    return 0;
}
