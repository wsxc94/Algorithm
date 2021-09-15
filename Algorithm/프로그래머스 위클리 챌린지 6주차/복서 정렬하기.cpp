#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;

struct info {
	int idx;
	float winRate;
	int win;
	int weights;

	info(int _idx, float _winRate, int _win, int _weights) : idx(_idx), winRate(_winRate), win(_win), weights(_weights) {}

	bool operator< (info &in) {
		if (winRate == in.winRate) {
			if (win == in.win) {
				if (weights == in.weights) {
					return idx < in.idx;
				}
				return weights > in.weights;
			}
			return win > in.win;
		}
		return winRate > in.winRate;
	}
};
vector<int> solution(vector<int> weights, vector<string> head2head) {
	vector<int> answer;
	vector<info> v;

	int idx = 1;
	for (string s : head2head) {
		int weightsCnt = 0;
		float f = s.size(), winCnt = 0, loseCnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'N') f--;
			else if (s[j] == 'W') {
				winCnt++;
				if (weights[idx - 1] < weights[j]) weightsCnt++;
			}
			else {
				loseCnt++;
			}
		}
		float winRate = 0;
		if (f == 0) winRate = 0;
		else winRate = winCnt / (winCnt + loseCnt) * 100;
		v.push_back(info(idx, winRate, weightsCnt, weights[idx - 1]));
		//cout << idx << " " << winRate << " " << weightsCnt << " " << weights[idx-1] << "\n";
		idx++;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) answer.push_back(v[i].idx);

	return answer;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<int> weights = { 50,82,75,120 };
	vector<string> head2head = { "NLWL","WNLL","LWNW","WWLN" };
	vector<int> ans = solution(weights, head2head);

	for (int a : ans) cout << a << " ";
	
	return 0;
}