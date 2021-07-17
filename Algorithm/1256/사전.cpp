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
   dynamic programming 을 이용해 사전의 문자열을 구하는 문제

   n개의 a , m개의 z로 이루어져 있고 사전에는 알파벳 순서로 수록되어 있다
   n , m , k 가 줭 졌을때 k번째 문자열이 무엇인지 구해야함

   n과 m의 개수에 따른 경우의 수를 봤을 때 점화식은 dp[i][j] = dp[i][j-1] + dp[i-1][j]
   
   ex) n = 2 , m = 2 , k = 2
   dp[2][2] = 6 , dp[2][1] , dp[1][2] = 3 이 되고
   2번째 문자열일 경우 첫문자 = a , dp[2][1]
   dp[2][1]에서도 2번째 이기 때문에 dp[1][1] = 2 , dp[2][0] = 1 , dp[1][1]에 속함
   반복하면 답은 azaz
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