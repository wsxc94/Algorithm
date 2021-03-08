#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
/*
     
	��������
	N���� ���ҷ� �̷���� ���տ��� ���� ������ �Ѱ����� A
	�Ѱ����� B��� �� �� ���� ��ġ�� ���� ���Ұ� �Ѱ����� ���� ����.
	ex ) 1 2 3 , 3 1 2 (o)
	ex ) 1 2 3 , 1 3 2 (x)

	���� ��ȭ���� dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])
  
*/
using namespace std;

constexpr int MOD = 1000000000;
long long dp[1000001];
int n;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
	}
	
	cout << dp[n] << "\n";
	return 0;
}