#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
/*
   입력받은 문자열을 가지고 압축된 부분을 풀이하는 문제
   괄호가 닫히는 시점을 구하는 것이기 때문에 재귀로 깊은곳부터 풀어줌
*/

bool ch[51];
string s;

int dfs(int idx) {
	int cnt = 0;
	for (int i =idx; i < s.size(); i++)
	{
		if (s[i] == '(' && !ch[i]) {
			ch[i] = true;
			int num = s[i - 1] - '0';
			cnt--;
			cnt += num * dfs(i + 1);
		}
		else if (s[i] == ')' && !ch[i])
		{
			ch[i] = true;
			return cnt;
		}
		else if (!ch[i])
		{
			ch[i] = true;
			cnt++;
		}
	}

	return cnt;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> s;
	cout << dfs(0) << "\n";

	return 0;
}