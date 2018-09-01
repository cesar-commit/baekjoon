/*
백준 온라인 저지 BOJ 2941번 크로아티아 알파벳

Tips:
- 크로아티아 알파벳인지 체크 할 때 첫번째 알파벳 기준으로 보기보다 뒤의 기호를 기준으로 체크하면
  if, if else 경우의 수가 더 적어서 string의 뒤에서부터 확인했다.
- if가 nested 될 경우 작은 if에 해당 되는 경우가 하나도 없어도 큰 if/ if else에서는 해당되어
  가장 마지막 큰 else에서 걸리지 않는 케이스가 많다.
  따라서 default 경우에 대한 조건문은 따로 하나의 if()로 빼고
  대신 bool flag 를 이용해서 크로아티아 알파벳 조건에 걸린 케이스가 있는지를 따로 표기했다.
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;	cin >> s;		int cnt = 0;	int i = s.length() - 1;		bool flag;
	while (i>=0){
		flag = false;
		if (i > 1 && s[i] == '=' && s[i - 1] == 'z' && s[i - 2] == 'd') {
			i -= 3;	++cnt;	flag = true;
		}
		else if (i != 0 && s[i] == '=') {
				if (s[i - 1] == 'c' || s[i - 1] == 's' || s[i - 1] == 'z')
					i -= 2;		++cnt;		flag = true;
		}
		else if (i != 0 && s[i] == '-') {
				if (s[i - 1] == 'c' || s[i - 1] == 'd')
					i -= 2;		++cnt;		flag = true;
			}
		else if (i != 0 && s[i] == 'j') {
			if (s[i - 1] == 'l' || s[i - 1] == 'n') {
				i -= 2;		++cnt;		flag = true;
			}
		}
		if (!flag) {	//default case (일반적인 알파벳 카운트)
			--i;	++cnt;
		}
	}
	cout << cnt;
	return 0;
}
