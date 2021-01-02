#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int F, S, G, U, D;
bool ch[1000001];
queue<int> q;

int bfs() {
	int res = 0;
	q.push(S);
	ch[S] = true;

	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int cur = q.front(); q.pop();

			if (cur == G) return res;

			int next = cur + U;
			if (1 <= next && next <= F && !ch[next])
			{
				ch[next] = true;
				q.push(next);
			}
			next = cur - D;
			if (1 <= next && next <= F && !ch[next])
			{
				ch[next] = true;
				q.push(next);
			}
		}
		res++;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	//전체층 현재 스타트링크 위로몇층 아래로몇충
	cin >> F >> S >> G >> U >> D;

	int ans = bfs();

	if (ans == -1) cout << "use the stairs\n";
	else cout << ans << "\n";


	return 0;
}