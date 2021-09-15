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
#include <set>
using namespace std;
/*
   https://programmers.co.kr/learn/courses/30/lessons/1835?language=cpp
   level 2

   각 프렌즈가 원하는 조건을 입력으로 받았을 때 모든 조건을 만족할 수 있도록 서는 경우의 수를 계산하는 문제

   { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' } 가 나올 수 있는 경우의 수 40320가지 8!

   순열을 통해 각 캐릭터 알파벳 , 기호 , 숫자를 추출해 간격에 따른 절댓값을 구해주며 if문으로 처리해준다.


*/

int find_index(vector<char>& friends, char c) {
	for (int i = 0; i < friends.size(); i++)
		if (c == friends[i]) return i;

	return -1;
}

bool check_equals(int a, int b, int num) {
	return abs(a - b) == num ? true : false;
}

bool check_lessThanSign(int a, int b, int num) {
	return abs(a - b) < num ? true : false;
}

bool check_greaterThanSign(int a, int b, int num) {
	return abs(a - b) > num ? true : false;
}

int solution(int n, vector<string> data) {
	vector<char> friends = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
	int answer = 0;

	do {
		bool cmp = true;

		for (string& s : data) {
			int a = find_index(friends, s[0]);
			int b = find_index(friends, s[2]);
			int num = (s[4] - '0') + 1;

			if (s[3] == '=') cmp = check_equals(a, b, num);
			else if (s[3] == '<') cmp = check_lessThanSign(a, b, num);
			else cmp = check_greaterThanSign(a, b, num);

			if (!cmp) break;
		}

		if (cmp) answer++;

	} while (next_permutation(friends.begin(), friends.end()));

	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n = 2;
	vector<string> data = { "N~F=0" , "R~T>2" };
	cout << solution(n, data);
	
	return 0;
}