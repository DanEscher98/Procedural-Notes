# Rust Std


## Core Primitive types
- **never**: The `!` type, also called “never”.
- **core::array**: A fixed-size array, denoted `[T; N]`, for the element type,
  T, and the non-negative compile-time constant size, N.
- **bool**: The boolean type.
- **core::char**: A character type.
- **core::f{32, 64}**: A floating point type (specifically IEEE 754-2008).
- **fn**: Function pointers, like `fn(usize) -> bool`.
- **core::i{8, 16, 32, 64, 128, size}**: The signed integer type.
- **pointer**: Raw, unsafe pointers, *const T, and *mut T.
- **reference**: References, &T and &mut T.
- **core::slice**: A dynamically-sized view into a contiguous sequence, `[T]`.
  Contiguous here means that elements are laid out so that every element
  is the same distance from its neighbors.
- **core::str**: String slices.
- **tuple**: A finite heterogeneous sequence, `(T, U, ..)`.
- **core::u{8, 16, 32, 64, 128}**: The unsigned integer type
- **unit**: The `()` type, also called “unit”.
- **core::usize**: The pointer-sized unsigned integer type.

## Common types and Collections
- **array**: Utilities for the array primitive type.
- **core::ascii**: Operations on `ASCII` strings and characters.
- **char**: Utilities for the char primitive type.
- **collections**: Collection types.
- **fmt**: Utilities for formatting and printing `Strings`.
- **core::hash**: Generic hashing support.
- **core::iter**: Composable external iteration.
- **core::num**: Additional functionality for numerics.
- **core::ops**: Overloadable operators.
- **core::option**: Optional values.
- **primitive**: This module reexports the primitive types to allow usage that
    is not possibly shadowed by other declared types.
- **core::result**: Error handling with the Result type.
- **slice**: Utilities for the slice primitive type.
- **str**: Utilities for the str primitive type.
- **string**: A `UTF-8`–encoded, growable string.
- **vec**: A contiguous growable array type with heap-allocated contents,
    written `Vec<T>`.

## Smart Pointers, Containers and Memory
- **core::alloc**: Memory allocation APIs.
- **core::any**: Utilities for dynamic typing or type reflection.
- **core::borrow**: A module for working with borrowed data.
- **boxed**: The `Box<T>` type for heap allocation.
- **core::clone**: The `Clone` trait for types that cannot be ‘implicitly copied’.
- **core::cell**: Shareable mutable containers.
- **core::mem**: Basic functions for dealing with memory.
- **core::pin**: Types that pin data to its location in memory.
- **core::ptr**: Manually manage memory through raw pointers.
- **rc**: Single-threaded reference-counting pointers. `Rc` stands for
    ‘Reference Counted’.

## Synchronous, Asynchronous and Concurrency
- **core::future**: Asynchronous basic functionality.
- **process**: A module for working with processes.
- **core::sync**: Useful synchronization primitives.
- **core::task**: Types and Traits for working with asynchronous tasks.
- **thread**: Native threads.

## Types and Traits
- **core::cmp**: Utilities for comparing and ordering values.
- **core::convert**: Traits for conversions between types.
- **core::default**: The `Default` trait for types with a default value.
- **core::marker**: Primitive traits and types representing basic properties of
    types.

## `IO`, `OS` and Network features
- **core::arch**: `SIMD` and vendor intrinsics module.
- **backtrace**: Support for capturing a stack backtrace of an OS thread
- **env**: Inspection and manipulation of the process’s environment.
- **error**: Interfaces for working with `Errors`.
- **core::ffi**: Utilities related to `FFI` bindings.
- **fs**: Filesystem manipulation operations.
- **core::hint**: Hints to compiler that affects how code should be emitted or
    optimized. Hints may be compile time or runtime.
- **io**: Traits, helpers, and type definitions for core `I/O` functionality.
- **net**: Networking primitives for `TCP/UDP` communication.
- **os**: OS-specific functionality.
- **core::panic**: Panic support in the standard library.
- **path**: Cross-platform path manipulation.
- **core::time**: Temporal quantification.
