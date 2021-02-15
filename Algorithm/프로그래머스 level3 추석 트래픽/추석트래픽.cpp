#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	vector<int> start_t, end_t;

	for (int i = 0; i < lines.size(); i++)
	{
		string h, m, s, ms;
		int ih, im, is, process;

		lines[i].pop_back();
		h = lines[i].substr(11, 2);
		m = lines[i].substr(14, 2);
		s = lines[i].substr(17, 2);
		ms = lines[i].substr(20, 3);
		process = stof(lines[i].substr(24, 5)) * 1000;

		//ms로 맞춰주기위해 초로바꾼후 1000 곱하기
		ih = stoi(h) * 3600 * 1000;
		im = stoi(m) * 60 * 1000;
		is = stoi(s) * 1000 + stoi(ms);

		start_t.push_back(ih + im + is - process + 1);
		end_t.push_back(ih + im + is);
	}

	//초당 최대 처리량 구하기
	//끝난 시간 + 1 초 사이의 요청을 찾아 count 를 더해주기
	for (int i = 0; i < lines.size(); i++)
	{
		int end_time = end_t[i] + 1000;
		int count = 0;

		for (int j = i; j < lines.size(); j++)
		{
			if (start_t[j] < end_time)
				count++;
		}

		if (answer < count)
			answer = count;
	}
	return answer;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<string> lines = { 
		"2016-09-15 01:00:04.001 2.0s",
		"2016-09-15 01:00:07.000 2s"
	};

	cout << solution(lines) << "\n";
	return 0;
}