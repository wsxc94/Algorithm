#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int unf[1000001];

int Find(int v) {
	if (v == unf[v]) return v;
	return unf[v] = Find(unf[v]);
}
void Union(int a, int b) {

	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (unf[a] < unf[b]) swap(a, b);
	unf[a] = b;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		unf[i] = i;
	}

	for (int i = 0; i < m; i++)
	{	
		cin >> a >> b >> c;
		if (a == 1) {
			if (Find(b) == Find(c)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
		else if (a == 0) Union(b, c);
	}

	return 0;
}