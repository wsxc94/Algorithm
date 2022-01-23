#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;

	for (long long i = left; i <= right; i++)
	{
		int div = i / n;
		int mod = i % n;

		if (div < mod) answer.push_back(mod + 1);
		else answer.push_back(div + 1);
	}

	return answer;
}

int main() {

	int n;
	long long left, right;
	n = 3, left = 2, right = 5;

	vector<int> answer = solution(n, left, right);

	for (auto a : answer) cout << a << " ";

	return 0;
}