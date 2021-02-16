#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	string str;
	vector<int> words(n);

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			words[i] |= (1 << (str[j] - 'a'));
		}

	}

	int forget = 0;

	for (int i = 0; i < m; i++)
	{
		int num;
		char w;
		cin >> num;
		cin >> w;

		forget ^= (1 << (w - 'a'));
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			if (forget & words[j]) cnt++;
		}

		cout << n - cnt << "\n";
	}

	return 0;
}