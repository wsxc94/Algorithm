#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

char mat[501][501];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 'S') {
				for (int k = 0; k < 4; k++)
				{
					int xx = i + dx[k];
					int yy = j + dy[k];
					if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
					if (mat[xx][yy] == 'W') {
						cout << "0" << "\n";
						return 0;
					}
				}
			}
		}
	}

	cout << "1" << "\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 'S') {
				for (int k = 0; k < 4; k++)
				{
					int xx = i + dx[k];
					int yy = j + dy[k];
					if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
					if (mat[xx][yy] == '.') {
						mat[xx][yy] = 'D';
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j];
		}
		cout << "\n";
	}


	return 0;
}