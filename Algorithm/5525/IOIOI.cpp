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
    for문 앞에서부터 s를 확인해 I가 나오면 while문으로 IOI 를 검출하여 size 를 +1 해준다
	 size == n 이 되면 size -1 그리고 결과값 ans +1을 해주면 된다.

*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, len, ans = 0;
	string s;

	cin >> n >> len >> s;

	for (int i = 0; i < len; i++)
	{
		int size = 0;

		if (s[i] == 'O') continue;
		else {
			while (s[i+1] == 'O' && s[i+2] == 'I')
			{
				size++;
				if (size == n) {
					size--;
					ans++;
				}
				i += 2;
			}
			size = 0;
		}
	}
	cout << ans << "\n";

	return 0;
}