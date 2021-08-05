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
    https://programmers.co.kr/learn/courses/30/lessons/77884

	left ~ right ����
	����� ������ ���ϴ� �˰��� O(n1/3) �� �̿��Ͽ� ������ ������ ¦������ Ȧ�� ����
	�Ǵ��ؼ� answer�� ���ϰų� ���ش�.

*/
int solution(int left, int right) {
	int answer = 0;

	for (int i = left; i <= right; i++) {
		int cnt = 0;
		for (int j = 1; j <= sqrt(i); j++) {
			if (i % j == 0) {
				if (i / j == j) {
					cnt++;
				}
				else {
					cnt += 2;
				}
			}
		}
		if (cnt % 2 == 0) {
			answer += i;
		}
		else {
			answer -= i;
		}
	}
	return answer;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int left = 24;
	int right = 27;

	cout << solution(left , right) << "\n";
	return 0;
}