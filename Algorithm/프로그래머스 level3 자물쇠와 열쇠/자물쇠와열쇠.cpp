#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int keysize, locksize, boardsize;

void rotateKey(vector<vector<int>>& key) {
	// ���踦 ȸ����Ų��.
	vector<vector<int>> newKey(keysize, vector<int>(keysize));

	for (int j = keysize - 1; j >= 0; j--) {
		for (int i = 0; i < keysize; i++) {
			newKey[i][j] = key[keysize - j - 1][i];
		}
	}

	key = newKey;
}
bool putInKey(int x , int y , vector<vector<int>> key , vector<vector<int>> board) {

	//(x, y)�� ���������� ���踦 �ڹ��迡 ���纻��.

	//key�� ���Ѵ�
	for (int i = x; i < x + keysize; i++) {
		for (int j = y; j < y + keysize; j++) {
			board[i][j] += key[i - x][j - y];
		}
	}


	//�¹��� �κ� Ȯ��
	for (int i = keysize - 1; i <= boardsize - keysize; i++) {
		for (int j = keysize - 1; j <= boardsize - keysize; j++) {
			if (board[i][j] == 1) continue;

			//1�� �ƴ϶�� �ٷ� false�� ����
			return false;
		}
	}


	return true;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<vector<int>> key = { {0,0,0} , {1,0,0} , {0,1,1} };
	vector<vector<int>> lock = { {1,1,1},{1,1,0},{1,0,1} };

	bool answer = false;

	keysize = key.size();
	locksize = lock.size();


	boardsize = locksize + (keysize - 1) * 2;

	vector<vector<int>> board(boardsize, vector<int>(boardsize, 0));


	//board�� lock�� �̸� ���س��´�. (lock�� �����Ǿ� �ְ� key�� ������ �� �̹Ƿ�)
	for (int i = keysize - 1; i <= boardsize - keysize; i++) {
		for (int j = keysize - 1; j <= boardsize - keysize; j++) {
			board[i][j] = lock[i - keysize + 1][j - keysize + 1];
		}
	}

	for (int r = 0; r < 4; r++) {

		for (int i = 0; i <= boardsize - keysize; i++) {
			for (int j = 0; j <= boardsize - keysize; j++) {

				//i,j �� key�� ����ĭ���� �ڹ��� Ȩ�� ���纻��.
				if (putInKey(i, j, key, board)) {
					answer = true;
					break;
				}

			}
		}
		//key �ð�������� 90�� ȸ��
		rotateKey(key);

	}

	cout << answer << "\n";
	return 0;
}