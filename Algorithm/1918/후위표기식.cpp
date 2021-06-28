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
   �־��� ���� ǥ������� �� ������ ���� ǥ������� �ٲٴ� ����
   ex) A*(B+C)  ->  ABC+*
   
   �����ڰ� �ƴ� A~Z ���ĺ����� ans ���ڿ��� �־��ش�
   ������ * / + - �� ��� stack�� ����ִ� top �����ں��� �켱������ ���������� top�� �ٷ� ans ���ڿ��� �־��ְ� pop
   * / �� + - ���� �켱������ ���⿡ if������ ������ ������
   ) �ݴ� ��ȣ�� ���´ٸ� stack�� ( ���� ��ȣ�� ���ö����� ans�� �ְ� pop �ݺ�
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