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

## Types of pointers

- Null Pointer: It's a pointer that points to nothing. They are useful
    at initialization.
- Void Pointer: It's a pointer that is not allied with any data types.
    Points to some data location within the storage. It's also known
    as a general purpose pointer. In C, `malloc` and `calloc`
    functions return `void*`.
- Wild Pointer: Pointers that are not initialized. It could be
    initialized to a non-NULL garbage value which may not be a valid
    address.
- Dangling Pointer: A pointer that points to a memory location that
    has been deleted.
- Complex Pointer
- Struct Pointer: This pointers can be utilized to refer to a struct
    by its address. This helps pass structs to a function.
- Near Pointer: It means a pointer that is utilized to bit address of
    up to 16 bits within a given section of that computer memory which
    is 16 bit enabled. It can only access data of the small size of
    about 64kb withing a given period, which is its main disadvantage.
- Far Pointer: Is typically 32 bit which can access memory outside
    that current segment. To utilize the far pointer, the compiler
    allows a segment register to save segment address, then another
    register to save offset inside current segment.
- Huger Pointer: A far pointer that is fixed and hence that part of
    that sector within which they are located cannot be changed in any
    way; huge pointers can be.


## Applications memory:

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

