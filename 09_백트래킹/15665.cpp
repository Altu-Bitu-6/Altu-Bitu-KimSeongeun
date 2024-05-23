#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void process(int lev, int n, int m, vector<int>& a, vector<int> &print) 
{
	int i;
	if (lev == m)
	{ 
		for (i = 1; i <= m; i++) {
			cout << print[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (i = 1; i <= n; i++) 
	{
		print[lev + 1] = a[i];
		process(lev + 1, n, m, a, print);
	}
}
int main(void)
{
	int N, m;

	cin >> N >> m;
	vector<int> A(N+1, 0); // 입력값 
	vector<int> print(m + 1, 0); // 출력할 배열. 1번 인덱스부터 저장

	for (int i = 1; i <= N; i++)
	{
		int x; cin >> x;
		A[i] = x;
	}

	// 입력값이 중복되지 않도록 새로운 a와 n을 만든다.
	// 배열 a도 1 인덱스부터 시작한다.

	vector<int> a;
	a.push_back(0);

	sort(A.begin(), A.end());
	for (int i = 1; i <= N ; i++)
	{
		if (A[i] != A[i - 1]) {
			a.push_back(A[i]);
		}
	}
	int n = a.size() - 1;

	//수정된 배열로 계산
	process(0, n, m, a, print);

	return 0;
}