#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; // ���� ũ��
	int k; // ��� ����
	int l; // ���� ��ȯ Ƚ��

	int map[101][101] = { 0, }; // �� �⺻�� : 0
	pair<int, char> dir_change[101]; // ���� ��ȯ
	int cur_change_index = 0;

	const int APPLE = 1;
	const int SNAKE = -1;

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	//���� ��ȯ �ε���
	//��ȸ�� �� ���, cur_direction = (cur_direction + 3) % 4;
	//��ȸ�� �� ���, cur_direction = (cur_direction + 1) % 4;
	int cur_direction = 0;

	//�ʱ� �� ��ġ
	map[0][0] = SNAKE;
	pair<int, int> head = { 0, 0 };
	queue<pair<int, int>> snake;
	snake.push(head);

	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y; // ��� ��ġ

		cin >> x >> y;
		map[x - 1][y - 1] = APPLE;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		//���⺯ȯ
		cin >> dir_change[i].first >> dir_change[i].second;
	}

	int sec = 0;

	while (1)
	{
		sec++;

		int nx = head.first + dx[cur_direction];
		int ny = head.second + dy[cur_direction];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
		{
			//���̸� ���� ��
			break;
		}
		else if (map[nx][ny] == SNAKE)
		{
			//�̵��� ��ġ�� ���� ���� �Ϻκ��̸� ���� ��
			break;
		}
		else if (map[nx][ny] != APPLE)
		{
			//����� ������ ������ �̵�
			auto tail = snake.front();
			snake.pop();

			map[tail.first][tail.second] = 0;
		}

		//�Ӹ� ��ĭ �̵�
		head = { nx, ny };
		snake.push(head);

		map[nx][ny] = SNAKE;


		//���� ������ ã��
		int dir_change_sec = dir_change[cur_change_index].first;
		if (cur_change_index < l && dir_change_sec == sec)
		{
			char dir = dir_change[cur_change_index].second;
			if (dir == 'L')
			{
				cur_direction = (cur_direction + 3) % 4;
			}
			else if (dir == 'D')
			{
				cur_direction = (cur_direction + 1) % 4;
			}
			cur_change_index++;
		}
	}

	cout << sec << '\n';

	return 0;
}