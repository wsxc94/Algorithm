#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;
struct point {
	int x, y; 
}; 
int M, N; 
vector<string> m_board;
vector<vector<point>> pos;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
bool matching(char c, point s, point e) {
	// 4�������� ������ ������ ������� 
	for (int i = 0; i < 4; ++i) {
		int x = s.x + dx[i]; 
		int y = s.y + dy[i]; 
		while (!(x < 0 || x >= M || y < 0 || y >= N)) {
			if (x == e.x && y == e.y) return true;
			if (m_board[x][y] != '.')  break; 
			// ���Ʒ� -> �翷, �翷 -> ���Ʒ� // ������ ��ġ�� �ʰ� 2�������θ� ������� 
			for (int j = ((i + 1) % 2); j < 4; j += 2) {
				int xx = x + dx[j]; 
				int yy = y + dy[j];
				while (!(xx < 0 || xx >= M || yy < 0 || yy >= N)) {
					if (xx == e.x && yy == e.y) return true;
					if (m_board[xx][yy] != '.')  break;
					xx += dx[j]; yy += dy[j];
				} 
			} 
			x += dx[i];
			y += dy[i]; 
		} 
	} 
	return false;
} 
bool gameStart(string &answer, int left) {
	while (true) {
		bool match = false; 
		// ���ĺ� ������ ���� ������ ���ڿ��� ����ؾ��Ѵ� 
		for (int i = 0; i < 26; ++i) {
			// ������� ¦�� ���� �����ִٸ� 
			if (!pos[i].empty()) {
				char c = i + 'A'; 
				point s = pos[i][0];
				point e = pos[i][1]; 
				// �� ���ĺ��� 1�� ���Ϸ� ��� ���� �� �ִٸ� 
				if (matching(c, s, e)) {
					// �� ���ڿ��� ���� 
					answer += c; 
					// ���ĺ��� �ִ� �ڸ� ��ĭó��, alpha_pos�� ����Ǿ� �ִ� ��ġ ���� 
					m_board[s.x][s.y] = '.'; 
					m_board[e.x][e.y] = '.'; 
					pos[i].clear(); 
					match = true; 
					left -= 2; 
					break;
				} 
			} 
		} 
		if (!match) break;
	} 
	// ��� ¦�� ���������� true��ȯ
	return (left == 0);
} 
string solution(int m, int n, vector<string> board) {
	// �������� ó�� 
	M = m; 
	N = n; 
	m_board = board; 
	pos = vector<vector<point>>(26); 
	// �� ���ĺ��� ��ġ 2�� ã�� alpha_pos���Ϳ� ���� 
	int cnt = 0; 
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (isalpha(board[i][j])) {
				// �� ���ĺ� ���� 
				++cnt; 
				pos[board[i][j] - 'A'].push_back({ i, j });
			}
		} 
	} 
	// ¦�� ��� ���ߴ°� �����ϸ� ���� ��� 
	string answer = ""; 
	if (gameStart(answer, cnt)) return answer;
	// �Ұ����� �� 
	return "IMPOSSIBLE"; 
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<string> board = { "DBA","C*A","CDB" };
	cout << solution(3, 3, board) << "\n";
	return 0;
}