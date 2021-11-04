#include "type_numbers.h"

typedef struct Vector {
	int size;
	float *values;
} vector;

vector initVector(int);

typedef struct Matrix {
	int rows;
	int cols;
	num_type type;
	number *values;
} matrix;

matrix initMatrix(int, int, num_type);

matrix dotMatrix(matrix, matrix);

matrix sumMatrix(matrix, matrix);

matrix inv(matrix);

matrix trans(matrix);

float det(matrix);

matrix vectorToMatrix(vector);

typedef enum Color {
	RED,
	GREEN,
	BLUE
} color;
