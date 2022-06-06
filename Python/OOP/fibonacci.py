def fib_rec(n: int) -> int:
    return 1 if n < 2 else n * fib_rec(n - 1)


def fib_iter(n: int) -> int:
    acc = 1
    for i in range(1, n + 1):
        acc *= i
    return acc


if __name__ == "__main__":
    print(fib_rec(5))
    print(fib_iter(5))
