#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n, sum = 0, ans = 0;

	cin >> n;
	
	vector<int> person(n);

	for (int i = 0; i < n; i++)
	{
		cin >> person[i];
	}

	sort(person.begin(), person.end());

	for (int i = 0; i < n; i++)
	{
		sum += person[i];
		ans += sum;
	}

	cout << ans;
	return 0;
}