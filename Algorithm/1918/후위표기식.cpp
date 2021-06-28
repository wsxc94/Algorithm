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
/*
   주어진 중위 표기법으로 된 수식을 후위 표기법으로 바꾸는 문제
   ex) A*(B+C)  ->  ABC+*
   
   연산자가 아닌 A~Z 알파벳들은 ans 문자열에 넣어준다
   연산자 * / + - 의 경우 stack에 들어있는 top 연산자보다 우선순위가 낮지않으면 top을 바로 ans 문자열에 넣어주고 pop
   * / 가 + - 보다 우선순위가 높기에 if문에서 순서를 정해줌
   ) 닫는 괄호가 나온다면 stack을 ( 여는 괄호가 나올때까지 ans에 넣고 pop 반복
*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s, ans;
	stack<char> oper;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			ans += s[i];
		}
		else {
			if (s[i] == '(') oper.push(s[i]);
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!oper.empty() && (oper.top() == '*' || oper.top() == '/'))
				{
					ans += oper.top();
					oper.pop();
				}
				oper.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
					while (!oper.empty() && oper.top() != '(')
					{
						ans += oper.top();
						oper.pop();
					}
					oper.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!oper.empty() && oper.top() != '(')
				{
					ans += oper.top();
					oper.pop();
				}
				oper.pop();
			}
		}
	}
	while (!oper.empty())
	{
		ans += oper.top();
		oper.pop();
	}

	cout << ans << "\n";

	return 0;
}