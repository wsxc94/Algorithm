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
#include <cmath>
using namespace std;
/*
    �ּ� ���д� Ʈ��
    �־��� ��ο� �ּ��� ��θ� ���ÿ� ã�� ����
	ũ�罺Į �˰����� �̿��Ͽ� �ִܰ�� �ִ��� Ž��
	�Ƿε��� ���������� K�� ���������� k^2�� �Ǳ⿡ ������ ���
*/
struct Edge
{
	int v1;
	int v2;
	int val;
	Edge(int a, int b, int c) : v1(a), v2(b), val(c) {}

	bool operator < (const Edge& b) {
		return val < b.val;
	}
};

int n, m, best, worst;

int unf[1001];
vector<Edge> ed;

int Find(int v) {
	if (unf[v] == v) return unf[v];
	return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b) unf[a] = b;
	else if (a > b) unf[b] = a;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	ed.reserve(m + 1);

	for (int i = 0; i <= n; i++) unf[i] = i;
	
	for (int i = 0; i < m + 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		ed.push_back(Edge(a, b, c));
	}

	sort(ed.begin(), ed.end());

	for (int i = 0; i < ed.size(); i++)
	{
		if (Find(ed[i].v1) != Find(ed[i].v2)) {
			Union(ed[i].v1, ed[i].v2);
			if (!ed[i].val) worst++;
		}
	}

	for (int i = 0; i <= n; i++) unf[i] = i;

	for (int i = ed.size() - 1; i >= 0; i--)
	{
		if (Find(ed[i].v1) != Find(ed[i].v2)) {
			Union(ed[i].v1, ed[i].v2);
			if (!ed[i].val) best++;
		}
	}

	cout << pow(worst, 2) - pow(best, 2) << "\n";


	return 0;
}