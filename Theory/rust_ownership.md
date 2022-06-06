---
author: Daniel Sánchez Domínguez
title: Rust Ownership
---

## Operators

```rust
::          // name-space operator
self        // Value (owner change)
&mut self   // Mutable reference (borrow)                               
&self       // Shared reference (only read)
```

## Ownership rules

1. Each value in `Rust` has a variable that's called its owner.
2. There can only be one owner at a time.
3. When the owner goes out of scope, the value will be dropped.

## The Rules of References

1. At any given time, you can have either one mutable reference or any
   number of immutable references.
2. References must always be valid.

## Lifetime rules

1. Each parameter that is a reference gets its own lifetime parameter.
2. If there is exactly one input lifetime parameter, that lifetime is
   assigned to all output lifetime parameters.
3. If there are multiple input lifetime parameters, but one of them is
    `&self` or `&mut self` the lifetime of self is assigned to all
    output lifetime parameters.

```rust
let x: i32 = 10;
let y: i32 = x; // Copy

let s1: String = String::from("hello");
let s2: String = s1; // Move (not shallow copy)
//               s1.copy() // Fix the error, allocates in heap

println!("{}, world!", s1); // Error
```

## Lifetime

Let people take pointers to random data on the stack, and the result
is a pervasive unmanageable un-safety. It allows to holding a pointer
to something that:

- went out of scope
- got mutated away

A lifetime is the name of a region (~block/scope) of code somewhere in 
a program.

```rust
// Only one reference in input, so the output must be derived
// from that input
fn foo(&A) -> &B; // sugar for:
fn foo<'a>(&'a A) -> &'a B;

// Many inputs, assume they're all independent
fn foo(&A, &B, &C); // sugar for:
fn foo<'a, 'b, 'c>(&'a A, &'b B, &'c C);

// Methods, assume all output lifetimes are derived from `self`
fn foo(&self, &B, &C) -> &D; // sugar for:
fn foo<'a, 'b, 'c>(&'a self, &'b B, &'c C) -> &'a D;
```

In practical terms, `fn foo<'a>(&'a A) -> &'a B` means that the input
must live at least as long as the output. If you keep the output
around for a long time, this will expand the region that the input
must be valid for.
