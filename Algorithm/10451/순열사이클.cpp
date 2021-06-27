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
#include <set>
using namespace std;
/*
   ���� ����Ŭ�� ������ ���ϴ� ����
   1 ~ N ��ŭ�� ������ �ٸ� ���ڵ��� ���´�

   ex)
   1 2 3 4 5 6 7 8
   3 2 7 8 1 4 5 6
   
   1 - 3 , 3 - 7 , 7 - 5 , 5 - 1
   2 - 2
   4 - 8 , 8 - 6 , 6 - 4
   �̷� �������� �̾��� 3���� ����Ŭ�� �����

   1~n ��ŭ�� �Է¹��� ���������� �������ְ�
   ch �迭�� ���� �湮���θ� üũ
   v �迭�� ���� �� ������ ����Ǿ� �ִ� ��带 DFS�� Ž���Ͽ�
   �� �׽�Ʈ���̽��� cnt�� �����ָ� �ȴ�.

*/
int ch[1001];
vector<int> v[1001];

void dfs(int idx) {
	ch[idx] = true;

	for (int i = 0; i < v[idx].size(); i++)
	{
		int next = v[idx][i];
		if (ch[next]) continue;
		dfs(next);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, cnt = 0;
		cin >> n;

		memset(ch, 0, sizeof(ch));

		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			v[i].push_back(k);
			v[k].push_back(i);
		}

		for (int i = 1; i <= n; i++)
		{
			if (ch[i]) continue;
			dfs(i);
			cnt++;
			ch[i] = true;
		}

		cout << cnt << "\n";
		
		for (int i = 1; i <= n; i++) v[i].clear();
	}
	
	return 0;
}