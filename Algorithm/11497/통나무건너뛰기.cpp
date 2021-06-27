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
#include <set>
using namespace std;
/*
   ���볪���� ������ ���������� �ּҰ��� ���ϴ� ����

   ���� �� 2ĭ ������ �볪������ ���� ������ �ִ밪�� �� ���� �ȴ�.

*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, ans = 0;

		cin >> n;

		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size() - 2; i++) {
			ans = max(ans, abs(v[i] - v[i + 2]));
		}

		cout << ans << "\n";
	}
	
	return 0;
}