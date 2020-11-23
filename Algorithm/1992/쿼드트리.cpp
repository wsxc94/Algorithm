#include <iostream>
#include <vector>
#include <string>

using namespace std;

char mat[65][65];
string ans = "";

void quad(int x , int y , int size) {

	bool cmp = true;

	char tmp = mat[x][y];

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (tmp != mat[i][j]) {
				cmp = false;
				break;
			}
		}
	}

	if (cmp) {
		ans += tmp;
	}
	else {
		ans += "(";
		size /= 2;
		quad(x, y, size);
		quad(x, y + size, size);
		quad(x + size, y, size);
		quad(x + size, y + size, size);
		ans += ")";
	}

	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}

	quad(0, 0, n);

	cout << ans << "\n";
	return 0;
}