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
   https://programmers.co.kr/learn/courses/30/lessons/83201
   자꼬 테스트케이스 20번만 막힌다... 왜 그러지..
   내일 수정예정.

*/
int check[101];

char func(float ave) {
	if (ave >= 90) return 'A';
	else if (ave >= 80) return 'B';
	else if (ave >= 70) return 'C';
	else if (ave >= 50) return 'D';
	else return 'F';
}

string solution(vector<vector<int>> scores) {
	string answer = "";
	int size = scores.size();

	for (int i = 0; i < size; i++) {
		int selfScore = scores[i][i];
		int maxScore = selfScore, minScore = selfScore;
		float sum = selfScore;
		for (int j = 0; j < size; j++) {
			if (j == i) continue;
			check[scores[j][i]] = true;
			maxScore = max(maxScore, scores[j][i]);
			minScore = min(minScore, scores[j][i]);
			sum += scores[j][i];
		}
		if ((selfScore == maxScore || selfScore == minScore) && !check[selfScore]) {
			sum -= selfScore;
			answer += func(sum / (size - 1));

		}
		else {
			answer += func(sum / size);
		}
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<vector<int>> scores = {
	{70,49,90},
	{68,50,38},
	{73,31,100}
	};
	cout << solution(scores);
	return 0;
}