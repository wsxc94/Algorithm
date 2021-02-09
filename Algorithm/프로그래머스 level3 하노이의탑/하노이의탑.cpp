#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int to, int pass) {
	vector<int> v = { from , to };

	if (n == 1) answer.push_back(v);
	else {
		hanoi(n - 1, from, pass, to);
		answer.push_back(v);
		hanoi(n - 1, pass, to, from);
	}
}
vector<vector<int>> solution(int n) {
	hanoi(n, 1, 3, 2);
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<vector<int>> ans = solution(2);

	for (auto& a : ans) {
		for (int i = 0; i < a.size(); i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}