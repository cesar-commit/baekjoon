/*
백준 온라인 저지 BOJ 1316번 그룹 단어 체커
*/

#include <iostream>
#include <string>
using namespace std;


//flag = true: 연속 모드 시작
//bigflag = true : 연속 모드 broken

int main(void) {
	string input;	int N = 0;		cin >> N;	int cnt = 0;
	while (N>0) {
		bool alpha[26] = { 0 };	bool flag = false;	bool bigflag = false;
		cin >> input;
		for (int i = 0; i < input.length(); i++) {
			int tmp = input[i] - 'a';

			if ((i != 0) && input[i - 1] == input[i])			//flag = T
				flag = true;
			else if ((i != 0) && flag && input[i - 1] != input[i])		//flag = f
				flag = false;

			if ((i > 0) && !flag && alpha[tmp]) {	//fail - 연속해서 나타나지 않은 글자가 있는 경우
				bigflag = true;	break;
			}
			if (!flag)		// if not failed, alpha[i]=T
				alpha[tmp] = true;
		}

		if (!bigflag) { // 연속해서만 나타났다면 count
			++cnt;
		}
		--N;
	}
	cout << cnt;
	return 0;
}
