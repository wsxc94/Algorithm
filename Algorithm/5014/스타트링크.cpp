#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int F, S, G, U, D;

constexpr int INF = 987654321;

vector<int> dist(10000001, INF);

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	//전체층 현재 스타트링크 위로몇층 아래로몇충
	cin >> F >> S >> G >> U >> D;


	priority_queue<int> q;

	q.push(S);
	dist[S] = 0;

	while (!q.empty())
	{
		int cur = q.top();
		int up = q.top() + U;
		int down = q.top() - D;
		q.pop();

		if (up > 0 && up <= F) {

			if (dist[up] > dist[cur] + 1) {
				dist[up] = dist[cur] + 1;
				q.push(up);
			}
		}

		if (down > 0 && down <= F)
		{
			if (dist[down] > dist[cur] + 1) {
				dist[down] = dist[cur] + 1;
				q.push(down);
			}
		}

	}

	if (dist[G] != INF)
		cout << dist[G] << "\n";
	else
		cout << "use the stairs" << "\n";

	return 0;
}