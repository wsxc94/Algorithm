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
   https://programmers.co.kr/learn/courses/30/lessons/76502?language=cpp
   
   ���ڿ� s �� ũ�⸸ŭ ��ȣ�� �������� ��ĭ�� ȸ���ϸ鼭 �� ������ ���ڿ��� �ùٸ� ��ȣ���� ���ϴ� ����
   ������ ���� ���� ��ȣ �϶� �߰� �ݴ� ��ȣ �϶� ¦�� �´� ���� ��ȣ�� pop ���ִ� ������ ��� ����
   �������� ������ ����ִٸ� �ùٸ� ��ȣ �����̹Ƿ� answer++
*/
bool check(string s) {
	stack<char> st;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
		else {
			if (st.empty()) return false;

			else if (s[i] == ']' && st.top() == '[') st.pop();
			else if (s[i] == '}' && st.top() == '{') st.pop();
			else if (s[i] == ')' && st.top() == '(') st.pop();
		}
	}
	if (!st.empty()) return false;
	return true;

}
int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.size(); i++) {

		if (check(s)) answer++;
		char tmp = s.front();
		s.erase(s.begin());
		s.push_back(tmp);
	}
	
	return answer;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s = "[](){}";
	//string s = "}]()[{";
	cout << solution(s);
	return 0;
}