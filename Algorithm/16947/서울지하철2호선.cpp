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
// 0�̸� �湮 ���� 1�̸� �湮 2�� ����Ŭ�� ���� 
int ch[3001]; 
int dist[3001]; 
// return ���� ����Ŭ ���� ���� ������ ��ȣ 
int dfs(int idx, int cnt){ 
	// �湮�� �����̶�� ����Ŭ�� �Ǵ��� Ȯ�� 
	if(ch[idx] == true){ 	
		if( cnt - dist[idx] >=3 ) return idx;
		else return -1; 
	} 

	ch[idx] = 1; 		
	dist[idx] = cnt; 
		
	// �������� ��ȸ 
	for(int i=0; i<mat[idx].size(); i++){
		int next = mat[idx][i]; 
		int cycle_start_idx = dfs(next, cnt + 1);
		// ���� ������ ��ȣ�� 
		if ( cycle_start_idx != -1) { 
			ch[idx] = 2; 
			//����Ŭ�� �ش����� ������ check�� ����Ŭ�� ������� �ʱ� ���� 
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
			//������ Ž���Ѵ�.
			if (dist[next] == -1) { 
				q.push(next);
				dist[next] = dist[cur] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';

	return 0;
}