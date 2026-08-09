# Mojo Fundamentals: A Comprehensive Mastery Guide (Mojo 1.0 Beta / v1.0.0b3+)

This guide covers the latest **Mojo 1.0 Beta** syntax (v1.0.0b1 through v1.0.0b3+), which unifies Python-like ergonomics with systems-level performance. Every concept is explained with theory, working code, expected output, and practice problems.

---

## Chapter 1: Introduction to Mojo

### 1.1 What is Mojo?

Mojo is a unified programming language that combines Python's usability with the performance of C, C++, and Rust. The 1.0 Beta completes the "def/fn unification" and introduces safe closures, conditional trait conformances, non-null pointers, and bounds-checked collections by default.

### 1.2 Hello World (Modern Mojo)

In Mojo 1.0, **all functions use `def`**. The `fn` keyword is deprecated and emits a compiler warning.

```mojo
# hello.mojo
def main():
    print("Hello, Mojo 1.0 Beta!")
```

> **Expected Output:**
> ```
> Hello, Mojo 1.0 Beta!
> ```

---

## 🔨 Practice Problem 1.1
Create a script called `greet.mojo` that prints "Welcome to Mojo 1.0 Beta!" and then prints "One keyword to rule them all: def." on a new line.

---

## Chapter 2: Variables and Scoping

### 2.1 Implicit Declaration (Modern Mojo)

The `let` and `var` keywords are **no longer required** for standard local variables. Variables are declared implicitly upon assignment, similar to Python, but remain statically typed.

```mojo
def main():
    x = 10          # Implicitly declared as Int
    name = "Mojo"   # Implicitly declared as String
    
    x = 15          # Variables are mutable by default
    
    print("x:", x)
    print("name:", name)
```

> **Expected Output:**
> ```
> x: 15
> name: Mojo
> ```

### 2.2 Explicit Typing (Optional but Recommended)

You can provide type hints for clarity, when a variable isn't immediately assigned, or to constrain the inferred type.

```mojo
def main():
    x: Int = 42
    y: Float64 = 3.14
    name: String = "Mojo"
    flag = True  # Implicitly Bool
    print(x, y, name, flag)
```

> **Expected Output:**
> ```
> 42 3.14 Mojo True
> ```

### 2.3 Type Inference from Literal Initializers (v1.0.0b3+)

Mojo now infers element types from list literals when using wildcard or bare container types:

```mojo
def main():
    var x: List[_] = [1, 2, 3]        # Infers List[Int]
    var y: List = [1.0, 2.0, 3.0]     # Infers List[Float64]
    var z: Array[_] = [1, 2, 3]       # Infers Array[Int, 3] (Array is now default for list expressions)
    print(type(x), type(y), type(z))
```

---

## 🔨 Practice Problem 2.1
Declare variables for your `favorite_number`, `city`, and `pi_approx` (3.14159). Print them all in a single statement with labels.

---

## Chapter 3: Functions and Argument Conventions

### 3.1 The Unified `def` (Critical Change)

**`fn` is deprecated** in Mojo 1.0 Beta. Use `def` everywhere. The `def` keyword now has the same non-raising, high-performance semantics that `fn` previously had.

```mojo
# Old (deprecated - emits warning)
fn add(a: Int, b: Int) -> Int:
    return a + b

# New (Mojo 1.0 Beta)
def add(a: Int, b: Int) -> Int:
    return a + b
```

### 3.2 Argument Conventions: `imm`, `mut`, `owned`

Mojo uses explicit conventions for how arguments are passed. **`imm` is now the preferred spelling** over `read` (which still works but will be deprecated).

| Convention | Keyword | Behavior |
|------------|---------|----------|
| **Immutable reference** (default) | `imm` / `read` | Read-only reference; cannot modify the original |
| **Mutable reference** | `mut` | Can modify the original variable |
| **Owned / Transfer** | `owned` | Takes full ownership; use `^` (transfer) operator when calling |

