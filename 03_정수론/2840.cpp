#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
	int n, k, i;
	cin >> n >> k; // n: 바퀴의 칸수 k: 돌린 횟수

	vector<char> wheel(n, '?');
	vector<int> check(150, -1); // 'A'~'z'가 어디있는지 체크

	int v = 0; // v: 화살표가 가르키는 지점

	for (i = 0; i < k; i++)
	{
		int s; char a;
		cin >> s >> a;
		v = (v + s) % n;

		//문자가 이미 있다면
		if (check[a]!=-1)
		{
			if (check[a] == v) { //같은 자리가 다시 나온거라면
				continue;
			}
			else { //다른 자리에 같은 문자가 온다면
				cout << '!';
				break;
			}			
		}
		else // 새로 나온 문자라면 
		{ 
			if (wheel[v] == '?') // 자리가 비어있다면
			{
				wheel[v] = a;
				check[a] = v;
			}
			else { // 같은 자리에 다른 문자가 온다면
				cout << '!';
				break;
			}
		}
	}

	if (i == k) 
	{
		for(int j=0; j<n; j++)
		{
			cout << wheel[v];
			v = (v - 1 + n) % n;
		}
	}

	return 0;
}