#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;
/*
   주어진 수열에 대해서 버블 소트를 수행할 때 Swap이 몇번 발생하는지 구하는 문제

   일반적인 버블소트(O(n^2))로 swap의 카운트를 세면 시간초과가 일어남
   합병정렬(O(n long n))을 통해 정렬을 하며 정렬 도중 위치가 바뀌는 경우에 swap 이 되는 수 사이의 거리 카운트를 해주면 된다
   이 거리는 버블정렬 이동 횟수 와 같다. 어렵다
*/
constexpr int MAX = 500001;
int n;
int arr[MAX], tmp[MAX];
long long ans;

void divide(int left, int right) {
	int mid, p1, p2, p3;
	if (left < right) {
		mid = (left + right) / 2;
		divide(left, mid);
		divide(mid + 1, right);
		p1 = left;
		p2 = mid + 1;
		p3 = left;

		while (p1 <= mid && p2 <= right) {
			if (arr[p1] <= arr[p2]) {
				tmp[p3++] = arr[p1++];
			}
			else {
				ans += mid - p1 + 1;
				tmp[p3++] = arr[p2++];
			}
		}
		while (p1 <= mid) tmp[p3++] = arr[p1++];
		while (p2 <= right) tmp[p3++] = arr[p2++];

		for (int i = left; i <= right; i++) {
			arr[i] = tmp[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	divide(0, n - 1);

	cout << ans << "\n";
	return 0;
}