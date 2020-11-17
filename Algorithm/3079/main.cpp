#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() { // 입국심사 

	int n, m;

	cin >> m >> n;

	vector<int> times;

	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		times.push_back(tmp);
	}

	long long min = 1;
	long long max = *max_element(times.begin(), times.end()) * (long long)n;
	long long mid = (min + max) >> 1;
	long long answer = max;
	long long sum;

	while (min <= max)
	{
		sum = 0;
		mid = (min + max) >> 1;
		for (int i = 0; i < times.size(); i++)
		{
			sum += mid / times[i];
		}
		if (sum < n) min = mid + 1;
		else {
			if (mid <= answer) answer = mid;
			max = mid - 1;
		}

	}
	cout << answer << endl;
	return 0;
}