```mojo
def increment(mut value: Int):
    value += 1

def take_ownership(owned s: String):
    print("Took ownership of:", s)

def main():
    count = 10
    increment(count)          # mut: modifies original
    print("After increment:", count)
    
    msg = "hello"
    take_ownership(msg^)      # ^ transfers ownership
    # msg is no longer valid here
```

> **Expected Output:**
> ```
> After increment: 11
> Took ownership of: hello
> ```

### 3.3 Function Effects

Functions can declare effects that change their calling convention:

```mojo
# Can raise errors - must be handled with try/except
def validate(x: Int) raises:
    if x < 0:
        raise Error("Negative value!")

# C calling convention - for FFI interop
def c_add(a: Int32, b: Int32) abi("C") -> Int32:
    return a + b

# Thin function pointer - no captured state
def add_one(n: Int) {} -> Int:
    return n + 1

def main():
    var fn_ptr: def(Int) thin -> Int = add_one
    print(fn_ptr(99))
```

### 3.4 Lambda Expressions (v1.0.0b3+)

Anonymous, single-expression closures that desugar to a nested `def`:

```mojo
def main():
    # Basic lambda
    add = lambda (x: Int, y: Int) -> Int: x + y
    print(add(3, 4))
    
    # With capture list (thin when no captures)
    var base = 10
    add_base = lambda (x: Int) {imm base} -> Int: x + base
    print(add_base(5))
    
    # Stateless lambda is thin - can bind to comptime
    comptime double = lambda (x: Int) -> Int: x * 2
    print(double(21))
```

> **Expected Output:**
> ```
> 7
> 15
> 42
> ```

### 3.5 Variadic Functions and Forwarding

Variadic parameters use `*Ts: Trait` syntax and can be forwarded with `*pack`:

```mojo
def callee[*Ts: Writable](*args: *Ts):
    comptime for i in range(args.__len__()):
        print(args[i])

def forwarder[*Ts: Writable](*args: *Ts):
    callee(*args)  # Forward the pack

def main():
    forwarder(1, "hello", 3.14)
```

> **Expected Output:**
> ```
> 1
> hello
> 3.14
> ```

Keyword variadics use `**kwargs` (must write `var **kwargs`):

```mojo
def takes_them(var **kwargs: Int): ...

def pass_them(var **kwargs: Int):
    takes_them(**kwargs^)
```

---

## 🔨 Practice Problem 3.1
Write a function `multiply_by_two(mut x: Int)` that doubles the value of its argument. Test it by passing a variable and printing the result.

---

## 🔨 Practice Problem 3.2
Create a `raises` function `divide(a: Int, b: Int) -> Int` that raises an error if `b == 0`. Handle it in `main` with `try/except`.

---

## Chapter 4: Control Flow

### 4.1 Loops and Conditionals

`def` functions are **non-raising by default**. Control flow works as expected:

```mojo
def main():
    temperature = 28
    if temperature > 30:
        print("Hot")
    else:
        print("Pleasant")
    
    for i in range(3):
        print("Iteration:", i)
    
    # while loops
    var n = 3
    while n > 0:
        print("Countdown:", n)
        n -= 1
```

> **Expected Output:**
> ```
> Pleasant
> Iteration: 0
> Iteration: 1
> Iteration: 2
> Countdown: 3
> Countdown: 2
> Countdown: 1
> ```

### 4.2 `comptime if` and Type Refinement (v1.0.0b1+)

Compile-time branching with type refinement driven by `conforms_to()`:

```mojo
def process[T: AnyType](value: T):
    comptime if conforms_to(T, Int):
        print("Got an Int:", value)
    elif conforms_to(T, String):
        print("Got a String:", value)
    else:
        print("Got something else")

def main():
    process(42)
    process("hello")
    process(3.14)
```

> **Expected Output:**
> ```
> Got an Int: 42
> Got a String: hello
> Got something else
> ```

### 4.3 Ternary with Compile-Time Evaluation

`A if comptime(C) else B` skips elaboration of the dead branch:

