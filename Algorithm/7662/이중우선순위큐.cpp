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
    map ���� dual priority queue ����
	ó���� multiset���� �����Ͽ����� �޸𸮿� �ӵ��� 2������ ������ map���� �ٽ� ����

	D�� �Էµ��� �� ���� ������� ������
	�Է¹��� num�� 0���� ū�� �������� ���� iterator�� ó�� , �� �� ����Ų��
	�׸��� iterator�� value�� ���� ���� ���� ���� �Ǵ��Ѵ�.

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