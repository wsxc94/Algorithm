#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int cnt = 0;
vector<int> ans;

vector<int> makeTable(string& pattern) {
	int patternSize = pattern.size();

	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string& parent, string& pattern) {

	vector<int> table = makeTable(pattern);
	
	int j = 0;
	for (int i = 0; i < parent.size(); i++)
	{
		while (j > 0 && parent[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (parent[i] == pattern[j])
		{
			if (j == pattern.size() - 1) {
				ans.push_back(i - pattern.size() + 2);
				j = table[j];
				cnt++;
			}
			else {
				j++;
			}
		}

	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string a, b;
	getline(cin, a);
	getline(cin, b);

	KMP(a, b);
	cout << cnt << "\n";
	for (int a : ans) {
		cout << a << "\n";
	}
	return 0;
}