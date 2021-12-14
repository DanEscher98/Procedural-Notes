#include "../src/vec_list.h"
#include <clove.h>

CLOVE_TEST(InitList)
{
	list xs = initList();
	CLOVE_INT_EQ(xs.length, 0);
	CLOVE_NULL(xs.head);
}
