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
#include <set>
using namespace std;
/*
단어를 주면 그 단어를 이루는 알파벳들로 만들 수 있는 
단어들을 사전 순으로 정렬할 때에 주어진 단어 다음에 
나오는 단어를 찾는 프로그램을 작성하시오.

ex) BEER
BEER
BERE
BREE
EBER
EBRE
EEBR
EERB
ERBE
EREB
RBEE
REBE
REEB

permutation을 통해 string 순열을 구하고 2번째 단어에서 break 해주고 출력하면 된다.
*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string word, ans;
		cin >> word;

		int cnt = 0;

		do
		{
			ans = word;
			if (cnt == 1) break;
			cnt++;

		} while (next_permutation(word.begin() , word.end()));

		cout << ans << "\n";
	
	}
	
	return 0;
}