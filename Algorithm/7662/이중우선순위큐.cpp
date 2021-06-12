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
    map 으로 dual priority queue 구현
	처음엔 multiset으로 구현하였으나 메모리와 속도가 2배정도 느려서 map으로 다시 구현

	D가 입력됐을 때 맵이 비어있지 않으면
	입력받은 num가 0보다 큰지 작은지에 따라 iterator를 처음 , 끝 을 가리킨다
	그리고 iterator의 value를 통해 삭제 할지 말지 판단한다.

*/
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		map<int, int> m;

		int size;
		cin >> size;

		char c;
		int num;

		while (size--)
		{
			cin >> c >> num;

			if (c == 'I') m[num]++;
			else if (c == 'D' && !m.empty()) {
				map<int, int>::iterator iter;
				if (num > 0) {
					iter = (--m.end());
				}
				else {
					iter = m.begin();
				}
				if (!--iter->second) m.erase(iter);
			}
		}

		if (m.empty()) cout << "EMPTY" << "\n";
		else cout << (--m.end())->first << ' ' << m.begin()->first << "\n";
	
	}
	
	return 0;
}