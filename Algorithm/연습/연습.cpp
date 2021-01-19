#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

//핸드폰 문자들을 먼저 배열에 기록 0번은 초기화이므로 비워둠
//0,1,2,3,4,5,6,7,8,9
vector<string> phone = { "" , ".QZ","ABC","DEF","GHI","JKL" , "MNO" , "PRS" , "TUV" , "WXY" };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	char before = ' '; // 전 인덱스의 문자를 저장하기위함 처음부터 출력이 되면 안되기때문에 임의의 스페이스 ' ' 로 시작함 인덱스를 1부터 시작하고 before을 s[0]번으로 먼저 시작하는 방법도 있음.
	int cnt = 0; // 중복 번호 카운트
	string ans = ""; // 답

	for (int i = 0; i < s.size(); i++)
	{
		if (before != ' ' && s[i] == before) { // 전 문자가 ' ' 이고  현재 인덱스의 숫자버튼이 같으면 중복이기때문에 카운트를 늘림
			cnt++;
		}
		else {
			if (before != ' ' && before != '0') { // 전 문자가 ' ' 이 아니고 초기화버튼인 0이 아니라면
				ans += phone[before - '0'][cnt]; // 답에 before 을 숫자로바꿔준 버튼 번호의 현재 중복횟수 cnt에 잇는 문자를 더해줌 ex) 2번이 3번 클릭됐으면 C라는 문자가 반환됨 
			}
				cnt = 0; //문자를 출력했으니 카운트 초기화하고
				before = s[i]; // 다음 검사할 버튼의 번호를 저장함 
		}
	}
	// s가 다돌았지만 마지막에 대한 부분을 처리해주지 못했기 때문에 마지막 연산을 해줌.
	ans += phone[before - '0'][cnt];

	cout << ans << "\n";

	return 0;
}