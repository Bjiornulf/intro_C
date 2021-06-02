#include <stdio.h>
#define SIZE 50

void print_array(int[], int);

int main()
{
	int arr[SIZE];

	for (int i = 0; i < SIZE; i++) {
		arr[i] = i*2;
	}
	print_array(arr, SIZE);
}

void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++){
		printf("%i\n", arr[i]);
	}
}
