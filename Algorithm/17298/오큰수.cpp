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
  ��ū�� ã��
  ��ū���� �����ʿ� �����鼭 A(i)���� ū �� �� ���� ���ʿ� �ִ� �� ���� ��� -1
  ex) A = [3,5,2,7] -> 5 7 7 -1

  �迭�� �� ���� ����
  �Ͽ� stack�� ����ִٸ� ��ū���� ���°� �̶� �ش� �迭�� -1�� ����
  ������ �ִٸ� �� �ȿ��� ��ū���� ���ö����� pop
  �ݺ�

*/

constexpr int MAX = 1000000;
int arr[MAX];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	stack<int> s;

	for (int i = n - 1; i >= 0; i--)
	{
		int top = arr[i];

		while (!s.empty() && s.top() <= top)
		{
			s.pop();
		}
		if (s.empty()) arr[i] = -1;
		else arr[i] = s.top();
		s.push(top);
	}

	for (int i = 0; i < n; i++) cout << arr[i] << ' ';


	return 0;
}