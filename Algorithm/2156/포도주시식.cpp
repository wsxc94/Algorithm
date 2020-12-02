#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n, ans = 0;
	cin >> n;

	vector<int> arr(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	//3�� ���� ���Ǽ� ���� ������ 3���� ��찡 �ִ�.
	//1. -3��° �ܸ��ð� -2��° �� �ǳʶٰ� -1��° ���� + ����
	//2. -2��° �� ���ð� ���ܸ��ñ�
	//3.���ܾȸ԰� -1��°���� �ִ밪 ���ñ�
	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], max(dp[i - 2] + arr[i], dp[i - 1]));

	}
	cout << dp[n] << "\n";

	return 0;
}