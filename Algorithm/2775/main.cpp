#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

#define MAX_ARR 15

using namespace std;

int a = 0, b = 0;

int mat[MAX_ARR][MAX_ARR] = { 0, };

void sum(int start) {

	if (start == a+1) return;
	
	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= i; j++) {
			mat[start][i] += mat[start - 1][j];
		}
	}

	sum(start + 1);

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int k;
	
	cin >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;

			for (int j = 1; j <= MAX_ARR; j++)
				mat[0][j] = j;

		    sum(1);
			
			cout << mat[a][b] << "\n";

			for (int k = 0; k < MAX_ARR; k++)
			{
				for (int l = 0; l < MAX_ARR; l++)
				{
					mat[k][l] = 0;
				}
			}
		}
		
	return 0;
}