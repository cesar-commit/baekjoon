/*
백준온라인저지 BOJ 4690 완전 세제곱

pow(a, 3.0)을 쓰는 것 보다 a*a*a 를 통해 연산하는 게 훨 빠르다.
동일한 코드에서 3제곱 연산에서 pow를 썻을 때는 864ms , a*a*a를 썼을 때는 4ms 가 걸린다.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	int l, m, n = 0;
	for (int a = 2; a <= 100; a++) {
		for (int b = 2; b < a; b++) {
			for (int c = b+1; c < a; c++) {
				for (int d = c+1; d < a; d++) {
					if (a*a*a==b*b*b + c*c*c + d*d*d) {
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
					}
				}
			}
		}
	}
	return 0;
}
