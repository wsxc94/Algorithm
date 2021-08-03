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
/*
    https://programmers.co.kr/learn/courses/30/lessons/81303
	
	삽입삭제에 대한 효율성 테스트를 위해 링크드 리스트 사용하여 행 선택 및 삭제 복구 구현
	삭제 복구는 최근에 삭제된 행이 복구되어야 하기 때문에 stack으로 deleteList를 관리하였다
*/
struct Node
{
	int num;
	Node* prev;
	Node* next;
	Node(int _num) : num(_num), prev(nullptr), next(nullptr) {}
};

int cur;
stack<int> deleteList;
vector<Node*> v;

void check(vector<string>& cmd) {
	for (string s : cmd)
	{
		if (s[0] == 'D') {
			int idx = stoi(s.substr(2));
			while (idx--) cur = v[cur]->next->num;
		}
		else if (s[0] == 'U')
		{
			int idx = stoi(s.substr(2));
			while (idx--) cur = v[cur]->prev->num;
		}
		else if (s[0] == 'C')
		{
			deleteList.push(cur);
			if (v[cur]->prev != nullptr) v[cur]->prev->next = v[cur]->next;
			if (v[cur]->next != nullptr) {
				v[cur]->next->prev = v[cur]->prev;
				cur = v[cur]->next->num;
			}
			else {
				cur = v[cur]->prev->num;
			}
		}
		else if (s[0] == 'Z')
		{
			int restore = deleteList.top();
			deleteList.pop();
			if (v[restore]->prev != nullptr) v[restore]->prev->next = v[restore];
			if (v[restore]->next != nullptr) v[restore]->next->prev = v[restore];
		}
	}
}
string solution(int& n, int& k, vector<string>& cmd) {

	string answer(n, 'X');
	v = vector<Node*>(n);

	for (int i = 0; i < n; i++) v[i] = new Node(i);

	v[0]->next = v[1];
	v[n - 1]->prev = v[n - 2];

	for (int i = 1; i < n-1; i++) {
		v[i]->next = v[i + 1];
		v[i]->prev = v[i - 1];
	}

	cur = k;
	check(cmd);

	int l_check = cur, r_check = cur;
	answer[cur] = 'O';

	while (v[l_check]->prev != nullptr)
	{
		l_check = v[l_check]->prev->num;
		answer[l_check] = 'O';
	}
	while (v[r_check]->next != nullptr)
	{
		r_check = v[r_check]->next->num;
		answer[r_check] = 'O';
	}
	
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" };
	int n = 8, k = 2;

	cout << solution(n, k, cmd);
	return 0;
}