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

vector<int> solution(vector<int>& numbers) {
	vector<int> answer;
	map<int, int> maps;

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < numbers.size(); i++) {
		for (int j = 0; j < numbers.size(); j++) {
			if (i == j) continue;
			maps[numbers[i] + numbers[j]]++;
		}
	}
	for (auto m : maps) {
		answer.push_back(m.first);
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<int> numbers = { 2,1,3,4,1 };

	numbers = solution(numbers);

	for (auto n : numbers) {
		cout << n << " ";
	}

	return 0;
}