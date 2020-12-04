#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;

constexpr int MAX_NUM = 1001;
vector<bool> check(MAX_NUM << 1, false);
vector<int> num;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n , input;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (!check[input + MAX_NUM]) {

			num.push_back(input);
			check[input + MAX_NUM] = true;
		}
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}
	return 0;
}