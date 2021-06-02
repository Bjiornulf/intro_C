#include <stdio.h>
#define SIZE 10

void print_array(int[], int);
int sum_array(int[], int, int[], int, int result[], int size_result);

int main()
{
	int arr1[SIZE];
	int arr2[SIZE];
	int result[SIZE];
	for (int i = 0; i < SIZE; i++){
		arr1[i] = arr2[i] = i;
	}
	sum_array(arr1, SIZE, arr2, SIZE, result, SIZE);
	print_array(result, SIZE);
}

int sum_array(int arr1[], int size1, int arr2[], int size2, int result[], int size_result)
{
	// returns the size of the result (might not be equal to the provided size)
	int limit = size1 < size2 ? size1 : size2;
	limit = limit < size_result ? limit : size_result;

	for (int i = 0; i < limit; i++){
		result[i] = arr1[i] + arr2[i];
	}	
	return limit;
}
void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++){
		printf("%i\n", arr[i]);
	}
}
