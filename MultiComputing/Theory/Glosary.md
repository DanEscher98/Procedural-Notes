# Glosary

- *Concurrency*: ability to execute two or more *tasks* which can
    start, run and complete in overlapping time periods. It can be
    truly parallel execution on multi-cores or time-sliced on a single
    core machine with the help of threads.
- *Parallelism*: is about executing *tasks* in parallel at the same
    time (at least two *threads* are executing simultaneously)
- *Threads*:
- *Subprocess*:
- *Coroutine*: these are computer program components that generalise
    subroutines for nonpreemptive multitasking, by allowing multiple
    entry points for suspending and resuming execution at certain
    locations. It helps to achive cooperative multitasking. It's a
    *generator* that:
    - coroutine _yields control_ to another coroutine and can resume
        execution from the point it gives up control
    - coroutines are data consumers while generators are data
        producers
    - can send values to generator based coroutines (using `send()`
        and `yield` statement)
- *Multi Processes*: Multi process are required to achive paralellism.

## Synchronous vs Asyncronous

- *Sync*: blocking execution of tasks. Execution of computation/task
    by a *thread*(cpu) is blocked/waiting for an operation (IO) to
    complete.
- *Async*: concurrent execution of tasks. Multiple tasks can start,
    pause and complete independent of each other which are executed by
    a single thread. Async tasks don't block operations that usually
    wait for IO. It is most helpful for IO bound.
    - Python: coroutines

## Libraries provided by languages

- Python:
    - multiprocessing
    - threading
    - concurrent
    - asyncio

## REFERENCES

- (Python generators coroutines async-io)[]