```mojo
def main():
    comptime cond = True
    var result = "yes" if comptime(cond) else "no"
    print(result)
    
    # Type-level ternary
    comptime some_type: AnyType = Int if cond else String
    print("Type:", some_type)
```

---

## 🔨 Practice Problem 4.1
Write a `for` loop that prints the squares of numbers from 1 to 5.

---

## 🔨 Practice Problem 4.2
Use `comptime if` to write a function that prints "Even" or "Odd" based on a compile-time integer parameter.

---

## Chapter 5: Structs (Modern Mojo)

### 5.1 Struct Definition and Initialization

Structs define custom types. Fields use `var`. Use `out self` in `__init__` to indicate memory initialization. **Method `self` parameters must now have type `Self`** (custom self types rejected unless using `@__allow_legacy_custom_self_type`).

```mojo
struct Player:
    var name: String
    var score: Int

    def __init__(out self, name: String, score: Int):
        self.name = name
        self.score = score

    def update_score(mut self, points: Int):
        self.score += points

    def __str__(self) -> String:
        return f"Player({self.name}, score={self.score})"
```

### 5.2 Conditional Trait Conformances (Major Feature)

Structs can conditionally conform to traits using `where` clauses:

```mojo
struct Container[T: AnyType]:
    var value: T

    # Conditionally Copyable when T is Copyable
    def __copy__(self) -> Self where conforms_to(T, Copyable):
        return Self(self.value)

    # Conditionally Equatable when T is Equatable
    def __eq__(self, other: Self) -> Bool where conforms_to(T, Equatable):
        return self.value == other.value
```

### 5.3 Closure Trait Conformance (v1.0.0b3+)

Structs must **explicitly declare** closure-trait conformance in their inheritance list:

```mojo
def apply[F: def(Int) -> Int](f: F, x: Int) -> Int:
    return f(x)

# Must inherit from def(Int) -> Int to satisfy the trait
struct Double(def(Int) -> Int):
    def __call__(self, x: Int) capturing -> Int:
        return x * 2

def main():
    _ = apply(Double(), 5)  # Works!
```

### 5.4 Destructor: `__deinit__` (Not `__del__`)

The destructor dunder method is now spelled `__deinit__` (with `deinit self`). The old `__del__` spelling emits a deprecation warning.

```mojo
struct Resource:
    var handle: Int

    def __init__(out self, handle: Int):
        self.handle = handle

    def __deinit__(deinit self):
        print("Cleaning up resource:", self.handle)

def main():
    var r = Resource(42)
    # Destructor runs automatically at end of scope
```

---

## 🔨 Practice Problem 5.1
Define a struct `Book` with `title: String` and `pages: Int`. Add an initializer, a method to print the book's info, and make it conditionally `Equatable` when `String` is `Equatable`.

---

## 🔨 Practice Problem 5.2
Create a struct `Counter` that is `Movable` by default (new in v1.0.0b3+) but add a conditional `Copyable` conformance.

---

## Chapter 6: Unified Closures (Major 1.0 Feature)

### 6.1 Closure Syntax with Capture Lists

The `unified` keyword is **removed**. Specify unified-closure semantics with an explicit capture list `{...}` after the signature:

```mojo
def main() raises:
    var a, b, c, d = 1, 2, 3, 4
    var x = "hello"

    # Legacy closure: no capture list, cannot capture variables
    def hello():
        print("hi")

    # Stateless closure: empty capture list {} — lifts to top-level function
    # Can be passed as FFI callback, binds to comptime
    def add_one(n: Int) {} -> Int:
        return n + 1

    # Unified closure with explicit captures and default convention
    def my_fn() {mut a, b, c^, read}:
        # a: mut reference
        # b: imm reference (default)
        # c: moved (owned)
        # d: imm reference (default `read` convention)
        print(a, b, c, d)

    # Capture by `ref` — carries origin-mutability parameter
    def show_x() {ref x}:
        print(x)

    # Function effects before capture list
    def fallible() raises {}:
        raise Error("nope")

    # Invoke like ordinary functions
    hello()
    print(add_one(41))
    my_fn()
    show_x()
    try:
        fallible()
    except e:
        print(e)

    # Thin function pointer type
    var fn_ptr: def(Int) thin -> Int = add_one
    print(fn_ptr(99))
```

