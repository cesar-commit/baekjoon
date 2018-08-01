# 2017 정보올림피아드 초등부

## 1. 딱지 놀이
*해당 페이지 문제는 백준(https://www.acmicpc.net/)을 참고했습니다*

문제를 보기 위해 [여기](https://www.acmicpc.net/problem/14696)를 클릭하세요.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int times;
	cin >> times;
	string res;

	while (times>0)
	{
		int an;
		cin >> an;
		int ar[4];
		for (int j = 0; j<4; j++)
		{
			ar[j] = 0;
		}
		for (int i = 0; i < an; i++)
		{
			int value;
			cin >> value;
			if (value == 1)
				ar[0]++;
			else if (value == 2)
				ar[1]++;
			else if (value == 3)
				ar[2]++;
			else if (value == 4)
				ar[3]++;

		}

		int bn;
		cin >> bn;
		int br[4];
		for (int j = 0; j<4; j++)
		{
			br[j] = 0;
		}
		for (int i = 0; i < bn; i++)
		{
			int value;
			cin >> value;
			if (value == 1)
				br[0]++;
			else if (value == 2)
				br[1]++;
			else if (value == 3)
				br[2]++;
			else if (value == 4)
				br[3]++;
		}



		string result = "D\n";
		for (int i = 3; i >= 0; i--)
		{
			if (ar[i] > br[i])
			{
				result = "A\n";
				break;
			}
			else if (ar[i] < br[i])
			{
				result = "B\n";
				break;
			}
		}

		res.append(result);
		times--;
		//printf ("%c\n", result);
	}

	cout << res;

	return 0;
}
```

## 2. 방 배정하기
*해당 페이지 문제는 백준(https://www.acmicpc.net/)을 참고했습니다*

문제를 보기 위해 [여기](https://www.acmicpc.net/problem/14697)를 클릭하세요.


```cpp
#include <iostream>

using namespace std;

int main()
{
	int a, b, c, tmp, num;
	cin >> a;
	cin >> b;
	if (a > b)
	{
		tmp = b;
		b = a;
		a = tmp;
	}	// a < b
	cin >> c;
	if (b > c)
	{
		tmp = c;
		c = b;
		b = tmp;
	}	// a< b< c
	cin >> num;

	int quo = 0; int quo2 = 0; int rem1 = 0; int rem2 = 0;
	int result = 0;
	quo = num / c;
	for (int i = quo; i >= 0; i--)
	{
		rem1 = num - c * i;
		if (rem1 == 0)
		{
			cout << '1';
			return 0;
		}
		quo2 = rem1 / b;
		for (int j = quo2; j >= 0; j--)
		{
			rem2 = rem1 - b * j;
			if (rem2 == 0)
			{
				cout << '1';
				return 0;
			}
			if (rem2%a == 0)
			{
				cout << '1';
				return 0;
			}
		}
	}

	cout << result;

	return 0;
}
```


## 3. 서울에서 경산까지
*해당 문제는 백준(https://www.acmicpc.net/)을 참고했습니다.*


*해당 소스 코드는 http://sanya-surplus.tistory.com/45 을 참고했습니다.*

문제를 보기 위해 [여기](https://www.acmicpc.net/problem/14863)를 클릭하세요.

- dp[n번째도시][현재까지의 시간합계]에 현재의 도시까지 모인 모금액을 표기한다.

- vis[n번째도시][현재까지의 시간합계] 배열이 '1'인 경우에만 모금액 계산을 실행한다.

	('1'이 아닌 vis[][]는 continue로 빨리 넘겨버림)

- 중간중간 comment는 예시 시뮬레이션


```cpp
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define MAXN 100
#define MAXK 100000

using namespace std;
//3 1650
//500 200 200 100
//800 370 300 120
//700 250 300 90
int W[MAXN];
int WC[MAXN];
int B[MAXN];
int BC[MAXN];

int N, K;

// 함수 밖에서 선언한 배열은 '0'으로 초기화됨
// (함수 안에서 선언하면 쓰레기값으로 초기화)
int DP[MAXN + 1][MAXK + 1];
int vis[MAXN + 1][MAXK + 1];

int main(void) {
	scanf_s("%d%d", &N, &K);
	for (int i = 0; i<N; i++) {
		scanf_s("%d%d%d%d", &W[i], &WC[i], &B[i], &BC[i]);
	}
	// W: 500 800 700
	//WC: 200 370 250
	// B: 200 300 300
	// BC: 100 120 90

	vis[0][0] = 1;
	int w, wc, b, bc;
	for (int i = 0; i<N; i++) {
		// w=500	wc=200	b=200	bc=100
		w = W[i], wc = WC[i], b = B[i], bc = BC[i];
		for (int j = 0; j <= K; j++) {
			// vis[1][500] 올때까지 continue
			if (vis[i][j] == 0) continue;
			if (j + w <= K) {
				//DP[i+1][j+w] = max(현재DP=0, 직전DP + 현재도시wc)
				//DP[1][500] = max(DP[1][500], DP[0][0] + 200)
				//DP[2][1300] = max(DP[2][1300], DP[1][500] + 370)
				DP[i + 1][j + w] = max(DP[i + 1][j + w], DP[i][j] + wc);
				//i=0/j=0:	DP[1][1200] = max(DP[1][1200], DP[0][0] + 2300)
				//i=1/j=1200:	DP[2][2900] = max(DP[2][2900], DP[1][1200] + 2000)
				//i=2/j=2900:	if(false) / if(false)
				//이 이후는 계속 첫번째 if에 걸려서 쭉 '0'으로 남음.

				//vis[1][500] = 1
				vis[i + 1][j + w] = 1;


			}
			if (j + b <= K) {
				DP[i + 1][j + b] = max(DP[i + 1][j + b], DP[i][j] + bc);
				vis[i + 1][j + b] = 1;
			}
		}
	}
	int m = 0;
	for (int j = 0; j <= K; j++) {
		//dp[][]의 n번째 row 값들만 비교해서 그 중 최대.
		// n번째 row 값들은 각각의 다른 경로를 통해서 도달한 모금액.
		// 중간에 시간 제한에 막힌 경로들의 nth row값은 '0'일 것.
		m = max(m, DP[N][j]);
	}
	printf("%d", m);
	}
	```
