/*
백준 온라인 저지 BOJ 1475번 방 번호
*/
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int dig[] = new int[9];
		String n = sc.nextLine();
		int max = 0;
		for(int i=0;i<n.length();i++) {
			char c = n.charAt(i);
			if(c - '0' == 6 || c - '0' == 9) {
				++dig[6];
			}
			else {
				++dig[c - '0'];
				if(max < dig[c - '0'])
					max = dig[c-'0'];
			}
		}
		int exc;
		if(dig[6]%2 != 0)
			exc = dig[6] / 2 + 1;
		else
			exc = dig[6] / 2;

		if(exc > max)
			max = exc;
		System.out.print(max);
	}
}
