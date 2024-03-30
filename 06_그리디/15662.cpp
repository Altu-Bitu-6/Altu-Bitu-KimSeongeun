#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
stack<pair<int, int>> s; // 회전 시킬 바퀴, 방향을 pair 형태로 스택에 저장

void getRotate(int v, int dir, vector<int> &visit, vector<vector<int>> &wheel) { 
	// v: 회전시킬 바퀴 번호, dir: 방향, visit: 바퀴를 스택에 넣었는지 체크하는 함수, wheel: 바퀴 정보
	
	if (v>=2 && visit[v-1]==0 && (wheel[v][6] != wheel[v - 1][2])) // 왼쪽 바퀴가 돌아가는지
	{
		s.push(make_pair(v-1,dir*-1)); // 왼쪽 바퀴를 스택에 넣는다.
		visit[v-1]=1;
		getRotate(v-1,dir*-1,visit,wheel); // 왼쪽 바퀴를 돌릴 때 같이 돌아갈 바퀴를 조사한다.
	}
	if (v <= wheel.size()-2 && visit[v + 1] == 0 && wheel[v][2] != wheel[v + 1][6]) // 오른쪽 바퀴가 돌아가는지
	{
		s.push(make_pair(v + 1, dir * -1)); // 오른쪽 바퀴를 스택에 넣는다.
		visit[v + 1] = 1;
		getRotate(v + 1, dir * -1, visit, wheel); // 오른쪽 바퀴를 돌릴 떄 같이 돌아갈 바퀴를 조사한다.
	}
}
int main(void)
{
	int t, k;  //t: 톱니바퀴 개수, k: 회전 횟수
	int i, j;

	cin >> t;
	vector<vector<int>> wheel(t+1,vector<int>(8,0)); // wheel: 톱니바퀴 톱니.

	for (i = 1; i <= t; i++) {
		for (j = 0; j < 8; j++) {
			char x; cin >> x;
			wheel[i][j] = x - '0'; // int형으로 바퀴 입력받는다.
		}
	}
	
	cin >> k;

	while(k--)
	{	
		int num, direction; // num: 회전시킬 바퀴 번호, direction: 회전 방향
		cin >> num >> direction;
		
		vector<int> visit(t+1, 0); // visit: 스택에 바퀴를 넣었는지 체크하는 배열

		while (!s.empty()) s.pop(); // 스택을 초기화한다.

		s.push(make_pair(num, direction)); // 현재 톱니바퀴를 스택에 넣는다.
		visit[num] = 1; // 스택에 넣은 바퀴번호를 체크한다. (무한루프 방지)
		getRotate(num, direction, visit, wheel); // getRotate함수로 현재 톱니바퀴 양쪽으로 돌릴 톱니바퀴를 구해서 스택에 넣는다.
	
		//돌릴 바퀴들이 스택에 모두 들어갔다. 이후 연산...
		while (!s.empty()) 
		{
			pair<int, int> rotateWheel = s.top(); // 스택에서 바퀴를 하나씩 꺼낸다.
			s.pop();

			int index = rotateWheel.first; // 돌릴 바퀴의 인덱스
			int dir = rotateWheel.second; // 바퀴 돌릴 방향

			if (dir == 1) { // 시계방향으로 돌리기
				int tmp = wheel[index][7];
				for (i = 7; i >= 1; i--) {
					wheel[index][i] = wheel[index][i - 1];
				}
				wheel[index][0] = tmp;
			}
			else { // 반시계방향으로 돌리기
				int tmp = wheel[index][0];
				for (i = 0; i <= 6; i++) {
					wheel[index][i] = wheel[index][i + 1];
				}
				wheel[index][7] = tmp;
			}
		}
	}

	int cnt = 0; // 0번 인덱스가 1인지 카운트하는 변수
	for (i = 1; i <= t; i++) {
		if (wheel[i][0] == 1) {
			cnt++;
		}
	}

	cout << cnt; // 최종적으로 0번 인덱스가 1인 바퀴 개수를 출력한다	

	return 0;
}