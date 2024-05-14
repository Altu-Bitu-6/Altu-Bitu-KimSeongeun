#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> wall(50, vector<int>(50, 0)); // 벽
vector<vector<int>> visit(50, vector<int>(50, 0)); // 해당 칸을 청소했는지 체크하는 배열
int dy[4] = { -1,0,1,0 }; // 북 서 남 동 (반시계 방향)
int dx[4] = { 0,-1,0,1 };
int sum = 0; // 청소한 칸 수
int n, m; // 방의 크기

void dfs(int y, int x, int d)
{
	if (visit[y][x] == 0) {
		visit[y][x] = 1;
		sum++;
	}

	int ty, tx;
	
	// 청소하지 않은 칸이 있는지 반시계 방향으로 4방향 탐색
	for (int i = 1; i <= 4; i++)
	{
		int td = (d + i) % 4;
		ty = y + dy[td]; 
		tx = x + dx[td];
		if (wall[ty][tx] == 0 && visit[ty][tx] == 0) {
			dfs(ty, tx, td);
		}
	}

	// 청소하지 않은 칸이 없다면 후진한다.
	ty = y - dy[d];
	tx = x - dx[d];
	if (wall[ty][tx] == 0) {
		dfs(ty, tx, d);
	}
	else { 
		cout << sum;
		exit(0);
	}
}
int main(void)
{
	int r, c, d; // 로봇 청소기 좌표와 처음 방향

	cin >> n >> m;
	cin >> r >> c >> d;

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
		{
			int x; cin >> x;
			wall[i][j] = x;
		}
	}

	// 처음에 초기화한 dy[] dx[] 배열에 맞게 d값 전환
	if (d == 1) d = 3;
	else if (d == 3) d = 1;

	dfs(r, c, d);
	cout << sum;

	return 0;
}