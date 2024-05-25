#include <iostream>
#include <vector>
#define INF 1000001

using namespace std;
int floyd(int start, int n, vector<vector<int>>& d) 
{
	int i, j, k;	

	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j]) { // 입력받은 그래프 배열 d 를 마을 간 최단 거리 배열로 갱신한다.
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	
	int maxTime = 0;
	for (i = 1; i <= n; i++)
	{
		if (i != start) { // i 마을의 소요시간은 (i 마을에서 파티 마을까지 가는 시간) + (파티 마을에서 i 마을로 오는 시간) 이다.
			maxTime = max(maxTime, d[i][start] + d[start][i]); // 각 마을의 소요시간 중 최댓값을 maxTime에 저장한다.
		}
	}

	return maxTime;
}
int main(void)
{
	int n, m, x; // 마을 수, 도로 수, 시작 정점
	int i;

	cin >> n >> m >> x;
	vector<vector<int>> d(n + 1, vector<int>(n + 1, INF)); // 마을 간 거리

	for (i = 1; i <= n; i++) {
		d[i][i] = 0;
	}

	for (i = 1; i <= m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		d[a][b] = t;
	}
	
	cout << floyd(x, n, d);

	return 0;
}