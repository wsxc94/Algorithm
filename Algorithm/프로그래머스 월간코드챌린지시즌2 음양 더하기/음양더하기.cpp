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
   https://programmers.co.kr/learn/courses/30/lessons/76501

   정수들의 절댓값을 차례대로 넣은 absolutes 배열과
   정수들의 부호를 차례대로 넣은 signs 배열을 통해
   answer를 구하는 문제

   true = +
   false = -

*/
int solution(vector<int> absolutes, vector<bool> signs) {
	int answer = 0;

	for (int i = 0; i < absolutes.size(); i++) {

		if (signs[i]) answer += absolutes[i];
		else answer -= absolutes[i];
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<int> absolutes = { 4,7,12 };
	vector<bool> signs = { true,false,true };

	cout << solution(absolutes, signs);

	return 0;
}