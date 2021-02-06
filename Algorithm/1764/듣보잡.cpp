#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int n, m;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<string> listen(n);
	vector<string> look;
	for (int i = 0; i < n; i++) {
		cin >> listen[i];
	}
	
	sort(listen.begin(), listen.end());
	
	string s;

	for (int i = 0; i < m; i++) {
		cin >> s;
		int low = 0, high = n - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (listen[mid] == s) {
				look.push_back(s);
				break;
			}
			else if (listen[mid].compare(s) > 0) { // 사전적으로 앞에 있는 경우
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}
	sort(look.begin(), look.end());

	cout << look.size() << "\n";
	for (int i = 0; i < look.size(); i++)
	{
		cout << look[i] << "\n";
	}


	return 0;
}