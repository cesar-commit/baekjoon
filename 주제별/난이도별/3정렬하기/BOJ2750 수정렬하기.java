/*
백준 온라인 저지 BOJ 2750번 수 정렬하기

- 아무렇게나 정렬해도 된다.
*/

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int sort[] = new int[N];	int i=0;	int j;
		while(i<N) {
			int val = sc.nextInt();
			if(i != 0) {
				for(j=0;j<i;j++) {
					if(sort[j] < val)
						continue;
					else if(sort[j] >= val) {
						for(int k=i-1; k >= j; k--)
							sort[k+1] = sort[k];
					}	break;
				}	sort[j] = val;
			}
			else {
				sort[i] = val;
			}
			++i;
		}
		for( j=0;j<N;j++) {System.out.println(sort[j]);}
	}
}
