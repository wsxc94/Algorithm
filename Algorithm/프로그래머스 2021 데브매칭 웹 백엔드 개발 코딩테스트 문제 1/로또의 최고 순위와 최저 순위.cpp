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
    https://programmers.co.kr/learn/courses/30/lessons/77484
	1~45 숫자중 6개를 찍어 로또를 뽑을 때 현재 번호로 당첨가능한
	최고 순위와 최저 순위를 구하는 문제

	일단 46개의 로또번호를 체크할 수 있는 check 배열을 만들어
	win_nums에 들어 있는 당첨번호를 true로 만든다
	그 후 0번호는 맞는 번호 일 수도 있으며 틀린 번호 일 수도 있으니 따로 zero 카운트를 해준다

	그리고 당첨번호가 아니라면 순위가 하나씩 내려가고 난 후의 rank가 최고 등수가 된다.
	그리고 최저 순위는 0이 다 당첨번호가 아니라는 가정의 rank + zero가 된다.
*/

int check[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int rank = 1;
	int zero = 0;

	for (int i = 0; i < win_nums.size(); i++) {
		check[win_nums[i]] = true;
	}
	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == 0) zero++;
		else if (!check[lottos[i]]) rank++;
	}

	if (rank >= 6) answer.push_back(6);
	else answer.push_back(rank);

	if (rank + zero >= 6) answer.push_back(6);
	else answer.push_back(rank + zero);


	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<int> lottos = { 44,1,0,0,31,25 };
	vector<int> win_nums = { 31,10,45,1,6,19 };

	vector<int> answer = solution(lottos, win_nums);

	for (int a : answer) {
		cout << a << " ";
	}


	return 0;
}