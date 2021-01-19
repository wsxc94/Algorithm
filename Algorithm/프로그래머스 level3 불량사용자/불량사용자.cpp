#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

bool ch[8];
int banned_size, user_size;
set<string> s;

void dfs(int idx, string res, vector<string> user_id, vector<string> banned_id) {
	if (idx == banned_size) {
		//�ҷ� ������� ���̵� �̺�Ʈ ������ ���̵�� ��� ���εǾ� �������� �� ��������ٸ�
		sort(res.begin(), res.end());
		s.insert(res);
		return;
	}

	string banName = banned_id[idx];
	int banSize = banName.size();

	//�� ������ ���̵�� index��° �ҷ� ����� ���̵� ���Ѵ�.
	for (int i = 0; i < user_size; i++) {
		string userName = user_id[i];

		//�̺�Ʈ ������ ���̵�� �ҷ� ����� ���̵��� ���̰� �ٸ��ٸ� continue
		if (userName.size() != banSize) continue;
		//i��° ������̵� �̹� �ҷ� ������� ���̵�� ���ε� ��� continue
		if (ch[i]) continue;


		bool cmp = true;
		//*�� ������ ���ڵ��� ������ �˻�
		for (int j = 0; j < banSize; j++) {
			if (banName[j] == '*') continue;

			//���ڰ� �ϳ��� �ٸ��� ���ε� �� ����.
			if (userName[j] != banName[j]) {
				cmp = false;
				break;
			}
		}


		//�ҷ� ������� ���̵�� ���� ������ �κ��� ���� ���
		if (cmp) {
			//i��° ����� ���̵�� index��° �ҷ����̵� ���ε� ������ üũ�ϰ� ���� �ҷ����̵� ��츦 Ž���Ѵ�.
			ch[i] = true;
			dfs(idx + 1, res + to_string(i), user_id, banned_id);

			//index��° �ҷ� ���̵� ���� �� �� �ִ� �ٸ� ����� ���̵� ���� ���� i���� �ٽ� false�� üũ
			ch[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int answer = 0;
	vector<string> user_id = {"frodo" , "fradi" , "crodo" "abc123" , "frodoc"};
	vector<string> banned_id = { "fr*d*" , "abc1**" };

	user_size = user_id.size();
	banned_size = banned_id.size();

	dfs(0, "", user_id, banned_id);

	answer = s.size();

	cout << answer << "\n";
	return 0;
}