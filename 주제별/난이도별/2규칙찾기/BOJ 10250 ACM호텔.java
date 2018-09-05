/*
백준 온라인 저지 BOJ 10250번 ACM 호텔

Tips:
- N값이 H로 나누어 떨어지는 경우(N % H =0)와 아닌 경우 (N % H != 0)로 나눠서 생각해야 한다.
- 방 호수가 한 자리 숫자인 경우, y와 x 사이에 '0'을 추가해 줘야 한다.
*/


import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String input = scanner.nextLine();
		int test = Integer.parseInt(input);	//number of test cases

		while(test>0) {
			String line = scanner.nextLine();
			String[] val = line.split(" ");
			int h = Integer.parseInt(val[0]);
			int w = Integer.parseInt(val[1]);
			int n = Integer.parseInt(val[2]);

			int y = n%h;	int x=0;
			if(y==0) {   //N값이 H로 나누어 떨어지는 경우
				x = n/h;
				System.out.print(h);
			}
			else {       //N값이 H로 나누어 떨어지지 않는 경우
				x = n/h + 1;
				System.out.print(y);
			}
			if(x<=9)   //방 호수가 한 자리 숫자인 경우, y와 x 사이에 '0'을 추가
				System.out.print(0);
			System.out.println(x);
			
			--test;
		}
	}
}
