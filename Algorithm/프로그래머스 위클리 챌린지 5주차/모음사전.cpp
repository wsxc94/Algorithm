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
   주어진 단어가 사전에서 몇 번째 단어인지 구하는 문제
*/

/*
   수학적 풀이법 O(word_length)

   앞자리가 A일 경우 1 ~
   앞자리가 E일 경우 782 ~
   앞자리가 I일 경우 1563 ~
   앞자리가 O일 경우 2344 ~
   앞자리가 U일 경우 3125 ~

   A를 기준으로 case 에 대한 경우의 수를 미리 구해논다
   (5^1 + 5^2 + 5^3 + 5^4 + 5^5) / 5 = 781
   (5^1 + 5^2 + 5^3 + 5^4) / 5 = 156
   (5^1 + 5^2 + 5^3) / 5 = 31
   (5^1 + 5^2) / 5 = 6
   (5^1) / 5 = 1

   ex) EIO
   
   첫글자가 E - 1 * 781 + 1 = 782
   두번째 글자가 I - 2 * 156 + 1 = 313
   세번째 글자가 O - 3 * 31 + 1 = 94
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
   DFS + sort 완전탐색 풀이법
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