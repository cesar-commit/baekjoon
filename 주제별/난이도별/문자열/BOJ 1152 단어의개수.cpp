/*
백준 온라인 저지 BOJ 1152번 단어의 개수

Tips:
1. cin vs getline(cin, string x)
	- cin: 입력의 첫 단어만 읽어옴
	- getline(cin, string x): 입력 첫 문장을 읽어옴 (단, newline으로 구분된 다음 문장은 읽어오지 못한다)

	- 둘의 차이는 다음 문서의 cin and strings 부분 참조
	 	http://www.cplusplus.com/doc/tutorial/basic_io/

2. 예외적인 경우들의 처리를 잘 해야 한다:
  1) " hi " - 문장 맨앞, 맨뒤 blank
  2) " " - 문자 없이 공백만 들어오는 경우
*/


#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string input;	getline(cin, input);	int cnt = 0;	int i;
	for (i = 0; i < input.length(); i++) {
		if (i != 0 && i != input.length() - 1 && input[i] == ' ')
			++cnt;
	}
	if (i != 1 && input[i - 1] != 0)
		cout << ++cnt;
	else
		cout << cnt;
	return 0;
}
