#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, min_num = 1000000001, max_num = -1000000001;
vector<int> num, oper;

void dfs(int ans, int idx) {
	if (idx == n)
	{
		if (ans < min_num) min_num = ans;
		if (ans > max_num) max_num = ans;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] > 0)
		{	
			oper[i]--;
			if (i == 0) dfs(ans + num[idx], idx + 1);
			else if (i == 1) dfs(ans - num[idx], idx + 1);
			else if (i == 2) dfs(ans * num[idx], idx + 1);
			else if (i == 3) dfs(ans / num[idx], idx + 1);		
			oper[i]++;
		}
	}
	return;
}
int main() {

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;
	num.reserve(n + 1);
	oper.reserve(5);


	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	
	for (int i = 0; i < 4; i++)
	{
		int tmp;
		cin >> tmp;
		oper.push_back(tmp);
	}

	dfs(num[0], 1);

	cout << max_num << "\n" << min_num;

	return 0;
}