### 6.2 Capture Conventions

| Convention | Syntax | Behavior |
|------------|--------|----------|
| Immutable (default) | `read` or `imm` | Read-only reference |
| Mutable | `mut` | Mutable reference |
| Owned (move) | `^` suffix | Takes ownership |
| Ref (origin-polymorphic) | `ref` | Preserves origin, mutable |

---

## 🔨 Practice Problem 6.1
Create a closure that captures a mutable counter by `mut` reference and increments it each time it's called. Call it 3 times and print the final value.

---

## Chapter 7: Metaprogramming

### 7.1 Parameters and `comptime`

Parameters allow compile-time logic. Use `comptime` for blocks evaluated during compilation:

```mojo
def repeat_print[count: Int](msg: String):
    comptime for _ in range(count):
        print(msg)

def main():
    repeat_print[2]("Optimized at compile-time!")
```

### 7.2 `comptime assert` with T-Strings (v1.0.0b1+)

```mojo
def foo[i: Int]():
    comptime assert i > 5, t"expected i > 5, got {i}"

def main():
    foo[10]()
    # foo[3]()  # Compile-time error with message
```

### 7.3 `where` Clauses with Messages (v1.0.0b3+)

```mojo
def foo[sc: Int]() where (sc > 1, "scaling factor must be greater than 1"):
    print("Scale:", sc)

def main():
    foo[2]()
    # foo[0]()  # Error: scaling factor must be greater than 1
```

### 7.4 Type Refinement

The compiler narrows types from `where` clauses, `comptime if`, and `comptime assert` driven by `conforms_to()`:

```mojo
# Before (v0.x) - needed trait_downcast
def __contains__[T: Equatable](self, value: T) -> Bool:
    for item in self:
        if trait_downcast[Equatable](item) == trait_downcast[Equatable](value):
            return True
    return False

# After (1.0) - direct trait method call
def __contains__[T: Equatable](self, value: T) -> Bool:
    for item in self:
        if item == value:  # Type refined, calls Equatable.__eq__ directly
            return True
    return False
```

---

## 🔨 Practice Problem 7.1
Create a parameterized function `cube[val: Int]() -> Int` that returns the cube of the parameter, evaluated at compile-time.

---

## 🔨 Practice Problem 7.2
Use `comptime assert` with a t-string to validate that a compile-time parameter is positive.

---

## Chapter 8: Pointers and Memory

### 8.1 `UnsafePointer` is Non-Null by Design (Breaking Change)

**Major change in 1.0 Beta:** `UnsafePointer` no longer has a null default constructor or `__bool__()`. It no longer conforms to `Defaultable` or `Boolable`.

```mojo
from std.memory import UnsafePointer

def main():
    # OLD (deprecated):
    # var ptr = UnsafePointer[Int]()  # Null default - REMOVED
    
    # NEW: Allocate explicitly
    ptr = UnsafePointer[Int].alloc(1)
    ptr[] = 123
    print("Value:", ptr[])
    ptr.free()
    
    # For nullable pointers, use Optional
    var opt_ptr: Optional[UnsafePointer[Int]] = None
    opt_ptr = UnsafePointer[Int].alloc(1)
    opt_ptr.value()[] = 456
    print("Optional value:", opt_ptr.value()[])
    opt_ptr.value().free()
```

### 8.2 `Optional[UnsafePointer]` for Nullability

`Optional[UnsafePointer[...]]` shares `UnsafePointer`'s layout (null address = `None` niche) — zero-overhead and FFI-safe.

```mojo
def maybe_allocate(should: Bool) -> Optional[UnsafePointer[Int]]:
    if should:
        return UnsafePointer[Int].alloc(1)
    return None

def main():
    var ptr = maybe_allocate(True)
    if ptr:
        ptr.value()[] = 999
        print("Allocated:", ptr.value()[])
        ptr.value().free()
    else:
        print("No allocation")
```

