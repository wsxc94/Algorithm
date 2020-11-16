#include <iostream>

using namespace std;

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL);

	int n, start , num;
	cin >> n;
	cin >> start;
	
	for (int i = 0; i < n-1; i++)
	{
		cin >> num;

			cout << start / gcd(start, num)
				<< "/" << num / gcd(start, num) << "\n";

	}
	return 0;
}