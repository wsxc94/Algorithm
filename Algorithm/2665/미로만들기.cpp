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

/*
   검은 방의 최소 개수를 구하는 문제다
   bfs로 방문하며 끝점으로 갈때 까지의 검은방의 갯수를 ch배열에 저장하면 된다.
*/

constexpr int MAX = 51;

int mat[MAX][MAX];
int ch[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = s[j] - '0';
		}
	}

	memset(ch, -1, sizeof(ch));

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	ch[0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;

			if (mat[xx][yy] == 1) {
				if (ch[xx][yy] == -1 || ch[xx][yy] > ch[x][y]) {
					q.push({ xx,yy });
					ch[xx][yy] = ch[x][y];
				}
			}
			else {
				if (ch[xx][yy] == -1 || ch[xx][yy] > ch[x][y] + 1) {
					q.push({ xx,yy });
					ch[xx][yy] = ch[x][y] + 1;
				}
			}	
		}
	}

	cout << ch[n - 1][n - 1];


	return 0;
}