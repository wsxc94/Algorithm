#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int n;
int mat[101][101];
bool ch[101];

void bfs(int start) {

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < n; i++)
		{
			if (mat[x][i] == 1 && !ch[i]) {
				ch[i] = true;
				q.push(i);
			}
		}

	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}
	

	for (int i = 0; i < n; i++)
	{
		memset(ch, false, sizeof(ch));
		bfs(i);

		for (int j = 0; j < n; j++)
		{
			if (ch[j]) mat[i][j] = 1;
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mat[i][j] << " ";

		}
		cout << "\n";
	}
	return 0;
}