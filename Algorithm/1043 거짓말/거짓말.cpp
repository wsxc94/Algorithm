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
   사람의 수 N이 주어진다. 
   그리고 그 이야기의 진실을 아는 사람이 주어진다. 
   그리고 각 파티에 오는 사람들의 번호가 주어진다. 
   지민이는 모든 파티에 참가해야 한다. 
   이때, 지민이가 거짓말쟁이로 알려지지 않으면서,
   과장된 이야기를 할 수 있는 파티 개수의 최댓값을 구하는 프로그램을 작성

   어떤 사람이 어떤 파티에서는 진실을 듣고 다른 파티에서 거짓말을 들었을 경우도 안되기 때문에
   진실을 알고있는 사람과 한번이라도 만난 사람은 제외 해야 한다.
   Union - Find 알고리즘을 이용해 집합에 대한 부분을 구현하였다.
   진실을 알게 되는 사람으로 이루어진 집합 , 진실을 끝까지 알 수 없는 사람들의 집합을 나눈다

   Union Find를 이용해 합쳐주고 파티에 갈 수 있는지 없는지 체크를 해 답을 구한다.
*/
constexpr int MAX = 51;

int unf[MAX];
vector<int> party_set[MAX]; //각 파티 집합
vector<int> know_person;    // 진실을 알고 있는 사람

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