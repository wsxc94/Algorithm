#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;
//플로이드 와샬
constexpr int INF = 25000000;
int mat[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INF;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mat[i][j] = INF;

	for (int i = 1; i <= n; i++) mat[i][i] = 0;

	for (auto& f : fares) {
		mat[f[0]][f[1]] = f[2];
		mat[f[1]][f[0]] = f[2];
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);

	for (int i = 1; i <= n; i++) answer = min(answer, mat[s][i] + mat[i][a] + mat[i][b]);

	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n = 6, s = 4, a = 6, b = 2;
	vector<vector<int>> v = {
	{4,1,10},
	{3,5,24},
	{5,6,2},
	{3,1,41},
	{5,1,24},
	{4,6,50},
	{2,4,66},
	{2,3,22},
	{1,6,25}
	};
	cout << solution(n, s, a, b, v) << "\n";
	return 0;
}