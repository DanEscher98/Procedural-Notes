#include <stdio.h>
#include <stdlib.h>
#include "matrix_algebra.h"
#include "safe_io.h"

float get_valM(matrix a, int i, int j) {
	if (a.row > i && a.col > j) {
		return a.values[a.row*i + j];
	} else {
		fputs("Out of range.\n", stdout);
		return 0;
	}
}

void set_valM(matrix a, int i, int j, float value) {
	if (a.row > i && a.col > j) {
		a.values[a.row*i + j] = value;
	} else  {
		fputs("Out of range.\n", stdout);
	}
}

matrix get_matrix() {
	matrix mtx;
	char msg[50];
	mtx.row = readInt("Number of rows: ");
	mtx.col = readInt("Number of columns: ");
	mtx.values = malloc(mtx.row * mtx.col * sizeof(float));
	for (int i=0; i < mtx.row; i++) {
		for (int j=0; j < mtx.col; j++) {
			sprintf(msg, "Valor [%d][%d]: ", i, j);
			set_valM(mtx, i, j, readFloat(msg));
		}
	}
	return mtx;
}

void put_matrix(matrix A) {
	char msg[50];
	sprintf(msg, "matrix (%d, %d)\n", A.row, A.col);
	fputs(msg, stdout);
	for (int i=0; i < A.row; i++) {
		for (int j=0; j < A.col; j++) {
			printf("%.2f\t", get_valM(A, i, j));
		}
		printf("\n");
	}
}

matrix init_matrix(int rows, int columns, float value) {
	matrix ans;
	ans.row = rows;
	ans.col = columns;
	ans.values = malloc(ans.row * ans.col * sizeof(float));
	for (int i=0; i < ans.row * ans.col; i++) {
		ans.values[i] = value;
	}
	return ans;
}

matrix matrix_id(int size) {
	matrix id = init_matrix(size, size, 0);
	for (int i=0; i < id.row; i++) {
		for (int j=0; j < id.col; j++) {
			id.values[id.row*i + j] = 1;	
		}
	}
	return id;
}

matrix transpose(matrix A) {
	matrix ans = init_matrix(A.col, A.row, 0);
	put_matrix(ans);
	for (int i=0; i < ans.row; i++) {
		for (int j=0; j < ans.col; j++) {
			ans.values[ans.row*i + j] = get_valM(A, j, i);
		}
	}
	return ans;
}

matrix matrix_sum(matrix A, matrix B) {
	matrix ans = init_matrix(A.row, B.col, 0);
	if (A.row == B.row && A.col == B.col) {
		for (int i=0; i < ans.row*ans.col; i++) {
			ans.values[i] = A.values[i] + B.values[i];
		}
	}
	return ans;
}

matrix dot_product(matrix A, matrix B) {
	matrix ans = init_matrix(A.row, B.col, 0);
	if (A.col == B.row) {
		int n = A.col;
		float sum;
		for (int i=0; i < ans.row; i++) {
			for (int j=0; j < ans.col; j++) {
				sum = 0;
				for (int k=0; k < n; k++) {
					sum += get_valM(A, i, n) * get_valM(B, n, j);
				}
				ans.values[ans.row*i + j] = sum;
			}
		}
	} else {
		fputs("Incompatible dot product.\n", stdout);
	}
	return ans;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chario.h"


int main(void){
  int user=1;
  while(user==1){
    HI();

    //code
    printf("\nRepeat program?1/0: ");
    scanf("%d", &user);
  }
  printf("Goodbye.");
  return 0;
}

int detM(int*M){
  int n=sizeof(M)/sizeof(M[0]);
  int k, i, j, ef, ec, user, div=1;
  int*piv, *elm;
  for(k=0; k<n; k++){ //Iteracion de diagonal
    piv = M+k*n+k; if(div==0) break;
    for(i=0; i<n-k-1; i++){
      for(j=0; j<n-k-1; j++){
        elm = (piv+n+1)+(i*n+j);
        ef= piv[div+j+1]; 
        ec= piv[n*(i+1)];
        putM(M,n,n);
        printf("\n(%d*%d - %d*%d)/%d =", *piv, *elm,ef,ec,div);
        *elm = ((*piv)*(*elm) - (ef)*(ec))/div;
        printf(" %d  ", *elm); scanf("%d",&user);
      }
    }
    div = *piv;
    for(i=0;i<n-k;i++){
      piv[i]=0;
      piv[i*n]=0;
    }
    scanf("%d",&user);
  }
  return *(M+n*n-1);
}
