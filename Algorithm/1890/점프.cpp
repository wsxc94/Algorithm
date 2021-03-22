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

/*
   dp [a][b] ���� �� �� �ִ� ����� ���� ���ϴ� ����
   ���� ��ġ���� ������, �Ʒ� �������� �̵��ϸ鼭 dp���� �����ָ��

*/
int mat[101][101];
long long dp[101][101];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}
	dp[0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) continue;
			int cost = mat[i][j];
			int d = cost + i;
			int r = cost + j;
			
			if (d < n) dp[d][j] = dp[d][j] + dp[i][j];
			if (r < n) dp[i][r] = dp[i][r] + dp[i][j];
		}
	}
	cout << dp[n - 1][n - 1] << "\n";


	return 0;
}