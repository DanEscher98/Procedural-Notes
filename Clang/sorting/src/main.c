#include "lib.h"
#include "vec_list.h"
#include <stdio.h>
#include <stdlib.h>

vector merge(vector, int, int, int);
vector merge_loop(vector, int, int);
vector merge_sort(vector);

int main(int argc, char** argv) {
	printf("Hello %s!\n", argv[1]);
	vector a = initVector(10, false, false);
	printVector(a);
	printVector(merge_sort(a));
	return EXIT_SUCCESS;
}

vector merge(vector arr, int left, int m, int right) {
	int n1 = m - left + 1;
	int n2 = right - m;
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++) L[i] = arr.values[left + i];
	for (int i = 0; i < n2; i++) R[i] = arr.values[m + 1 + i];
	
	int i, j, k;
	for (i=0, j=0, k=left; i < n1 && j < n2; k++) {
		if (L[i] <= R[j]) {
			arr.values[k] = L[i];
			i++;
		} else {
			arr.values[k] = R[j];
			j++;
		}
	}

	for (; i < n1; i++, k++) arr.values[k] = L[i];
	for (; j < n2; j++, k++) arr.values[k] = R[i];
	return arr;
}

vector merge_loop(vector arr, int left, int right) {
	if (left < right) {
		int m = left + (right - left)/2;
		arr = merge_loop(arr, left, m);
		arr = merge_loop(arr, m+1, right);
		arr = merge(arr, left, m, right);
	}
	return arr;
}

vector merge_sort(vector arr) {
	return merge_loop(arr, 0, arr.length - 1);
}
