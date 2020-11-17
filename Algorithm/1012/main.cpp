#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int mat[101][101] = { 0, };

queue<pair<int, int>> q;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1 , 0 , 1 ,0 };

int N, M;

void BFS(int x, int y) {

	q.push(make_pair(x, y));

	mat[x][y] = 0;

	while (!q.empty())
	{
		int curX, curY;
		curX = q.front().first;
		curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nX, nY;
			nX = curX + dx[i];
			nY = curY + dy[i];
			if (nX < 0 || nX >= N || nY < 0 || nY >= M || mat[nX][nY] == 0)
				continue;

			mat[nX][nY] = 0;
			q.push(make_pair(nX, nY));
		}
	}
}


int main() {

	int num;
	int K;

	cin >> num;

	for (int idx = 0; idx < num; idx++) {

		int cnt = 0;

		cin >> N >> M >> K;

		int f, s;
		for (int i = 0; i < K; i++)
		{
			cin >> f >> s;
			mat[f][s] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (mat[i][j] == 1) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				mat[i][j] = 0;
			}
		}

	}

	return 0;
}