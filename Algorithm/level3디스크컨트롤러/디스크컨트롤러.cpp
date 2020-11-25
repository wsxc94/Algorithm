#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct compare
{
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a > b;
	}
};
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int cnt = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (int i = 0; i < jobs.size(); i++) {
		pq.push({ jobs[i][0] , jobs[i][1] });
	}

	while (!pq.empty()) {
		cout << pq.top().second << " ";
		answer += pq.top().second;
		//cout << answer << " ";
		pq.pop();
		cnt++;
	}

	return answer / 3;
}

int main() {

	vector<vector<int>> v;

	v.push_back({ 0,3 });
	v.push_back({ 1,9 });
	v.push_back({ 2,6 });

	cout << solution(v) << "\n";
	return 0;
}