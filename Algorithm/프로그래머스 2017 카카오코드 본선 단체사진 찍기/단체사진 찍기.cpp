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

   �� ����� ���ϴ� ������ �Է����� �޾��� �� ��� ������ ������ �� �ֵ��� ���� ����� ���� ����ϴ� ����

   { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' } �� ���� �� �ִ� ����� �� 40320���� 8!

   ������ ���� �� ĳ���� ���ĺ� , ��ȣ , ���ڸ� ������ ���ݿ� ���� ������ �����ָ� if������ ó�����ش�.


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