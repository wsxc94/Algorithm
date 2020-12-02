#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n, price, ans = 0;
	cin >> n >> price;
	vector<int> coin(n);

	for (int i = n-1; i >= 0; i--)
	{
		cin >> coin[i];
	}

	for (int i = 0; i < coin.size(); i++)
	{
			ans += price / coin[i];
			price = price % coin[i];	
	}
	cout << ans;

	return 0;
}