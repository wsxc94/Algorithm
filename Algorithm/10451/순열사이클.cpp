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
#include <set>
using namespace std;
/*
   순열 사이클의 개수를 구하는 문제
   1 ~ N 만큼의 순서가 다른 숫자들이 들어온다

   ex)
   1 2 3 4 5 6 7 8
   3 2 7 8 1 4 5 6
   
   1 - 3 , 3 - 7 , 7 - 5 , 5 - 1
   2 - 2
   4 - 8 , 8 - 6 , 6 - 4
   이런 간선으로 이어져 3개의 사이클이 생긴다

   1~n 만큼의 입력받은 순서에따라 연결해주고
   ch 배열을 통해 방문여부를 체크
   v 배열을 통해 각 간선에 연결되어 있는 노드를 DFS로 탐색하여
   각 테스트케이스의 cnt를 구해주면 된다.

*/
int ch[1001];
vector<int> v[1001];

void dfs(int idx) {
	ch[idx] = true;

	for (int i = 0; i < v[idx].size(); i++)
	{
		int next = v[idx][i];
		if (ch[next]) continue;
		dfs(next);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, cnt = 0;
		cin >> n;

		memset(ch, 0, sizeof(ch));

		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			v[i].push_back(k);
			v[k].push_back(i);
		}

		for (int i = 1; i <= n; i++)
		{
			if (ch[i]) continue;
			dfs(i);
			cnt++;
			ch[i] = true;
		}

		cout << cnt << "\n";
		
		for (int i = 1; i <= n; i++) v[i].clear();
	}
	
	return 0;
}