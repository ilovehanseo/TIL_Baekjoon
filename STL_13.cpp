#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>

using namespace std;


// 벡터를 const 참조로 전달 (읽기 전용), 수정하면 const 사용 x
// 배열에는 포인터, 벡터는 참조 (메모리 효율적)
//int find_Dup(const vector<pair<string, bool>>& v, const string& str,const int i) {
//    for (int i = 0; i < i; i++) {
//        if (v[i].first == str) {
//            return i; // 중복 발견 시 인덱스 반환
//        }
//    }
//    return -1; // 중복 없음
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

   // vector<pair<string, bool>> v;
    vector<string> names;

    string name, action;

    for (int i = 0; i < n; i++) {
        cin >> name >> action;
        if (action == "enter") {
            names.push_back(name);
        }
        else {
            auto it = find(names.begin(), names.end(), name);
            if (it != names.end())
                names.erase(it);
        }
        
    }

    /*int dup = find_Dup(p, p[i].first, i);
    if (dup == -1) {
        if (goin == "enter") {
            p[i].second = true;
        }
        else {
            p[i].second = false;
        }
    }
    else {
        if (goin == "enter") {
            p[dup].second = true;
        }
        else {
            p[dup].second = false;
        }
        p.erase(p.begin() + i);
    }*/

    //역순 정렬
    //sol1) 
    /*sort(names.begin(), names.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
        });*/
    //sol2)
    sort(names.rbegin(), names.rend());

    //sort 커스텀 비교자
    
    //greater<>() - 내림차순 정렬
    //vector<int> v = { 3, 1, 5, 2 };
    //sort(v.begin(), v.end(), greater<int>());  // 내림차순
    // 결과: v = {5, 3, 2, 1}

    //복합 정렬
    //sort(people.begin(), people.end(), [](auto& a, auto& b) {
    //    if (a.second != b.second) return a.second < b.second; // 나이 오름차순
    //    return a.first < b.first; // 나이가 같으면 이름순
    //    });

    //stable_sort() 정렬 기준이 동일한 경우 원래 순서 유지

    for (const auto& vec : names) {
        cout << vec << "\n";
    }

    return 0;
}