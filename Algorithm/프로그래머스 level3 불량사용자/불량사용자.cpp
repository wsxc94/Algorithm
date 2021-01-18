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
		//불량 사용자의 아이디가 이벤트 응모자 아이디와 모두 매핑되어 제재목록이 다 만들어졌다면
		sort(res.begin(), res.end());
		s.insert(res);
		return;
	}

	string banName = banned_id[idx];
	int banSize = banName.size();

	//각 응모자 아이디와 index번째 불량 사용자 아이디를 비교한다.
	for (int i = 0; i < user_size; i++) {
		string userName = user_id[i];

		//이벤트 응모자 아이디와 불량 사용자 아이디의 길이가 다르다면 continue
		if (userName.size() != banSize) continue;
		//i번째 응모아이디가 이미 불량 사용자의 아이디와 매핑된 경우 continue
		if (ch[i]) continue;


		bool cmp = true;
		//*을 제외한 문자들이 같은지 검사
		for (int j = 0; j < banSize; j++) {
			if (banName[j] == '*') continue;

			//문자가 하나라도 다르면 매핑될 수 없다.
			if (userName[j] != banName[j]) {
				cmp = false;
				break;
			}
		}


		//불량 사용자의 아이디와 별을 제외한 부분이 같은 경우
		if (cmp) {
			//i번째 사용자 아이디는 index번째 불량아이디에 매핑된 것으로 체크하고 다음 불량아이디를 경우를 탐색한다.
			ch[i] = true;
			dfs(idx + 1, res + to_string(i), user_id, banned_id);

			//index번째 불량 아이디에 매핑 될 수 있는 다른 사용자 아이디를 위해 현재 i번은 다시 false로 체크
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