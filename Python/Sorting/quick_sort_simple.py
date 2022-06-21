#!/usr/bin/python3
""" Some sorting functions """
from typing import List, Tuple

# The main function that implements QuickSort
# arr[] -> Array to be sorted,
# low -> Starting index,
# high -> Ending index


def quick_sort(arr: List | Tuple) -> List:
    """Implementation of quicksort"""

    def partition(arr, low, high):
        i = low - 1
        pivot = arr[high]

        for j in range(low, high):
            if arr[j] <= pivot:
                i = i + 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    def aux_loop(arr, low, high) -> List:
        if len(arr) == 1:
            return arr
        if low < high:
            pivot = partition(arr, low, high)
            arr = aux_loop(arr, low, pivot - 1)
            arr = aux_loop(arr, pivot + 1, high)
        return arr

    return aux_loop(arr, 0, len(arr) - 1)


data = (10, 7, 8, 9, 0, 1)
data = quick_sort(data)
print(data)
