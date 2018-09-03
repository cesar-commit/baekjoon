/*
백준 온라인 저지 BOJ 1157번 단어공부
*/

#include <iostream>
#include <string>
using namespace std;

string input;

int main(void) {
	int alpha[26] = { 0 };	//initialize w/ 0
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] > 96) 	//lowercase
			++alpha[input[i] - 'a'];
		else   	            //uppercase
			++alpha[input[i] - 'A'];
	}

	int max = -1;		int idx = 0;	bool flag = false; //최빈도 알파벳이 중복되는지
	for (int i = 0; i < 26; i++) {
		if (max == alpha[i])
			flag = true;
		if (max < alpha[i]) {
			max = alpha[i];	 idx = i;		flag = false;
		}
	}
	if (flag) {  //중복이 있다면 ?
		cout << "?";
	}
	else {
		char c = idx + 'A';
		cout << c;
	}
	return 0;
}
