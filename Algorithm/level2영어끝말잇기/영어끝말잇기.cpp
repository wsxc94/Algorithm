#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string>& words) {
	vector<int> answer(2);
	unordered_map<string, int> maps;
	char tmp = words[0][words[0].size() - 1];
	maps[words[0]]++;

	for (int i = 1; i < words.size(); i++) {

		if (maps[words[i]] > 0 || tmp != words[i][0])
		{
			cout << n << "\n";
			answer[0] = (i + 1) / n;
			answer[1] = (i + 1) % n;
			break;
		}
		 maps[words[i]]++;
		 tmp = words[i][words[i].size() - 1];

       
	}

	return answer;
}

int main() {
	vector<string> w = { "tank", "kick", "know", "wheel", "land", "dream",
		"mother", "robot", "tank" };
	int n = 3;

	vector<int> s = solution(n, w);

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}

	return 0;
}