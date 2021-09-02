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
    https://programmers.co.kr/learn/courses/30/lessons/43163?language=cpp
	두개의 단어 begin , target과 단어 집합 words을
	1.한 번에 한 개의 알파벳만 바꿀 수 있습니다.
	2.words에 있는 단어로만 변환할 수 있습니다.
	의 규칙을 가지고 begin을 target으로 변환하는 가장 짧은 변환 과정을 찾는 문제

	dfs를 통해 현재 단어와 1글자씩 다른단어를 찾아 순환한다.
*/
int answer = 100;

void dfs(string begin, string target, vector<string> words, vector<bool>& useCheck, int cnt = 0) {
	for (int i = 0; i < words.size(); i++) {
		int count = 0;
		for (int j = 0; j < words[i].length(); j++)
			if (!useCheck[i] && begin[j] != words[i][j]) count++;

		if (count == 1) {
			if (target == words[i] && answer > cnt + 1) {
				answer = cnt + 1;
				return;
			}
			useCheck[i] = true;
			dfs(words[i], target, words, useCheck, cnt + 1);
			useCheck[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	vector<bool> useCheck(words.size(), false);
	dfs(begin, target, words, useCheck);
	if (answer == 100)   return 0;
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };

	cout << solution(begin, target, words);

	return 0;
}