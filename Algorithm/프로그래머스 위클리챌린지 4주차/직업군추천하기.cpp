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
#include <sstream>

using namespace std;
/*
    https://programmers.co.kr/learn/courses/30/lessons/84325?language=cpp
	
	�� table�� �ִ� ���ڿ��� stringstream�� ���� ��ũ����¡�� ����
	���Ϳ� ���� �׸��� ������ ���� ��������� ���� ���� �����Ѵ�
	5~1�� ������ ���;ȿ� �ִ� �� key , ������ value�� ��������
	maps���� �����ϰ� ���� ������ ã�� �ش� ���ڸ� ������ش�
*/

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
	string answer = "";
	map<string, map<string, int>> maps;
	int max_score = 0;

	for (int i = 0; i < 5; i++) {
		string token, tmp;
		stringstream ss(table[i]);
		vector<string> v;
		map<string, int> language_map;

		while (ss >> token) v.push_back(token);
		tmp = v[0];

		for (int j = 1; j < 6; j++) {
			language_map[v[j]] = 6 - j;
		}
		maps[tmp] = language_map;
	}

	for (auto iter = maps.begin(); iter != maps.end(); iter++) {
		string tmp = iter->first;
		int score = 0;

		for (int i = 0; i < languages.size(); i++) {
			score += iter->second[languages[i]] * preference[i];
		}
		if (max_score < score) {
			max_score = score;
			answer = tmp;
		}
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<string> table = { "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" };
	vector<string> languages = { "PYTHON", "C++", "SQL" };
	vector<int> preference = { 7,5,5 };
	cout << solution(table, languages, preference);
	return 0;
}