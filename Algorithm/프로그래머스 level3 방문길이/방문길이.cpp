#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

bool ch[11][11][11][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int dir;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string dirs = "ULURRDLLU";
	int answer = 0;
	int x = 5, y = 5;

	for (int i = 0; i < dirs.size(); i++) {

		if (dirs[i] == 'U') dir = 0;
		else if (dirs[i] == 'D') dir = 1;
		else if (dirs[i] == 'R') dir = 2;
		else if (dirs[i] == 'L') dir = 3;

		int xx = x + dx[dir];
		int yy = y + dy[dir];

		if (xx < 0 || yy < 0 || xx >= 11 || yy >= 11) continue;

		if (!ch[x][y][xx][yy]) {
			ch[x][y][xx][yy] = ch[xx][yy][x][y] = true;
			answer++;
		}
		x = xx;
		y = yy;

	}

	cout << answer << "\n";

	return 0;
}