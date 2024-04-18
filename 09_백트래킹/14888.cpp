#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

int MAX = INF * -1 - 1;  // 재귀함수에서 사용하기 위해 MAX, MIN, n 을 전역변수로 설정했습니다!
int MIN = INF + 1;
int n;
void process(int lev, int sum, vector<int>& op, vector<int>& v) // lev번째 숫자 뒤에 올 기호를 브루트포스로 탐색해서 
{																// 모든 sum(최종값)을 구하고 MAX, MIN과 비교합니다.
	if (lev == n-1) // n-1 개 기호 순서를 모두 정했을 때 
	{
		MAX = max(MAX, sum); // 최댓값 갱신하기
		MIN = min(MIN, sum); // 최솟값 갱신하기
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (op[i] != 0) 
		{
			op[i]--; //i번째 기호(+,-,*,/) 를 사용합니다.

			if (i == 0)	{ // +이 남았을 때
				process(lev + 1, sum + v[lev + 1], op, v);
			}
			else if (i == 1) { // -이 남았을 때
				process(lev + 1, sum - v[lev + 1], op, v);
			}
			else if (i == 2) { // *이 남았을 때
				process(lev + 1, sum * v[lev + 1], op, v);
			}
			else { // /이 남았을 때
				process(lev + 1, sum / v[lev + 1], op, v);
			}

			op[i]++; // i번째 기호 사용이 끝나면 op[]에 1을 더해서 복구합니다.
		}
	}
}
int main(void)
{
	int i, x;
	
	cin >> n;
	vector<int> v(n, 0); // n개의 숫자 입력
	for (i = 0; i < n; i++)
	{
		cin >> x;
		v[i] = x;
	}

	vector<int> op(4, 0); // 연산자 +, -, x, / 입력
	for (i = 0; i < 4; i++)
	{
		cin >> x;
		op[i] = x;
	}

	process(0, v[0], op, v); // 탐색 시작

	cout << MAX << "\n" << MIN; // 정답 출력

	return 0;
}