### 8.3 Pointer Dereferencing

Modern Mojo uses `[]` for all dereferencing (not `.load()`/`.store()`):

```mojo
def main():
    ptr = UnsafePointer[Int].alloc(3)
    ptr[0] = 1
    ptr[1] = 2
    ptr[2] = 3
    
    for i in range(3):
        print(ptr[i])
    
    ptr.free()
```

---

## 🔨 Practice Problem 8.1
Allocate an `UnsafePointer` for a `Float64`, store `2.718`, print it, and then free it.

---

## 🔨 Practice Problem 8.2
Write a function that takes an `Optional[UnsafePointer[Int]]` and safely prints the value if present, otherwise prints "null".

---

## Chapter 9: Collections and Iterators

### 9.1 Bounds-Checked by Default (CPU)

**Negative indexing removed** from all stdlib collections (`List`, `Span`, `String`, `Array`, etc.). Use `x[len(x) - 1]` instead. Bounds checking is **on by default for CPU**.

```mojo
def main():
    var x = [1, 2, 3]
    # print(x[-1])  # COMPILE-TIME ERROR: negative indexing not supported
    print("Last:", x[len(x) - 1])  # Correct way
    
    # Out-of-bounds reports YOUR call site
    # print(x[3])  # Runtime error: "index 3 is out of bounds, valid range is 0 to 2"
```

### 9.2 `Array` is Default for List Expressions (v1.0.0b3+)

```mojo
def main():
    var x = [1, 2, 3]
    print(type(x))  # Array[Int, 3] (not List[Int])
```

### 9.3 `NDBuffer` Removed — Use `TileTensor`

```mojo
# OLD (removed):
# from std.memory import NDBuffer

# NEW:
from std.layout import TileTensor
```

### 9.4 `IterableOwned` Trait

Types conforming to `IterableOwned` implement `__iter__(var self)`, consuming the collection:

```mojo
def main():
    var list = [1, 2, 3]  # Array[Int, 3]
    
    # Owned iteration consumes the collection
    for item in list:  # Array conforms to IterableOwned
        print(item)
    # list is now moved-from
```

### 9.5 `Optional` Enhancements

```mojo
def main():
    var o = Optional[Int](42)
    
    # map: apply function to contained value
    var mapped = o.map[To=String](lambda (n: Int) -> String: String(n + 1))
    print(mapped)  # Optional("43")
    
    # and_then: flat-map over Optional-returning operations
    def try_parse(s: String) -> Optional[Int]:
        # ... parsing logic
        return Optional[Int](42)
    
    var result = Optional[String]("123").and_then(try_parse)
    print(result)
```

---

## 🔨 Practice Problem 9.1
Create a `List[Int]`, add elements, and print the last element using `len(x) - 1` (not negative indexing).

---

## 🔨 Practice Problem 9.2
Use `Optional.map` to transform an `Optional[String]` to an `Optional[Int]` by parsing the string.

---

## Chapter 10: Strings and Text

### 10.1 `String.__len__` Deprecated

Use `String.byte_length()` or `String.count_codepoints()` instead:

```mojo
def main():
    s = "Hello, Mojo!"
    print("Byte length:", s.byte_length())
    print("Codepoint count:", s.count_codepoints())
```

### 10.2 Grapheme Cluster Support (UAX #29)

Correctly handles combining marks, emoji ZWJ sequences, flag emoji, Hangul syllables:

```mojo
def main():
    s = "👨‍👩‍👧‍👦"  # Family emoji (ZWJ sequence)
    
    print("Grapheme count:", s.count_graphemes())  # 1
    print("Codepoint count:", s.count_codepoints())  # 7 (or more)
    
    # Iterate graphemes
    for g in s.graphemes():
        print("Grapheme:", g, "bytes:", g.byte_length())
    
    # Slice by grapheme
    flag = "🇺🇸"
    print("First 1 grapheme:", flag[grapheme=0:1])
```

