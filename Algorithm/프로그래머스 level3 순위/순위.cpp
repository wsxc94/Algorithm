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

	//�̹� �¸��� ��쿡 ���� check 
	for (int i = 0; i < results.size(); i++) {
		check[results[i][0]][results[i][1]] = true;
	}
	//�÷��̵� �ͼ�
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// j�� i�� �̱� ���ÿ� i�� k�� �̱��� j�� k�� �̱� ���̹Ƿ� check
				if (check[j][i] && check[i][k]) check[j][k] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int winCnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			//i�� j�� �̰�ų� j�� i�� �̱��� �¸��� ī��Ʈ
			if (check[i][j] || check[j][i]) winCnt++;
		}
		// ���а� Ȯ���� ��� answer ī��Ʈ (����� ���� ��� ������� ������ �� �� �ֱ� ����)
		if (winCnt == n - 1) answer++;
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n = 5; //������ ��
	vector<vector<int>> res = { {4,3},{4,2},{3,2} ,{1,2},{2,5} }; // ��� ���

	cout << solution(n , res) << '\n';

	return 0;
}