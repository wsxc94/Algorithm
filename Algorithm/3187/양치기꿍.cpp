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
#include <algorithm>

using namespace std;

constexpr int MAX = 251;
int R, C;
int Sheep = 0, Wolf = 0;
char mat[MAX][MAX];
bool ch[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int BFS(int init_x, int init_y) {
	queue<pair<int, int>> que;
	que.push(make_pair(init_x, init_y));
	ch[init_x][init_y] = true;
	int Sheep_num = 0;
	int Wolf_num = 0;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || xx >= R || yy < 0 || yy >= C) continue;
			if (mat[xx][yy] == '#' || ch[xx][yy]) continue;

			if (mat[xx][yy] == 'k') {
				Sheep_num += 1;
				que.push(make_pair(xx, yy));
				ch[xx][yy] = true;
			}
			else if (mat[xx][yy] == 'v') {
				Wolf_num += 1;
				que.push(make_pair(xx, yy));
				ch[xx][yy] = true;
			}
			else {
				que.push(make_pair(xx, yy));
				ch[xx][yy] = true;
			}
		}
	}
	if (Sheep_num > Wolf_num)
		Sheep += Sheep_num;
	else
		Wolf += Wolf_num;
	return 0;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if(!ch[i][j]) BFS(i, j);
		}
	}

	cout << Sheep << " " << Wolf << "\n";

	return 0;
}