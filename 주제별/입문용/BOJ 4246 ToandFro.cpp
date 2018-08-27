/*
백준 온라인 저지 BOJ 4246 To and Fro
*/

#include <iostream>
#include <string>
using namespace std;
#define MAX 200

int main(void) {
	char arr[MAX] = { ' ' };
	unsigned int col;	string msg;
	while (true) {
		cin >> col;
		if (col == 0)
			return 0;
		else {
			cin >> msg;
			//rearrange
			for (int i = 1; i <= msg.length() / col; i++) {
				if (i % 2 == 0) {
					for (int j = col - 1; j >= 0; j--) {
						arr[(i - 1) * col + (col-1) - j] = msg[(i - 1) * col+ j];
					}
				}
				else {
					for (int j = 0; j < col; j++) {
						arr[(i - 1) * col + j] = msg[(i - 1) * col + j];
					}
				}
			}

			//print
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < msg.length() / col; j++) {
					cout << arr[i + j*col];
				}
			}		cout << '\n';
		}
	}
	return 0;
}


/*
다른 분 코드도 좋아서 노트해둔다.(블로그 http://www.crocus.co.kr/996?category=159837 참고)

algorithm 에 들어있는 reverse 함수를 유용하게 사용했다.
reverse를 사용하면 mul=홀수 인 부분들에 대해서는 처리를 안 해도 되므로 속도도 빨라진다.
reverse 함수에 관한 example은 여기 http://www.cplusplus.com/reference/algorithm/reverse/
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        string str;
        cin >> str;

        int len = str.size();

        for (int mul = 1; n * mul < len; mul+=2)
            reverse(str.begin() + n * mul, str.begin() + n * (mul + 1));

        for (int start = 0; start < n; start++)
            for (int pos = start; pos < len; pos += n)
                cout << str[pos];
        cout << endl;
    }

    return 0;
}
