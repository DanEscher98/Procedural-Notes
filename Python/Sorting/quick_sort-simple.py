#!/usr/bin/python3


# The main function that implements QuickSort
# arr[] -> Array to be sorted,
# low -> Starting index,
# high -> Ending index


def quick_sort(arr):
    def partition(arr, low, high):
        i = low - 1
        pivot = arr[high]

        for j in range(low, high):
            if arr[j] <= pivot:
                i = i + 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    def aux_loop(arr, low, high):
        if len(arr) == 1:
            return arr
        if low < high:
            pivot = partition(arr, low, high)
            aux_loop(arr, low, pivot - 1)
            aux_loop(arr, pivot + 1, high)

    aux_loop(arr, 0, len(arr) - 1)


arr = [10, 7, 8, 9, 0, 1]
quick_sort(arr)
print(arr)
