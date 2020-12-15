#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<char> oper(10);
vector<bool> check(10);
vector<int> ans(10);
long long max_ans;
long long min_ans;

long long makenum()
{
	long long num = 0;
	for (int i = 0; i <= n; i++)
	{
		num = (num * 10) + ans[i];
	}
	return num;
}

void dfs(int cur, int idx)
{
	ans[idx] = cur;
	check[cur] = true;
	if (idx == n)
	{
		long long tmp = makenum();
		if (min_ans == 0) min_ans = tmp;
		if (max_ans == 0 || max_ans < tmp) max_ans = tmp;
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (!check[i])
		{
			if (((oper[idx] == '>') && ans[idx] > i) || ((oper[idx] == '<') && ans[idx] < i))
			{
				dfs(i, idx + 1);
				ans[idx + 1] = 0;
				check[i] = false;
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> oper[i];
	}
	for (int i = 0; i <= 9; i++) {
		dfs(i, 0);
		check[i] = false;
	}

	string max_val = to_string(max_ans);
	string min_val = to_string(min_ans);

	if (max_val.length() != n + 1) cout << "0" + max_val << '\n';
	else cout << max_val << '\n';
	if (min_val.length() != n + 1) cout << "0" + min_val << '\n';
	else cout << min_val << '\n';
	return 0;
}