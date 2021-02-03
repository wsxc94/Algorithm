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
string SplitDot(string s) {
	if (s.front() == '.') s.erase(s.begin());
	if (s.back() == '.') s.erase(s.end() - 1);

	return s;
}
string solution(string new_id) {
	string answer = "";
	// 1�ܰ� �ҹ��� ġȯ
	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
	string tmp = "";
	//2�ܰ� Ư������ ����
	for (int i = 0; i < new_id.size(); i++) {

		if (new_id[i] >= '0' && new_id[i] <= '9') tmp += new_id[i];
		else if (new_id[i] >= 'a' && new_id[i] <= 'z') tmp += new_id[i];
		else if (new_id[i] == '-' || new_id[i] == '.' || new_id[i] == '_') tmp += new_id[i];

	}
	//3�ܰ� ��ħǥ ġȯ
	int cnt = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '.')cnt++;
		else {
			if (cnt >= 1) {
				answer += '.';
				cnt = 0;
			}
			answer += tmp[i];
			cnt = 0;
		}
	}
	//4�ܰ� ��ħǥ ����
	answer = SplitDot(answer);
	//5�ܰ� ���ڿ��� a �߰�
	if (answer == "") answer += 'a';
	//6-1 �ܰ� �ڸ��� �Ǻ��� 16�� �̻��̸� �ڸ���
	if (answer.length() >= 15) answer = answer.substr(0, 15);
	//6-2 �ܰ� ��ħǥ ����
	answer = SplitDot(answer);
	//7�ܰ� 2�ڸ� ���ϸ� ���������� add
	while (true) {
		if (answer.length() > 2) break;
		answer += answer.back();
	}
	return answer;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s = "...!@BaT#*..y.abcdefghijklm";
	cout << solution(s) << "\n";
	return 0;
}