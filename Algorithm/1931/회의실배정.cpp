#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	int num;
	cin >> num;
	vector<pair<int, int>> vec(num);

	int currentTime = 0;
	int cnt = 0;

	for (int i = 0; i < num; i++) {
		cin >> vec[i].second >> vec[i].first;
	}

	sort(vec.begin(), vec.end());

	//끝나는 시간을 먼저 입력받고
	//끝나는 시간을 기준으로 오름차순 정렬한다.
	//그리고 현재 시작하는 시간이 끝나는 시간보다 작으면
	//카운트롤 올려주고 시작하는시간을 다시 받아온다.
	for (int i = 0; i < num; i++) {
		if (currentTime <= vec[i].second) {
			currentTime = vec[i].first;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}