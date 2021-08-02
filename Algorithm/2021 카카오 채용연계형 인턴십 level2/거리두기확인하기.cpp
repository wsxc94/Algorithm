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
    https://programmers.co.kr/learn/courses/30/lessons/81302?language=cpp#fn1

	�Ÿ��α⿡�� �ɾ� �ִ� �ڸ� ���̰� ��Ƽ������ ���� ���� ������ ����ư �Ÿ��� 2 ���� �̸�
	�Ÿ��α⸦ ��Ű�� ���� ���̴�.
	BFS�� ���� P�� �ִ� �� ���� �����Ͽ� �Ÿ��α⸦ ���״��� ��ȸ�Ѵ�.

*/
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct pos {
	int x;
	int y;
	int dist;
	pos(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist) {}
};

bool bfs(vector<string>& places, int x, int y) {
	vector<vector<bool>> ch(5, vector<bool>(5, false));
	queue<pos> q;
	q.push(pos(x, y, 0));
	ch[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.dist == 2) continue;

		for (int i = 0; i < 4; i++) {
			int xx = cur.x + dx[i];
			int yy = cur.y + dy[i];
			if (xx < 0 || yy < 0 || xx >= 5 || yy >= 5 || ch[xx][yy]) continue;
			if (places[xx][yy] == 'O') {
				ch[xx][yy] = true;
				q.push(pos(xx, yy, cur.dist + 1));
			}
			else if (places[xx][yy] == 'P') return false;
		}
	}
	return true;
}

int Check_places(vector<string>& places) {
	for (int i = 0; i < places.size(); i++) {
		for (int j = 0; j < places[i].size(); j++) {
			if (places[i][j] == 'P' && !bfs(places, i, j)) {
				return 0;
			}
		}
	}
	return 1;
}

void Find_answer(vector<int>& answer, vector<vector<string>>& places) {

	for (int i = 0; i < places.size(); i++) {
		answer.push_back(Check_places(places[i]));
	}
}

vector<int> solution(vector<vector<string>>& places) {
	vector<int> answer;

	Find_answer(answer, places);

	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector <vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}
		,{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}
		,{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}
		,{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}
		,{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };

	vector<int> answer = solution(places);

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << ' ';
	}
	return 0;
}