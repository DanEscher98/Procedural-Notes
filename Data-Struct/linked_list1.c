#include <stdio.h>
#include <stdlib.h>
#include "matrix_algebra.h"

int main(void) {
	matrix A = get_matrix();
	put_matrix(A);
	put_matrix(init_matrix(3, 4, 0));
	/*
	matrix B, C;
	B = get_matrix();
	C = dot_product(A, transpose(B));
	put_matrix(C);
	put_matrix(matrix_sum(C, init_matrix(C.row, C.col, 2))); 
	free(A.values);
	free(B.values);
	free(C.values);
	*/
	return 0;
}
