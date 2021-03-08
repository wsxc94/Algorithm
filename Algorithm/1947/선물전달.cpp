#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
/*
     
	완전순열
	N개의 원소로 이루어진 집합에서 나온 순열중 한가지는 A
	한가지는 B라고 할 때 같은 위치에 같은 원소가 한가지도 없는 경우다.
	ex ) 1 2 3 , 3 1 2 (o)
	ex ) 1 2 3 , 1 3 2 (x)

	따라서 점화식은 dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])
  
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