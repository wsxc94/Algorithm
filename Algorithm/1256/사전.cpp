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

using namespace std;
/*
   dynamic programming �� �̿��� ������ ���ڿ��� ���ϴ� ����

   n���� a , m���� z�� �̷���� �ְ� �������� ���ĺ� ������ ���ϵǾ� �ִ�
   n , m , k �� �a ������ k��° ���ڿ��� �������� ���ؾ���

   n�� m�� ������ ���� ����� ���� ���� �� ��ȭ���� dp[i][j] = dp[i][j-1] + dp[i-1][j]
   
   ex) n = 2 , m = 2 , k = 2
   dp[2][2] = 6 , dp[2][1] , dp[1][2] = 3 �� �ǰ�
   2��° ���ڿ��� ��� ù���� = a , dp[2][1]
   dp[2][1]������ 2��° �̱� ������ dp[1][1] = 2 , dp[2][0] = 1 , dp[1][1]�� ����
   �ݺ��ϸ� ���� azaz
*/
constexpr int INF = 1000000000;
int n, m, k;
long long dp[101][101];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= 100; i++) dp[i][0] = dp[0][i] = 1;

	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] > INF) dp[i][j] = INF;
		}
	}

	if (dp[n][m] < k) {
		cout << -1 << '\n';
		return 0;
	}

	int a = n, z = m;

	for (int i = 0; i < n + m; i++) {
		int a_start = dp[a - 1][z];
		int z_start = dp[a][z - 1];

		if (a == 0) {
			cout << 'z';
			z--;
		}
		else if (z == 0) {
			cout << 'a';
			a--;
		}
		else if (k <= a_start)
		{
			cout << 'a';
			a--;
		}
		else {
			k = k - a_start;
			cout << 'z';
			z--;
		}
	}


	return 0;
}