### 10.3 Reverse Grapheme Iteration

```mojo
def main():
    s = "abc"
    for g in s.graphemes_reversed():
        print(g)
```

---

## 🔨 Practice Problem 10.1
Create a string with an emoji ZWJ sequence (e.g., "👨‍👩‍👧‍👦") and print its grapheme count vs codepoint count.

---

## Chapter 11: Error Handling

### 11.1 Explicit `raises`

`def` functions must declare `raises` if they can raise errors:

```mojo
def validate(x: Int) raises:
    if x < 0:
        raise Error("Negative value!")

def main():
    try:
        validate(-5)
    except e:
        print("Error caught:", e)
```

### 11.2 `assert_raises` for Testing (v1.0.0b1+)

Now catches custom `Writable` error types, not just `Error`.

---

## 🔨 Practice Problem 11.1
Write a function `check_even(n: Int) raises` that raises an error if the number is odd. Handle the error in `main`.

---

## Chapter 12: Traits and Type System

### 12.1 Trait Hierarchy Changes

`Boolable`, `Defaultable`, `Writable` **no longer inherit from `ImplicitlyDestructible`** (now `Deinitable`). Generic code needing destructor bound must request it explicitly:

```mojo
# OLD:
# def foo[T: Writable](x: T): ...

# NEW:
def foo[T: Writable & Deinitable](x: T): ...
```

### 12.2 Conditional Conformances (Standard Library)

Standard library types now use conditional conformances:

- `Span`: `Writable`, `Hashable`
- `Tuple`, `Optional`, `Variant`, `UnsafeMaybeUninit`: `RegisterPassable`
- `Tuple`: `Defaultable` (when all elements are `Defaultable`)
- `Variant`: `Copyable`, `ImplicitlyCopyable`
- `Optional`: `DevicePassable` (conditional on element type)

### 12.3 `ArcPointer` Value Equality

`ArcPointer` conditionally conforms to `Hashable` and `Equatable` when inner type does — delegates to managed value (like C++ `shared_ptr` / Rust `Arc`).

### 12.4 Type Equality: `==` and `!=` (v1.0.0b3+)

```mojo
def main():
    comptime T = Int
    comptime U = Int
    print(T == U)  # True
    print(T != String)  # True
    # _type_is_eq removed
```

---

## Chapter 13: Reflection (Unified API)

### 13.1 `reflect[T]()` Entry Point

New unified reflection API in `std.reflection` (auto-imported via prelude):

```mojo
from std.reflection import reflect

struct Point:
    var x: Int
    var y: Int

def main():
    var reflected = reflect[Point]()
    print("Type name:", reflected.name())
    print("Fields:", reflected.fields())
```

Legacy `struct_field_*` free functions and `get_type_name` / `get_base_type_name` are deprecated.

---

## Chapter 14: Atomics and Concurrency

### 14.1 Atomic Operations Moved to `std.atomic`

```mojo
# OLD:
# from std.os import Atomic
# from std.os.atomic import Atomic, Consistency, fence
# _ = atom.load[ordering=Consistency.MONOTONIC]()

# NEW:
from std.atomic import Atomic, Ordering, fence

_ = atom.load[ordering=Ordering.RELAXED]()
```

`Consistency` → `Ordering`, `MONOTONIC` → `RELAXED` (aligns with C++/Rust).

### 14.2 `compare_exchange` Argument Order Swapped

`success_ordering` now comes before `failure_ordering` (matches C++/Rust).

### 14.3 Platform-Aware Default Ordering

`Ordering` default constructor selects `RELEASE` on Apple GPU, `SEQUENTIAL` elsewhere.

---

## Chapter 15: GPU Programming

### 15.1 GPU Primitive IDs: `UInt` → `Int` Migration

All primitive accessors now return `Int`:

- `thread_idx`, `block_idx`, `block_dim`, `grid_dim`, `global_idx`
- `lane_id`, `warp_id`, `cluster_dim`, `cluster_idx`, `block_id_in_cluster`

