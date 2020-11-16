#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);

	int N , M;
	vector<int> v;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> M;
		v.push_back(M);
	}
	sort(v.begin(), v.end());

	cout << ( v[0]* v[v.size() - 1]) << "\n";
	return 0;
}