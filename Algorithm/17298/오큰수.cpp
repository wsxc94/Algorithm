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
  오큰수 찾기
  오큰수는 오른쪽에 있으면서 A(i)보다 큰 수 중 가장 왼쪽에 있는 수 없는 경우 -1
  ex) A = [3,5,2,7] -> 5 7 7 -1

  배열의 끝 부터 시작
  하여 stack이 비어있다면 오큰수가 없는것 이라 해당 배열을 -1로 변경
  스택이 있다면 그 안에서 오큰수가 나올때까지 pop
  반복

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