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
		//���� ���� Ȥ�� �밢��
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
			mat[x] = i; // �ش� ��ġ�� ���� ��ġ �ϰ�
			if (checkQueen(x)) { //��ȿ�ϸ� ���� �� ����ġ �ƴϸ� ��ġ ����
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