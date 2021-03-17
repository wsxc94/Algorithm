#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

/*
    문자열 두개를 입력받고 
	첫번째 문자열에서 두번째 문자열이 보이지않을때까지 없애주는 문제

	stack과 비슷한 형식으로 한글자씩 넣어주며 word 검사 후 word 문자열의 마지막 글자와 같으면 이전 문자열을
	확인해주며 길이 판별후 삭제해주는 식으로 구현하였다.
*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s, word;
	cin >> s >> word;

	string ans = "";

	int w_len = word.length() - 1;

	for (int i = 0; i < s.length(); i++) {
		ans += s[i];
		if (ans[ans.length() - 1] == word[w_len]) {
			if (ans.length() >= word.length()) {
				int cnt = 1;
				for (int j = w_len - 1; j >= 0; j--) {
					if (ans[ans.length() - (w_len - j) - 1] == word[j]) {
						cnt++;
					}

				}
				if (word.length() == cnt) {
					for (int b = 0; b < word.length(); b++) {
						ans.pop_back();
					}
				}
			}
		}
	}
	if (ans.length() > 0) {
		cout << ans << endl;
	}
	else {
		cout << "FRULA" << endl;
	}

	return 0;
}