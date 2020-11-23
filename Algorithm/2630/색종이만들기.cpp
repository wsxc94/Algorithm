#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int mat[128][128] = { 0, };

int zero = 0;
int one = 0;

void quad(int start , int end , int size) {

	bool o = false;
	bool z = false;

	for (int i = start; i < start + size; i++)
	{
		for (int j = end; j < end + size; j++)
		{
			if (mat[i][j] == 0) z = true;
			else o = true;
		}
	}
	if (!z && o) {
		one++;
		return;
	}
	if (!o && z) {
		zero++;
		return;
	}

	size /= 2;

	quad(start, end, size);
	quad(start, end + size, size);
	quad(start + size, end, size);
	quad(start + size, end + size, size);

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

	cout << zero << "\n" << one << "\n";


	return 0;
}