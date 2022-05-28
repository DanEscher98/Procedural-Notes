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
1. Unlimited borrows for read-only borrows: `let x = &n`.
2. For a read only borrow, the original data is immutable for the
   duration of the borrow.
3. You can only have a single borrow at a time for mutable borrows:
   `let a = &mut x`.

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

The first thing one needs to realize about lifetimes is that they are
all about references, and nothing else. Let people take pointers to
random data on the stack, and the result is a pervasive unmanageable
`un-safety`. It allows to holding a pointer to something that:

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

fn print(s: &str);                                      // elided
fn print<'a>(s: &'a str);                               // expanded

fn debug(lvl: usize, s: &str);                          // elided
fn debug<'a>(lvl: usize, s: &'a str);                   // expanded

fn substr(s: &str, until: usize) -> &str;               // elided
fn substr<'a>(s: &'a str, until: usize) -> &'a str;     // expanded

fn get_mut(&mut self) -> &mut T;                        // elided
fn get_mut<'a>(&'a mut self) -> &'a mut T;              // expanded

fn args<T: ToCStr>(&mut self, args: &[T]) -> &mut Command                  // elided
fn args<'a, 'b, T: ToCStr>(&'a mut self, args: &'b [T]) -> &'a mut Command // expanded

fn new(buf: &mut [u8]) -> BufWriter;                    // elided
fn new(buf: &mut [u8]) -> BufWriter<'_>;                // elided (with `rust_2018_idioms`)
fn new<'a>(buf: &'a mut [u8]) -> BufWriter<'a>          // expanded

fn get_str() -> &str;                                   // ILLEGAL

fn frob(s: &str, t: &str) -> &str;                      // ILLEGAL
```

In practical terms, `fn foo<'a>(&'a A) -> &'a B` means that the input
must live at least as long as the output. If you keep the output
around for a long time, this will expand the region that the input
must be valid for.

## Coercion vs Subtying

The key difference is that subtyping does not change the underlying
value while coercion does.

```rust
// This is coercion:
let values: [u32; 5] = [1, 2, 3, 4, 5];
let slice: &[u32] = &values;

// This is subtyping:
let val1 = 42;
let val2 = 24;
'x: {
    let ref1 = &'x val1;
    'y: {
        let mut ref2 = &'y val2;
        ref2 = ref1;
    }
}
```
