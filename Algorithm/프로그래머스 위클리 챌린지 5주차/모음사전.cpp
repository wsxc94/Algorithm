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
   https://programmers.co.kr/learn/courses/30/lessons/84512?language=cpp
   �־��� �ܾ �������� �� ��° �ܾ����� ���ϴ� ����
*/

/*
   ������ Ǯ�̹� O(word_length)

   ���ڸ��� A�� ��� 1 ~
   ���ڸ��� E�� ��� 782 ~
   ���ڸ��� I�� ��� 1563 ~
   ���ڸ��� O�� ��� 2344 ~
   ���ڸ��� U�� ��� 3125 ~

   A�� �������� case �� ���� ����� ���� �̸� ���س��
   (5^1 + 5^2 + 5^3 + 5^4 + 5^5) / 5 = 781
   (5^1 + 5^2 + 5^3 + 5^4) / 5 = 156
   (5^1 + 5^2 + 5^3) / 5 = 31
   (5^1 + 5^2) / 5 = 6
   (5^1) / 5 = 1

   ex) EIO
   
   ù���ڰ� E - 1 * 781 + 1 = 782
   �ι�° ���ڰ� I - 2 * 156 + 1 = 313
   ����° ���ڰ� O - 3 * 31 + 1 = 94
   answer = 1189

*/
constexpr int cases[5] = { 781,156,31,6,1 };

int solution(string word) {
	int answer = 0;

	for (int i = 0; i < word.size(); i++)
		answer += string("AEIOU").find(word[i]) * cases[i] + 1;

	return answer;
}

/*
   DFS + sort ����Ž�� Ǯ�̹�
*/
vector<string> v;
void dfs(string word) {
	if (word.size() == 5) return;
	for (auto c : string("AEIOU"))
	{
		string next = word + c;
		v.push_back(next);
		dfs(next);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string word = "U";
	
	cout << solution(word) << '\n';
	
	dfs("");
	sort(v.begin(), v.end());
	cout << lower_bound(v.begin(), v.end(), word) - v.begin() + 1;


	return 0;
}