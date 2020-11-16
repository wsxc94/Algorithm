#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a, int b) {
	return a % b ? gcd(b, a%b) : b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
	
	int arr[101];
	int answer[301];

	int n, m, cnt(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	m = arr[1] - arr[0];
	for (int i = 2; i < n; i++)
	{
		m = gcd(m, arr[i] - arr[i - 1]);
	}

	for (int i = 1; i*i <= m; i++)
	{
		if (m % i == 0) {
			answer[cnt++] = i;
			if (i != m / i) answer[cnt++] = m / i;
		}
	}
	sort(answer, answer + cnt);

	for (int i = 0; i < cnt; i++)
	{
		if (answer[i] != 1) cout << answer[i] << " ";
	}

	return 0;
}