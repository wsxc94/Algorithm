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
�������� + �켱����ť

�ڽſ��� ������ ��� ���� ����ϰ�  indegree�� 0�� �Ǹ� ���� �������ִ� ��.
���� ������ ����Ŭ�� ����� �ȵȴ� indegree�� ��� 0���� ũ�� ����Ŭ�� ����ٴ� �ǹ��̱⿡
���� ������ indegree�� 0�� ���� �ϳ� �̻� ������ �� ����
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