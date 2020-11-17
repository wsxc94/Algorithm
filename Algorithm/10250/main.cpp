#include <iostream>
#include <vector>
using namespace std;

int mat[101][101];
int t, h, w, n;

void hotel() {
	
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			mat[i][j] = (100 * (i + 1)) + (j + 1);
		}
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			n--;
			if (n == 0) cout << mat[j][i] << "\n";
		}
	}

}
int main() {

	ios::sync_with_stdio(false), cin.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> h >> w >> n;

		hotel();
	}


	return 0;
}