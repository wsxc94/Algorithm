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
   ���̻� �迭
   ���� ���ڿ��� ��� ���̻縦 ���������� ������ �迭�� ����ϴ� ����
   baekjoon�� ���̻�� baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n
   ���� �� 8������ �ִ�
   1���ھ� �ٿ����鼭 word �迭�� �ְ� �����ϸ�ȴ�.

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