#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int mat[2188][2188] = { 0, };
int ans[3];

//void dfs(int x, int y, int size) {
//	bool ch = true;
//	int cur = mat[x][y];
//
//	for (int i = x; i < x + size; i++)
//	{
//		for (int j = y; j < y + size; j++)
//		{
//			if (cur != mat[i][j])
//			{
//				ch = false;
//				break;
//			}
//		}
//	}
//	if (ch)
//	{
//		if (cur == -1) {
//			ans[0]++;
//		}
//		else if (cur == 0)
//		{
//			ans[1]++;
//		}
//		else
//			ans[2]++;
//	}
//	else {
//		size /= 3;
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j= 0;  j< 3; j++)
//			{
//				dfs(x + size * i, y + size * j, size);
//			}
//		}
//	}
//
//}
int dfs(int x , int y , int size) {
	if (size == 1) {
		ans[mat[x][y] + 1]++;
		return mat[x][y];
	}
	bool one = true;
	for (int i = 0; i < size; i += size / 3)
	{
		for (int j = 0; j < size; j += size / 3)
		{
			if (dfs(x + i, y + j, size / 3) != mat[x][y]) {
				one = false;
			}
		}
	}
	if (one) {
		ans[mat[x][y] + 1] -= 8;
		return mat[x][y];
	}
	else return 2;

}
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}

	dfs(0, 0, n);

	for (int i = 0; i < 3; i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}