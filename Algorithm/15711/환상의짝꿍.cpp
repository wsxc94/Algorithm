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

constexpr int MAX_NUM = 2000000;
vector<int> primeNum;
vector<bool> check(MAX_NUM + 1, false);
long long n, m, sum;

bool isPrime(long long num) {

	if (num <= MAX_NUM) return !check[num];
	else {
		for (int i = 0; i < primeNum.size(); i++)
			if (num % primeNum[i] == 0)
				return false;
		return true;
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int T;
	cin >> T;

	check[0] = check[1] = true;
	for (int i = 2; i <= MAX_NUM; i++)
	{
		if (!check[i]) {
			primeNum.push_back(i);
			for (int j = i + i; j <= MAX_NUM; j += i)
			{
				check[j] = true;
			}
		}
	}

	while (T--)
	{
		cin >> n >> m;
		sum = n + m;
		if (sum == 2) cout << "NO\n";
		else if (sum % 2 == 0) cout << "YES\n";
		else {
			if (isPrime(sum - 2)) cout << "YES\n";
			else cout << "NO\n";
		}

	}
	return 0;
}