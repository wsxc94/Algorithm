#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

map<string, double> m;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string str;
	int cnt = 0;

	while (getline(cin , str))
	{
		cnt++;
		m[str]++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto& item : m)
	{
		double percent = item.second;
		percent /= cnt;
		percent *= 100.0;

		cout << item.first << " " << percent << "\n";

	}

	return 0;
}