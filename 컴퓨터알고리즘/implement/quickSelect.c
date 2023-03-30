#include <stdio.h>

int devide(int *data, int start, int end){
	//퀵정렬의 분할 방법과같음

	int right = data[end];
	//배열의 마지막값
	int left = start -1;
	//처음 인덱스 
	int temp;

	printf("%d :left\n",left);

	for(int i= start; i<end; i++){
		//배열의 처음부터 끝가지 반복
		if(data[i] <= right ){
			//배열의 값이 right보다 작거나 같으면 값을 교환후 left를 한칸 이동 
			temp = data[i];
			data[i] = data[++left];
			data[left] = temp;
		}
	}

	//값을 교환후 배열의 마지막값과 이동된 left의 값을 교환 
	temp = data[end];
	data[end] = data[left +1];
	data[left + 1] = temp;

	//왼쪽 고정 값을 출력 
	printf("left is : %d\n",left + 1);
	return left +1;
}

int select(int *data, int start, int end, int k){
	//배열의 값이 1개이면 바로 ㅂ값을 반환 
	if(start == end)
		return data[start];


	int q = devide(data,start,end);

	//기준 값을 정하여 left , right를 분할    
	int i = q - start + 1;
	// k가 배열 data에서 몇번째로 작은 원소인지 계산

	//입력된 k 의 값이배열index보다 작다면 
	if(k<i){
		return select(data, start, q-1, k);
		//left에서 탐색

	}
	//k의 값이 배열의 index와 같다면 값을 바로 반환
	else if(k == i){
		return data[q];
	}
	//다 아니라면 right에서 탐색후 출력
	else{
		return select(data, q + 1, end, k- i);
	}
}


int main(void){

	int data[12] = {6,3,11,9,12,2,8,15,18,10,7,14};
	int k;
	printf("k -> ");
	//k를 입력 받음 
	scanf("%d",&k);
	int result = select(data,0,11, k);
	
	//k번째로 작은 값을 출력
	printf("%d\n",result);

	return 0;
}
