#include <iostream>
#include <vector>

using namespace std;
void process(int v, int n, vector<vector<int>>& d, vector<int>& visit)
{
	if (visit[v] == 1) {
		return;
	}
	visit[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0 && d[v][i] == 1) {
			process(i, n, d, visit);
		}
	}
}
int main(void)
{
	int n, m;
	int i;

	cin >> n >> m;

	vector<vector<int>> d(n+1, vector<int>(n+1, 0)); // 그래프
	vector<int> visit(n + 1, 0); // 방문할 수 있는 노드는 visit[]가 1

	for (i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		d[a][b] = d[b][a] = 1;
	}

	process(1, n, d, visit); // visit[](방문 가능 노드)를 체크하는 함수

	int cnt = 0;
	for (i = 1; i <= n; i++) {
		cnt += visit[i];
	}

	cout << cnt - 1; // 1번 컴퓨터를 제외하고 방문한 노드의 수를 출력한다.
	return 0;
}