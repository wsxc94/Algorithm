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
  DFS를 이용해 각 노드의 부모를 찾는 문제
  연결된 정점이 부모 - 자식 순서가 아니고 랜덤으로 주기때문에 양방향으로 넣어준다
  1은 루트이기 때문에 1부터 DFS시작
*/
constexpr int MAX = 100001;

int n;
vector<int> edge[MAX];
int parent[MAX];
bool visit[MAX];

void findParent(int v) {
	visit[v] = true;
	for (int i = 0; i < edge[v].size(); i++)
	{
		int next = edge[v][i];
		if (!visit[next]) {
			parent[next] = v;
			findParent(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n;

	int a, b;
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	findParent(1);

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}
	
	return 0;
}