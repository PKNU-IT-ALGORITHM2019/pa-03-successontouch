#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma warning(disable:4996)

#define MAX 100000
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
	int tmp;
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
	//·£´ý
	
	for (int i = 0; i < N; i++) {
		man[i] = rand() % N+1;
	}
	


}
void reverse_create(int N) {
	//reverse

	for (int i = 0; i < N; i++) {
		man[i] = N-i;
	}
}
int fun(int choice, int choice2, int num)
{
	double time = 0;
	for (int i = 0; i < 10; i++) {
		switch (choice)
		{
			case 1: {
				rand_create(num);
				break;
			}
			case 2: {
				reverse_create(num);
				break;
			}
				
		}
		start = clock();
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
				mergeSort(0, num-1);
				break;
			}
			case 5: {
				quickSort(0, num-1);
				break;
			}
			case 6: {
				mid_quickSort(0, num-1);
				break;
			}
			case 7: {
				rand_quickSort(0, num-1);
				break;
			}
		}
		end = clock();
		time += end - start;
	}
	return time / 10.0;
}
void main()
{
	clock_t start, end;
	srand((unsigned)time(NULL));
	
	int num;
	
			
			printf("Random1000\tReverse1000\tRandom10000\tReverse10000\tRandom100000\tReverse100000\n");


			for (int i = 0; i <= 7; i++) {
				
				
				int time = fun(1, i, 1000);
				printf("%.3lfÃÊ\t", time / 100.0);

				time = fun(2, i, 1000);
				printf("\t%.3lfÃÊ\t", time / 100.0);

				
				time = fun(1, i, 10000);
				printf("\t%.3lfÃÊ\t", time / 100.0);

				time = fun(2, i, 10000);

				printf("\t%.3lfÃÊ\t", time / 100.0);

				time = fun(1, i, 100000);

				printf("\t%.3lfÃÊ\t", time / 100.0);

				time = fun(2, i, 100000);

				printf("\t%.3lfÃÊ\t", time / 100.0);

				printf("\n");
			}
			
		
	getchar();
	getchar();
}
