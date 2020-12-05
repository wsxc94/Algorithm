#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;

bool check(int idx , vector<int>& mat) {

	for (int i = 0; i < idx; i++)
	{
		//새로운 퀸 , 기존 퀸 같은행 대각선
		if (mat[idx] == mat[i] || abs(mat[idx] - mat[i]) == (idx - i))
			return false;
	}
	return true;
}
void dfs(int idx , vector<int>& mat) {

	if (idx == n) answer++;
	else {
		for (int i = 0; i < n; i++)
		{
			mat[idx] = i;
			if (check(idx , mat)) dfs(idx + 1 , mat);
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	cin >> n;

	vector<int> mat(n, 0);

	dfs(0,mat);

	cout << answer << "\n";

	return 0;
}