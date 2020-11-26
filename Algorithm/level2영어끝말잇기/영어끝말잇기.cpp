#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string>& words) {
	vector<int> answer(2, 0);
	unordered_map<string, int> maps;
	char tmp = words[0][words[0].size() - 1];
	maps[words[0]]++;

	int num = 2, turn = 1;

	for (int i = 1; i < words.size(); i++) {
		if (num > n) {
			num = 1;
			turn++;
		}
		if (maps[words[i]] > 0 || tmp != words[i][0])
		{
			answer[0] = num;
			answer[1] = turn;
			return answer;
		}
		maps[words[i]]++;
		tmp = words[i][words[i].size() - 1];
		num++;
	}

	return answer;
}

int main() {
	vector<string> w = { "tank", "kick", "know", "wheel", "land", "dream",
		"mother", "robot", "tank" };
	int n = 3;

	//vector<string> tmp = { "hello" , "one" , "even" , "never" , "now" , "world" , "draw" };
	
	//vector<int> s = solution(2, tmp);
	vector<int> s = solution(n, w);

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}

	return 0;
}