#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

/*
 ���̳��� ���α׷��� ���� �߿� ������ ���� Ư���� ��ȭ�Ŀ� ���ؼ� ����ȭ�� �����ϴٰ� �Ѵ�.
 Kruth's optimization 

1) �簢�ε��
C[a][c] + C[b][d] <= C[a][d] + C[b][c](a <= b <= c <= d)

2) ��������
C[b][c] <= C[a][d](a <= b <= c <= d)

���� : https://js1jj2sk3.tistory.com/search/11066
*/
int psum[502];
int novel[502];
int dp2[502][502];
int num[502][502];
int T, N;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> novel[i];
			psum[i] = psum[i - 1] + novel[i];
		}

		for (int i = 1; i <= N; i++)
			num[i - 1][i] = i;

		for (int d = 2; d <= N; d++) {
			for (int i = 0; i + d <= N; i++) {
				int j = i + d;
				dp2[i][j] = 2e9;
				for (int k = num[i][j - 1]; k <= num[i + 1][j]; k++) {

					int v = dp2[i][k] + dp2[k][j] + psum[j] - psum[i];
					if (dp2[i][j] > v)
						dp2[i][j] = v, num[i][j] = k;
				}
			}
		}
		cout << dp2[0][N] << "\n";
	}
	return 0;
	
}