#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

//시계,반시계 다된다. 하지만 친구의 수를 가장 적게 하려면 똑같은 방향으로 친구가 탐색하지 못한 , 다음 취약지점부터 보내줘야한다.
//원형 -> 직선
//테스트케이스 1번 기준으로 (1 5 6 10) -> (5 6 10 1) -> (6 10 1 5) -> (10 1 5 6) 의 4가지 경우를 탐색

int solution(int n, vector<int> weak, vector<int> dist) {

	int answer = -1;

	// 거리순으로 정렬
	sort(dist.begin(), dist.end());
	
	for (auto& a : dist) cout << a << " ";

	//원형탐색 weak.size()만큼 반복
	for (int i = 0; i < weak.size(); i++) {

		//취약지점 순환 
		// 쉽게 탐색을 하기위해 맨 앞의 숫자가 뒤로 가면서 숫자 n을 더해준다
		// ex (1 5 6 10) -> (5,6,10,13) -> (6,10,13,17) -> (10 ,13 ,17 ,18)
		int tmp = weak[0] + n;
		for (int j = 1; j < weak.size(); j++) {
			weak[j - 1] = weak[j];
		}
		weak[weak.size() - 1] = tmp;

		//친구들 배치
		do {

			//w : 취약지점 index, d : 친구들 index
			int w = 0;
			int d = 0;

			//친구 한명이 갈 수 있는 취약지점 까지 모두 탐색
			for (d = 0; d < dist.size(); d++) {
				int fin = weak[w] + dist[d];
				while (fin >= weak[w]) {
					w++;
					if (w == weak.size()) {
						break;
					}
				}
				if (w == weak.size()) {
					break;
				}
			}

			//모든 취약지점이 탐색 되었다면, 가장 적게 친구를 사용한 결과 저장
			if (w == weak.size()) {
				if (answer == -1 || d + 1 < answer) {
					answer = d + 1;
				}
			}

		} while (next_permutation(dist.begin(), dist.end()));
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<int> weak = { 1,5,6,10 };
	vector<int> dist = { 1,2,3,4 };
	cout << solution(12, weak, dist) << "\n";

	return 0;
}