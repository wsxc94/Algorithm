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
#include <set>
using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> check(n + 1, vector<bool>(n + 1, false));

	//이미 승리한 경우에 대한 check 
	for (int i = 0; i < results.size(); i++) {
		check[results[i][0]][results[i][1]] = true;
	}
	//플로이드 와샬
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// j가 i를 이긴 동시에 i가 k를 이긴경우 j는 k를 이긴 것이므로 check
				if (check[j][i] && check[i][k]) check[j][k] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int winCnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			//i가 j를 이겼거나 j가 i를 이긴경우 승리수 카운트
			if (check[i][j] || check[j][i]) winCnt++;
		}
		// 승패가 확실한 경우 answer 카운트 (당사자 빼고 모든 사람들의 전적을 알 수 있기 때문)
		if (winCnt == n - 1) answer++;
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n = 5; //선수의 수
	vector<vector<int>> res = { {4,3},{4,2},{3,2} ,{1,2},{2,5} }; // 경기 결과

	cout << solution(n , res) << '\n';

	return 0;
}