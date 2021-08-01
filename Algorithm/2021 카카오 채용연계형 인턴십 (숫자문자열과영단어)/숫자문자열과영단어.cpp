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
   https://programmers.co.kr/learn/courses/30/lessons/81301
   
   ���� ���ڿ��� ���ܾ ���� ���ڷ� �ٲٴ� ����

   one4seveneight -> 1478

   �밡�ټ� ���ڿ� ����
   substr �� �̿��� ù���ڰ����� ���� ���ܾ �����ϵ�����

*/
int solution(string s) {

	string answer = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] == 'z') {
				answer += '0';
				i += 3;
			}
			else if (s[i] == 'o') {
				answer += '1';
				i += 2;
			}
			else if (s[i] == 't') {
				if (s.substr(i, 3) == "two") {
					answer += '2';
					i += 2;
				}
				else {
					answer += '3';
					i += 4;
				}
			}
			else if (s[i] == 'f') {
				if (s.substr(i, 4) == "four") {
					answer += '4';
					i += 3;
				}
				else {
					answer += '5';
					i += 3;
				}
			}
			else if (s[i] == 's') {
				if (s.substr(i, 3) == "six") {
					answer += '6';
					i += 2;
				}
				else {
					answer += '7';
					i += 4;
				}
			}
			else if (s[i] == 'e') {
				answer += '8';
				i += 4;
			}
			else if (s[i] == 'n') {
				answer += '9';
				i += 3;
			}

		}
		else
		{
			answer += s[i];
		}
	}
	return stoi(answer);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s = "one4seveneight";

	cout << solution(s);

	return 0;
}