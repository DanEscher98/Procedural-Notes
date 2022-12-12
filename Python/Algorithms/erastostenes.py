import operator
from functools import reduce
from typing import List, Iterable

def filter_naturals(i, naturals: Iterable[int]) -> Iterable[int]:
    return reduce(operator.or_ , map(lambda p: i%p, naturals), True)


def funk(primes, naturals):
    for i in naturals:
        if not :
            yield
