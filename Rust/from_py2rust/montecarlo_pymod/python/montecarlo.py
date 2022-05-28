#!/usr/bin/python3


import math
import multiprocessing
import random
import time
from concurrent.futures import ThreadPoolExecutor
from typing import Tuple

import psutil


def monte_carlo(iterations: int) -> Tuple[float, str]:
    num_cpus = psutil.cpu_count(logical=True)

    now = time.time()
    total_inside = thread_montecarlo(num_cpus, iterations)
    stop = time.time()

    total_iterations = iterations * num_cpus
    elapsed = stop - now
    calculations_str = round(total_iterations / elapsed)

    aprox_pi = total_inside / total_iterations * 4
    return (aprox_pi, f"{calculations_str:,}")


def monte_compute(iterations: int) -> float:
    inside = 0
    random.seed()
    for _ in range(iterations):
        a = random.random()
        b = random.random()
        c = math.pow(a, 2.0) + math.pow(b, 2.0)
        if c <= 1.0:
            inside += 1
    return inside


def proc_montecarlo(num_cpu: int, iterations: int) -> float:
    with multiprocessing.Pool(num_cpu) as procs:
        results = procs.map(monte_compute, [iterations] * num_cpu)
        total_inside = sum(results)
    return total_inside


def thread_montecarlo(num_cpu: int, iterations: int) -> float:
    with ThreadPoolExecutor() as executor:
        futures = [executor.submit(monte_compute, iterations) for _ in range(num_cpu)]
        total_inside = sum(f.result() for f in futures)
    return total_inside


if __name__ == "__main__":
    start = time.time()
    aprox_pi, calcs_per_sec = monte_carlo(1_000_000)
    stop = time.time()

    print(f"{stop - start:.2f}s runtime")
    print(f"{aprox_pi=}")
    print(f"{calcs_per_sec} calculations per second")
