#include <iostream>
#include <vector>
#define INF 501

using namespace std;

int getStudent(int n, vector<vector<int>>& d) { // graph 배열을 d 배열로 이름 바꿔서 입력 받음
	
	int i, j, k;

	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	/* jeewoo1025.log 브이로그를 참고했습니다!😁 */
	// "자신의 키가 몇 번째인지 알 수 있다"는 "모든 학생과 비교가 가능하다"와 동일하다. 
	// 즉, 거리가 무한대(∞)가 아닌 학생의 수가 N-1인 경우이다.

	int cnt = n; // 자신이 몇번째인지 알 수 있는 학생 수

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (d[i][j] != INF || d[j][i] != INF) {
				continue;
			}
			else { // i 학생과 j 학생이 서로 비교할 수 없으면 cnt-- 
				cnt--;
				break;
			}
		}
	}
	return cnt;
}
int main(void)
{
	int n, m; // 학생 수, 키 비교 횟수
	int i;

	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
	for (i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}
	for (i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1; // 간선이 있으면 graph[][] = 1;
	}

	cout << getStudent(n, graph);

	return 0;
}