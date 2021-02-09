#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;
int N, answer;
int mat[12];

bool checkQueen(int idx) {

	for (int i = 0; i < idx; i++) {
		//같은 라인 혹은 대각선
		if (mat[i] == mat[idx] || abs(mat[idx] - mat[i]) == idx - i) return false;
	}

	return true;
}
void dfs(int x) {
	if (x == N) {
		answer++;
	}
	else {
		for (int i = 0; i < N; i++) {
			mat[x] = i; // 해당 위치에 퀸을 배치 하고
			if (checkQueen(x)) { //유효하면 다음 행 퀸배치 아니면 위치 변경
				dfs(x + 1);
			}
		}
	}
}

int solution(int n) {
	N = n;
	dfs(0);
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cout << solution(4) << "\n";
	return 0;
}