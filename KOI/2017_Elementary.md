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
