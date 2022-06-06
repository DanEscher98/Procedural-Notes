---
author: Daniel Sánchez Domínguez
title: Thoughts about Data Structures
---

## Lists vs Arrays

### Good use cases of lists

- It's needed to do a lot of splitting or merging of big lists
- In lock-free concurrent things
- Writing a kernel/embedded thing and one wants to use an intrusive
    list
- Using a pure functional language

### Counter arguments

- "The lists have $O(1)$ split-append-insert-remove if you have a
    pointer there". But this doesn't matter if the time it takes to
    get that pointer equals to $O(n)$.
- "Linked lists waste less space than vectors". Linked lists
    unconditionally waste space per element (one pointer for
    singly-linked lists and two for doubly-linked lists).
- "Linked lists are great for building concurrent data structures".
