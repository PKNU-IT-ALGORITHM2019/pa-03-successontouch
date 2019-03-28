#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma warning(disable:4996)

#define MAX 1000000
clock_t end, start;

int man[MAX];
int temp[MAX];

void print(int N) {
	for (int i = 0; i < N; i++) {
		printf("%d \n", man[i]);
	}
}
int rand_partition(int p, int r) {

	int q = rand() % (r-p)+p;
	int tmp = man[q];
	man[q] = man[r];
	man[r] = tmp;
	int x = man[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (man[j] <= x) {
			i = i + 1;
			tmp = man[i];
			man[i] = man[j];
			man[j] = tmp;
		}

	}
	tmp = man[i + 1];
	man[i + 1] = man[r];
	man[r] = tmp;
	return i + 1;

}
void rand_quickSort(int p, int r) {
	if (p < r) {
		int q = rand_partition(p, r);

		rand_quickSort(p, q - 1);
		rand_quickSort(q + 1, r);
	}
}
int mid_partition(int p, int r) {

	int q = (p + r) / 2;
	int tmp = man[q];
	man[q] = man[r];
	man[r] = tmp;
	int x = man[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (man[j] <= x) {
			i = i + 1;
			tmp = man[i];
			man[i] = man[j];
			man[j] = tmp;
		}
		
	}
	tmp = man[i + 1];
	man[i + 1] = man[r];
	man[r] = tmp;
	return i + 1;

}

void mid_quickSort(int p, int r) {

	if (p < r) {
		int q = mid_partition(p, r);
		mid_quickSort(p, q - 1);
		mid_quickSort(q + 1, r);
	}
}
int partition(int p, int r) {
	int x = man[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (man[j] <= x) {
			i = i + 1;
			int tmp = man[i];
			man[i] = man[j];
			man[j] = tmp;
		}

	}
	int tmp = man[i + 1];
	man[i + 1] = man[r];
	man[r] = tmp;
	return i + 1;

}
void quickSort(int p, int r) {
	if (p < r) {
		int q = partition(p, r);
		quickSort(p, q - 1);
		quickSort(q + 1, r);
	}

}
void merge(int p, int q, int r) {
	int i = p, j = q + 1, k = p;

	while (i <= q && j <= r) {
		if (man[i] <= man[j])
			temp[k++] = man[i++];
		else
			temp[k++] = man[j++];
	}
	while (i <= q)
		temp[k++] = man[i++];
	while (j <= r)
		temp[k++] = man[j++];
	for (int i = p; i <= r; i++)
		man[i] = temp[i];
}
void mergeSort(int p, int r) {

	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(p, q);
		mergeSort(q + 1, r);
		merge(p, q, r);
	}
}
void insertion(int N) {
	int j;
	for (int i = 0; i < N - 1; i++) {
		int check = man[i + 1];
		for ( j = i; j > -1; j--) {
			if (man[j] > check) {
				man[j + 1] = man[j];
			}
			else
				break;
		}
		man[j + 1] = check;
	}


}
void selection(int N)
{


	for (int i = N - 1; i >= 2; i--) {
		int max = 0;
		int remember = 0;
		for (int j = 0; j < i; j++) {
			if (man[j] > max) {
				max = man[j];
				remember = j;
			}
		}

		int tmp = man[remember];
		man[remember] = man[i];
		man[i] = tmp;
		
	}
}
void bubble(int N) {

	for (int i = N - 1; i >= 2; i--) {
		for (int j = 1; j < N; j++) {
			if (man[j] > man[j + 1]) {
				int tmp = man[j];
				man[j] = man[j + 1];
				man[j + 1] = tmp;
			}
		}
	}
}
void rand_create(int N) {
	//랜덤
	
	for (int i = 0; i < N; i++) {
		man[i] = rand() % N;
	}
	


}
void reverse_create(int N) {
	//reverse

	for (int i = 0; i < N; i++) {
		man[i] = N-i;
	}



}
void main()
{
	clock_t start, end;
	srand((unsigned)time(NULL));
	start = clock();
	int num;
	printf("랜덤 1 리버스 2\n");
	int choice;
	scanf("%d", &choice);
	printf("num ?");
	scanf("%d", &num);
	switch (choice)
	{
	case 1:{
			rand_create(num);
			break;
		}
	case 2:{
			reverse_create(num);
			break;
		}
	}
	int choice2;
	printf("버블 1 선택 2 삽입 3 합병 4 빠른 5 빠른 6 빠른 7\n");
	scanf("%d", &choice2);
	switch (choice2) {
	case 1: {
		bubble(num);
		break;
	}
	case 2: {
		selection(num);
		break;
	}
	case 3: {
		insertion(num);
		break;
	}
	case 4: {
		mergeSort(0,num);
		break;
	}
	case 5: {
		quickSort(0, num);
		break;
	}
	case 6: {
		mid_quickSort(0, num);
		break;
	}
	case 7: {
		rand_quickSort(0, num);
		break;
	}

	}
	print(num);
	end = clock();


	getchar();
	getchar();
}