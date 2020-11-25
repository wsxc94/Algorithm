#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

struct greaterOrder
{
	bool operator() (const string& a, const string& b) const {
		if (a.size() == b.size()) return a < b;
		return a.size() < b.size();
	}
};
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	
	int n;
	cin >> n;

	set<string , greaterOrder> s;

	string tmp;
	
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		
		s.insert(tmp);
	}

	for (auto it : s) {
		cout << it << "\n";
	}

	return 0;
}