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
	direction.push_back(make_pair(-1, 'X')); // 오버플로 오류 안나도록

	deque<pair<int, int>> snake;
	int directNum = 0; // 0이면 오른쪽, 1이면 아래쪽, 2면 왼쪽, 3이면 위쪽.
	int time = 0;
	snake.push_back(make_pair(1, 1));
	int directCount = 0;
	while (1) {
		time++;
		int newRow, newCol;
		// 일단 머리 추가
		switch (directNum) {
		case 0: // 오른쪽
			//1. 머리 늘어나기, 머리가 닿는지 확인, 머리에 사과 있는지 확인, 꼬리처리
			newRow = snake.back().first;
			newCol = snake.back().second + 1;
			snake.push_back(make_pair(newRow, newCol));
			break;
		case 1: // 아래쪽
			newRow = snake.back().first+1;
			newCol = snake.back().second;
			snake.push_back(make_pair(newRow, newCol));
			break;
		case 2: // 왼쪽
			newRow = snake.back().first;
			newCol = snake.back().second - 1;
			snake.push_back(make_pair(newRow, newCol));
			break;
		case 3: // 위쪽
			newRow = snake.back().first - 1;
			newCol = snake.back().second;
			snake.push_back(make_pair(newRow, newCol));
			break;
		default:
			break;
		}

		// 머리가 게임판 초과하지는 않는지
		if (snake.back().first < 1 || snake.back().first > n || snake.back().second <1 || snake.back().second > n) {
			break;
		}
		// 뱀이 뱀에 닿는지 확인 (머리 제외)
		bool isCollide = false;
		for (int i = 0; i < snake.size()-1; i++) { 
			if (snake[i].first == snake.back().first
				&& snake[i].second == snake.back().second) {
				isCollide = true;
				break; // 뱀의 몸이 새로 추가된 머리와 닿는지
			}
		}
		if (isCollide) break;

		// 머리 위치에 사과가 있다면
		bool isApple = false;
		for (int i = 0; i < apple.size(); i++) {
			if (apple[i].first == snake.back().first 
				&& apple[i].second == snake.back().second) { //i index 위치에 사과가 있다면,
				isApple = true;
				//iterator 이용하여 사과 삭제하기
				deque<pair<int,int>>::iterator iter;
				iter = apple.begin();
				for (int j = 1; j <= i; j++) {
					iter++;
				}
				apple.erase(iter);

				break;
			}
		}
		if (!isApple) snake.pop_front(); // 애플 없으면 꼬리 줄이기
		
		if (time == direction[directCount].first) { //time이 방향전환시각에 도달한다면
			if (direction[directCount].second == 'L') directNum = (directNum + 3) % 4;
			else if (direction[directCount].second == 'D') directNum = (directNum + 1) % 4;
			directCount++;
		}
	}
	cout << time;

}