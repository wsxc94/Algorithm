#include <iostream>

using namespace std;

#define MAX_DP 1020

int main() {
	
	ios::sync_with_stdio(false), cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	int mat[MAX_DP][MAX_DP] = { 0, };

	mat[1][1] = 1;

	for (int i = 2; i <= n + 1; i++)
	{
		for (int j = 1; j <= n + 1; j++)
		{
			mat[i][j] = (mat[i - 1][j] + mat[i - 1][j - 1]) % 10007;

		}
	}

	cout << mat[n + 1][k + 1] << "\n";
	return 0;
}