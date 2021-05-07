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
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int res;
	int idx = 1;

	// 캠핑장을 연속하는 P일중 L일동안만 사용할 수 있고
	// V일 짜리 휴가를 막 시작했다.
	// (V/P) * L = 연속하는 P일이 V일중에 몇번인지 세고 P일중 L일만 사용가능한지 구한다
	// min(V%P , L) = 더하는 부분이 만약 L,P,V가 5,8,20 이면
	// 연속하는 8일씩 사용하고 난 뒤 나머지 4일
	// 나머지와 사용 가능 일수를 비교해서 더적은 날만큼 더한다.
	while (true)
	{
		int L, P, V;
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0) break;

		res = (V / P) * L + min(V%P, L);

		cout << "Case " << idx << ": " << res << "\n";
		idx++;
	}
	return 0;
}