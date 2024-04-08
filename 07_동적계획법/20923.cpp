#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards; // 카드 deque 배열을 저장할 자료형을 cards로 이름 짓는다.
const int DO = 0, SU = 1; // DO 와 SU를 ! 연산으로 편하게 계산하기 위해 0, 1로 상수화 한다.

string judge(cards& deck) // [가장 마지막 단계] 누가 승자인지 판단하기
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size(); // 도도와 수연의 덱 크기를 구한다.
	if (do_deck > su_deck) { // 도도의 덱 크기가 더 클 경우 도도 리턴
		return "do";
	}
	else if (do_deck < su_deck) { // 수연의 덱 크기가 더 클 경우 수연 리턴
		return "su";
	}
	return "dosu"; // 두 덱 크기가 같을 경우 무승부 리턴
}

void groundToDeck(deque<int>& deck, deque<int>& ground) // 승자의 덱과 넣을 카드 더미를 입력받음
{
	while (!ground.empty()) {
		deck.push_back(ground.back()); // push_back()과 pop_back()으로 카드 더미를 전부 덱 밑으로 넣는다. 방향 주의하기.
		ground.pop_back();
	}
}

void ringTheBell(int player, cards& deck, cards& ground) 
{
	groundToDeck(deck[player], ground[!player]); // 상대방의 그라운드 더미를 내 덱으로 넣는다.
	groundToDeck(deck[player], ground[player]);  // 내 그라운드 더미도 내 덱에 넣는다.
}


int whoCanRingTheBell(cards& deck, cards& ground) 
{
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 만약 도도 그라운드의 맨 위 카드가 5이면 (empty() 체크로 오류 방지)
		return DO; // 도도가 벨을 울린다.
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 만약 수연 그라운드의 맨 위 카드가 5이면 (empty() 체크로 오류 방지)
		return DO; // 도도가 벨을 울린다.
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { 
		return SU; // 만약 두 그라운드가 비어있지 않고, 맨 위 카드의 합이 5이면 수연이 벨을 울린다.
	}
	return -1; // 조건을 만족하지 않으면 벨을 울리지 않는다. (-1 반환)
}

string game(int m, cards& deck, cards& ground) 
{
	bool turn = DO; // 도도부터 게임을 시작한다.
	while (m--) {
		ground[turn].push_front(deck[turn].front()); //그라운드에 카드를 내려놓는다.
		deck[turn].pop_front(); // 덱에서 내려놓은 맨 위 카드 삭제
		if (deck[turn].empty()) { // 덱이 비게되면 게임을 멈춘다. (상대방의 승리)
			break;
		}

		int bell = whoCanRingTheBell(deck, ground); // 벨을 울릴 수 있는지 확인한다.
		if (bell != -1) {  //벨을 울릴 조건을 만족하면
			ringTheBell(bell, deck, ground); //벨을 울린다.
		}
		turn = !turn; // 다음 사람 진행 (0->1 , 1->0)
	}
	return judge(deck); //게임이 끝나고 누가 이겼는지 판단해서 이름 문자열을 리턴한다.
}

int main() 
{
	int n, m, card1, card2;
	cards deck(2), ground(2); // deck[0]과 ground[0]은 도도의 카드 더미이다. deck[1]과 ground[1]은 수연의 카드 더미이다.

	cin >> n >> m;
	while (n--) { // 도도와 수연이 n장의 카드를 입력받는다.
		cin >> card1 >> card2;
		deck[DO].push_front(card1); // 밑에 카드부터 도도 덱에 push한다.
		deck[SU].push_front(card2); // 밑에 카드부터 수연 덱에 push한다.
	}

	cout << game(m, deck, ground); // 입력받은 deck과 ground로 m번 게임 실행해서 승자를 출력하기.

	return 0;
}