#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
/*
   스택을 사용하여 풀 수 있는 문제.

   입력을 받으면서 스택체킹
   처음에 입력을 받은 후 스택이 비었는지 확인한다. 비었을 경우 해당 탑의 레이저를 받을 수 없기 때문에 0 출력
   있을 경우 현재 입력받은 탑의 높이와 스택의 top의 높이를 비교하여 현재 탑 보다 크기가 작을 경우 pop
   아니면 그 스택의 인덱스 번호 출력 top의 저장된 높이보다 클때까지 while을 돌다보면 답이 나온다.

*/

int n;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;
	
	stack<pair<int,int>> s;

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;

		while (!s.empty())
		{
			if (s.top().second > k) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}

		if (s.empty()) cout << 0 << " ";
		s.push({ i , k });
	}
	

	return 0;
}