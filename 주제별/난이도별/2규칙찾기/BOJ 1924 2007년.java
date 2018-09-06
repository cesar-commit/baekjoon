/*
백준 온라인 저지 BOJ 1924번 2007년
*/
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String input = scanner.nextLine();
		String str[] = input.split(" ");
		int month = Integer.parseInt(str[0]);
		int day = Integer.parseInt(str[1]);
		int diff=0;
		int[] calen = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		String[] week =  {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

		if(month==1) {
			diff = day-1;
		}
		else {
			diff += 30;
			for(int i=2;i<month;i++) {
				diff+=calen[i-1];
			}
			diff+=day;
		}
		int result=diff%7;
		System.out.print(week[result]);
	}
}
