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
		//���� a�� ����ִ� �� + ���� b�� ����ִ� ����
		//�Է°� B(�ִ�뷮)���� ū ��� B������ �ִ�뷮��ŭ
		//���� ����ä������ �ǰ�, A������ ���� a�� + ���� b�� - �ִ�뷮��ŭ
		//���� ���� �ȴ�.
		if (cur.a + cur.b > b) q.push({ (cur.a + cur.b) - b , b , cur.c });
		else q.push({ 0,cur.a + cur.b , cur.c });
		//���� a + ���� b �뷮�� B(�ִ�뷮)���� ���� ���
		//A���뿡�� ���� ���� �Ű����Ƿ� A�� 0
		//B�� ���� a + ���� b �뷮�� �ȴ�.
		//C�� ��ȭ�� �����Ƿ� ���� �뷮 now.c�� �־��ش�.



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