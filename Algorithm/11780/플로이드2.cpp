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
   플로이드와샬 + 경로저장

   mat 배열을 가지고 각 노드까지의 거리를 입력받고 , 기존의 값보다 작은 경우에만 수정
   플로이드 와샬을 수행하면서 최단경로가 갱신될때 최단경로의 값 , 최단경로에 이르기까지의 경로 갱신
   path vector를 이용해 경로 출력.
*/
constexpr int INF = 987654321;
long long mat[101][101];
vector<int> path[101][101];

int n, m, s, e, cost;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) mat[i][j] = 0;
			else mat[i][j] = INF;
			path[i][j].push_back(i);
			path[i][j].push_back(j);
		}
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> cost;
		if (mat[s][e] > cost)
			mat[s][e] = cost;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (mat[i][j] > mat[i][k] + mat[k][j]) {
					mat[i][j] = mat[i][k] + mat[k][j];
					vector<int> v = path[k][j];
					path[i][j].clear();
					path[i][j] = path[i][k];
					for (int m = 1; m < v.size(); m++)
						path[i][j].push_back(v[m]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == INF) mat[i][j] = 0;
			cout << mat[i][j] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 0)	cout << 0 << " ";
			else {
				cout << path[i][j].size() << " ";
				for (int k = 0; k < path[i][j].size(); k++)
					cout << path[i][j][k] << " ";
			}
			cout << '\n';
		}
	}

	return 0;

}