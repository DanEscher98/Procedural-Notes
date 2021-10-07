---
author: Daniel Sanchez
title: Pointers in C
---

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
