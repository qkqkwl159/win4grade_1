#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int front;
	int back;
	int *farr;
	int *barr;
}value;

void merge(int arr[], int left[], int left_size, int right[], int right_size){
	int i =0, j=0, k=0;

	while(i<left_size && j< right_size){
		if(left[i] <=right[j]){
		arr[k++] = left[i++];
		}else{
			arr[k++] =right[j++];
		}
	}
	while(i < left_size){
		arr[k++] = left[i++];
	}
	while(j < right_size){
		arr[k++] = right[j++];
	}

}
void devide(int *arr,int arrsize){


	printf("ArrSize : %d\n\n",arrsize);
	if(arrsize==1){
		printf("끝\n");
		return;
//		p.front = fr[0];
//		p.back = ba[0];
	}
	//int N = sizeof(arr);

	int mid=arrsize/2;

	int *fr = (int*)malloc(sizeof(int) * mid);
	int *ba = (int*)malloc(sizeof(int) * (arrsize - mid));



	for(int i = 0; i<mid;i++){
		fr[i]=arr[i];
	//	printf("fr--------\nfr[%d] = %d\n",i,fr[i]);
	}
	printf("\n\n");
	for(int i = mid; i<arrsize;i++){
		ba[i-mid]=arr[i];
	//	printf("ba--------\nba[%d] = %d\n",i,fr[i]);
	}

	devide(fr,mid);
	devide(ba,arrsize-mid);
//	p.farr = fr;
//	p.barr = ba;

	printf("end\n");
	merge(arr,fr,mid,ba,arrsize-mid);
}


	
int main(void){

	int A[8] = {37,10,22,30,35,13,25,24};
	value *p = (value*)malloc(sizeof(p) * 8);
	//n 은 Arr A의 원소 갯수
	int n = sizeof(A)/sizeof(int);
	// 분할 하기위한 n / 2
//	while(n!=1){
//	n = n/2;
//	printf("N = %d\n\n",n);
//
//	//절반 분할하고 그 갯수 만큼 동적할당
//	int *B  = (int*)malloc(sizeof(int) * n);
//	printf("B ");
//	for(int i =0; i<n;i++){
//		B[i] = A[i];
//		printf("%d -> ",B[i]);
//	}
//
//	printf("\n");
//	printf("C ");
//	int *C = (int*)malloc(sizeof(int) * n);
//	for(int i =n; i<n*2; i++){
//		C[i-n] = A[i];
//		printf("%d -> ",C[i-n]);
//	}
//
//	printf("\n\n");
//
//	}

//	for(int i=0;i<n-1;i++){
//
//		p[i]=devide(A,n);
//		n=n/2;
//	}
	devide(A,n);

	for(int i =0;i< n; i++){
		printf("%d -> ", A[i]);
	}
	printf("\n");
//
//	n = n/2;
//	p[1] = devide(p[0].farr,n);
//	p[2] = devide(p[0].barr,n);
//
//	n = n/2;
//	p[3] = devide(p[1].farr,n);
//	p[4] = devide(p[1].barr,n);
//	p[5] = devide(p[2].farr,n);
//	p[6] = devide(p[2].barr,n);
//
//	printf("%d : %d\n",p[3].front,p[3].back);
//	printf("%d : %d\n",p[4].front,p[4].back);
//	printf("%d : %d\n",p[5].front,p[5].back);
//	printf("%d : %d\n",p[6].front,p[6].back);
//
	printf("-------------------------------\n");
	int index = 0;

	int *result = (int*)malloc(sizeof(int) * 8);

	for(int i=3;i<7;i++){
		if(p[i].front > p[i].back){
			printf("front Excute!\n");
			result[index] = p[i].back;
			index++;
			result[index] = p[i].front;
			index++;
		}else{
			result[index] = p[i].front;
			index++;
			result[index] = p[i].back;
			index++;
		}
	}
	for(int i =0; i<8;i++)
		printf("%d -> ",result[i]);
		


	free(p->farr);
	free(p->barr);
	free(p);
	

	return 0;
}
