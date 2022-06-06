typedef enum NumType {
	INTEGER,
	FLOAT,
	COMPLEX
} num_type;

typedef union Rational {
	float F;
	int I;
} rational;

typedef union Complex {
	rational Re;
	rational Img;
} complex;

typedef union Number {
	num_type type;
	rational R;
	complex  C;
} number;
