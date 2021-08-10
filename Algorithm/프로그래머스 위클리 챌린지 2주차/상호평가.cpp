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
   
   자기 자신이 매긴 점수가 유일하게 제일 큰 수 이거나 제일 작은 수 일 경우 점수를
   제외하고 평균을 매겨야 하기 때문에
   selfScore = 자기자신을 매긴 점수 를 저장해놓아서
   maxScore , minScore와 같은지 검사한다.


   2021-08-10
   check 배열 초기화를 안해줬던거 수정

*/
int check[101];
char func(float sum, int size) {
	float ave = sum / size;
	//cout << ave << " ";
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
		int maxScore = -1;
		int minScore = 987654321;
		float sum = 0;
		vector<int> v;
		for (int j = 0; j < size; j++) {
			if (j != i) {
				check[scores[j][i]] = true;
				v.push_back(scores[j][i]);
				sum += scores[j][i];
			}
			maxScore = max(maxScore, scores[j][i]);
			minScore = min(minScore, scores[j][i]);

		}
		if ((selfScore == maxScore || selfScore == minScore) && !check[selfScore]) {
			answer += func(sum, size - 1);

		}
		else {
			sum += selfScore;
			answer += func(sum, size);
		}
		for (int a : v) check[a] = false;
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