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
   �÷��̵� �ͼ� �˰����� ����
   �� ȸ���� ����������� �Ÿ��� ã�� ������ �ް� �Ѵ�.
   �׸��� ȸ���� �߿� ���� ������ ���� ����� ã�� ȸ���� �� �� �ִ� ��� ����� ã�� �� �ִ�.

*/
int mat[50][50];
int dist[50];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;

		mat[a][b] = 1;
		mat[b][a] = 1;

	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (mat[j][i] == 0 || mat[i][k] == 0 || j == k) continue;
				if (mat[j][k] == 0 || mat[j][k] > mat[j][i] + mat[i][k]) mat[j][k] = mat[j][i] + mat[i][k];
			}
		}
	}

	int minNum = 987654321;

	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int j = 1; j <= n; j++)
		{
			ans = max(ans, mat[i][j]);
		}
		dist[i] = ans;
		minNum = min(minNum, ans);
	}

	int pNum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (minNum == dist[i]) pNum++;
	}

	cout << minNum << " " << pNum << "\n";

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == minNum) cout << i << " ";
	}
	
	return 0;
}