Temporary `*_uint` aliases provided for migration.

### 15.2 Apple Metal GPU Support

- `print()` works on Apple Metal
- `external_memory[]()` (dynamic threadgroup memory) supported
- Apple M5 MMA intrinsics for hardware matrix multiply-accumulate
- Metal targets prefer `metal4` features by default
- Floating-point > 32 bits rejected on Apple GPU (Metal only supports Float16/Float32)

---

## Chapter 16: Professional Tips and Best Practices

### 16.1 Migration Checklist (v0.x → 1.0 Beta)

| Old | New |
|-----|-----|
| `fn` | `def` |
| `read` | `imm` (preferred) |
| `unified` | Capture list `{...}` |
| `__del__` | `__deinit__(deinit self)` |
| `ImplicitlyDestructible` | `Deinitable` |
| `UnsafePointer()` (null) | `Optional[UnsafePointer[...]] = None` |
| `x[-1]` | `x[len(x) - 1]` |
| `NDBuffer` | `TileTensor` |
| `Consistency.MONOTONIC` | `Ordering.RELAXED` |
| `String.__len__()` | `String.byte_length()` / `count_codepoints()` |
| `fn` function pointers | `def(...) thin -> ...` |
| `struct_field_*` | `reflect[T]()` |

### 16.2 Performance Tips

1. **Use `def` (not `fn`)** — same performance, unified syntax
2. **Prefer `imm` (default) over `mut`** — enables more compiler optimizations
3. **Use `comptime` for compile-time computation** — eliminates runtime overhead
4. **Stateless closures (`{} `) lift to top-level** — can be FFI callbacks, bind to `comptime`
5. **Use `thin` function pointers** — no captured state, smaller, faster
6. **Bounds checking on by default (CPU)** — catch bugs early; disable with `-D ASSERT=none` for release
7. **Use `Array` (fixed-size) over `List` when size known** — stack allocation, no heap
8. **Conditional trait conformances** — zero-cost abstractions

### 16.3 Memory Safety Patterns

```mojo
# Non-null pointers by default
def safe_access(ptr: UnsafePointer[Int]) -> Int:
    return ptr[]  # Guaranteed non-null

# Nullable with Optional
def maybe_access(ptr: Optional[UnsafePointer[Int]]) -> Optional[Int]:
    if ptr:
        return Optional[Int](ptr.value()[])
    return None

# Interior origins (v1.0.0b3+) protect against use-after-reallocation
def main():
    var list = [1, 2, 3]
    ref elem = list[0]
    # list.append(4)  # Error: use of invalidated interior reference
    print(elem)
```

### 16.4 FFI Best Practices

```mojo
# C ABI function definition (safe as callback into C)
def c_callback(a: Int32, b: Int32) abi("C") -> Int32:
    return a + b

# C ABI function pointer type (enforced by DLHandle.get_function)
from std.ffi import DLHandle

def load_sqrt() -> def(Float64) abi("C") -> Float64:
    var handle = DLHandle.open("libm.so")
    return handle.get_function[def(Float64) abi("C") -> Float64]("sqrt")
```

### 16.5 Struct Design Guidelines

```mojo
# 1. Use conditional conformances for generic structs
struct Wrapper[T: AnyType](Deinitable where conforms_to(T, Deinitable)):
    var value: T

# 2. Declare closure traits explicitly in inheritance
struct Adder(def(Int) -> Int):
    def __call__(self, x: Int) capturing -> Int:
        return x + 10

# 3. Opt out of Movable when needed
struct Pinned(Movable where False):
    var data: Int

# 4. Use `__deinit__` for cleanup
struct FileHandle:
    var fd: Int
    def __deinit__(deinit self):
        close(self.fd)
```

---

## Chapter 17: Advanced Topics

### 17.1 `abi("C")` for C Interop

