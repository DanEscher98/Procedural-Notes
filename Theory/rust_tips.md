---
author: Daniel Sánchez
title: Rust Tips
---

1. Examples have first-class support in Cargo. Place them in a
   directory `examples` next to `src`. They can then be run with
   `cargo run --example foo`. They will need to import the crate in
   order to use it.
2. Prefer to use `module::function` instead of importing a free
   function directly. This helps the developer track where they come
   from. The only exception I make is for `min` and `max`.
3. When `where` clauses are used, they go on a separate line from the
   argument and return types, and the opening curly brace does as
   well. When there are multiple clauses, each goes on a separate
   line.
4. Use trailing commas on arrays and structures. This reduces the
   lines of `diff` when a new `struct` member is added.
5. Evaluate comments for what consumers of a function need to know
   versus what the implementor need to know. Use `Rustdoc` comments
   (`///`) when talking to the consumer. It's reasonable to add
   `Rustdoc` for non-public methods, so the consumer may be another
   developer of the library.
6. Remove useless documentation like "... like `foo` but mutable".
   Don't repeat information that is described in the function name or
   type. Document information that cannot be captured that way.
7. Note that `Rustdoc` uses `Markdown`; use `Markdwon` syntax to refer
   to variables as `code`, for example.
8. Instead of adding comments for each of the "other" cases, write
   them out. Generally, annotating something in code is less brittle
   that writing it in comments, as the complier checks the former and
   not the latter.
9. Instead of a debug assertion, add the explicit patterns it cannot
   be and use something like `unimplemented!`.
10. Prefer regular assertions instead of debug assertions in general;
    there's no worse time for invalid data to occur than **in
    production**. Only switch to debug assertions if profiling shows
    that the assertion is adding significant overhead.
11. Instead of dereferencing a value at every use in a loop,
    pattern-match to `&foo`, if the type is `Copy`.
12. All code should have some tests, doubly so for data structures
    that are intended to be used pervasively. The examples also
    require a human to look at the output and decide if they are
    correct.
13. Check out the `|` and `@` aspects of pattern matching. These are
    helpful to coalesce duplicate cases (like left/right symmetry) and
    to avoid unwrapping and re-wrapping types like `Option`.
14. `Unbox` usually means to remove a value from a box and free the
    box (`Box<T> -> T`).
15. Look into `QuickCheck`. Data structures have certain invariants
    that should be upheld at all times, and generative testing helps
    tease those out.
14. I'd go ahead and make a `Node::new` to avoid needing to set left
    and right to `None` at the call site.
15. I might prefer `while let Some(node) = self.current.as_ref()`
    versus `while let Some(ref node) = *self.current`.
