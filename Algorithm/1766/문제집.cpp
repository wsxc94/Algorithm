#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
/*
위상정렬 + 우선순위큐

자신에게 들어오는 노드 수를 계산하고  indegree가 0이 되면 먼저 정렬해주는 것.
위상 정렬은 사이클이 생기면 안된다 indegree가 모두 0보다 크면 사이클이 생긴다는 의미이기에
위상 정렬은 indegree가 0인 것이 하나 이상 존재할 때 가능
*/
int n, m;
vector<int> mat[32001];
int inDegree[32001];

void topological_Sort() {
	priority_queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0) q.push(-i);
	}

	while (!q.empty())
	{
		int cur = -q.top();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < mat[cur].size(); i++)
		{
			int idx = mat[cur][i];
			inDegree[idx]--;
			if (inDegree[idx] == 0) q.push(-idx);
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		mat[a].push_back(b);
		inDegree[b]++;
	}

	topological_Sort();

	return 0;
}