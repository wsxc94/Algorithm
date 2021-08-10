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
   https://programmers.co.kr/learn/courses/30/lessons/82612?language=cpp
   1~n 까지의 합은 n + (n+1) / 2 로 간단히 구할 수 있다.
*/
long long solution(int price, int money, int count)
{
	long long answer = 1LL * price * count * (count + 1) / 2;

	if (answer < money) return 0;

	return answer - money;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cout << solution(3, 20, 4);
	return 0;
}