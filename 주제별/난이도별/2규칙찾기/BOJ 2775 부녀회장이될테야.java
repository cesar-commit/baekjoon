/*
백준 온라인 저지 BOJ 2775번 부녀회장이 될테야
*/

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int[][] ar = new int[15][14];
		for(int i=0;i<14;i++) //initialize 0F
			ar[0][i]= i+1;
		for(int i=1;i<15;i++) {
			for(int j=0;j<14;j++) {
				if(j==0)
					ar[i][j]=1;
				else
					ar[i][j]=ar[i][j-1] + ar[i-1][j];
			}
		}

		while(t>0) {
			int k = sc.nextInt();	int n = sc.nextInt();
			System.out.println(ar[k][n-1]);
			--t;
		}
	}
}
