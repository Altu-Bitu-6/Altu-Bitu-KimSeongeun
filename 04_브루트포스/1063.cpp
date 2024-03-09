#include <iostream>
#include <vector>

using namespace std;

int isok(int n, char& y, char& x, int dy[], int dx[]) //킹 또는 돌이 벗어나지 않는지 확인하는 함수
{
	if ('1' <= y + dy[n] && y + dy[n] <= '8') {
		if ('A' <= x + dx[n] && x + dx[n] <= 'H') {
			return 1;
		}
	}
	return 0;
}
void move(int num, char &sy, char &sx, char &stoneY, char &stoneX, int dy[], int dx[]) {
	
	// 킹이 벗어나지 않고 돌과 겹치지 않으면 -> 킹을 이동한다.
	// 킹이 벗어나지 않았는데 돌과 겹치면 -> 돌이 벗어나지 않으면 -> 킹과 돌을 이동한다.

	if (isok(num, sy, sx, dy, dx)) 
	{
		if (sy + dy[num] == stoneY && sx + dx[num] == stoneX) {
			if (isok(num, stoneY, stoneX, dy, dx)) {
				sy += dy[num]; sx += dx[num]; stoneY += dy[num]; stoneX += dx[num];
			}
		}
		else {
			sy += dy[num]; sx += dx[num];
		}
	}
}
int main(void)
{
	int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
	int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
	int n;

	char sy, sx;
	char stoneY, stoneX;

	cin >> sx >> sy;
	cin >> stoneX >> stoneY;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		
		if (s == "R") move(0, sy, sx, stoneY, stoneX, dy, dx);
		if (s == "L") move(4, sy, sx, stoneY, stoneX, dy, dx);
		if (s == "B") move(2, sy, sx, stoneY, stoneX, dy, dx);
		if (s == "T") move(6, sy, sx, stoneY, stoneX, dy, dx);
		if (s == "RT") move(7, sy, sx, stoneY, stoneX, dy, dx);
		if (s == "LT") move(5, sy, sx, stoneY, stoneX, dy, dx);
		if (s == "RB") move(1, sy, sx, stoneY, stoneX, dy, dx);
		if (s == "LB") move(3, sy, sx, stoneY, stoneX, dy, dx);
	}
	
	cout << sx << sy << "\n" << stoneX << stoneY;

	return 0;
}