#include <iostream>
#include <vector>

using namespace std;

long long triangle[101] = { 0, };

long long dp(int num) {

	if (num == 1 || num == 2 || num == 3) return 1;

	if (triangle[num] != 0) return triangle[num];

	return triangle[num] = dp(num - 3) + dp(num - 2);

}
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	long long n,m;
	cin >> n;

	for (long long i = 0; i < n; i++)
	{
		cin >> m;
		cout << dp(m) << "\n";
	}
	return 0;
}