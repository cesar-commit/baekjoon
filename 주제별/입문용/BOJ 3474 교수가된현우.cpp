/*
백준 온라인 저지 BOJ 3474 교수가 된 현우

## 알고리즘 tip:
'0'이 하나 생기기 위해서는 2 x 5가 필요하다.
2, 5 각각 총 몇개의 인수가 있는지 세고, 그 중 작은 수만큼 '0'이 생긴다.
그런데 2는 짝수가 한번 곱해질때마다 하나 이상 인수가 생기므로
5의 개수만 새면 된다.

## 코딩 tip:
C++의 최적화를 위한
    ios :: sync_with_stdio(false);
    cin.tie(0);
을 사용하지 않으면 시간초과가 뜬다.

또, cout에서 '\n' 대신 endl을 사용하면 시간초과가 뜬다.
이거때매 너무 해멨다;;
*/

#include <iostream>
using namespace std;

int main(void) {
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int n;		cin >> n;
	int m = 0;
	while(n--) {
		cin >> m;		int sum = 0;
		for(int div = 5; div <= m; div *= 5){
			sum += m / div;
		}
		cout << sum << '\n';
	}
	return 0;
}
