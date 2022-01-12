#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(int& fatigue, int& cnt, int& max_num, vector<vector<int>>& dungeons, vector<bool>& check)
{
    if (max_num < cnt) max_num = cnt;
  

    int size = dungeons.size();

    for (int i = 0; i < size; i++)
    {
        int minimumEntryFatigue = dungeons[i][0];
        int exhaustionFatigue = dungeons[i][1];

        if (true == check[i]) continue;
        if (fatigue < minimumEntryFatigue) continue;

        fatigue -= exhaustionFatigue;
        check[i] = true;
        cnt++;

        dfs(fatigue, cnt, max_num, dungeons, check);

        fatigue += exhaustionFatigue;
        check[i] = false;
        cnt--;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;
	int cnt = 0;
	vector<bool> check(dungeons.size(), false);
	dfs(k, cnt, answer, dungeons, check);

	return answer;
}
int main() {
	int k = 80;
	vector<vector<int>> dungeons = { {80,20},{50,40},{30,10} };
	cout << solution(k , dungeons) << "\n";

	return 0;
}