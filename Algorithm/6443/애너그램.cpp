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
#include <algorithm>
using namespace std;
/*
    문자열을 입력받은 후
    정렬 후 순열을 출력해주면된다.
*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < s.size(); i++)
	{
		sort(s[i].begin(), s[i].end());
		do
		{
			cout << s[i] << "\n";
		} while(next_permutation(s[i].begin() , s[i].end()));
	}

	return 0;
}