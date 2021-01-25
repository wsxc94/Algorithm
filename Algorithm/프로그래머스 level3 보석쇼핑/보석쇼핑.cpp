#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

//투포인터 해시

unordered_map<string,int> maps;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<string> gems = { "DIA" , "RUBY" , "RUBY" , "DIA" , "DIA" , "EMERALD" , "SAPPHIRE" , "DIA" };

	vector<int> answer = { 1 , (int)gems.size() };

	for (int i = 0; i < gems.size(); i++)
	{		
		maps[gems[i]]++;
	}
	int s = 0, e = 0;
	int gemSize = gems.size() - 1; // 최대 구간
	int len = maps.size(); // 최소 구간 (보석의 개수)
	maps.clear();

	
	while (true)
	{
		if (maps.size() == len) {
			if (e - s < gemSize) { // 최단구간인지 판별
				gemSize = e - s;
				answer[0] = s + 1;
				answer[1] = e;
			}


			if (maps[gems[s]] == 1) { // 보석의 개수가 1일 떄
				maps.erase(gems[s]);
				s++;
			}
			else { // 보석의 개수가 1개 이상
				maps[gems[s]]--;
				s++;
			}
		}
		else if (e == gems.size()) break; // 탐색끝
		else { // 보석을 찾지 못함
			maps[gems[e]]++;
			e++;
		}
	}
	
	cout << answer[0] << " " << answer[1] << "\n";
	return 0;
}