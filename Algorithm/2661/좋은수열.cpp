#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
bool cmp = false;

bool isValid(string str) {
	
	int last = str.size() - 1;
	for (int i = 1; i <= str.size()/2; i++)
	{
		string a = str.substr(last - i, i);
		string b = str.substr(last, i);
		if (a == b) return false;
		last--;
	}
	return true;
}

void dfs(int cnt, string str) {

	if (cmp) return;
	if (!isValid(str)) return;
	if (cnt == n) {
		cout << str << "\n";
		cmp = true;
		return;
	}
	dfs(cnt + 1, str + '1');
	dfs(cnt + 1, str + '2');
	dfs(cnt + 1, str + '3');
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	dfs(0, "");
	return 0;
}