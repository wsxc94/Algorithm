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

int prime[20] = { 2,3,5,7,11,13,17 };
double teamA, teamB;
double dp[20][20][20];

double func(int a, int b, int cnt) {
	if (cnt == 18) {
		for (int i = 0; i < 7; i++) {
			if (a == prime[i] || b == prime[i]) {
				return (double)1.0;
			}
		}
		return 0;
	}
	double& res = dp[a][b][cnt];
	if (res != -1.0) {
		return res;
	}
	double ans = 0;
	ans += (1 - teamA)*(1 - teamB)*func(a, b, cnt + 1);
	ans += (1 - teamA)*teamB*func(a, b + 1, cnt + 1);
	ans += teamA * (1 - teamB)*func(a + 1, b, cnt + 1);
	ans += teamA * teamB*func(a + 1, b + 1, cnt + 1);

	return res = ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> teamA >> teamB;
	teamA = teamA / 100;
	teamB = teamB / 100;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < 20; k++) {
				dp[i][j][k] = -1.0;
			}
		}
	}

	cout << func(0, 0, 0) << "\n";
	
	return 0;
}