#include <iostream>

using namespace std;

int factorial(int n) {

	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}

int bino_factorial(int n, int r) {
	return factorial(n) / factorial(r) / factorial(n - r);
}

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	cout << bino_factorial(n, k) << "\n";

	return 0;
}