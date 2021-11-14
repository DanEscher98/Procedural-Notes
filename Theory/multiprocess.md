---
author: Daniel Sánchez
title: Multi Process
---

## Features of Threading

## Benefits of threading:

- Ease of reading code. The code can run concurrently, but still be
    set out in a very simple, top-down linear sequence commands.
- Parallelism with shared memory. The code can exploit multiple CPUs
    while having threads share memory. This is important in many
    workloads where it would be too costly to move large amounts of
    data between the separate memory spaces of different processes.
- Know-how and existing code.

### Drawback of Threading

- Threading is difficult. Threading bugs and race conditions in
    threaded programs are the hardest kind of bugs to fix.
- Threads are resource-intensive. Threads require extra operating
    system resources to create, such as preallocated, per-thread stack
    space that consumes process virtual memory up front.
- Threading can affect throughput. At very high concurrency levels
    (i.e >5,000 threads), there can also be an impact on throughput
    due to *context-switching* costs, assuming you can figure out how
    to configure your operating system to even allow you to create
    that many threads.
- Threading is inflexible. The operating system share CPU time with
    all threads regardless of whether a thread is ready to do work or
    not.


## Features of `Asyncio`

For I/O-bound workloads, there are two reasons to use async-bases
concurrency over thread-based concurrency:

- Asyncio offers a safer alternative to preemptive
    multitasking (i.e., using threads) thereby avoiding the bugs, race
    conditions, and other nondeterministic dangers that frequently
    occur in nontrivial threaded applications.
- Asycio offers a simple way to support many thousands osf
    simultaneous socket connections, including being able to handle
    many long-lived connections for newer technologies like
    WebSockets, or MQTT for Internet of Things applications.

Threading, as a programming model, is best suited to certain kinds of
computational tasks that are best executed with multiple CPUs and
shared memory for efficient communication between the threads. The
true value of threading lies in being able to write multi-CPU
programs, in which different computational tasks can share memory.

### Things that Asyncio is not

- Asyncio doesn't make a code blazing fast
- Asyncio doesn't makes threading redundant
- Asyncio doesn't removes the problems with the Global Interpreter
    Lock (`GIL`).
- Asyncio doesn't prevents all race conditions
- Asyncio doesn't make concurrent programming easy. It only makes a
    little easyer to avoid certain race condition bugs
