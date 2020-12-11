#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

vector<bool> primeNum;
vector<int> num;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	primeNum.resize(n + 1, false);

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (primeNum[i]) continue;
		for (int j = i+i; j <= n; j+=i)
		{
			primeNum[j] = true;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (!primeNum[i]) num.push_back(i);
	}

	int cnt = 0, high = 0, low = 0, sum = 0;

	while (true)
	{
		if (sum >= n)
			sum -= num[low++];
		else if (high == num.size()) 
			break;
		else
			sum += num[high++];

		if (sum == n)cnt++;
	}

	cout << cnt << "\n";
	return 0;

}