/*
백준 온라인 저지 BOJ 2292번 벌집
*/
#include<iostream>
using namespace std;

int main() {
	int room;		cin >> room;	int sum = 0;		int i = 0;
	while (true) {
		if (i == 0) {
			sum = 1;
		}
		else {
			sum += i * 6;
		}
		if (room <= sum)
			break;
		i++;
	}
	cout << i + 1;
	return 0;
}
