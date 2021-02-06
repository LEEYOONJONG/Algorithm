#include <iostream>
#include <deque>
using namespace std;



int main() {
	int n, k;
	deque<pair< int, int >> apple;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int row, col;
		cin >> row >> col;
		apple.push_back(make_pair(row, col));
	}
	
	int l;
	deque<pair<int, char>> direction;
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		direction.push_back(make_pair(x, c));
		// 8 D
		// 10 D
		// 11 D
		// 13 L
	}
	direction.push_back(make_pair(-1, 'X')); // �����÷� ���� �ȳ�����

	deque<pair<int, int>> snake;
	int directNum = 0; // 0�̸� ������, 1�̸� �Ʒ���, 2�� ����, 3�̸� ����.
	int time = 0;
	snake.push_back(make_pair(1, 1));
	int directCount = 0;
	while (1) {
		time++;
		int newRow, newCol;
		// �ϴ� �Ӹ� �߰�
		switch (directNum) {
		case 0: // ������
			//1. �Ӹ� �þ��, �Ӹ��� ����� Ȯ��, �Ӹ��� ��� �ִ��� Ȯ��, ����ó��
			newRow = snake.back().first;
			newCol = snake.back().second + 1;
			snake.push_back(make_pair(newRow, newCol));
			break;
		case 1: // �Ʒ���
			newRow = snake.back().first+1;
			newCol = snake.back().second;
			snake.push_back(make_pair(newRow, newCol));
			break;
		case 2: // ����
			newRow = snake.back().first;
			newCol = snake.back().second - 1;
			snake.push_back(make_pair(newRow, newCol));
			break;
		case 3: // ����
			newRow = snake.back().first - 1;
			newCol = snake.back().second;
			snake.push_back(make_pair(newRow, newCol));
			break;
		default:
			break;
		}

		// �Ӹ��� ������ �ʰ������� �ʴ���
		if (snake.back().first < 1 || snake.back().first > n || snake.back().second <1 || snake.back().second > n) {
			break;
		}
		// ���� �쿡 ����� Ȯ�� (�Ӹ� ����)
		bool isCollide = false;
		for (int i = 0; i < snake.size()-1; i++) { 
			if (snake[i].first == snake.back().first
				&& snake[i].second == snake.back().second) {
				isCollide = true;
				break; // ���� ���� ���� �߰��� �Ӹ��� �����
			}
		}
		if (isCollide) break;

		// �Ӹ� ��ġ�� ����� �ִٸ�
		bool isApple = false;
		for (int i = 0; i < apple.size(); i++) {
			if (apple[i].first == snake.back().first 
				&& apple[i].second == snake.back().second) { //i index ��ġ�� ����� �ִٸ�,
				isApple = true;
				//iterator �̿��Ͽ� ��� �����ϱ�
				deque<pair<int,int>>::iterator iter;
				iter = apple.begin();
				for (int j = 1; j <= i; j++) {
					iter++;
				}
				apple.erase(iter);

				break;
			}
		}
		if (!isApple) snake.pop_front(); // ���� ������ ���� ���̱�
		
		if (time == direction[directCount].first) { //time�� ������ȯ�ð��� �����Ѵٸ�
			if (direction[directCount].second == 'L') directNum = (directNum + 3) % 4;
			else if (direction[directCount].second == 'D') directNum = (directNum + 1) % 4;
			directCount++;
		}
	}
	cout << time;

}