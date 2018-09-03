/*
백준 온라인 저지 BOJ 2908번 상수

Tips:
int를 string으로 변환하는 과정 등 없이 입력받은 자연수를 뒤집는 코드를 작성한다.
*/

#include<iostream>
using namespace std;

int main() {
	int x, y;		int reversex=0, reversey = 0;	cin >> x;		cin >> y;
	while (x > 0) {
		reversex = reversex * 10 + x % 10;
		x /= 10;
	}
	while (y > 0) {
		reversey = reversey * 10 + y % 10;
		y /= 10;
	}

	if (reversex >= reversey)
		cout << reversex;
	else
		cout << reversey;
	return 0;
}
