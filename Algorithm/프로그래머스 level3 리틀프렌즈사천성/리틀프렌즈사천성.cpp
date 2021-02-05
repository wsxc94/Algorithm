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
	// 4방향으로 가능한 끝까지 뻗어나가기 
	for (int i = 0; i < 4; ++i) {
		int x = s.x + dx[i]; 
		int y = s.y + dy[i]; 
		while (!(x < 0 || x >= M || y < 0 || y >= N)) {
			if (x == e.x && y == e.y) return true;
			if (m_board[x][y] != '.')  break; 
			// 위아래 -> 양옆, 양옆 -> 위아래 // 방향이 겹치지 않게 2방향으로만 뻗어나가기 
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
		// 알파벳 순으로 가장 먼저인 문자열을 출력해야한다 
		for (int i = 0; i < 26; ++i) {
			// 맞춰야할 짝이 아직 남아있다면 
			if (!pos[i].empty()) {
				char c = i + 'A'; 
				point s = pos[i][0];
				point e = pos[i][1]; 
				// 두 알파벳이 1번 이하로 꺾어서 닿을 수 있다면 
				if (matching(c, s, e)) {
					// 답 문자열에 저장 
					answer += c; 
					// 알파벳이 있던 자리 빈칸처리, alpha_pos에 저장되어 있던 위치 비우기 
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
	// 모든 짝이 맞춰졌으면 true반환
	return (left == 0);
} 
string solution(int m, int n, vector<string> board) {
	// 전역변수 처리 
	M = m; 
	N = n; 
	m_board = board; 
	pos = vector<vector<point>>(26); 
	// 각 알파벳의 위치 2개 찾아 alpha_pos벡터에 저장 
	int cnt = 0; 
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (isalpha(board[i][j])) {
				// 총 알파벳 개수 
				++cnt; 
				pos[board[i][j] - 'A'].push_back({ i, j });
			}
		} 
	} 
	// 짝을 모두 맞추는게 가능하면 순서 출력 
	string answer = ""; 
	if (gameStart(answer, cnt)) return answer;
	// 불가능할 때 
	return "IMPOSSIBLE"; 
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<string> board = { "DBA","C*A","CDB" };
	cout << solution(3, 3, board) << "\n";
	return 0;
}