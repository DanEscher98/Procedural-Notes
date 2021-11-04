---
author: Daniel Sanchez
title: Pointers in C
---

lldb, gdb
`int* ptr, var;`
`var = 2;`
`ptr = &var;`

  var       ptr

> ┌---┐--&->┌---┐
> | 2 |     |0x1|
> └---┘<-*--└---┘

```sh
    var == \*ptr
   &var ==  ptr:up
```

```c
*(*(ch_arr + i) + j);
ch_arr[i][j];
```

```cpp
// Equivalent accessing
*(ptr + n) = val;
ptr[n] = val;

// Equivalent for structs
(*node).next;
node->next;

// Declare a reference
int& num;
```

# Applications memory:

Each byte in the memory is addressable

- Global/static:
    - Static memory persists throughout the entire life of the program
    - Is usually used to store things like global variables
    - Or variables created with the static clause
- Stack:
    - the stack is managed by the CPU
    - It's a LIFO structure. Every time a function declares a new
        variable, it's "pushed" onto the stack
    - variables are allocated and freed automatically
    - the stack it not limitless – most have an upper bound
    - the stack grows and shrinks as variables are created and
        destroyed
    - stack variables only exist whilst the function that created
        them exists
- Heap:
    - the heap is managed by the programmer, and is the portion of 
        memory where dynamically allocated memory resides
    - in C, variables are allocated and freed using functions like
        `malloc()` and `free()`
    - the heap is large, and is usually limited by the physical memory
        available
    - the heap requires pointers to access it
    - If all references to allocated memory are lost (e.g. you don't
        store a pointer to it anymore), you have what is called a
        memory leak.
    - Unlike the stack where memory is allocated and released in a 
        very defined order, individual data elements allocated on the 
        heap are typically released in ways which is asynchronous
        from one another.
 
