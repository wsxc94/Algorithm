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
#include <algorithm>
using namespace std;
int n;
vector<string> v;
vector<int> alpa(26, 0);

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < n; i++)
	{
		string tmp = v[i];
		int len = tmp.length();
		int pow = 1;
		for (int j = len - 1; j >= 0; j--)
		{
			int idx = tmp[j] - 'A';
			alpa[idx] = alpa[idx] + pow;
			pow = pow * 10;
		}

	}
	sort(alpa.begin(), alpa.end() , greater<int>());

	int num = 9, ans = 0;

	for (int i = 0; i < 26; i++)
	{
		if (alpa[i] == 0) continue;
		ans = ans + (alpa[i] * num);
		num--;
	}

	cout << ans << "\n";
	return 0;
}