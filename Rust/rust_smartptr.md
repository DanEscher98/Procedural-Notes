# Rust Smart Pointers

- `Box<T>` - a unique pointer to an object on the heap. Analogous to
  C++'s std::unique_ptr.
- `Cow<'a, B>` - a clone-on-write smart pointer. Useful for when you
  have a value that could be borrowed or owned.
- `Rc<T>` - a shared pointer that provides shared ownership of a value
  on a single thread. This smart pointer cannot be sent between threads
  safely since it does not use atomic operations to maintain its
  refcount (the compiler will make sure you don't accidentally do
  this).
- `Arc<T>` - very similar to Rc except it uses atomic operations to
  update its refcount, and thus is thread-safe. Similar to
  std::shared_ptr.

- `Pin`
- `MutexGuard`

- Cell - A mutable memory location.
- Ref - Wraps a borrowed reference to a value in a RefCell box. A
  wrapper type for an immutably borrowed value from a RefCell<T>.
- RefCell - A mutable memory location with dynamically checked borrow
  rules
- RefMut - A wrapper type for a mutably borrowed value from a
  RefCell<T>.
- UnsafeCell - The core primitive for interior mutability in Rust.


- `Vec<T>/String/PathBuf/OsString` et al. - all of these are smart
  pointers for owning dynamically allocated arrays of items on the
  heap. Read their documentation for more specific details.


