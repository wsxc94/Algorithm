#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

unordered_map<long long, long long> maps;
vector<long long> answer;

long long Find(long long num) {
	if (maps[num] == 0) return num;
	else return maps[num] = Find(maps[num]);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);


	long long k;
	vector<long long> room_number = { 1,3,4,1,3,1 };

	maps.reserve(200002);
	answer.reserve(200002);

	for (long long room : room_number) {
		long long num = Find(room);
		answer.push_back(num);
		maps[num] = num + 1;
	}

	for (long long num : answer)
	{
		cout << num << " ";
	}
	return 0;
}