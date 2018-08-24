/*
백준 온라인 저지 BOJ 4641: Doubles

brute force 사용
*/


#include <iostream>
#include <string>
using namespace std;
int value[15];

int main(void) {
	while (true) {
		int input;		cin >> input;		int answer = 0;

		//입력 끝인지 아닌지 구분
		if (input == -1) {
			return 0;
		}
		//입력 모두 배열에 넣기
		else {
			value[0] = input;		int n = 1;	//number of inputs per line(for for loops)
			while (true) {
				int input2;		cin >> input2;
				if (input2 == 0)
					break;
				else {
					value[n] = input2;
					n++;
				}
			}
			//brute force
			for (int idx = 0; idx < n; idx++) {
				for (int j = 0; j < n; j++) {
					if (value[idx] * 2 == value[j])
						++answer;
				}
			}
		}
		cout << answer << endl;
	}
	return 0;
}
