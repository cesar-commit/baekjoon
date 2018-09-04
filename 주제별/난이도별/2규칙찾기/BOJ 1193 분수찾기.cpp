/*
백준 온라인 저지 BOJ 1193번 분수찾기
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
	int x;		cin >> x;		int i = 1;	int sum = 0;		int tmp = 0;
	while (x > sum) {
		sum += i;
		i++;
	}
	--i;
	sum -= i;
	tmp = x - sum;
	if (i % 2 == 0) {
		cout<< tmp << "/" << i - (tmp - 1);
	}
	else {
		cout<< i - (tmp - 1) << "/" << tmp;
	}
	return 0;
}
