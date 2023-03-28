#include <stdio.h>


void quickSort(int data[], int start, int end){
	if (start >= end){  // 원소 가 1개인경우
		return;
	}
	int pivot = start ; //pivot은 첫번째 원소
	int left= start + 1;   // left 는 pivot값을 제외한 첫번째 값 
	int right = end;			//right는 배열의 제일 마지막 값  
	int temp;

	while(left <= right){									//left 선택된값이 right와 교차 하기 전까지 
		while(data[left] <= data[pivot]){		//첫번째 pivot값보다 작다면 		
			left++;														//left를 한칸 오른쪽으로 이동 
		}
		while(data[right] >= data[pivot] && right > start){
			//pivot값보다 right값이 크고 right 는 start보다 클때 ->
			//start = pivot값이기 때문에 오른쪽으로 이동하더라도 넘어가면 안되는부분이다.
			right--;
			//right를 왼쪽으로 한칸 이동 
		}
		if(left > right){
			//현재 교차한 상태라면 왼쪽에 있는값 (교차한 상태여서 오른쪽값이 왼쪽에 가있다.)
			//pivot 과  왼쪽에 있는값 교환 
			temp = data[right];
			data[right] = data[pivot];
			data[pivot] = temp;
		}
		else{
			//교차 상태가 아니라면 right 값과  left값을 교환 
			temp = data[right];
			data[right] = data[left];
			data[left] = temp;
		}

		for(int i = 0; i<end;i++){
			printf("%d ->",data[i]);
		}
		printf("\n");
		printf("---------------------------------\n");
		quickSort(data, start , right);
		quickSort(data, left+1 , end);
		
	}


}

int main(void){
	int num = 12;
	int data[12] = {6, 3, 11,9,12, 2, 8, 15,18,10,7,14};

	printf("-----------------Before----------------\n");
	for(int i=0;i<num;i++){
		printf("%d ->",data[i]);
		}
	printf("\n---------------------------------------\n");
	quickSort(data,0,11);
	printf("-----------------Result----------------\n");
	for(int i=0;i<num;i++){
		printf("%d ->",data[i]);
		}
	printf("\n");

	return 0;
}
