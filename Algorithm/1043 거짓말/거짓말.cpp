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

using namespace std;
/*
   ����� �� N�� �־�����. 
   �׸��� �� �̾߱��� ������ �ƴ� ����� �־�����. 
   �׸��� �� ��Ƽ�� ���� ������� ��ȣ�� �־�����. 
   �����̴� ��� ��Ƽ�� �����ؾ� �Ѵ�. 
   �̶�, �����̰� ���������̷� �˷����� �����鼭,
   ����� �̾߱⸦ �� �� �ִ� ��Ƽ ������ �ִ��� ���ϴ� ���α׷��� �ۼ�

   � ����� � ��Ƽ������ ������ ��� �ٸ� ��Ƽ���� �������� ����� ��쵵 �ȵǱ� ������
   ������ �˰��ִ� ����� �ѹ��̶� ���� ����� ���� �ؾ� �Ѵ�.
   Union - Find �˰����� �̿��� ���տ� ���� �κ��� �����Ͽ���.
   ������ �˰� �Ǵ� ������� �̷���� ���� , ������ ������ �� �� ���� ������� ������ ������

   Union Find�� �̿��� �����ְ� ��Ƽ�� �� �� �ִ��� ������ üũ�� �� ���� ���Ѵ�.
*/
constexpr int MAX = 51;

int unf[MAX];
vector<int> party_set[MAX]; //�� ��Ƽ ����
vector<int> know_person;    // ������ �˰� �ִ� ���

int Find(int v) {
	if (v == unf[v]) return unf[v];
	return Find(unf[v]);
}
void Union(int a , int b) {
	a = Find(a);
	b = Find(b);
	if (a < b) unf[b] = a;
	else if (a > b) unf[a] = b;
}
bool IsSameRoot(int a , int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int n, m, k, ans;
	cin >> n >> m >> k;

	ans = m;

	for (int i = 1; i <= n; i++) unf[i] = i;

	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		know_person.push_back(num);
	}

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int node;
			cin >> node;
			party_set[i].push_back(node);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int first = party_set[i][0];
		for (int j = 1; j < party_set[i].size(); j++)
		{
			int second = party_set[i][j];
			Union(first, second);
		}
	}

	for (int i = 0; i < m; i++)
	{
		bool cmp = true;
		for (int j = 0; j < party_set[i].size(); j++)
		{
			if (!cmp) break;
			int first = party_set[i][j];
			for (int k = 0; k < know_person.size(); k++)
			{
				int second = know_person[k];
				if (IsSameRoot(first, second)) {
					cmp = false;
					break;
				}
			}
		}
		if (!cmp) ans--;
	}

	cout << ans << "\n";
	return 0;
}