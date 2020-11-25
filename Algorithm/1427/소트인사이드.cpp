#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	string s;

	cin >> s;

	sort(s.begin(), s.end() , greater<char>());

	cout << s << "\n";
	
	return 0;
}