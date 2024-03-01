#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main(void)
{
	int n, i;
	stack<int> s; // 인덱스를 넣을 스택
	vector<int> hei; // 높이
	vector<int> ans; // 답안

	cin >> n;
	ans.assign(n, -1);
	
	for (i = 0; i < n; i++)
	{
		int x; 
		cin >> x;
		hei.push_back(x);

		while (!(s.empty()) && hei[s.top()] < hei[i]) // 아직 오큰수를 만나지 못한 인덱스보다 현재 높이가 더 크면
		{
			ans[s.top()] = hei[i]; // 현재 높이를 오큰수로 저장해줌
			s.pop(); // 스택에서 pop
		}

		s.push(i); // 현재 인덱스를 스택에 삽입
	}

	for (i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}