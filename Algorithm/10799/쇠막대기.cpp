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
   스택을 활용하여 풀 수 있는 문제
   ( ) 가 만날경우 스택에 쌓여있는 ( 의 개수만큼 더해주고
   마지막 ) ) 일때 총개수에 한개를 더해주면 끝남.
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