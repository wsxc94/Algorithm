#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int n, m;
int mat[1001][1001];
bool ch[1001][1001][2];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int BFS()
{
	queue<pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	ch[0][0][0] = true;

	while (Q.empty() == 0)
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int B = Q.front().second.first;
		int Cnt = Q.front().second.second;
		Q.pop();

		if (x == n - 1 && y == m - 1)
		{
			return Cnt;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (mat[nx][ny] == 1 && B == 0)
				{
					ch[nx][ny][B + 1] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(B + 1, Cnt + 1)));
				}
				else if (mat[nx][ny] == 0 && ch[nx][ny][B] == false)
				{
					ch[nx][ny][B] = true;
					Q.push(make_pair(make_pair(nx, ny), make_pair(B, Cnt + 1)));
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	char tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			mat[i][j] = tmp - '0';
		}
	}

	cout << BFS() << "\n";
	return 0;
}