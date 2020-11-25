#include <iostream>
#include <vector>

using namespace std;

#define MAX 100
int mat[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];

int main() {

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k, l;
	cin >> n >> m;

	

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];

	cin >> k >> l;

	for (int i = 0; i < k; i++)
		for (int j = 0; j < l; j++)
			cin >> mat2[i][j];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < l; j++)
			for (int h = 0; h < m; h++)
				result[i][j] += mat[i][h] * mat2[h][j];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}