```mojo
# C-ABI function definition
def c_add(a: Int32, b: Int32) abi("C") -> Int32:
    return a + b

# C-ABI function pointer type
var handle = DLHandle.open("libm.so")
var sqrt_fn = handle.get_function[def(Float64) abi("C") -> Float64]("sqrt")
print(sqrt_fn(16.0))
```

### 17.2 Parameter Packs and `TypeList`

```mojo
def foo[*arg_types: Copyable](*args: *arg_types) -> Int:
    # Equivalent to:
    # def foo(*args: *SomeTypeList[Copyable]) -> Int: ...
    return 0

def main():
    foo(1, 2, 3)  # arg_types = TypeList[Int, Int, Int]
```

### 17.3 Interior Origins (v1.0.0b3+)

Collections return element references bound to an **interior origin** — invalidated on mutation:

```mojo
def main():
    var list = [1, 2, 3]
    ref elem = list[0]
    # list.append(4)  # Compile error: use of invalidated interior reference
    print(elem)  # Safe
```

### 17.4 Struct Fields and `UnsafeAnyOrigin`

Struct fields can no longer hide `UnsafeAnyOrigin`. Add an `Origin` parameter or use `UntrackedOrigin`:

```mojo
# OLD (rejected):
# struct Example:
#     var ptr: UnsafePointer[Int, MutUnsafeAnyOrigin]

# NEW: Parameterize origin
struct Example[origin: Origin]:
    var ptr: UnsafePointer[Int, Self.origin]

# OR: Explicitly untracked
struct Example:
    var ptr: UnsafePointer[Int, MutUntrackedOrigin]
```

---

## Chapter 18: Complete Example — Modern Mojo 1.0 Module

```mojo
# modern_module.mojo
from std.memory import UnsafePointer
from std.reflection import reflect
from std.atomic import Atomic, Ordering

# Conditional trait conformance
struct Buffer[T: AnyType](Deinitable where conforms_to(T, Deinitable)):
    var data: UnsafePointer[T]
    var len: Int

    def __init__(out self, len: Int):
        self.data = UnsafePointer[T].alloc(len)
        self.len = len

    def __deinit__(deinit self):
        self.data.free()

    def __getitem__(self, idx: Int) -> T:
        # Bounds checked by default on CPU
        return self.data[idx]

    def __setitem__(mut self, idx: Int, value: T):
        self.data[idx] = value

# Stateless closure for FFI
def square(x: Int) {} -> Int:
    return x * x

# Unified closure with captures
def make_adder(base: Int) -> def(Int) -> Int:
    def adder(x: Int) {imm base} -> Int:
        return x + base
    return adder

def main() raises:
    # Buffer with Int (Deinitable)
    var buf = Buffer[Int](5)
    for i in range(5):
        buf[i] = i * 2
    
    for i in range(5):
        print(buf[i])
    
    # Reflection
    var r = reflect[Buffer[Int]]()
    print("Type:", r.name())
    
    # Closures
    var add_10 = make_adder(10)
    print("add_10(5):", add_10(5))
    
    # Thin function pointer
    var fn: def(Int) thin -> Int = square
    print("square(7):", fn(7))
    
    # Optional pointer
    var opt: Optional[UnsafePointer[Int]] = None
    opt = UnsafePointer[Int].alloc(1)
    opt.value()[] = 42
    print("Optional ptr:", opt.value()[])
    opt.value().free()
```

---

## 🔨 Final Practice Problem

Create a complete Mojo 1.0 Beta module that:

1. Defines a generic `Stack[T]` struct with `push`, `pop`, `peek` methods
2. Uses conditional conformances for `Copyable`, `Equatable`, `Deinitable`
3. Implements `__deinit__` for cleanup
4. Uses `UnsafePointer` internally with proper allocation/freeing
5. Provides a stateless closure `make_stack_printer` that returns a closure printing stack contents
6. Demonstrates all features in `main` with error handling

---

*Mojo Fundamentals Mastery Guide — Updated for Mojo 1.0 Beta (v1.0.0b3+)*  
*Last updated: August 2026*