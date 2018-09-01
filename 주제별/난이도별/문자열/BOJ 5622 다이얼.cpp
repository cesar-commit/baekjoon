/*
백준 온라인 저지 BOJ 5622번 다이얼

Tips:
- 번호에 알파벳이 3개 있는 번호가 있고 4개 있는 번호가 있다는 것을 주의해야 한다.
- if else if else if ... 할 때 조건문에
  79 < c <= 83 이렇게 하면 제대로 작동을 안 한다.
  79 < c && c <= 83 이렇게 해야 의도대로 작동한다.
- 길고 긴 switch 문을 사용하고 싶지 않아서 다르게 작성해 보았다.
*/


#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;	cin >> s;	int c;		int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		c = s[i];
		if (c <= 79)	//A - O
			sum += (c - 65) / 3 + 3;
		else if (79 < c && c <= 83)	//P - S
			sum += 8;
		else if (83 < c && c<= 86)	//T - V
			sum += 9;
		else	//W - Z
			sum += 10;
	}
	cout << sum;
	return 0;
}
