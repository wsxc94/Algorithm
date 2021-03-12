#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
/*
   접미사 배열
   받은 문자열의 모든 접미사를 사전순으로 정렬한 배열을 출력하는 문제
   baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n
   으로 총 8가지가 있다
   1글자씩 줄여가면서 word 배열에 넣고 정렬하면된다.

*/

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	vector<string> word;
	word.reserve(s.size());
	word.push_back(s);

	for (int i = 1; i < s.size(); i++)
	{
		word.push_back(s.substr(i, s.size() - 1));
	}

	sort(word.begin(), word.end());

	for (int i = 0; i < word.size(); i++)
	{
		cout << word[i] << "\n";
	}

	return 0;
}