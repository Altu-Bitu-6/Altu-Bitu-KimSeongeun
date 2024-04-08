#include <iostream>
#include <vector>
#define INF 100

using namespace std;
void process(int s, int n, vector<int>& d, vector<vector<int>>& cho) 
{
	int i, j;
	vector<int> visit(n + 1, 0);

	d[s] = 0;

	for (i = 1; i <= n; i++)
	{
		int min = INF, v=s;
		for (j = 1; j <= n; j++) 
		{
			if (min > d[j] && visit[j] == 0) 
			{
				min = d[j];
				v = j;
			}
		}
		visit[v] = 1;
		for (j = 1; j <= n; j++)
		{
			if (cho[v][j] == 1 && d[j] > d[v] + 1) {
				d[j] = d[v] + 1;
			}
		}
	}
}
int main(void)
{
	int i;
	int n, m;
	int s, e; // 촌수를 구해야 하는 두 사람

	cin >> n;
	cin >> s >> e;
	vector<vector<int>> cho(n + 1, vector<int>(n + 1, 0)); // 촌수 그래프
	vector<int> d(n + 1, INF); // 사람에게 도달할 수 있는 최소 거리. (100으로 초기화)

	cin >> m;
	for (i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		cho[x][y] = cho[y][x] = 1;
	}

	process(s, n, d, cho); // d[](최소 거리)를 구하는 함수
	
	if (d[e] == INF) {
		cout << -1;
	}
	else {
		cout << d[e];
	}

	return 0;
}