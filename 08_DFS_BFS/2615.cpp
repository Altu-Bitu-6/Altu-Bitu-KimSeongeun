#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix; //바둑판을 저장할 2차원 vector배열을 matrix로 이름짓는다.
const int SIZE = 20, EMPTY = 0; // 바둑판의 너비는 20이다 (0 ~ 19행열). 
                                // 0은 비어있는 칸(EMPTY)이다. 1은 검은 바둑알이고 2는 흰 바둑알이다. 

const vector<int> dx = { -1, 0, 1, 1 }; // 바둑알을 왼쪽-아래 대각선, 아래, 오른쪽-아래 대각선, 오른쪽으로 4방향 탐색한다.
const vector<int> dy = { 1, 1, 1, 0 }; // dx[]와 dy[] 배열값을 현재 위치에 더하면 해당 방향으로 1칸 이동할 수 있다.

bool isValid(matrix& board, int x, int y, int color) { //바둑판의 x열 y행이 현재 위치 바둑알과 같은 색깔인지 확인한다.
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color); // 현재위치 바둑알과 x열y행 바둑알 색깔이 같다면 true를 리턴. 
}

bool checkWin(matrix& board, int x, int y) { //checkWin은 현재 바둑알과 같은 바둑알이 몇개 연속하는지 확인하는 함수이다!!
    int color = board[x][y]; // color는 바둑돌 색깔

    for (int idx = 0; idx < 4; idx++) { // 현재 바둑알을 기준으로 dx와 dy에 설정한 4방향을 차례대로 탐색하겠다.
        int cnt = 1;    // 현재위치에서 count 시작한다.
        int prev_x = x - dx[idx], prev_y = y - dy[idx]; // 탐색할 방향의 반대 방향 (이전 바둑알)
        int next_x = x + dx[idx], next_y = y + dy[idx]; // 탐색할 방향의 다음 바둑알

        if (isValid(board, prev_x, prev_y, color)) { // 만일 이전 방향으로 바둑알이 있다면 (= 현재 위치가 시작 바둑알이 아니라면)
            continue; // 다른 방향을 보겠다.
        }

        //만일 현재 위치가 시작 바둑알 이라면, 해당 방향으로 몇개가 연속하는지 count한다.
        while (isValid(board, next_x, next_y, color) && cnt < 6) { // 같은색 바둑알을 끝까지 카운트. cnt는 6까지 커질 수 있다.
            next_x += dx[idx];  // next_x와 next_y에 dx[], dy[]를 더해서 같은방향으로 1칸 가기 
            next_y += dy[idx];
            cnt++;
        }

        if (cnt == 5) { // 5개가 연속하는 방향이므로
            return true; //true를 리턴
        }
    }
    return false; // for문을 돌아서 4방향 모두 조건을 만족하지 않았다면 false를 리턴. 
}

int main() {

    matrix board(SIZE, vector<int>(SIZE, 0)); // 바둑판을 초기화한다.
    
    for (int i = 1; i < SIZE; i++)
        for (int j = 1; j < SIZE; j++)
            cin >> board[i][j];  // 바둑판에 올라와있는 검은돌, 흰돌을 입력받는다.

    // 위에서부터 차례대로 바둑알을 탐색한다.
    for (int y = 1; y < SIZE; y++) {
        for (int x = 1; x < SIZE; x++) { 

            if (board[x][y] == EMPTY) {
                continue; // 바둑알 놓여있지 않으면 continue.
            }

            if (checkWin(board, x, y)) {  // 바둑알이 놓여있고, checkWin에서 5개가 연속으로 놓여있음이 확인되면
                cout << board[x][y] << '\n' // 바둑알의 색깔과 위치를 출력한다.
                    << x << ' ' << y;
                return 0; // 정답을 출력하고 main 나오기 (끝내기). 
            }
        }
    }
    cout << 0; // for문이 끝까지 돌았다면( = 조건에 해당하는 바둑알이 없어서 return되지 않았다면) 0을 출력한다.

    return 0;
}