#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

struct Bucket
{
	int a, b, c;
};
int a, b, c;
bool ch[202][202], ans[202];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> a >> b >> c;

	queue<Bucket> q;
	q.push({ 0,0,c });

	while (!q.empty())
	{
		Bucket cur = q.front();
		q.pop();

		if (ch[cur.a][cur.b]) continue;
		ch[cur.a][cur.b] = true;

		if (cur.a == 0) ans[cur.c] = true;


		//a->b
		//현재 a에 담겨있는 양 + 현재 b에 담겨있는 양이
		//입력값 B(최대용량)보다 큰 경우 B물통은 최대용량만큼
		//물이 가득채워지게 되고, A물통은 현재 a양 + 현재 b양 - 최대용량만큼
		//물이 남게 된다.
		if (cur.a + cur.b > b) q.push({ (cur.a + cur.b) - b , b , cur.c });
		else q.push({ 0,cur.a + cur.b , cur.c });
		//현재 a + 현재 b 용량이 B(최대용량)보다 작은 경우
		//A물통에서 물이 전부 옮겨지므로 A는 0
		//B는 현재 a + 현재 b 용량이 된다.
		//C는 변화가 없으므로 현재 용량 now.c를 넣어준다.



		//a->c
		if (cur.a + cur.c > c)
			q.push({ (cur.a + cur.b) - c,cur.b,c });
		else
			q.push({ 0,cur.b,cur.a + cur.c });

		//b->a
		if (cur.b + cur.a > a)
			q.push({ a,(cur.b + cur.a) - a,cur.c });
		else
			q.push({ cur.b + cur.a, 0, cur.c });

		//b->c
		if (cur.b + cur.c > c)
			q.push({ cur.a,(cur.b + cur.c) - c,c });
		else
			q.push({ cur.a, 0, cur.b + cur.c });

		//c->a
		if (cur.c + cur.a > a)
			q.push({ a,cur.b,(cur.c + cur.a) - a });
		else
			q.push({ cur.c + cur.a,cur.b,0 });

		//c->b
		if (cur.c + cur.b > b)
			q.push({ cur.a,b,(cur.c + cur.b) - b });
		else
			q.push({ cur.a,cur.c + cur.b,0 });
	}


	for (int i = 0; i < 202; i++)
	{
	 
		if (ans[i]) cout << i << " ";
	}
	return 0;
}