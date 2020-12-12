#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
constexpr int MAX_NUM = 100001;

int member[MAX_NUM];
bool visit[MAX_NUM], check[MAX_NUM];
int cnt;

void dfs(int idx) {
	int next_num = member[idx];
	visit[idx] = true;

	if (!visit[next_num]) 
		dfs(next_num);
	else {
		if (!check[next_num]) {
			for (int i = next_num; i != idx; i = member[i])
			{
				cnt++;
			}
			cnt++;
		}
	}
	check[idx] = true;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n;

	while (n--)
	{
		cin >> m;

		memset(member, 0, sizeof(member));
		memset(visit, false, sizeof(visit));
		memset(check, false, sizeof(check));
		
		for (int i = 1; i <= m; i++) 
			cin >> member[i];

		cnt = 0;

		for (int i = 1; i <= m; i++)
			if(!visit[i]) dfs(i);
		

		cout << m - cnt << "\n";

	}
	return 0;
}