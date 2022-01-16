#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;

	unordered_map<string, set<string>> check_map; // key = �Ű� �� ��� value = �Ű� ���� ����� ����
	unordered_map<string, set<string>> report_map; // key = �Ű� ���� ��� value = �Ű� �� ����� ����

	for (string id : id_list) {
		check_map[id];
		report_map[id];
	}

	for (string re : report)
	{
		stringstream ss(re);
		string fir, sec;

		ss >> fir;
		ss >> sec;

		check_map[fir].insert(sec);
		report_map[sec].insert(fir);
	}

	for (string id : id_list)
	{
		int cnt = 0;
		for (string s : check_map[id]) {
			if (report_map[s].size() >= k) cnt++;
		}
		
		answer.push_back(cnt);
	}

	return answer;
}
int main() {

	vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
	vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
	int k = 2;

	vector<int> ans = solution(id_list, report, k);

	for (auto a : ans) {
		cout << a << " ";
	}

	return 0;
}