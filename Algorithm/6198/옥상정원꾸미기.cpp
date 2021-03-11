#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

/*
    monotone stack 알고리즘

	내려다 볼 수 있는 건물이 아닐 경우 다 pop하며 스택을 채운다.
	10 3 7 4 12 2 가 들어온다 치면
	
	들어오는값         스택                      ans
	v[i] = 10  - 10                              0
	v[i] = 3   - 10 3                            1
	v[i] = 7   - 10 3(pop) 7                     2
	v[i] = 4   - 10 7 4                          4
	v[i] = 12  - 10(pop) 7(pop) 4(pop)           4
	v[i] = 2   - 12 2                            5
	의 결과로 인해 답이 5가 된다.

*/

int n;
long long ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	stack<int> s;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top() <= v[i])
		{
			s.pop();
		}
		ans += (long long)s.size();
		cout << ans << " ";
		s.push(v[i]);
	}
	cout << "\n";
	cout << ans << "\n";
	return 0;
}