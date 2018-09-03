/*
백준 온라인 저지 BOJ 10809번 알파벳 찾기

26개의 알파벳을 기준으로 for()을 실행하지 않고
입력된 string을 기준으로 for()을 실행했다.

*/

#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

string input;

int main(void) {
	int alphabet[26];
	fill_n(alphabet, 26, -1);  //alphabet배열 -1로 초기화하기 (algorithm)
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (alphabet[input[i] - 'a'] == -1) //각 알파벳의 첫번째 등장 idx만 입력하면 된다
			alphabet[input[i] - 'a'] = i;  //string의 알파벳 - 'a'하면 alphabet[]에서 자신의 자리 idx를 찾을 수 있다.
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}
	return 0;
}
