#include <iostream>
#include <vector>

using namespace std;
struct coordinate {
	int y;
	int x;
} a[6], s, v;

void findS(int minX, int maxX, int minY, int maxY)
{
	int yy, xx;
	int i;

	yy = minY; xx = minX;
	for (i = 0; i < 6; i++) {
		if (a[i].y == yy && a[i].x == xx) {
			break;
		}
	}
	if (i == 6) {
		s.x = xx; s.y = yy; return;
	}

	yy = maxY; xx = minX;
	for (i = 0; i < 6; i++) {
		if (a[i].y == yy && a[i].x == xx) {
			break;
		}
	}
	if (i == 6) {
		s.x = xx; s.y = yy; return;
	}

	yy = minY; xx = maxX;
	for (i = 0; i < 6; i++) {
		if (a[i].y == yy && a[i].x == xx) {
			break;
		}
	}
	if (i == 6) {
		s.x = xx; s.y = yy; return;
	}

	yy = maxY; xx = maxX;
	for (i = 0; i < 6; i++) {
		if (a[i].y == yy && a[i].x == xx) {
			break;
		}
	}
	if (i == 6) {
		s.x = xx; s.y = yy; return;
	}
}
int main(void)
{
	int i;
	int k;
	int y=0, x=0; // 좌표 시작점

	cin >> k;
	for (i = 0; i < 6; i++)  // 여섯 꼭짓점 좌표를 배열 a에 입력받는다.
	{
		int way, len;
		cin >> way >> len;
		if (way == 1) { //동쪽
			x += len;
		}
		else if (way == 2) { //서쪽
			x -= len;
		}
		else if (way == 3) { // 남쪽
			y -= len;
		}
		else { //북쪽
			y += len;
		}

		a[i].x = x; a[i].y = y;
	}

	int minX = a[0].x, maxX = a[0].x, minY = a[0].y, maxY = a[0].y;

	for (i = 0; i < 6; i++)
	{
		if (a[i].x < minX) {
			minX = a[i].x;
		}
		if (a[i].x > maxX) {
			maxX = a[i].x;
		}
		if (a[i].y < minY) {
			minY = a[i].y;
		}
		if (a[i].y > maxY) {
			maxY = a[i].y;
		}
	}

	// 가장 큰 사각형 안에 쏙 들어가있는 점(안쪽 꼭짓점)을 찾는다. => 꼭짓점 v
	
	for (i = 0; i < 6; i++) {
		if (a[i].x == minX || a[i].x == maxX || a[i].y == minY || a[i].y == maxY) {
			continue;
		}
		else {
			break;
		}
	}
	
	v.y = a[i].y; v.x = a[i].x;

	// 안쪽으로 파인 지점의 가상 꼭짓점 (큰 사각형의 꼭짓점으로 있어야 할) 좌표 구하기 => 꼭짓점 s

	findS(minX, maxX, minY, maxY);

	// 잘리지 않았다고 가정할 때 큰 사각형의 넓이
	int bigSum = (maxX - minX) * (maxY - minY);

	// 잘려진 부분 사각형의 넓이
	int subSum = abs(v.x - s.x) * abs(v.y - s.y);

	// 출력값
	cout << (bigSum - subSum) * k;

	return 0;
}