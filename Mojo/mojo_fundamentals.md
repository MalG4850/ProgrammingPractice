# Mojo Fundamentals: A Comprehensive Mastery Guide (2026 Nightly / Mojo 1.0)

This guide covers the latest **Modern Mojo** syntax, which unifies Python-like ergonomics with systems-level performance. Every concept is explained with theory, working code, expected output, and a practice problem.

---

## Chapter 1: Introduction to Mojo

### 1.1 What is Mojo?

Mojo is a unified programming language that combines Python's usability with the performance of C, C++, and Rust. The latest nightly builds have eliminated the "two-language problem" within Mojo by unifying function and variable declaration syntax.

### 1.2 Hello World

In Modern Mojo, all functions use the `def` keyword. The `main` function is the entry point of your program.

```mojo
# hello.mojo
def main():
    print("Hello, Modern Mojo!")
```

> **Expected Output:**
> ```
> Hello, Modern Mojo!
> ```

---

## 🔨 Practice Problem 1.1
Create a script called `greet.mojo` that prints "Welcome to the Unified Mojo!" and then prints "One keyword to rule them all: def." on a new line.

---

## Chapter 2: Variables and Scoping

### 2.1 Implicit Declaration

In Modern Mojo, the `let` and `var` keywords have been removed for standard local variables. Variables are declared implicitly upon assignment, similar to Python, but remain statically typed.

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

### 2.2 Explicit Typing (Optional)

You can still provide type hints for clarity or when a variable is not immediately assigned.

```mojo
def main():
    x: Int = 42
    print(x)
```

> **Expected Output:**
> ```
> 42
> ```

---

## 🔨 Practice Problem 2.1
Declare a variable for your `favorite_number` and `city`. Print them both in a single statement.

---

## Chapter 3: Functions and Argument Conventions

### 3.1 The Unified `def`

The `def` keyword is now the only way to define functions. It defaults to the strict, high-performance behavior previously associated with `fn`.

### 3.2 Argument Conventions: `read` and `mut`

Mojo uses explicit conventions for how arguments are passed to ensure memory safety:

- **`read`**: The default convention. Provides a read-only (immutable) reference to the argument.
- **`mut`**: Provides a mutable reference. Changes made inside the function affect the original variable.
- **`owned`**: The function takes full ownership. Use the `^` (transfer) operator when passing values.

```mojo
def increment(mut value: Int):
    value += 1

def main():
    count = 10
    increment(count)
    print("Updated Count:", count)
```

> **Expected Output:**
> ```
> Updated Count: 11
> ```

---

## 🔨 Practice Problem 3.1
Write a function `multiply_by_two(mut x: Int)` that doubles the value of its argument. Test it by passing a variable and printing the result.

---

## Chapter 4: Control Flow

### 4.1 Loops and Conditionals

Mojo supports standard Python control flow. Note that in Modern Mojo, `def` functions are **non-raising** by default.

```mojo
def main():
    temperature = 28
    if temperature > 30:
        print("Hot")
    else:
        print("Pleasant")
    
    for i in range(3):
        print("Iteration:", i)
```

> **Expected Output:**
> ```
> Pleasant
> Iteration: 0
> Iteration: 1
> Iteration: 2
> ```

---

## 🔨 Practice Problem 4.1
Write a `for` loop that prints the squares of numbers from 1 to 5.

---

## Chapter 5: Structs

### 5.1 Modern Structs

Structs define custom types. Use `out self` in the initializer to indicate that the memory is being initialized.

```mojo
struct Player:
    var name: String  # Fields still use 'var' for clarity in structs
    var score: Int

    def __init__(out self, name: String, score: Int):
        self.name = name
        self.score = score

    def update_score(mut self, points: Int):
        self.score += points

def main():
    p = Player("Alice", 100)
    p.update_score(50)
    print(p.name, "score:", p.score)
```

> **Expected Output:**
> ```
> Alice score: 150
> ```

---

## 🔨 Practice Problem 5.1
Define a struct `Book` with `title: String` and `pages: Int`. Add an initializer and a method to print the book's info.

---

## Chapter 6: Metaprogramming

### 6.1 `comptime` and Parameters

Parameters allow for compile-time logic. Use the `comptime` keyword for blocks that should be evaluated during compilation.

```mojo
def repeat_print[count: Int](msg: String):
    comptime for _ in range(count):
        print(msg)

def main():
    repeat_print[2]("Optimized at compile-time!")
```

> **Expected Output:**
> ```
> Optimized at compile-time!
> Optimized at compile-time!
> ```

---

## 🔨 Practice Problem 6.1
Create a parameterized function `cube[val: Int]() -> Int` that returns the cube of the parameter, evaluated at compile-time.

---

## Chapter 7: Pointers and Memory

### 7.1 `UnsafePointer`

`UnsafePointer[T]` provides raw memory access. Modern Mojo uses `[]` for all dereferencing operations.

```mojo
from std.memory import UnsafePointer

def main():
    # Allocate space for one Int
    ptr = UnsafePointer[Int].alloc(1)
    
    # Store value using dereference syntax
    ptr[] = 123
    
    # Load value
    print("Value:", ptr[])
    
    # Free memory
    ptr.free()
```

> **Expected Output:**
> ```
> Value: 123
> ```

---

## 🔨 Practice Problem 7.1
Allocate an `UnsafePointer` for a `Float64`, store `2.718`, print it, and then free it.

---

## Chapter 8: Error Handling

### 8.1 Explicit `raises`

In Modern Mojo, `def` functions must explicitly declare if they can raise an error using the `raises` keyword.

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

> **Expected Output:**
> ```
> Error caught: Negative value!
> ```

---

## 🔨 Practice Problem 8.1
Write a function `check_even(n: Int) raises` that raises an error if the number is odd. Handle the error in `main`.

---
*Mojo Fundamentals Mastery Guide (2026 Nightly Edition)*
