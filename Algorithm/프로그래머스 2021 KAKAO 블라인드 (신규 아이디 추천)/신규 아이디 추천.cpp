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
	// 1단계 소문자 치환
	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
	string tmp = "";
	//2단계 특정문자 제거
	for (int i = 0; i < new_id.size(); i++) {

		if (new_id[i] >= '0' && new_id[i] <= '9') tmp += new_id[i];
		else if (new_id[i] >= 'a' && new_id[i] <= 'z') tmp += new_id[i];
		else if (new_id[i] == '-' || new_id[i] == '.' || new_id[i] == '_') tmp += new_id[i];

	}
	//3단계 마침표 치환
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
	//4단계 마침표 제거
	answer = SplitDot(answer);
	//5단계 빈문자열에 a 추가
	if (answer == "") answer += 'a';
	//6-1 단계 자리수 판별후 16자 이상이면 자르기
	if (answer.length() >= 15) answer = answer.substr(0, 15);
	//6-2 단계 마침표 제거
	answer = SplitDot(answer);
	//7단계 2자리 이하면 마지막문자 add
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