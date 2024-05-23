#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci; // 뱀이 위치한 칸 (x,y)들이 하나하나 저장된 덱을 편하게 사용하기 위해 pair형을 pi로 이름 지었다.

const int EMPTY = 0; // 보드에 들어있는 값. board[][]가 0이면 EMPTY(빈칸), 1이면 APPLE(사과), 2이면 뱀(SNAKE)이 있다. 
const int APPLE = 1;
const int SNAKE = 2;

int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
    int dx[4] = { 0, -1, 0, 1 }; // 뱀 머리 위치값에 더해서 방향을 바꾸는 함수이다.
    int dy[4] = { 1, 0, -1, 0 }; // 뱀 현재 위치에 dx[(dir + 1) % 4], dy[(dir + 1) % 4]를 더하면 왼쪽(L)으로 가게 된다.
                                 // 뱀 현재 위치에 dx[(dir + 3) % 4], dy[(dir + 3) % 4]를 더하면 오른쪽(R)으로 가게 된다.

    /* 2. 연산 시작 */
    deque<ci> snake;
    snake.push_front({ 1, 1 }); // 시작 위치 (1, 1)을 덱에 넣는다. 덱에 하나만 있으므로 현재 뱀의 길이는 1이다.
    board[1][1] = SNAKE;        // 보드에 뱀 이동을 반영한다.

    int time = 0;   // 시간
    int dir = 0;    // 현재 방향
    while (true) {
        
        /* 3. 방향을 결정하고 앞으로 간다 */
        if (cmd[time] == 'L') { // 왼쪽으로 이동해야 되면 방향 전환한다.
            dir = (dir + 1) % 4;
        }
        else if (cmd[time] == 'D') { // 오른쪽으로 이동해야 되면 방향 전환한다.
            dir = (dir + 3) % 4;
        }

        time++;                              // 시간을 1 증가시키고 앞으로 간다. (일단 간다!)

        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        /*4-1. 머리가 잘못된 위치에 있을 경우 */
        if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == SNAKE) { // 머리 위치가 벽이거나 자기 몸과 부딪힌 경우 break 한다.
            break;
        }

        /*4-2. 머리가 정상적으로 들어온 경우 */
        snake.push_front({ nx, ny }); // 빈칸으로 머리가 들어왔다면 덱에도 현재 머리 위치를 넣어준다.

        if (board[nx][ny] != APPLE) { // 들어온 위치가 사과가 아니었다면 꼬리를 뺀다.
            ci tail = snake.back();     
            board[tail.first][tail.second] = EMPTY; // 꼬리가 있던 보드 칸을 EMPTY로 바꾸고 덱에서도 꼬리를 지운다.
            snake.pop_back();
        }
        board[nx][ny] = SNAKE; // 보드에 머리를 반영한다.
    }

    /*5. 총 소요 시간을 리턴한다.*/
    return time;  
}
int main() {
    int n, k, x, y, l, time;
    char command;

    /* 1. 입력 */
    cin >> n >> k; // n: 보드의 크기  k: 사과의 개수 
    vector<vector<int>> board(n + 1, vector<int>(n + 1, EMPTY)); 
    // board: 보드판에 빈 칸(0), 사과의 위치(1), 뱀의 위치(2)가 저장된다.

    while (k--) {
        cin >> x >> y;
        board[x][y] = APPLE; // 사과의 위치를 입력 받아서 보드에 1로 저장한다.
    }
    
    cin >> l;
    map<int, char> cmd; // 뱀이 l번 바꾸는 방향을 입력받아서 cmd 맵에 저장한다. <방향 바꾸는 시간, D(오른쪽)/L(왼쪽)>
    while (l--) {
        cin >> time >> command; 
        cmd[time] = command;
    }

    cout << playGame(n, board, cmd); // 입력값을 함수에 넘겨서 답을 출력한다.
    return 0;
}