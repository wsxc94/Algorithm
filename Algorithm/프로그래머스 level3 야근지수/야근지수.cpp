#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	int size = works.size();
	int idx = size - 1;
	sort(works.begin(), works.end());

	while (n > 0) {
		n--;
		if (works[idx] > 0) works[idx]--;
		if (idx == 0) idx = size - 1;
		else {
			if (works[idx] < works[idx - 1]) idx--;
			else idx = size - 1;
		}
	}
	for (auto& w : works) answer += pow(w, 2);
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<int> works = { 4,3,3 };
	int n = 4;

	cout << solution(n, works) << "\n";
	return 0;
}