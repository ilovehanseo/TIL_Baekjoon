#include<iostream>
#include<string>

using namespace std;

//버블정렬
void bubble_Sort(int arr[],int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//병합정렬
void merge(int arr[], int l, int mid, int r) {
	int* sorted = new int[r - l + 1];

	int i, j, k;
	i = l;
	j = mid + 1;
	k = 0;

	//한쪽이 전멸할떄까지
	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	//왼쪽이 살아있다면
	while (i <= mid) {
		sorted[k++] = arr[i++];
	}
	
	//오른쪽이 살아있다면
	while (j <= r) {
		sorted[k++] = arr[j++];
	}
	k--;

	//최종 기록
	for (int m = 0; m <= k; m++) {
		arr[l + m] = sorted[m];
	}

	delete[] sorted;
}
void merge_Sort(int arr[],int l,int r) {
	if (l < r) {
		//int mid = l + r / 2;
		int mid = l + (r - l) / 2; //overflow 방지
		
		merge_Sort(arr, l, mid);
		merge_Sort(arr, mid+1, r);

		merge(arr, l, mid, r);
		
	}
}


//기본 계수 정렬 (자연수 조건)
void counting_Sort(int arr[],int n) {
	const int MAX = 10001; 
	int count[MAX] = { 0 };  


	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	for (int i = 1; i < MAX; i++) {
		while (count[i] > 0) {
			cout << i << '\n';
			count[i]--;
		}
	}
}

//누적합 계수 정렬
void stableCountingSort(int arr[], int n) {
	const int MAX = 10001;
	int count[MAX] = { 0 };
	int* output = new int[n];

	// 1. 카운팅
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	// 2. 누적합 계산
	for (int i = 1; i < MAX; i++) {
		count[i] += count[i - 1];
	}

	// 3. 뒤에서부터 안정 정렬
	for (int i = n - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	// 4. 결과 복사 (또는 바로 출력)
	for (int i = 0; i < n; i++) {
		arr[i] = output[i]; // 원본 배열 업데이트
	}

	delete[] output;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	return 0;
}