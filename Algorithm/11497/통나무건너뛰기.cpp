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
   각통나무의 인접한 높이차이의 최소값을 구하는 문제

   정렬 후 2칸 떨어진 통나무와의 높이 차이의 최대값이 곧 답이 된다.

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