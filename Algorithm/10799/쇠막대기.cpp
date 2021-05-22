#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

/*
   ������ Ȱ���Ͽ� Ǯ �� �ִ� ����
   ( ) �� ������� ���ÿ� �׿��ִ� ( �� ������ŭ �����ְ�
   ������ ) ) �϶� �Ѱ����� �Ѱ��� �����ָ� ����.
*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	stack<char> s;
	
	string str;
	cin >> str;

	int ans = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else if (str[i] == ')' && str[i - 1] == '(') {
			s.pop();
			ans += s.size();
		}
		else {
			ans++;
			s.pop();
		}
	}

	cout << ans << "\n";
	
	return 0;
}