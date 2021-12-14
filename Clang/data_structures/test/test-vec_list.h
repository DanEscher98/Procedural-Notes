#include "../src/vec_list.h"
#include <clove.h>

CLOVE_TEST(InitVector)
{
	int n = 10;
	vector xs = initVector(10, true, true);
	CLOVE_INT_EQ(xs.values[n - 1], 0);
	free(xs.values);
}

CLOVE_TEST(InitList)
{
	list xs = initList();
	CLOVE_INT_EQ(xs.length, 0);
	CLOVE_NULL(xs.head);
}
