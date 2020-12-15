#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

long long n, m, sum;

long long power(long long x, long long y, long long mod) {
	long long res = 1;
	x %= mod;
	while (y) {
		if (y % 2) res = (res * x) % mod;
		y /= 2;
		x = (x*x) % mod;
	}
	return res;
}

//if n is prime, return true
bool miller(long long n, long long a) {
	if (a % n == 0) return false;
	long long k = n - 1;
	while (1) {
		long long temp = power(a, k, n);
		if (temp == n - 1) return true; //a^k = -1 (mod n)
		if (k % 2) return (temp == 1 || temp == n - 1);
		k /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> n >> m;
		
		if (miller(n, m)) cout << "YES" << "\n";
		else cout << "NO" << "\n";

	}
	return 0;
}