/*
백준 온라인 저지 BOJ 6064번 카잉 달력

Tips:
- 단순 구현을 하면 시간 복잡도는 O(M*N)이 되므로 시간제한(1초)를 넘겨버린다.
- 따라서 중간 단계를 건너뛸 수 있을 알고리즘을 고안해야 한다.

- 맨 처음 (1, 1)에서 각 좌표를 1씩 증가시키면서 주어진 목표의 좌표 (x, y)의 두 수 x, y에 먼저 도달하는 좌표는 고정을 시켜둔다.
예]
(1, 1)
(2, 2)
(3, 3) ==> x좌표(x)와 목표 x좌표(xe) 일치. x는 고정, y는 x의 상한인 M만큼씩 스킵.
(3, 1) : ()위의 y좌표 3 + x좌표 상한 10) % y좌표 상한 12 = 1
(3, 11)
(3, 9) ==> x, y 각각 목표 x, y좌표와 일치. break!
*/

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			int m = sc.nextInt();	int n = sc.nextInt();
			int xe = sc.nextInt(); 	int ye = sc.nextInt();
			int x=1, y=1, d=1, cnt=1;

			for(;;) {
        //x 또는 y 중 목표 좌표와 일치하는 쪽이 있다면 고정
				if(x == xe)	d=m;
				else if(y == ye) d=n;

        //고정되지 않은 좌표를 고정된 좌표의 상한만큼씩 스킵하면서 count
				x = ((x+d) % m == 0) ? m : (x+d)%m;
				y = ((y+d) % n == 0) ? n : (y+d)%n;
				cnt += d;

				if(x==xe && y==ye) break;
				if(cnt > m*n) {
					cnt = -1; break;
				}
			}
		System.out.println(cnt);
		--t;
		}

	}
}
