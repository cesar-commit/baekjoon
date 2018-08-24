/*
백준 온라인 저지 BOJ 6376번: e 계산

0, 1, 2 일때는 cout.precision() 처리 할 필요 없고,
n=3 이상부터는 cout.precision(9), cout<<fixed 를 처리하면 된다.
precision(9) 처리만 하면 8자리가 출력되고,
precision(9), cout<<fixed 를 하면 9자리가 출력된다.
*/


#include <iostream>
#include <string>
using namespace std;

int main(void) {
	double e = 0;
	int fact = 1;
	cout << 'n' << ' ' << 'e' << endl;
	cout << "- -----------" << endl;
	for (int i = 0; i < 10; i++) {
			if (i > 0) {
			fact *= i;
		}
		e += (double)1 / fact;
		if (i < 3)
			cout << i << " " << e << "\n";
		else {
			cout.precision(9);
			cout << i << fixed << " " << e << "\n";
		}
	}
	return 0;
}
