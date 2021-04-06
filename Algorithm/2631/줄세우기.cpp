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
   ���� ���� ���� �ִ� ���� ���� ���� ������ ���ϰ�
   �����ϴ� �κм����� �� Ŀ������ �� Ŀ���ٸ� �����Ѵ�

*/
constexpr int MAX = 201;

int arr[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (ans < dp[i]) ans = dp[i];
	}

	cout << n - ans << "\n";

	return 0;
}