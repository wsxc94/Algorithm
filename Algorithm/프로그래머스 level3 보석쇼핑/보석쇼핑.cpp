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

//�������� �ؽ�

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
	int gemSize = gems.size() - 1; // �ִ� ����
	int len = maps.size(); // �ּ� ���� (������ ����)
	maps.clear();

	
	while (true)
	{
		if (maps.size() == len) {
			if (e - s < gemSize) { // �ִܱ������� �Ǻ�
				gemSize = e - s;
				answer[0] = s + 1;
				answer[1] = e;
			}


			if (maps[gems[s]] == 1) { // ������ ������ 1�� ��
				maps.erase(gems[s]);
				s++;
			}
			else { // ������ ������ 1�� �̻�
				maps[gems[s]]--;
				s++;
			}
		}
		else if (e == gems.size()) break; // Ž����
		else { // ������ ã�� ����
			maps[gems[e]]++;
			e++;
		}
	}
	
	cout << answer[0] << " " << answer[1] << "\n";
	return 0;
}