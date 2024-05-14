#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> sushiArray; // 연속된 k개 접시의 접시 종류 수

void getSushiArray(vector<int>& sushi, int n, int k, int d)
{
	int s, e; // 접시 시작과 끝
	vector<int> check(d + 1, 0); // 초밥 1번부터 d번까지 몇개 있는지 체크

	//0 ~ k-1 번째 접시 계산
	s = 0; e = k - 1;
	for (int i = s; i <= e; i++) 
	{
		check[sushi[i]]++;
		if (check[sushi[i]] == 1) {
			sushiArray[0]++;
		}
	}

	// 투 포인터로 나머지 배열도 계산 : [s,e] 는 [s-1, e-1] 의 앞을 빼고 뒤를 더한 범위
	// [s-1, e-1]에 sushi[e]가 없으면 sushiArray[]에 1 더한다. [s,e]에 sushi[s-1]이 없으면 sushiArray[]에 1 뺀다
	for (s = 1; s < n; s++)
	{
		e = (s + k - 1) % n;
		sushiArray[s] = sushiArray[s - 1];

		if (check[sushi[e]] == 0) {
			sushiArray[s]++;
		}

		check[sushi[e]]++; check[sushi[s - 1]]--;
		
		if (check[sushi[s - 1]] == 0) {
			sushiArray[s]--;
		}
	}
}
int getAns(vector<int> &sushi, int n, int d, int k, int c) 
{
	int s, i;
	int maxSushi = 0;

	sushiArray.assign(n, 0); // sushiArray를 먼저 구한다
	getSushiArray(sushi, n, k, d); 

	for (s = 0; s < n; s++)
	{
		int cnt = sushiArray[s];// cnt: s번부터 k개의 접시를 고를 때 스시 종류 수

		// 접시에 c가 없으면 cnt를 1 증가시킨다.
		for (i = 0; i < k; i++)
		{
			int t = (s + i) % n;
			if (sushi[t] == c) {
				break;
			}
		}
		if (i == k) cnt++;

		//maxSushi 갱신
		if (maxSushi < cnt) {
			maxSushi = cnt;
		}
	}

	return maxSushi;
}

int main(void)
{
	int n, d, k, c; // n: 접시 수  d: 초밥 갯수(1~d)  k: 연속된 접시 수  c: 쿠폰 번호
	int i;

	cin >> n >> d >> k >> c;
	vector<int> sushi(n, 0);  // 접시에 담긴 초밥 종류
	for (i = 0; i < n; i++) {
		int x; cin >> x;
		sushi[i] = x;
	}

	cout << getAns(sushi, n, d, k, c);
	return 0;
}