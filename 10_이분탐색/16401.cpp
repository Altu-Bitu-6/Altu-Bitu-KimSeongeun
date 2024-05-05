#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxLen = 0; // m명에게 나눠줄 수 있는 과자 최대 길이

int count(int len, int n, vector<int>& L)
{
	int i;
	int cnt = 0;

	for (i = 0; i < n; i++) {
		cnt += L[i] / len;
	}

	return cnt;
}
void binarySearch(int m, int n, vector<int>& L)
{
	int s = 1, e = L[n-1]; // 과자 길이의 최솟값은 1, 최댓값은 L[n-1]이다.
	int mid;

	while (true)
	{
		if (s > e) {
			break;
		}
		mid = (s + e) / 2;
		int cnt = count(mid, n, L); // cnt: mid 길이로 과자를 나눠줄 수 있는 최대 사람 수

		if (cnt >= m) // mid 길이로 m명 이상에게 나눠줄 수 있다면 더 길게 나눠줄 수 있는지 조사한다.
		{
			maxLen = mid;
			s = mid + 1; 
		}
		else {
			e = mid - 1; // mid보다 더 작은 길이를 조사한다.
		}
	}
}
int main(void)
{
	int n, m;
	int i;

	cin >> m >> n; // m: 조카의 수, n: 막대 과자의 수
	vector<int> L(n, 0);

	for (i = 0; i < n; i++)
	{
		int x; cin >> x;
		L[i] = x;
	}

	sort(L.begin(), L.end());
	
	binarySearch(m, n, L); // 이진탐색

	cout << maxLen;

	return 0;
}