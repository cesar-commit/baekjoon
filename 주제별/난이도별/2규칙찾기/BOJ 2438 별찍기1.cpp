/*
백준 온라인 저지 BOJ 2438번 별찍기 -1
*/

#include<iostream>
using namespace std;

int main() {
	int n;		cin >> n;
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << "\n";
	}
	return 0;
}
