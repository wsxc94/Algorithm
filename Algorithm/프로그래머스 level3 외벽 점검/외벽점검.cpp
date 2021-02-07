#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

//�ð�,�ݽð� �ٵȴ�. ������ ģ���� ���� ���� ���� �Ϸ��� �Ȱ��� �������� ģ���� Ž������ ���� , ���� ����������� ��������Ѵ�.
//���� -> ����
//�׽�Ʈ���̽� 1�� �������� (1 5 6 10) -> (5 6 10 1) -> (6 10 1 5) -> (10 1 5 6) �� 4���� ��츦 Ž��

int solution(int n, vector<int> weak, vector<int> dist) {

	int answer = -1;

	// �Ÿ������� ����
	sort(dist.begin(), dist.end());
	
	for (auto& a : dist) cout << a << " ";

	//����Ž�� weak.size()��ŭ �ݺ�
	for (int i = 0; i < weak.size(); i++) {

		//������� ��ȯ 
		// ���� Ž���� �ϱ����� �� ���� ���ڰ� �ڷ� ���鼭 ���� n�� �����ش�
		// ex (1 5 6 10) -> (5,6,10,13) -> (6,10,13,17) -> (10 ,13 ,17 ,18)
		int tmp = weak[0] + n;
		for (int j = 1; j < weak.size(); j++) {
			weak[j - 1] = weak[j];
		}
		weak[weak.size() - 1] = tmp;

		//ģ���� ��ġ
		do {

			//w : ������� index, d : ģ���� index
			int w = 0;
			int d = 0;

			//ģ�� �Ѹ��� �� �� �ִ� ������� ���� ��� Ž��
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

			//��� ��������� Ž�� �Ǿ��ٸ�, ���� ���� ģ���� ����� ��� ����
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