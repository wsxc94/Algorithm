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
�ܾ �ָ� �� �ܾ �̷�� ���ĺ���� ���� �� �ִ� 
�ܾ���� ���� ������ ������ ���� �־��� �ܾ� ������ 
������ �ܾ ã�� ���α׷��� �ۼ��Ͻÿ�.

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

permutation�� ���� string ������ ���ϰ� 2��° �ܾ�� break ���ְ� ����ϸ� �ȴ�.
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