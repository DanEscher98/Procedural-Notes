typedef struct matrix matrix;
struct matrix {
	int row;
	int col;
	float *values;
};

float	get_valM(matrix, int, int);
void	set_valM(matrix, int, int, float);
matrix	get_matrix();
void	put_matrix(matrix);

matrix init_matrix(int, int, float);
matrix matrix_id(int);

matrix transpose(matrix);
matrix matrix_sum(matrix, matrix);
matrix dot_product(matrix, matrix);
