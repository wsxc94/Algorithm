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

char str[16];
int n, m;

void dfs(int idx, string word, int mo, int ja){

	if (word.size() == n)	{
		if (mo >= 1 && ja >= 2)
			cout << word << endl;
		return;
	}

	for (int i = idx; i <= m; i++){
		if (str[i] == 'a' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o' || str[i] == 'e')
			dfs(i + 1, word + str[i], mo + 1, ja);
		else
			dfs(i + 1, word + str[i], mo, ja + 1);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= m; i++){
		cin >> str[i];
	}
	sort(str, str + m + 1);
	dfs(1, "", 0, 0);

	return 0;
}