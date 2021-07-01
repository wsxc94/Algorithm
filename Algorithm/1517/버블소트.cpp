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
   �־��� ������ ���ؼ� ���� ��Ʈ�� ������ �� Swap�� ��� �߻��ϴ��� ���ϴ� ����

   �Ϲ����� �����Ʈ(O(n^2))�� swap�� ī��Ʈ�� ���� �ð��ʰ��� �Ͼ
   �պ�����(O(n long n))�� ���� ������ �ϸ� ���� ���� ��ġ�� �ٲ�� ��쿡 swap �� �Ǵ� �� ������ �Ÿ� ī��Ʈ�� ���ָ� �ȴ�
   �� �Ÿ��� �������� �̵� Ƚ�� �� ����. ��ƴ�
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