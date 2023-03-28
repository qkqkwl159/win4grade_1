#include <stdio.h>
#include <stdlib.h>


void quickSort(int arr[] , int L,int R){


	int left = L, right = R;					//L은가장 왼쪽 R은 가장 오른쪽 index
																		//left ,right는 조건에 따라 움직이는 index
	int pivot = arr[(L + R) /2];			//pivot 은 가운데 값으로 배열의중심 값
	int pivotIdx = (L + R) /2;
	printf("function start ----------------------\n");
	printf("Pivot Index : %d\n",pivotIdx);
	printf("Pivot  : %d\n",pivot);
	int temp;													//스왑을 위한 빈 변수 

	do{																//한번은 실행해주는 do while을 이용 
		while (arr[left] < pivot)				//배열의 left값이 가운데 값보다 작다면 left index를 오른쪽으로이동 
			left++;
		while (arr[right] > pivot)			//배열의 right값이 가운데 값보다 크다면 right index를 왼쪽으로 이동
			right--;
		if (left<= right){							//left와 right가 계속이동하다가 left의 index가 right보다 작을때
																		//-> right와 left가 교차하기 전까지  
			temp = arr[left];							// 두값을 바꾸어 준다 (swap)
			arr[left] = arr[right];
			arr[right] = temp;
			left++;												//left and right 를 한칸씩 이동
			right--;
		}
	}while (left <=right);						//위 과정을 left 가 right보다 오른쪽에 갈때까지 반복

	printf("-------------------------------------------------------\n");


	printf("\n\n");
	if (L < right)										//pivot 기준으로 나누어진 왼쪽 배열을 반복
		quickSort(arr,L, right);
		printf("\nleft\n\n");
		for(int i=0;i<pivotIdx;i++){
			printf("%d -> ",arr[i]);
		}
	
	if (left < R)
		quickSort(arr,left, R);					//pivot 기준으로 나누어진 오른쪽  배열을 반복
		printf("\nright\n\n");
		for(int i=pivotIdx;i<R;i++){
			printf("%d -> ",arr[i]);
		}

}

int main(void){
	int A[12] = {6,3,11,9,12,2,8,15,18,10,7,14};

	printf("Before : ");
	for(int i=0;i<12;i++)
		printf("%d -> ",A[i]);

	quickSort(A,0,12-1);

	printf("\n\n");

	printf("After : ");
	for(int i=0;i<12;i++)
		printf("%d -> ",A[i]);

	//https://code-lab1.tistory.com/
	return 0;

}
