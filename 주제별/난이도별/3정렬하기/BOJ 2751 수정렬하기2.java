/*
백준온라인저지 BOJ 2751번 수 정렬하기 2

O(nlogn)이 가능한 병합정렬을 선택했다.

병합정렬 Tips:
- 병합정렬의 핵심 수행을 쪼개보면:
		1)가운데 index를 구해서 정렬 쪼개기
		+
		2)오름차순(or 내림차순)으로 재정렬하면서 정렬 두개씩 병합하기

- 1번에서 "정렬을 쪼갠다"는 것은 결국 코드로 나타냈을 때는 실제로 array를 새로 만드는 게 아니라,
	처음 만들어둔 array[N]의 index번호를 가지고 노는 것이다. 여기의 경우 정렬을 반으로 쪼개는 것이므로
	서로 다른 index변수 2개를(i, j) 만들어서 각각 하나씩이 각각 다른 정렬을 의미한다고 여기면 된다.
	(이 개념이 왜 그렇게 생각해 내기가 어려웠는지 모르겠다)

- 2번에서 "쪼갠 정렬을 병합한다"는 것은 병합하여 새로운 정렬을 만드는 것이 아니라,
	방금 가지고 있던 두 개의 index 변수를(i, j)를 통합할 또 다른 하나의 변수로(k)
	처음에 만든 array[N]를 변경하기만 하면 된다.
	단, 이 때 잠정적으로 써먹을 array가 하나 필요해서 여기에서 tmp[]를 잠시 생성하고,
	병합이 끝날 때(merge()함수가 끝날때)는 tmp[]도 소멸한다.
	tmp[] 소멸 직전, index k를 가지고 원본 array[k]에 새로운 값을 넣을 뿐이다.

- 즉, 총 사용하는 array[] 개수는 2개이다.
			총 사용하는 index 변수 개수는 3개이다.

*/
import java.util.Scanner;

public class Main {
	static void mergeSort(int[] ar, int start, int last) {
		if(start < last){
			int mid = (start+last) / 2;
			mergeSort(ar, start, mid);
			mergeSort(ar, mid+1, last);
			merge(ar, start, mid, last);
		}
	}

	static void merge(int ar[], int start, int mid, int last) {
		int tmp[] = new int[last - start + 1];
		int i=start;	int j = mid+1; int k=0;

		while(i<=mid && j<=last) {
			if(ar[i]<ar[j]) {
				tmp[k++]=ar[i++];
			}
			else {
				tmp[k++]=ar[j++];
			}
		}
		while(i<=mid) {
			tmp[k++]=ar[i++];
		}
		while(j<=last) {
			tmp[k++]=ar[j++];
		}
		k = 0;	i=start;
		while(k<tmp.length) {
			ar[i++]=tmp[k++];
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();	int ar[]=new int[N];
		for(int i=0;i<N;i++)
			ar[i]=sc.nextInt();
		mergeSort(ar, 0, N-1);
		for(int i=0;i<N;i++)
			System.out.println(ar[i]);
	}
}
