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
   
   문자열 s 의 크기만큼 괄호를 왼쪽으로 한칸씩 회전하면서 그 차례의 문자열이 올바른 괄호인지 구하는 문제
   스택을 만들어서 여는 괄호 일땐 추가 닫는 괄호 일땐 짝이 맞는 열린 괄호면 pop 해주는 식으로 계속 간다
   마지막에 스택이 비어있다면 올바른 괄호 상태이므로 answer++
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