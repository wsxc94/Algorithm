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
    https://programmers.co.kr/learn/courses/30/lessons/77484
	1~45 ������ 6���� ��� �ζǸ� ���� �� ���� ��ȣ�� ��÷������
	�ְ� ������ ���� ������ ���ϴ� ����

	�ϴ� 46���� �ζǹ�ȣ�� üũ�� �� �ִ� check �迭�� �����
	win_nums�� ��� �ִ� ��÷��ȣ�� true�� �����
	�� �� 0��ȣ�� �´� ��ȣ �� ���� ������ Ʋ�� ��ȣ �� ���� ������ ���� zero ī��Ʈ�� ���ش�

	�׸��� ��÷��ȣ�� �ƴ϶�� ������ �ϳ��� �������� �� ���� rank�� �ְ� ����� �ȴ�.
	�׸��� ���� ������ 0�� �� ��÷��ȣ�� �ƴ϶�� ������ rank + zero�� �ȴ�.
*/

int check[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int rank = 1;
	int zero = 0;

	for (int i = 0; i < win_nums.size(); i++) {
		check[win_nums[i]] = true;
	}
	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == 0) zero++;
		else if (!check[lottos[i]]) rank++;
	}

	if (rank >= 6) answer.push_back(6);
	else answer.push_back(rank);

	if (rank + zero >= 6) answer.push_back(6);
	else answer.push_back(rank + zero);


	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<int> lottos = { 44,1,0,0,31,25 };
	vector<int> win_nums = { 31,10,45,1,6,19 };

	vector<int> answer = solution(lottos, win_nums);

	for (int a : answer) {
		cout << a << " ";
	}


	return 0;
}