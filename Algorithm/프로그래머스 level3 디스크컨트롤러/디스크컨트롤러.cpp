#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<vector<int>> jobs = { {0,3} , {1,9} , {2,6} };

	int answer = 0, idx = 0, len = jobs.size(),
		time = 0; // ���� ó������ �۾��� ������ �ð�

	sort(jobs.begin(), jobs.end());

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	while (idx < len || !pq.empty())
	{
		if (idx < len && time >= jobs[idx][0]) { // time �ð��ȿ� ������ jobs�� ������
			pq.push({ jobs[idx][1] , jobs[idx][0] }); // min heap�� Ǫ��
			idx++;
			continue;
		}

		if (!pq.empty())
		{
			time += pq.top().first;
			answer += time - pq.top().second;
			pq.pop();
		}
		else {
			time = jobs[idx][0];
		}
	}

	cout << answer / len << "\n";

	return 0;
}