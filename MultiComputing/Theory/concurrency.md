# Concurrency

## Definitions

- **Concurrency**: Programming as the composition of independently
    executing processes. It's about structure.
- **Programming**: Programming as the simultaneous execution of
    (possibly related) computations. It's about execution.
- Concurrency provides a way to structure a solution to solve a
    problem that may (but not necessarily) be parallelized.
- *Communicating Sequential Processes* (CSP): The model in which `Go`
    and `Erlang` are based on. 
    [CSP. Hoare](https://www.cs.cmu.edu/~crary/819-f09/Hoare78.pdf)

## Step to do a program concurrent

0. Task: _process_ _data_ and send it to a _consumer_
1. Add more processes
2. Synchronize the processes (communication)
3. Split the data and consummer, so the processes are independent from
   each other.
4. Add a staging pile in the middle, so we are able to compose two
   processes.

## Concurrency is ...
- powerful
- not parallelism
- enables parallelism
- makes parallelism and scaling easy


## Support in different languages

### Golang
- concurrent execution (gorutine: a function running independently in
    the same address space as other goroutines, they aren't threads)
- synchronization and messaging (channels: typed values that allow
    goroutines to synchronize and exchange information)
- multi-way concurrent control (select: is like `switch` but the
    decision is bases on ability to communicate rather than equal
    values)

