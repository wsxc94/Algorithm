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
#include <algorithm>

using namespace std;

int n;
vector<int> mat[3001]; 
// 0이면 방문 안함 1이면 방문 2면 사이클에 포함 
int ch[3001]; 
int dist[3001]; 
// return 값은 사이클 형성 시작 정점의 번호 
int dfs(int idx, int cnt){ 
	// 방문한 정점이라면 사이클이 되는지 확인 
	if(ch[idx] == true){ 	
		if( cnt - dist[idx] >=3 ) return idx;
		else return -1; 
	} 

	ch[idx] = 1; 		
	dist[idx] = cnt; 
		
	// 인접정점 순회 
	for(int i=0; i<mat[idx].size(); i++){
		int next = mat[idx][i]; 
		int cycle_start_idx = dfs(next, cnt + 1);
		// 시작 정점의 번호면 
		if ( cycle_start_idx != -1) { 
			ch[idx] = 2; 
			//사이클에 해당하지 않으면 check에 사이클로 기록하지 않기 위함 
			if(idx == cycle_start_idx) return -1; 
			else return cycle_start_idx; 
		} 
	} 
	return -1; 
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;

	int a, b;

	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	dfs(1, 0);

	queue<int> q;
	
	for (int i = 1; i <= n; i++)
	{
		if (ch[i] == 2) {
			dist[i] = 0;
			q.push(i);
		}
		else {
			dist[i] = -1;
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < mat[cur].size(); i++)
		{
			int next = mat[cur][i];
			//정점만 탐색한다.
			if (dist[next] == -1) { 
				q.push(next);
				dist[next] = dist[cur] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';

	return 0;
}