#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

struct Car {
	int x, y, cost, dir;
};
int dist[26][26];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int answer = 987654321;

	vector<vector<int>> board = { {0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0} };
	n = board.size();

	queue<Car> q;
	q.push({ 0,0,0,10 });
	board[0][0] = 1;

	while (!q.empty()) {
		Car cur = q.front();
		q.pop();

		if (cur.x == n - 1 && cur.y == n - 1) {
			if (answer > cur.cost) answer = cur.cost;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int xx = cur.x + dx[i];
			int yy = cur.y + dy[i];

			if (xx < 0 || yy < 0 || xx >= n || yy >= n || board[xx][yy] == 1) continue;
			int nextCost = 0;

			if (cur.dir == 10 || cur.dir == i) nextCost = cur.cost + 100;
			else if (cur.dir != i) nextCost = cur.cost + 600;

			if (board[xx][yy] == 0 || board[xx][yy] >= nextCost) {
				board[xx][yy] = nextCost;
				q.push({ xx,yy,nextCost , i });
			}

		}
	}
	

	cout << answer << "\n";
	return 0;
}