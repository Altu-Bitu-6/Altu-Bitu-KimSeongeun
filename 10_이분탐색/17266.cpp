#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
	int n, m;
	int i;

	cin >> n >> m;
	vector<int> light(m, 0);

	for (i = 0; i < m; i++) {
		int x; cin >> x;
		light[i] = x;
	}
	
	/* 다리 끝 - 가로등 사이 거리, 가로등 - 가로등 사이 거리를 탐색한다*/

	int hei = light[0]; // 다리 왼쪽 끝과 가로등 0 의 거리

	for (i = 1; i <= m - 1; i++)
	{
		if (light[i] - light[i - 1] > hei * 2)
		{
			int len = light[i] - light[i - 1]; // 가로등-가로등 사이 거리
			hei = len / 2 + len % 2;
		}
	}

	if (hei < n - light[m - 1]) { // 가로등 m-1과 다리 오른쪽 끝의 거리 
		hei = n - light[m - 1];
	}

	cout << hei;

	return 0;
}