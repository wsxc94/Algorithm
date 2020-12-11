#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;

constexpr int MAX_NUM = 1000000;

vector<bool> check(MAX_NUM+1, false);
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n = 0, cnt = 0;
	for (int i = 2; i <= sqrt(MAX_NUM); i++)
	{
		if (check[i]) continue;
		for (int j = i + i; j <= MAX_NUM; j += i)
		{
			check[j] = true;
		}
	}
	check[0] = check[1] = true;

	while (true)
	{
		cin >> n;
		if (n == 0) break;
		
		for (int i = 3; i <= MAX_NUM; i++)
		{
			if (!check[i] && !check[n - i]) {
				cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
		}
	}
	return 0;
}