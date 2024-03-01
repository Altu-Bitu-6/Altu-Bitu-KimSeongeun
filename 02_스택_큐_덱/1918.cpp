#include <iostream>
#include <stack>
#include <map>

using namespace std;
int main(void)
{
	string c; // 입력 문장
	stack<char> s; // 피연산자를 담을 스택
	map<char, int> priority; // 산술기호의 우선순위
	
	priority['*'] = 2; 	priority['/'] = 2;
	priority['+'] = 1; 	priority['-'] = 1;
	priority['('] = 0;

	cin >> c;

	for (int i = 0; i < c.length(); i++)
	{
		if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/') {
			while (!(s.empty()) && priority[s.top()] >= priority[c[i]]) // 스택에 있는 피연산자의 우선순위가 높거나 같으면 출력한다.
			{
				cout << s.top();
				s.pop();
			}
			s.push(c[i]); // 현재 인덱스(피연산자)를 스택에 삽입한다.
		}
		else if (c[i] == '(') {
			s.push(c[i]);
		}
		else if (c[i] == ')') {
			char op = s.top(); 
			s.pop();

			while (op != '(') {
				cout << op;
				op = s.top(); 
				s.pop();
			}
		}
		else {
			cout << c[i]; // 피연산자가 아닌 문자는 바로 출력한다.
		}
	}

	while (!(s.empty())) { // 스택에 남아있는 피연산자를 출력한다.
		cout << s.top();
		s.pop();
	}

	return 0;
}