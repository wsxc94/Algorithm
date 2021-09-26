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
#include <set>
using namespace std;

int solution(vector<int> numbers) {
	int answer = 45;

	for (int i = 0; i < numbers.size(); i++) {
		answer -= numbers[i];
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<int> numbers = { 1,2,3,4,6,7,8,0 };
	cout << solution(numbers) << "\n";
	return 0;
}