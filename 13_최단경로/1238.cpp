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
                // 마을 그래프 배열 d를 마을간 최단 거리 배열로 갱신
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	
	int maxTime = 0;
	for (i = 1; i <= n; i++)
	{
        // i 마을의 소요 시간은 (i 마을에서 파티 마을까지 시간) + (파티 마을에서 i 마을까지 시간) 
		if (i != start) { // maxTime 에 각 마을 소요시간의 최댓값을 저장
			maxTime = max(maxTime, d[i][start] + d[start][i]);
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