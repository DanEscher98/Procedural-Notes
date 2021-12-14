#include "../src/lib.h"
#include "test_list.h"
#include <clove.h>

CLOVE_TEST(FirstTest)
{
	int a = shift(1);
	CLOVE_INT_EQ(a, 2);
}

CLOVE_RUNNER(FirstTest, InitList)
