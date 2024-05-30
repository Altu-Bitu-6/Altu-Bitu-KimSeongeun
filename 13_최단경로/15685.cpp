#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100; // 격자의 좌표 범위 (0 <= x,y <= 100)

int dy[4] = { 0, -1, 0, 1 }; // dy dx는 오른쪽, 위, 왼쪽, 아래 를 나타내는 방향값 배열이다. 
int dx[4] = { 1, 0, -1, 0 };

int cntSquares(vector<vector<bool>>& plane) { /* 문제 조건에 맞는 사각형 수를 구한다. */
    int ans = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // 사각형의 모든 꼭짓점을 지나면(true) ans이 1 증가한다.
            if (plane[i][j] && plane[i + 1][j] && plane[i][j + 1] && plane[i + 1][j + 1]) { 
                ans++;
            }
        }
    }
    return ans;
}

void drawDragonCurve(vector<vector<bool>>& plane, int x, int y, int d, int g) { 
    
    /* 전달된 값으로 plane 배열에 커브를 그린다. */

    vector<int> direct; // direct[]: 매 순간마다 그린 방향을 저장한다.

    /* 시작점 입력 */
    plane[y][x] = plane[y + dy[d]][x + dx[d]] = true; // (x,y)와 (x + dx[d], y + dy[d]) 를 그린다 (true).

    x += dx[d]; // 기준점을 (x + dx[d], y + dy[d])로 바꿔준다.
    y += dy[d];
    
    direct.push_back(d); // 처음에 그린 방향 저장
    
    /* 세대 수(=커브를 그려야 하는 횟수) 만큼 순환 한다*/
    while (g--) { 
        int size_d = direct.size();
        for (int j = size_d - 1; j >= 0; j--) {
            int next_d = (direct[j] + 1) % 4; // next_d : 이전에 그렸던 선에서 시계 방향으로 한번 튼 방향
            x += dx[next_d];
            y += dy[next_d];
            plane[y][x] = true; // plane[y][x]에 표시한다(true).
            direct.push_back(next_d); // 다음 세대를 위해 next_d를 push 한다.
        }
    }
}

int main()
{
    int n, x, y, d, g;
    vector<vector<bool>> plane(SIZE + 1, vector<bool>(SIZE + 1, false));  // plane[][]: 꼭짓점을 지나가면 true 

    /* 입력 */
    cin >> n; // n: 드래곤 커브를 그리는 횟수
    while (n--) {
        cin >> x >> y >> d >> g; // (x,y): 드래곤 커브 시작점  d: 방향  g: 세대
        drawDragonCurve(plane, x, y, d, g); // 입력을 바로 plane 배열에 반영한다.
    }

    /* drawDragonCurve()로 그래프를 모두 그리면, cntSquares()로 조건에 맞는 사각형 수를 구한다.  */
    cout << cntSquares(plane) << '\n';
    return 0;
}