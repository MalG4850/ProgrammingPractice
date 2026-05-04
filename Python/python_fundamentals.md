# Python Fundamentals: A Comprehensive Mastery Guide

This guide is structured to take you from absolute zero to confident Python programmer — and then a bit further. Every concept, no matter how small, is explained with theory, working code, expected output, and a practice problem. The progression is deliberate: each chapter builds on the last, and no assumption is made about prior Python knowledge (though general programming exposure helps). By the end, you will have covered not only core fundamentals but also file I/O, OOP, functional patterns, error handling, modules, comprehensions, generators, decorators, and much more.

Read every section. Run every program. Attempt every exercise. That is the only path to mastery.

---

## Chapter 1: Python — The Language and Its Philosophy

### 1.1 What Is Python?

Python is a **high-level, interpreted, dynamically typed, garbage-collected, general-purpose programming language** created by Guido van Rossum and first released in 1991. "High-level" means it abstracts away machine details like memory addresses and CPU registers. "Interpreted" means a program called the **interpreter** reads your source code and executes it directly, without a separate compile step to machine code (though CPython does compile to bytecode internally). "Dynamically typed" means the type of a variable is determined at runtime, not by a declaration you write.

Python is intentionally readable. Its syntax enforces indentation as part of the grammar — a block of code is delimited by consistent indentation, not braces. This makes well-written Python feel almost like executable pseudocode.

Python is **multi-paradigm**: it supports procedural programming (step-by-step instructions), object-oriented programming (classes and objects), and functional programming (first-class functions, comprehensions, higher-order functions). You can mix styles freely.

### 1.2 The Zen of Python

The philosophy of the language is captured in a document called **PEP 20**, accessible by typing `import this` in any Python interpreter. Key principles include:

- *Beautiful is better than ugly.*
- *Explicit is better than implicit.*
- *Simple is better than complex.*
- *Readability counts.*
- *There should be one — and preferably only one — obvious way to do it.*

These principles actively shape how experienced Python programmers write code. When you are unsure which of two approaches to take, the Pythonic one is usually the simpler, more readable one.

### 1.3 Installing Python and Running Your First Program

Download Python 3 from [python.org](https://www.python.org). Verify your installation:

```bash
python3 --version
```

You can run Python in three modes:

1. **Interactive (REPL):** Type `python3` in a terminal. You get a `>>>` prompt where expressions are evaluated immediately. Great for exploration.
2. **Script mode:** Write code in a `.py` file and run it with `python3 filename.py`.
3. **IDE/Editor:** Use VS Code, PyCharm, or IDLE for larger projects.

```python
# hello.py
print("Hello, World!")
```

> **Expected Output:**
> ```
> Hello, World!
> ```

The `print()` function writes to **standard output** (your terminal by default). The `#` character begins a **comment** — everything after it on that line is ignored by the interpreter.

### 1.4 How the Interpreter Executes Code

When you run `python3 hello.py`, CPython (the reference implementation) does the following:

1. **Lexing:** Converts raw text into tokens (keywords, identifiers, literals, operators).
2. **Parsing:** Builds an **Abstract Syntax Tree (AST)** from the token stream.
3. **Compilation:** Converts the AST to **bytecode** (`.pyc` files in `__pycache__`).
4. **Execution:** The **Python Virtual Machine (PVM)** executes the bytecode.

You never need to manage these steps manually — they happen transparently every time you run a script.

### 1.5 Python Versions: 2 vs 3

Python 2 reached end-of-life in January 2020. **Always use Python 3.** If you encounter Python 2 code in the wild, the most common difference you will see is `print "hello"` (no parentheses) versus `print("hello")`. This guide exclusively covers Python 3.

---

## 🔨 Practice Problem 1.1

Open a terminal, start the Python interactive shell (`python3`), and type the following expressions one at a time, observing the output:

```python
2 + 3
10 / 3
10 // 3
"hello" + " " + "world"
type(42)
type(3.14)
type("Python")
```

Note how the REPL immediately evaluates each expression. Then write a script called `intro.py` that prints your name, your age, and the phrase "I am learning Python." on three separate lines.

---

## Chapter 2: Variables, Data Types, and Literals

### 2.1 Variables and Assignment

A **variable** is a named reference to a value stored in memory. In Python, you create a variable simply by assigning a value to a name — there is no type declaration keyword like `int` or `String`.

```python
# variables.py
name = "Alice"
age = 30
height = 5.7
is_student = True

print(name)
print(age)
print(height)
print(is_student)
```

> **Expected Output:**
> ```
> Alice
> 30
> 5.7
> True
> ```

**Naming rules:**
- Must start with a letter or underscore (`_`).
- Can contain letters, digits, and underscores.
- Case-sensitive: `name`, `Name`, and `NAME` are three different variables.
- Cannot be a Python **keyword** (like `if`, `for`, `class`, `return`).

**Convention (PEP 8):** Use `snake_case` for variable and function names (`my_variable`, `calculate_area`). Use `UPPER_SNAKE_CASE` for constants (`MAX_SIZE`, `PI`). Use `PascalCase` for class names.

### 2.2 Multiple Assignment and Tuple Unpacking

Python allows elegant simultaneous assignment:

```python
# multiple_assignment.py

# Assign the same value to multiple variables
x = y = z = 0
print(x, y, z)

# Assign multiple values in one line (tuple unpacking)
a, b, c = 1, 2, 3
print(a, b, c)

# Swap two variables (a Python idiom — no temp variable needed)
a, b = b, a
print(a, b)

# Extended unpacking with *
first, *rest = [10, 20, 30, 40, 50]
print(first)   # 10
print(rest)    # [20, 30, 40, 50]
```

> **Expected Output:**
> ```
> 0 0 0
> 1 2 3
> 2 1
> 10
> [20, 30, 40, 50]
> ```

The swap `a, b = b, a` works because Python evaluates the **entire right-hand side** first, forming a tuple `(b, a)`, and then unpacks it into `a` and `b`. This is a common Python idiom.

### 2.3 Built-in Data Types Overview

Python has a rich set of built-in types:

| Category | Types |
|---|---|
| **Numeric** | `int`, `float`, `complex` |
| **Text** | `str` |
| **Boolean** | `bool` |
| **Sequence** | `list`, `tuple`, `range` |
| **Mapping** | `dict` |
| **Set** | `set`, `frozenset` |
| **Binary** | `bytes`, `bytearray`, `memoryview` |
| **None** | `NoneType` |

### 2.4 Integers (`int`)

Python integers have **arbitrary precision** — they can be as large as your memory allows. There is no overflow in the traditional sense.

```python
# integers.py
a = 42
b = -17
c = 0
big = 10 ** 100          # googol — works fine in Python!
binary_literal = 0b1010  # binary: 10
octal_literal = 0o17     # octal: 15
hex_literal = 0xFF       # hexadecimal: 255
readable = 1_000_000     # underscores for readability

print(a, b, c)
print(big)
print(binary_literal, octal_literal, hex_literal)
print(readable)
print(type(a))
```

> **Expected Output:**
> ```
> 42 -17 0
> 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
> 10 15 255
> 1000000
> <class 'int'>
> ```

### 2.5 Floating-Point Numbers (`float`)

Floats are 64-bit IEEE 754 double-precision numbers. They have finite precision — not all decimal fractions can be represented exactly.

```python
# floats.py
pi = 3.14159
e = 2.71828
scientific = 1.5e10       # 1.5 × 10^10
negative_exp = 2.5e-3     # 0.0025

print(pi, e, scientific, negative_exp)
print(type(pi))

# Floating-point imprecision — a fundamental property of binary floating-point
print(0.1 + 0.2)           # Not exactly 0.3
print(0.1 + 0.2 == 0.3)    # False!

# Correct way to compare floats: use math.isclose
import math
print(math.isclose(0.1 + 0.2, 0.3))  # True
```

> **Expected Output:**
> ```
> 3.14159 2.71828 15000000000.0 0.0025
> <class 'float'>
> 0.30000000000000004
> False
> True
> ```

**Important:** Never compare floats with `==` unless you are certain there is no accumulated error. Use `math.isclose()` instead.

### 2.6 Complex Numbers (`complex`)

Python has native complex number support:

```python
# complex_numbers.py
z1 = 3 + 4j
z2 = complex(1, -2)

print(z1)
print(z2)
print(z1 + z2)
print(z1.real, z1.imag)
print(abs(z1))  # magnitude: sqrt(3^2 + 4^2) = 5.0
```

> **Expected Output:**
> ```
> (3+4j)
> (1-2j)
> (4+2j)
> 3.0 4.0
> 5.0
> ```

### 2.7 Booleans (`bool`)

`bool` is a subclass of `int`. `True` equals `1` and `False` equals `0`. This occasionally produces surprising arithmetic results.

```python
# booleans.py
t = True
f = False

print(t, f)
print(type(t))

# Boolean arithmetic
print(True + True)   # 2
print(True * 5)      # 5
print(False + 1)     # 1

# Truthiness: objects have a boolean interpretation
print(bool(0))         # False
print(bool(1))         # True
print(bool(""))        # False — empty string is falsy
print(bool("hello"))   # True — non-empty string is truthy
print(bool([]))        # False — empty list
print(bool([1, 2]))    # True
print(bool(None))      # False
```

> **Expected Output:**
> ```
> True False
> <class 'bool'>
> 2
> 5
> 1
> False
> True
> False
> True
> False
> True
> False
> ```

**Falsy values in Python:** `False`, `0`, `0.0`, `0j`, `""`, `[]`, `()`, `{}`, `set()`, `None`, and any object whose `__bool__` or `__len__` returns 0/False. Everything else is truthy.

### 2.8 The `NoneType` and `None`

`None` is Python's null value — it represents the **absence of a value**. It is the only instance of `NoneType`. Functions that do not explicitly return a value return `None` implicitly.

```python
# none_type.py
x = None
print(x)
print(type(x))

# Always test for None with 'is', not '=='
print(x is None)    # Correct
print(x == None)    # Works but not idiomatic

def greet():
    print("Hi!")
    # No return statement → returns None implicitly

result = greet()
print(result)
```

> **Expected Output:**
> ```
> None
> <class 'NoneType'>
> True
> True
> Hi!
> None
> ```

### 2.9 The `type()` and `isinstance()` Functions

`type(x)` returns the exact type of `x`. `isinstance(x, T)` returns `True` if `x` is an instance of `T` or any subclass of `T`. Prefer `isinstance` when checking types in logic.

```python
# type_checking.py
x = 42
print(type(x))              # <class 'int'>
print(type(x) == int)       # True
print(isinstance(x, int))   # True
print(isinstance(x, (int, float)))  # True — checks against a tuple of types

# isinstance respects inheritance
print(isinstance(True, int))  # True — bool is a subclass of int
print(isinstance(True, bool)) # True
```

> **Expected Output:**
> ```
> <class 'int'>
> True
> True
> True
> True
> True
> ```

### 2.10 Dynamic Typing and Variable Rebinding

In Python, a variable is a **label** that can be rebound to any object at any time. The type belongs to the object, not the variable.

```python
# dynamic_typing.py
x = 10
print(x, type(x))

x = "hello"           # Rebind x to a str object
print(x, type(x))

x = [1, 2, 3]         # Rebind again to a list
print(x, type(x))

x = None
print(x, type(x))
```

> **Expected Output:**
> ```
> 10 <class 'int'>
> hello <class 'str'>
> [1, 2, 3] <class 'list'>
> None <class 'NoneType'>
> ```

This flexibility is powerful but requires discipline — keeping track of what type a variable currently holds is your responsibility.

---

## 🔨 Practice Problem 2.1

Write a program that:
1. Declares a variable for each of the following: your name (`str`), your age (`int`), your GPA (`float`), whether you are enrolled (`bool`), and a contact email (set to `None` for now).
2. Prints each variable along with its type using `type()`.
3. Swaps your age and GPA values using tuple unpacking (observe what happens to the types).
4. Demonstrates that `True == 1` and `False == 0` by printing the results of `True + 4` and `False * 100`.

---

## Chapter 3: Operators and Expressions

### 3.1 Arithmetic Operators

```python
# arithmetic.py
a = 17
b = 5

print(a + b)    # Addition: 22
print(a - b)    # Subtraction: 12
print(a * b)    # Multiplication: 85
print(a / b)    # True division (always returns float): 3.4
print(a // b)   # Floor division (rounds toward -∞): 3
print(a % b)    # Modulo (remainder): 2
print(a ** b)   # Exponentiation: 1419857
print(-a // b)  # Floor division of negative: -4 (rounds toward -∞, not toward 0!)
```

> **Expected Output:**
> ```
> 22
> 12
> 85
> 3.4
> 3
> 2
> 1419857
> -4
> ```

**Critical distinction:** `/` always produces a `float`. `//` (floor division) rounds toward negative infinity, not toward zero. So `-7 // 2` is `-4`, not `-3`. This is mathematically consistent but surprises programmers from other languages.

The modulo `%` is consistent with floor division: `a == (a // b) * b + (a % b)` always holds.

### 3.2 Augmented Assignment Operators

```python
# augmented.py
x = 10
x += 3    # x = x + 3 → 13
x -= 2    # x = x - 2 → 11
x *= 4    # x = x * 4 → 44
x //= 3   # x = x // 3 → 14
x %= 5    # x = x % 5 → 4
x **= 2   # x = x ** 2 → 16
print(x)  # 16
```

> **Expected Output:**
> ```
> 16
> ```

**Note:** Python does **not** have `++` or `--` operators. Use `x += 1` and `x -= 1`.

### 3.3 Comparison Operators

Comparison operators return `bool` values (`True` or `False`).

```python
# comparisons.py
a, b = 10, 20

print(a == b)   # Equal: False
print(a != b)   # Not equal: True
print(a < b)    # Less than: True
print(a > b)    # Greater than: False
print(a <= 10)  # Less than or equal: True
print(a >= 10)  # Greater than or equal: True

# Python supports chained comparisons (a powerful feature)
x = 15
print(10 < x < 20)    # True — equivalent to (10 < x) and (x < 20)
print(1 < 2 < 3 < 4)  # True
print(5 < 3 < 10)     # False — because 5 < 3 is False
```

> **Expected Output:**
> ```
> False
> True
> True
> False
> True
> True
> True
> True
> False
> ```

### 3.4 Logical Operators

```python
# logical.py
# 'and', 'or', 'not' — spelled out as words in Python, not &&, ||, !

print(True and True)    # True
print(True and False)   # False
print(False or True)    # True
print(False or False)   # False
print(not True)         # False
print(not False)        # True

# Short-circuit evaluation
# 'and': if left is falsy, returns left; otherwise returns right
print(0 and "hello")       # 0 (short-circuits, never evaluates "hello")
print(5 and "hello")       # "hello"

# 'or': if left is truthy, returns left; otherwise returns right
print(0 or "default")      # "default"
print("found" or "default")# "found"

# This behavior is used for default values (a common Python idiom)
name = "" or "Anonymous"
print(name)  # Anonymous
```

> **Expected Output:**
> ```
> True
> False
> True
> False
> False
> True
> 0
> hello
> default
> found
> Anonymous
> ```

**Short-circuit semantics:** `and` and `or` do not always return `True` or `False` — they return one of their operands. The returned value is the one that **determined** the result.

### 3.5 Identity and Membership Operators

```python
# identity_membership.py

# Identity: 'is' checks if two names refer to the same object in memory
a = [1, 2, 3]
b = a           # b is the same object as a
c = [1, 2, 3]  # c is a different object with equal contents

print(a is b)   # True — same object
print(a is c)   # False — different objects
print(a == c)   # True — same contents

# 'is not'
print(a is not c)  # True

# None checks use 'is'
x = None
print(x is None)     # Correct idiom
print(x is not None) # Also correct

# Membership: 'in' and 'not in'
fruits = ["apple", "banana", "cherry"]
print("apple" in fruits)     # True
print("grape" in fruits)     # False
print("grape" not in fruits) # True

# Works on strings too
sentence = "hello world"
print("world" in sentence)   # True
print("xyz" in sentence)     # False
```

> **Expected Output:**
> ```
> True
> False
> True
> True
> True
> True
> True
> False
> True
> True
> False
> ```

### 3.6 Bitwise Operators

Bitwise operators work on the binary representation of integers:

```python
# bitwise.py
a = 0b1010  # 10
b = 0b1100  # 12

print(bin(a & b))   # AND:  0b1000  → 8
print(bin(a | b))   # OR:   0b1110  → 14
print(bin(a ^ b))   # XOR:  0b0110  → 6
print(bin(~a))      # NOT:  ~10 = -(10+1) = -11
print(bin(a << 1))  # Left shift:  0b10100 → 20
print(bin(a >> 1))  # Right shift: 0b0101  → 5
```

> **Expected Output:**
> ```
> 0b1000
> 0b1110
> 0b110
> -0b1011
> 0b10100
> 0b101
> ```

### 3.7 Operator Precedence

When an expression has multiple operators, Python applies them in a specific order (highest to lowest):

| Precedence | Operator |
|---|---|
| Highest | `**` |
| | `+x`, `-x`, `~x` (unary) |
| | `*`, `/`, `//`, `%` |
| | `+`, `-` |
| | `<<`, `>>` |
| | `&` |
| | `^` |
| | `\|` |
| | `==`, `!=`, `<`, `>`, `<=`, `>=`, `is`, `in` |
| | `not` |
| | `and` |
| Lowest | `or` |

When in doubt, use **parentheses** to make precedence explicit and improve readability.

```python
# precedence.py
print(2 + 3 * 4)     # 14, not 20 (multiplication first)
print((2 + 3) * 4)   # 20 (parentheses override)
print(2 ** 3 ** 2)   # 512 (** is right-associative: 2 ** (3 ** 2) = 2 ** 9 = 512)
print(not True or False)   # False (not binds tighter: (not True) or False)
print(not (True or False)) # False
```

> **Expected Output:**
> ```
> 14
> 20
> 512
> False
> False
> ```

### 3.8 The Walrus Operator (`:=`) — Python 3.8+

The **walrus operator** (assignment expression) assigns a value and returns it, all in one expression. Useful in loops and conditionals to avoid computing a value twice.

```python
# walrus.py
import re

data = [1, 5, 3, 9, 2, 8, 4]

# Instead of: n = len(data); if n > 5: print(n)
if (n := len(data)) > 5:
    print(f"List has {n} elements, which is more than 5")

# Useful in while loops
numbers = iter([10, 20, 0, 30])
while (val := next(numbers, None)) is not None:
    if val == 0:
        print("Stopping at zero")
        break
    print(val)
```

> **Expected Output:**
> ```
> List has 7 elements, which is more than 5
> 10
> 20
> Stopping at zero
> ```

---

## 🔨 Practice Problem 3.1

Write a program that:
1. Takes two integers `a = 37` and `b = 6` and prints the result of every arithmetic operator on them, with a label (e.g., `"37 // 6 = 6"`).
2. Demonstrates short-circuit evaluation by printing `(0 or "fallback")` and `(42 and "yes")` and explains in a comment why each produces its output.
3. Uses a chained comparison to check if a variable `temperature = 22` is between 18 and 26 (inclusive), printing `"Comfortable"` or `"Uncomfortable"`.
4. Uses the walrus operator to compute the square of a number and print it only if it exceeds 100 — all in a single `if` statement.

---

## Chapter 4: Strings

### 4.1 String Literals and Quotes

Strings in Python are **immutable sequences of Unicode characters**. You can use single quotes, double quotes, or triple quotes:

```python
# string_basics.py
s1 = 'single quotes'
s2 = "double quotes"
s3 = '''triple single — can span
multiple lines'''
s4 = """triple double — also
multiline"""

print(s1)
print(s2)
print(s3)
print(s4)
print(type(s1))
```

> **Expected Output:**
> ```
> single quotes
> double quotes
> triple single — can span
> multiple lines
> triple double — also
> multiline
> <class 'str'>
> ```

Single and double quotes are interchangeable. Use double quotes when your string contains a single quote (e.g., `"it's fine"`), and single quotes when it contains a double quote (e.g., `'say "hello"'`). Triple-quoted strings span multiple lines and are often used for **docstrings** (documentation).

### 4.2 Escape Sequences

```python
# escape.py
print("She said \"Hello!\"")   # Escaped double quotes
print('It\'s a test')           # Escaped single quote
print("Line 1\nLine 2")         # Newline
print("Tab\there")              # Tab
print("Backslash: \\")          # Literal backslash
print("Unicode: \u03C0")        # π (pi symbol)
print("Null char: \0 end")      # Null character
```

> **Expected Output:**
> ```
> She said "Hello!"
> It's a test
> Line 1
> Line 2
> Tab	here
> Backslash: \
> Unicode: π
> Null char:  end
> ```

### 4.3 Raw Strings

Prefix a string with `r` or `R` to disable escape processing. Every backslash is treated as a literal character. Essential for **regular expressions** and **Windows file paths**.

```python
# raw_strings.py
normal = "C:\\Users\\Alice\\Documents"
raw    = r"C:\Users\Alice\Documents"

print(normal)  # C:\Users\Alice\Documents
print(raw)     # C:\Users\Alice\Documents (same output, easier to write)

# In regex, raw strings prevent double-escaping
import re
pattern = r"\d+"   # matches one or more digits
print(re.findall(pattern, "I have 3 cats and 12 dogs"))
```

> **Expected Output:**
> ```
> C:\Users\Alice\Documents
> C:\Users\Alice\Documents
> ['3', '12']
> ```

### 4.4 String Concatenation and Repetition

```python
# string_ops.py
first = "Hello"
second = "World"

# Concatenation with +
combined = first + ", " + second + "!"
print(combined)

# Repetition with *
dashes = "-" * 30
print(dashes)

banner = ("=" * 10 + " PYTHON " + "=" * 10)
print(banner)

# Concatenation of adjacent string literals (compile-time, not runtime)
message = ("This is a long string that "
           "spans multiple source lines "
           "but is one string.")
print(message)
```

> **Expected Output:**
> ```
> Hello, World!
> ------------------------------
> ========== PYTHON ==========
> This is a long string that spans multiple source lines but is one string.
> ```

### 4.5 String Indexing and Slicing

Strings are sequences. Each character has an index starting from 0. Negative indices count from the end.

```python
# indexing.py
s = "Python"
#    P  y  t  h  o  n
# index: 0  1  2  3  4  5
# neg:  -6 -5 -4 -3 -2 -1

print(s[0])     # P
print(s[5])     # n
print(s[-1])    # n (last character)
print(s[-2])    # o

# Slicing: s[start:stop:step]
# start is inclusive, stop is exclusive
print(s[0:3])   # Pyt  (indices 0, 1, 2)
print(s[2:5])   # tho
print(s[:3])    # Pyt  (start defaults to 0)
print(s[3:])    # hon  (stop defaults to end)
print(s[:])     # Python (full copy)
print(s[::2])   # Pto  (every 2nd character)
print(s[::-1])  # nohtyP (reversed!)
```

> **Expected Output:**
> ```
> P
> n
> n
> o
> Pyt
> tho
> Pyt
> hon
> Python
> Pto
> nohtyP
> ```

**Slicing never raises `IndexError`** — if the slice goes out of range, Python clips it silently.

### 4.6 String Methods

Strings have a rich collection of built-in methods. Because strings are immutable, all methods return a **new** string; the original is never modified.

```python
# string_methods.py
s = "  Hello, World!  "

print(s.strip())           # "Hello, World!"  — remove leading/trailing whitespace
print(s.lstrip())          # "Hello, World!  "
print(s.rstrip())          # "  Hello, World!"

s = "Hello, World!"
print(s.upper())           # HELLO, WORLD!
print(s.lower())           # hello, world!
print(s.title())           # Hello, World!
print(s.swapcase())        # hELLO, wORLD!

print(s.replace("World", "Python"))  # Hello, Python!
print(s.replace("l", "L"))           # HeLLo, WorLd!

print(s.find("World"))     # 7 (index of first occurrence)
print(s.find("xyz"))       # -1 (not found)
print(s.index("World"))    # 7 (like find, but raises ValueError if not found)

print(s.startswith("Hello"))  # True
print(s.endswith("!"))        # True

print(s.count("l"))           # 3 (count of 'l')

print(s.split(", "))          # ['Hello', 'World!']
print("a,b,,c".split(","))    # ['a', 'b', '', 'c']
print("a,b,,c".split(",", 1)) # ['a', 'b,,c'] (max 1 split)

words = ["one", "two", "three"]
print(" ".join(words))         # one two three
print("-".join(words))         # one-two-three

print(s.center(25, "*"))       # *****Hello, World!*****
print(s.ljust(20, "."))        # Hello, World!.......
print(s.zfill(6))              # Hello, World! (no effect, longer than 6)
print("42".zfill(6))           # 000042

print("abc123".isalpha())      # False
print("abc".isalpha())         # True
print("123".isdigit())         # True
print("abc123".isalnum())      # True
print("  \t\n".isspace())      # True
```

> **Expected Output:**
> ```
> Hello, World!
> Hello, World!  
>   Hello, World!
> HELLO, WORLD!
> hello, world!
> Hello, World!
> hELLO, wORLD!
> Hello, Python!
> HeLLo, WorLd!
> 7
> -1
> 7
> True
> True
> 3
> ['Hello', 'World!']
> ['a', 'b', '', 'c']
> ['a', 'b,,c']
> one two three
> one-two-three
> *****Hello, World!*****
> Hello, World!.......
> Hello, World!
> 000042
> False
> True
> True
> True
> True
> ```

### 4.7 f-Strings (Formatted String Literals) — Python 3.6+

**f-strings** are the modern, preferred way to embed expressions inside strings. Prefix the string with `f` or `F`, and wrap any Python expression in `{}`.

```python
# fstrings.py
name = "Alice"
age = 30
pi = 3.14159

# Basic embedding
print(f"My name is {name} and I am {age} years old.")

# Expressions inside {}
print(f"Next year I will be {age + 1}.")
print(f"Pi to 2 decimal places: {pi:.2f}")
print(f"Pi to 5 decimal places: {pi:.5f}")
print(f"Age in binary: {age:b}")
print(f"Age padded to 10: {age:10d}")
print(f"Age left-aligned: {age:<10d}!")
print(f"Name centered: {name:^20}!")

# Format spec mini-language
value = 1234567.89
print(f"Formatted: {value:,.2f}")     # 1,234,567.89

# Calling methods inside {}
city = "new york"
print(f"City: {city.title()}")

# Multiline f-string
item = "book"
price = 9.99
qty = 3
msg = (
    f"Item: {item}\n"
    f"Price: ${price:.2f}\n"
    f"Qty: {qty}\n"
    f"Total: ${price * qty:.2f}"
)
print(msg)

# Debugging with = (Python 3.8+)
x = 42
print(f"{x = }")  # Prints 'x = 42'
```

> **Expected Output:**
> ```
> My name is Alice and I am 30 years old.
> Next year I will be 31.
> Pi to 2 decimal places: 3.14
> Pi to 5 decimal places: 3.14159
> Age in binary: 11110
> Age padded to 10:         30
> Age left-aligned: 30        !
> Name centered:        Alice         !
> Formatted: 1,234,567.89
> City: New York
> Item: book
> Price: $9.99
> Qty: 3
> Total: $29.97
> x = 42
> ```

### 4.8 The `format()` Method and `%` Formatting

Older formatting styles you may encounter in existing code:

```python
# old_formatting.py

# str.format() — Python 2.6+ style
print("Hello, {}!".format("World"))
print("{0} + {1} = {2}".format(3, 4, 7))
print("{name} is {age}".format(name="Bob", age=25))
print("{:.3f}".format(3.14159))

# % operator — oldest style (C-style)
print("Hello, %s!" % "World")
print("Int: %d, Float: %.2f" % (42, 3.14))
```

> **Expected Output:**
> ```
> Hello, World!
> 3 + 4 = 7
> Bob is 25
> 3.142
> Hello, World!
> Int: 42, Float: 3.14
> ```

Prefer **f-strings** in new code. Use `str.format()` when you need to defer formatting (e.g., store the template first). Avoid `%` formatting in new code.

### 4.9 String Immutability

Strings cannot be changed after creation. Any operation that appears to modify a string actually creates a new one.

```python
# immutability.py
s = "hello"
# s[0] = "H"  # This raises TypeError: 'str' object does not support item assignment

# Instead, create a new string
s = "H" + s[1:]
print(s)  # Hello

# id() returns the memory address of an object
a = "Python"
b = a.upper()
print(id(a), id(b))   # Different addresses — two different objects
print(a)              # "Python" — unchanged
print(b)              # "PYTHON" — new object
```

> **Expected Output:**
> ```
> Hello
> (two different numbers)
> Python
> PYTHON
> ```

### 4.10 Useful String Functions

```python
# string_functions.py
s = "hello world"

print(len(s))            # 11 — length of string
print(ord('A'))          # 65 — Unicode code point
print(chr(65))           # A  — character from code point
print(min(s))            # ' ' (space has lowest ASCII value)
print(max(s))            # 'w'
print(sorted(s))         # sorted list of characters
```

> **Expected Output:**
> ```
> 11
> 65
> A
>  
> w
> [' ', 'd', 'e', 'h', 'l', 'l', 'l', 'o', 'o', 'r', 'w']
> ```

---

## 🔨 Practice Problem 4.1

Write a program that:
1. Takes the string `s = "  the quick brown fox jumps over the lazy dog  "`.
2. Strips whitespace, converts to title case, and prints it.
3. Counts the total number of characters (after stripping) and prints it.
4. Replaces `"Fox"` (after title-casing) with `"Cat"`.
5. Splits the resulting string into a list of words and prints the list.
6. Joins the words back with `" | "` as the separator and prints it.
7. Uses an f-string to print: `"The sentence has X words and Y characters."` where X and Y are computed values.

---

## Chapter 5: Control Flow

### 5.1 The `if` / `elif` / `else` Statement

Conditional logic is controlled by `if`, `elif` (else-if), and `else`. The condition is any expression that evaluates to a truth value. The colon `:` ends the condition, and the indented block that follows is the body.

```python
# if_elif_else.py
score = 78

if score >= 90:
    grade = "A"
    remark = "Excellent"
elif score >= 80:
    grade = "B"
    remark = "Good"
elif score >= 70:
    grade = "C"
    remark = "Satisfactory"
elif score >= 60:
    grade = "D"
    remark = "Needs Improvement"
else:
    grade = "F"
    remark = "Failing"

print(f"Score: {score}, Grade: {grade}, Remark: {remark}")
```

> **Expected Output:**
> ```
> Score: 78, Grade: C, Remark: Satisfactory
> ```

Python uses **indentation** to define blocks. The standard is **4 spaces** (never mix tabs and spaces). The interpreter will raise `IndentationError` if indentation is inconsistent.

### 5.2 One-Line `if` and the Conditional Expression (Ternary)

```python
# ternary.py
age = 20

# Standard if-else
if age >= 18:
    status = "adult"
else:
    status = "minor"
print(status)

# Ternary / conditional expression: value_if_true if condition else value_if_false
status = "adult" if age >= 18 else "minor"
print(status)

# Nested ternary (use sparingly — can reduce readability)
x = 5
label = "positive" if x > 0 else ("negative" if x < 0 else "zero")
print(label)
```

> **Expected Output:**
> ```
> adult
> adult
> positive
> ```

### 5.3 The `while` Loop

A `while` loop repeats its body as long as its condition is `True`. The condition is checked **before** each iteration.

```python
# while_loop.py
count = 1
while count <= 5:
    print(f"Count: {count}")
    count += 1
print("Done")

# Infinite loop with break
attempt = 0
while True:
    attempt += 1
    print(f"Attempt {attempt}")
    if attempt >= 3:
        print("Max attempts reached")
        break

# while-else: the else block runs if the loop ended normally (no break)
n = 10
divisor = 2
while divisor <= n // 2:
    if n % divisor == 0:
        print(f"{n} is not prime (divisible by {divisor})")
        break
    divisor += 1
else:
    print(f"{n} is prime")  # This runs because no break occurred? No—10 is not prime
```

> **Expected Output:**
> ```
> Count: 1
> Count: 2
> Count: 3
> Count: 4
> Count: 5
> Done
> Attempt 1
> Attempt 2
> Attempt 3
> Max attempts reached
> 10 is not prime (divisible by 2)
> ```

### 5.4 The `for` Loop

`for` iterates over any **iterable** — a sequence, range, string, list, tuple, dictionary, file, etc.

```python
# for_loop.py

# Iterating over a list
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)

# Iterating over a string
for char in "Python":
    print(char, end=" ")
print()  # newline after the loop

# Iterating over a range
for i in range(5):         # 0, 1, 2, 3, 4
    print(i, end=" ")
print()

for i in range(2, 10, 2): # 2, 4, 6, 8 (start, stop, step)
    print(i, end=" ")
print()

for i in range(10, 0, -2):# 10, 8, 6, 4, 2 (counting down)
    print(i, end=" ")
print()
```

> **Expected Output:**
> ```
> apple
> banana
> cherry
> P y t h o n 
> 0 1 2 3 4 
> 2 4 6 8 
> 10 8 6 4 2 
> ```

### 5.5 The `range()` Function

`range(stop)`, `range(start, stop)`, and `range(start, stop, step)` produce sequences of integers on demand (lazily). They are **not** lists — they are range objects that generate numbers one at a time.

```python
# range_demo.py
r = range(5)
print(r)             # range(0, 5)
print(type(r))       # <class 'range'>
print(list(r))       # [0, 1, 2, 3, 4]
print(len(r))        # 5
print(4 in r)        # True
print(5 in r)        # False
print(r[2])          # 2 (supports indexing)

# Reversed range
for i in range(5, 0, -1):
    print(i, end=" ")
print()

# All even numbers from 0 to 18
evens = list(range(0, 20, 2))
print(evens)
```

> **Expected Output:**
> ```
> range(0, 5)
> <class 'range'>
> [0, 1, 2, 3, 4]
> 5
> True
> False
> 2
> 5 4 3 2 1 
> [0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
> ```

### 5.6 `break`, `continue`, and `pass`

```python
# loop_control.py

# break: exits the loop immediately
print("--- break ---")
for i in range(10):
    if i == 5:
        break
    print(i, end=" ")
print()

# continue: skips the rest of the current iteration
print("--- continue ---")
for i in range(10):
    if i % 2 == 0:
        continue  # skip even numbers
    print(i, end=" ")
print()

# pass: a no-op placeholder (does nothing)
# Useful when a block is syntactically required but you have nothing to do yet
print("--- pass ---")
for i in range(5):
    if i == 3:
        pass    # placeholder; will add logic later
    print(i, end=" ")
print()
```

> **Expected Output:**
> ```
> --- break ---
> 0 1 2 3 4 
> --- continue ---
> 1 3 5 7 9 
> --- pass ---
> 0 1 2 3 4 
> ```

### 5.7 `for`-`else` and `while`-`else`

Python's `for` and `while` loops support an `else` clause. The `else` block runs **only if the loop completed without hitting a `break`**. This is useful for "search and report" patterns.

```python
# loop_else.py

# Search for a prime number
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            print(f"  {n} is divisible by {i}")
            break
    else:
        # Loop ended without a break → no divisor found → prime
        print(f"  {n} is prime")
        return True
    return False

for num in [7, 15, 11, 4]:
    is_prime(num)
```

> **Expected Output:**
> ```
>   7 is prime
>   15 is divisible by 3
>   11 is prime
>   4 is divisible by 2
> ```

### 5.8 Nested Loops

```python
# nested_loops.py

# Multiplication table
for i in range(1, 4):
    for j in range(1, 4):
        print(f"{i}×{j}={i*j}", end="  ")
    print()  # newline after each row

# Triangle pattern
n = 5
for i in range(1, n + 1):
    print("*" * i)
```

> **Expected Output:**
> ```
> 1×1=1  1×2=2  1×3=3  
> 2×1=2  2×2=4  2×3=6  
> 3×1=3  3×2=6  3×3=9  
> *
> **
> ***
> ****
> *****
> ```

### 5.9 The `match` Statement (Structural Pattern Matching) — Python 3.10+

`match` is Python's modern alternative to long `if-elif` chains for pattern-based dispatching. It supports **structural patterns**, not just value equality.

```python
# match_statement.py
def describe_point(point):
    match point:
        case (0, 0):
            print("Origin")
        case (x, 0):
            print(f"On the X-axis at x={x}")
        case (0, y):
            print(f"On the Y-axis at y={y}")
        case (x, y):
            print(f"Point at ({x}, {y})")

describe_point((0, 0))
describe_point((5, 0))
describe_point((0, 3))
describe_point((2, 7))

# Matching with guards
def classify(n):
    match n:
        case n if n < 0:
            return "negative"
        case 0:
            return "zero"
        case n if n % 2 == 0:
            return "positive even"
        case _:
            return "positive odd"

for val in [-3, 0, 4, 7]:
    print(f"{val}: {classify(val)}")
```

> **Expected Output:**
> ```
> Origin
> On the X-axis at x=5
> On the Y-axis at y=3
> Point at (2, 7)
> -3: negative
> 0: zero
> 4: positive even
> 7: positive odd
> ```

---

## 🔨 Practice Problem 5.1

Write a program that:
1. Uses a `while` loop to implement a **number guessing game** (hardcode the secret number as `42`). In each iteration, generate a guess as `(attempt * 13) % 100` starting from `attempt = 1`. Print each guess and whether it's too low, too high, or correct. Stop when the correct number is found. Use `while-else` to print `"Never guessed"` if it somehow never found it.
2. Uses a `for` loop over `range(1, 101)` to find and print all numbers that are divisible by both 3 and 7.
3. Prints a **right triangle** of numbers: row 1 has `1`, row 2 has `1 2`, row 3 has `1 2 3`, etc., up to row 6.

---

## Chapter 6: Functions

### 6.1 Defining and Calling Functions

A **function** is a reusable, named block of code. Define with `def`, call by name followed by parentheses.

```python
# functions_basic.py

def greet():
    """Print a greeting message."""
    print("Hello from a function!")

def greet_person(name):
    """Greet a specific person."""
    print(f"Hello, {name}!")

def add(a, b):
    """Return the sum of a and b."""
    return a + b

# Calling functions
greet()
greet_person("Alice")
result = add(3, 7)
print(f"3 + 7 = {result}")

# Functions can return multiple values (as a tuple)
def min_max(numbers):
    return min(numbers), max(numbers)

lo, hi = min_max([5, 2, 8, 1, 9])
print(f"Min: {lo}, Max: {hi}")
```

> **Expected Output:**
> ```
> Hello from a function!
> Hello, Alice!
> 3 + 7 = 10
> Min: 1, Max: 9
> ```

### 6.2 Docstrings

A **docstring** is a string literal as the first statement of a function (or class, or module). It documents what the function does. Access it with `help(func)` or `func.__doc__`.

```python
# docstrings.py
def calculate_area(radius):
    """
    Calculate the area of a circle.

    Args:
        radius (float): The radius of the circle. Must be non-negative.

    Returns:
        float: The area of the circle.

    Raises:
        ValueError: If radius is negative.
    """
    import math
    if radius < 0:
        raise ValueError("Radius cannot be negative")
    return math.pi * radius ** 2

print(calculate_area(5))
print(calculate_area.__doc__[:50])  # First 50 chars of docstring
```

> **Expected Output:**
> ```
> 78.53981633974483
> 
>     Calculate the area of a circle.

>     Args:
> ```

### 6.3 Default Parameter Values

Parameters can have default values, making them optional when calling the function.

```python
# default_params.py
def power(base, exponent=2):
    """Return base raised to exponent. Default exponent is 2."""
    return base ** exponent

print(power(3))       # 3^2 = 9
print(power(3, 3))    # 3^3 = 27
print(power(2, 10))   # 2^10 = 1024

def create_profile(name, age, city="Unknown", is_active=True):
    print(f"Name: {name}, Age: {age}, City: {city}, Active: {is_active}")

create_profile("Alice", 30)
create_profile("Bob", 25, "Paris")
create_profile("Charlie", 35, is_active=False)
```

> **Expected Output:**
> ```
> 9
> 27
> 1024
> Name: Alice, Age: 30, City: Unknown, Active: True
> Name: Bob, Age: 25, City: Paris, Active: True
> Name: Charlie, Age: 35, City: Unknown, Active: False
> ```

**Important — mutable default argument pitfall:** Never use a mutable object (list, dict) as a default value. Use `None` and create the mutable object inside the function:

```python
# mutable_default_bug.py

# WRONG — the list is shared across all calls!
def append_wrong(item, lst=[]):
    lst.append(item)
    return lst

print(append_wrong(1))  # [1]
print(append_wrong(2))  # [1, 2] — Bug! Shared list persists

# CORRECT
def append_correct(item, lst=None):
    if lst is None:
        lst = []
    lst.append(item)
    return lst

print(append_correct(1))  # [1]
print(append_correct(2))  # [2] — Correct! New list each time
```

> **Expected Output:**
> ```
> [1]
> [1, 2]
> [1]
> [2]
> ```

### 6.4 Keyword Arguments

When calling a function, you can name the arguments to pass them in any order.

```python
# keyword_args.py
def describe_book(title, author, year, genre="Fiction"):
    print(f'"{title}" by {author} ({year}) — {genre}')

# Positional
describe_book("1984", "Orwell", 1949)

# Keyword — order doesn't matter
describe_book(author="Huxley", title="Brave New World", year=1932, genre="Dystopian")

# Mix: positional first, then keyword
describe_book("Dune", "Herbert", year=1965, genre="Sci-Fi")
```

> **Expected Output:**
> ```
> "1984" by Orwell (1949) — Fiction
> "Brave New World" by Huxley (1932) — Dystopian
> "Dune" by Herbert (1965) — Sci-Fi
> ```

### 6.5 `*args` — Variable Positional Arguments

`*args` collects any number of positional arguments into a **tuple**.

```python
# args_demo.py
def sum_all(*args):
    """Sum any number of arguments."""
    print(f"args = {args}, type = {type(args)}")
    total = 0
    for n in args:
        total += n
    return total

print(sum_all(1, 2, 3))
print(sum_all(10, 20, 30, 40, 50))
print(sum_all())  # Zero arguments

# Mixing regular params with *args
def greet_many(greeting, *names):
    for name in names:
        print(f"{greeting}, {name}!")

greet_many("Hello", "Alice", "Bob", "Charlie")
```

> **Expected Output:**
> ```
> args = (1, 2, 3), type = <class 'tuple'>
> 6
> args = (10, 20, 30, 40, 50), type = <class 'tuple'>
> 150
> args = (), type = <class 'tuple'>
> 0
> Hello, Alice!
> Hello, Bob!
> Hello, Charlie!
> ```

### 6.6 `**kwargs` — Variable Keyword Arguments

`**kwargs` collects any number of keyword arguments into a **dict**.

```python
# kwargs_demo.py
def print_info(**kwargs):
    """Print key-value pairs."""
    print(f"kwargs = {kwargs}, type = {type(kwargs)}")
    for key, value in kwargs.items():
        print(f"  {key}: {value}")

print_info(name="Alice", age=30, city="Paris")
print()
print_info(language="Python", version=3.12)

# Combining all parameter types
def full_example(a, b, *args, key1="default", **kwargs):
    print(f"a={a}, b={b}")
    print(f"args={args}")
    print(f"key1={key1}")
    print(f"kwargs={kwargs}")

full_example(1, 2, 3, 4, 5, key1="custom", x=10, y=20)
```

> **Expected Output:**
> ```
> kwargs = {'name': 'Alice', 'age': 30, 'city': 'Paris'}, type = <class 'dict'>
>   name: Alice
>   age: 30
>   city: Paris
> 
> kwargs = {'language': 'Python', 'version': 3.12}, type = <class 'dict'>
> a=1, b=2
> args=(3, 4, 5)
> key1=custom
> kwargs={'x': 10, 'y': 20}
> ```

### 6.7 Unpacking Arguments with `*` and `**`

You can unpack a list/tuple as positional arguments with `*`, and a dict as keyword arguments with `**`:

```python
# unpacking_call.py
def add(a, b, c):
    return a + b + c

nums = [1, 2, 3]
print(add(*nums))          # Unpacks list as positional args

d = {"a": 10, "b": 20, "c": 30}
print(add(**d))            # Unpacks dict as keyword args

# Combining
def print_range(start, stop, step=1):
    print(list(range(start, stop, step)))

args = (1, 20)
kwargs = {"step": 3}
print_range(*args, **kwargs)
```

> **Expected Output:**
> ```
> 6
> 60
> [1, 4, 7, 10, 13, 16, 19]
> ```

### 6.8 Return Values

A function can return any object, including `None` (implicitly or explicitly), multiple values, or complex structures.

```python
# return_values.py
def divide(a, b):
    """Return quotient and remainder, or None if b is zero."""
    if b == 0:
        return None   # Explicit None return
    return a // b, a % b  # Returns a tuple

result = divide(17, 5)
if result is not None:
    q, r = result
    print(f"17 ÷ 5 = {q} remainder {r}")

result = divide(10, 0)
print(result)   # None

# Early return for guard clauses
def process(x):
    if x < 0:
        return "negative — skipping"
    if x == 0:
        return "zero"
    return f"processed: {x * 2}"

for val in [-1, 0, 5]:
    print(process(val))
```

> **Expected Output:**
> ```
> 17 ÷ 5 = 3 remainder 2
> None
> negative — skipping
> zero
> processed: 10
> ```

### 6.9 Variable Scope: LEGB Rule

Python resolves names using the **LEGB** rule: **L**ocal → **E**nclosing → **G**lobal → **B**uilt-in.

```python
# scope.py
x = "global"           # Global scope

def outer():
    x = "enclosing"    # Enclosing scope (for inner)

    def inner():
        x = "local"    # Local scope (for inner)
        print(f"inner sees: {x}")

    inner()
    print(f"outer sees: {x}")

outer()
print(f"module sees: {x}")

# Accessing global inside a function
counter = 0

def increment():
    global counter      # Declare intent to modify the global
    counter += 1

increment()
increment()
print(counter)   # 2

# nonlocal for enclosing scope
def make_counter():
    count = 0
    def increment():
        nonlocal count  # Modify enclosing variable
        count += 1
        return count
    return increment

cnt = make_counter()
print(cnt(), cnt(), cnt())  # 1 2 3
```

> **Expected Output:**
> ```
> inner sees: local
> outer sees: enclosing
> module sees: global
> 2
> 1 2 3
> ```

### 6.10 Lambda Functions

**Lambda** creates an anonymous, single-expression function. Use for short functions passed as arguments — not for complex logic.

```python
# lambda_demo.py
square = lambda x: x ** 2
print(square(5))    # 25

add = lambda a, b: a + b
print(add(3, 4))    # 7

# Most common use: as argument to higher-order functions
numbers = [5, 2, 8, 1, 9, 3]

sorted_nums = sorted(numbers)
print(sorted_nums)

sorted_desc = sorted(numbers, key=lambda x: -x)
print(sorted_desc)

words = ["banana", "apple", "cherry", "date"]
sorted_by_len = sorted(words, key=lambda w: len(w))
print(sorted_by_len)

# With map and filter
squares = list(map(lambda x: x**2, range(1, 6)))
print(squares)

evens = list(filter(lambda x: x % 2 == 0, range(1, 11)))
print(evens)
```

> **Expected Output:**
> ```
> 25
> 7
> [1, 2, 3, 5, 8, 9]
> [9, 8, 5, 3, 2, 1]
> ['date', 'apple', 'banana', 'cherry']
> [1, 4, 9, 16, 25]
> [2, 4, 6, 8, 10]
> ```

### 6.11 Recursion

A function that calls itself is **recursive**. Every recursive function needs a **base case** (to stop recursion) and a **recursive case** (to progress toward the base case).

```python
# recursion.py
def factorial(n):
    """Compute n! recursively."""
    if n == 0 or n == 1:  # Base case
        return 1
    return n * factorial(n - 1)  # Recursive case

for i in range(8):
    print(f"{i}! = {factorial(i)}")

# Fibonacci (naive recursion — exponential time)
def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)

print([fib(i) for i in range(10)])

# Python has a recursion limit (default 1000)
import sys
print(sys.getrecursionlimit())  # 1000
```

> **Expected Output:**
> ```
> 0! = 1
> 1! = 1
> 2! = 2
> 3! = 6
> 4! = 24
> 5! = 120
> 6! = 720
> 7! = 5040
> [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
> 1000
> ```

**Python's recursion limit** is 1000 by default. Deep recursion raises `RecursionError`. For large inputs, prefer **iterative** solutions or use `functools.lru_cache` to memoize recursive calls.

### 6.12 Higher-Order Functions

Functions that take functions as arguments or return functions are called **higher-order functions**.

```python
# higher_order.py
from functools import reduce

numbers = [1, 2, 3, 4, 5]

# map: apply function to each element → returns iterator
doubled = list(map(lambda x: x * 2, numbers))
print(doubled)

# filter: keep elements where function returns True → returns iterator
odds = list(filter(lambda x: x % 2 != 0, numbers))
print(odds)

# reduce: reduce to a single value by applying function cumulatively
total = reduce(lambda acc, x: acc + x, numbers)
print(total)  # 1+2+3+4+5 = 15

product = reduce(lambda acc, x: acc * x, numbers)
print(product)  # 1*2*3*4*5 = 120

# Function that returns a function
def multiplier(factor):
    def multiply(x):
        return x * factor
    return multiply

double = multiplier(2)
triple = multiplier(3)
print(double(5))   # 10
print(triple(5))   # 15
```

> **Expected Output:**
> ```
> [2, 4, 6, 8, 10]
> [1, 3, 5]
> 15
> 120
> 10
> 15
> ```

---

## 🔨 Practice Problem 6.1

Write the following functions and test each one:

1. `celsius_to_fahrenheit(c)` — converts Celsius to Fahrenheit.
2. `is_palindrome(s)` — returns `True` if string `s` is the same forwards and backwards (ignore case and spaces).
3. `count_vowels(s)` — returns the count of vowels in string `s`.
4. `flatten(*args)` — accepts any number of lists as positional arguments and returns a single flattened list. E.g., `flatten([1,2], [3,4], [5])` → `[1,2,3,4,5]`.
5. `make_adder(n)` — returns a function that adds `n` to its argument. Demonstrate: `add5 = make_adder(5); print(add5(10))` should print `15`.

---

---

## Chapter 7: Lists

### 7.1 What Is a List?

A **list** is Python's most versatile built-in data structure. It is an **ordered, mutable, heterogeneous sequence** — ordered means elements have a fixed position; mutable means you can change elements after creation; heterogeneous means a single list can hold items of different types (though in practice, lists usually hold items of the same type for clarity).

Lists are defined with square brackets and comma-separated values:

```python
# lists_intro.py
empty = []
numbers = [1, 2, 3, 4, 5]
mixed   = [42, "hello", 3.14, True, None]
nested  = [[1, 2], [3, 4], [5, 6]]

print(empty)
print(numbers)
print(mixed)
print(nested)
print(type(numbers))
print(len(numbers))   # Number of elements
```

> **Expected Output:**
> ```
> []
> [1, 2, 3, 4, 5]
> [42, 'hello', 3.14, True, None]
> [[1, 2], [3, 4], [5, 6]]
> <class 'list'>
> 5
> ```

### 7.2 Indexing and Slicing

Lists share the same indexing and slicing rules as strings: zero-based, supports negative indices, slicing never raises `IndexError`.

```python
# list_indexing.py
fruits = ["apple", "banana", "cherry", "date", "elderberry"]

print(fruits[0])      # apple
print(fruits[-1])     # elderberry
print(fruits[1:4])    # ['banana', 'cherry', 'date']
print(fruits[::-1])   # reversed list
print(fruits[::2])    # every second element

# Unlike strings, you can assign to slices and indices
fruits[1] = "blueberry"
print(fruits)         # 'banana' replaced

fruits[1:3] = ["kiwi", "mango", "papaya"]  # Slice assignment can change length!
print(fruits)
```

> **Expected Output:**
> ```
> apple
> elderberry
> ['banana', 'cherry', 'date']
> ['elderberry', 'date', 'cherry', 'banana', 'apple']
> ['apple', 'cherry', 'elderberry']
> ['apple', 'blueberry', 'cherry', 'date', 'elderberry']
> ['apple', 'kiwi', 'mango', 'papaya', 'date', 'elderberry']
> ```

**Key difference from strings:** Lists are **mutable**. You can assign to any index or slice without creating a new list.

### 7.3 Common List Methods

All list methods operate **in place** (they mutate the list) unless otherwise noted.

```python
# list_methods.py
lst = [3, 1, 4, 1, 5, 9, 2, 6]

# append: add one item to the end
lst.append(5)
print("append:", lst)

# insert: add one item at a specific index
lst.insert(0, 99)
print("insert:", lst)

# extend: add all items from another iterable
lst.extend([10, 11])
print("extend:", lst)

# remove: remove first occurrence of a value
lst.remove(1)
print("remove first 1:", lst)

# pop: remove and return item at index (default: last)
last = lst.pop()
print(f"pop: removed {last}, list is now {lst}")

item = lst.pop(0)
print(f"pop(0): removed {item}, list is now {lst}")

# index: find index of first occurrence
print("index of 9:", lst.index(9))

# count: count occurrences
print("count of 1:", lst.count(1))

# sort: sort in place (ascending by default)
lst.sort()
print("sort:", lst)

lst.sort(reverse=True)
print("sort desc:", lst)

# reverse: reverse in place
lst.reverse()
print("reverse:", lst)

# clear: remove all elements
copy_lst = lst.copy()  # shallow copy
copy_lst.clear()
print("cleared copy:", copy_lst)
print("original intact:", lst)
```

> **Expected Output:**
> ```
> append: [3, 1, 4, 1, 5, 9, 2, 6, 5]
> insert: [99, 3, 1, 4, 1, 5, 9, 2, 6, 5]
> extend: [99, 3, 1, 4, 1, 5, 9, 2, 6, 5, 10, 11]
> remove first 1: [99, 3, 4, 1, 5, 9, 2, 6, 5, 10, 11]
> pop: removed 11, list is now [99, 3, 4, 1, 5, 9, 2, 6, 5, 10]
> pop(0): removed 99, list is now [3, 4, 1, 5, 9, 2, 6, 5, 10]
> index of 9: 4
> count of 1: 1
> sort: [1, 2, 3, 4, 5, 5, 6, 9, 10]
> sort desc: [10, 9, 6, 5, 5, 4, 3, 2, 1]
> reverse: [1, 2, 3, 4, 5, 5, 6, 9, 10]
> cleared copy: []
> original intact: [1, 2, 3, 4, 5, 5, 6, 9, 10]
> ```

### 7.4 Useful Built-in Functions on Lists

```python
# list_builtins.py
nums = [4, 2, 9, 1, 7, 3]

print(len(nums))        # 6 — number of elements
print(min(nums))        # 1 — smallest element
print(max(nums))        # 9 — largest element
print(sum(nums))        # 26 — sum of all elements
print(sorted(nums))     # [1, 2, 3, 4, 7, 9] — NEW sorted list (does not modify nums)
print(nums)             # [4, 2, 9, 1, 7, 3] — original unchanged

# reversed() returns an iterator; wrap in list() to see it
print(list(reversed(nums)))  # [3, 7, 1, 9, 2, 4]

# enumerate: iterate with index
for i, val in enumerate(nums):
    print(f"  index {i}: {val}")

# zip: pair elements from two lists
letters = ["a", "b", "c"]
numbers = [1, 2, 3]
for letter, number in zip(letters, numbers):
    print(f"  {letter} → {number}")
```

> **Expected Output:**
> ```
> 6
> 1
> 9
> 26
> [1, 2, 3, 4, 7, 9]
> [4, 2, 9, 1, 7, 3]
> [3, 7, 1, 9, 2, 4]
>   index 0: 4
>   index 1: 2
>   index 2: 9
>   index 3: 1
>   index 4: 7
>   index 5: 3
>   a → 1
>   b → 2
>   c → 3
> ```

### 7.5 Copying Lists — Shallow vs. Deep

**This is one of the most common sources of bugs for beginners.** A simple assignment (`b = a`) does not copy a list — it creates a second name that points to the **same** list object.

```python
# list_copying.py
import copy

# Assignment — NOT a copy!
a = [1, 2, 3]
b = a            # b and a point to the same list
b.append(4)
print("a:", a)   # [1, 2, 3, 4] — a is also modified!
print("b:", b)   # [1, 2, 3, 4]

# Shallow copy — creates a new list, but nested objects are still shared
original = [[1, 2], [3, 4]]
shallow  = original.copy()        # or original[:] or list(original)

shallow.append([5, 6])            # Modifies only shallow
original[0].append(99)            # Modifies nested object — BOTH see it!

print("original:", original)      # [[1, 2, 99], [3, 4]]
print("shallow: ", shallow)       # [[1, 2, 99], [3, 4], [5, 6]]

# Deep copy — fully independent at all levels
original2 = [[1, 2], [3, 4]]
deep = copy.deepcopy(original2)
original2[0].append(99)

print("original2:", original2)    # [[1, 2, 99], [3, 4]]
print("deep:     ", deep)         # [[1, 2], [3, 4]] — fully independent
```

> **Expected Output:**
> ```
> a: [1, 2, 3, 4]
> b: [1, 2, 3, 4]
> original: [[1, 2, 99], [3, 4]]
> shallow:  [[1, 2, 99], [3, 4], [5, 6]]
> original2: [[1, 2, 99], [3, 4]]
> deep:      [[1, 2], [3, 4]]
> ```

**Rule of thumb:** Use `.copy()` for flat lists. Use `copy.deepcopy()` when the list contains mutable objects (other lists, dicts, etc.).

### 7.6 Sorting with a Key Function

The `sort()` method and `sorted()` function both accept a `key` argument — a function applied to each element to determine sort order.

```python
# list_sort_key.py
words = ["banana", "apple", "Cherry", "date", "Elderberry"]

# Default sort (lexicographic, uppercase before lowercase)
print(sorted(words))

# Case-insensitive sort
print(sorted(words, key=str.lower))

# Sort by string length
print(sorted(words, key=len))

# Sort by last character
print(sorted(words, key=lambda w: w[-1]))

# Sort list of dicts by a field
people = [
    {"name": "Alice", "age": 30},
    {"name": "Bob",   "age": 25},
    {"name": "Carol", "age": 35},
]
people.sort(key=lambda p: p["age"])
for p in people:
    print(f"  {p['name']}: {p['age']}")
```

> **Expected Output:**
> ```
> ['Cherry', 'Elderberry', 'apple', 'banana', 'date']
> ['apple', 'banana', 'Cherry', 'date', 'Elderberry']
> ['apple', 'date', 'banana', 'Cherry', 'Elderberry']
> ['banana', 'apple', 'date', 'Elderberry', 'Cherry']
>   Bob: 25
>   Alice: 30
>   Carol: 35
> ```

---

## 🔨 Practice Problem 7.1

Write a program that:

1. Creates a list of 10 integers: `[5, 3, 8, 1, 9, 2, 7, 4, 6, 10]`.
2. Prints the list sorted in ascending and descending order **without** modifying the original.
3. Removes all even numbers from the list **in place** using a `while` loop (do not use list comprehensions yet).
4. Creates a list of five student tuples `(name, grade)` and sorts it first by grade descending, then alphabetically by name for ties.
5. Demonstrates the shallow-copy bug: make a shallow copy of `[[10, 20], [30, 40]]`, mutate an inner list, and show that the original is also affected.

---

## Chapter 8: Tuples

### 8.1 What Is a Tuple?

A **tuple** is an **ordered, immutable sequence**. It looks like a list but uses parentheses instead of square brackets. Because tuples are immutable, they are hashable (can be used as dictionary keys and set members), slightly faster than lists, and semantically signal that their data should not change.

```python
# tuples_intro.py
empty   = ()
single  = (42,)       # Note the trailing comma — it makes it a tuple, not just (42)
coords  = (10.5, 20.3)
mixed   = (1, "two", 3.0, True)
nested  = ((1, 2), (3, 4))

print(empty, type(empty))
print(single, type(single))
print(coords)
print(mixed)
print(type(coords))

# Parentheses are often optional — comma creates the tuple
implicit = 1, 2, 3
print(implicit, type(implicit))

# Tuple unpacking
x, y = coords
print(f"x={x}, y={y}")
```

> **Expected Output:**
> ```
> () <class 'tuple'>
> (42,) <class 'tuple'>
> (10.5, 20.3)
> (1, 'two', 3.0, True)
> <class 'tuple'>
> (1, 2, 3) <class 'tuple'>
> x=10.5, y=20.3
> ```

**Critical:** `(42)` is just the integer `42` in parentheses. `(42,)` is a tuple. The **comma** is what makes a tuple, not the parentheses.

### 8.2 Tuple Indexing, Slicing, and Methods

Tuples support all the same read-only operations as lists. Because they are immutable, they have only two methods: `count()` and `index()`.

```python
# tuple_ops.py
t = (10, 20, 30, 20, 40, 20)

print(t[0])         # 10
print(t[-1])        # 20
print(t[1:4])       # (20, 30, 20)
print(t[::-1])      # (20, 40, 20, 30, 20, 10)

print(t.count(20))  # 3 — number of times 20 appears
print(t.index(30))  # 2 — index of first 30

# Attempting to mutate raises TypeError
try:
    t[0] = 99
except TypeError as e:
    print(f"Error: {e}")

# Tuple concatenation creates a NEW tuple
t2 = t + (50, 60)
print(t2)
```

> **Expected Output:**
> ```
> 10
> 20
> (20, 30, 20)
> (20, 40, 20, 30, 20, 10)
> 3
> 2
> Error: 'tuple' object does not support item assignment
> (10, 20, 30, 20, 40, 20, 50, 60)
> ```

### 8.3 When to Use Tuples vs. Lists

| Use **tuple** when... | Use **list** when... |
|---|---|
| Data is fixed (coordinates, RGB, DB row) | Data needs to grow/shrink |
| You need a hashable sequence (dict key, set member) | Order is meaningful but mutable |
| Returning multiple values from a function | Collecting results via `.append()` |
| Semantic emphasis: "this should not change" | Items are conceptually homogeneous |

```python
# tuples_as_keys.py

# Tuples can be dict keys (lists cannot — they are unhashable)
grid = {}
grid[(0, 0)] = "origin"
grid[(1, 0)] = "right"
grid[(0, 1)] = "up"
print(grid[(0, 0)])
print(grid[(1, 0)])

# Named tuples provide attribute access — best of both worlds
from collections import namedtuple

Point = namedtuple("Point", ["x", "y"])
p = Point(3, 4)
print(p.x, p.y)
print(p[0], p[1])     # Also supports indexing
print(p)

distance = (p.x**2 + p.y**2) ** 0.5
print(f"Distance from origin: {distance}")
```

> **Expected Output:**
> ```
> origin
> right
> 3 4
> 3 4
> Point(x=3, y=4)
> Distance from origin: 5.0
> ```

---

## 🔨 Practice Problem 8.1

Write a program that:

1. Creates a tuple representing a student record: `(name, age, gpa, enrolled)`. Unpack it into four separate variables and print each.
2. Attempts to modify the tuple and catches the resulting `TypeError`, printing a friendly error message.
3. Creates a list of five `Point` namedtuples (with `x` and `y` fields) and sorts the list by distance from the origin (computed as `sqrt(x² + y²)`), printing the sorted result.
4. Uses a tuple as a dictionary key to build a mapping of `(row, col)` → `cell_value` for a 3×3 grid, then prints the value at each position.

---

## Chapter 9: Dictionaries

### 9.1 What Is a Dictionary?

A **dictionary** (`dict`) is an **ordered** (Python 3.7+), **mutable**, **mapping** of unique **keys** to **values**. Keys must be **hashable** (immutable: strings, numbers, tuples). Values can be any object. Dictionaries are Python's go-to tool for structured data — think JSON objects, configuration tables, lookup maps, and counters.

```python
# dict_intro.py
empty = {}
phone_book = {"Alice": "555-1234", "Bob": "555-5678", "Carol": "555-9012"}
config = {
    "host": "localhost",
    "port": 5432,
    "debug": True,
    "tags": ["web", "api"]
}

print(empty, type(empty))
print(phone_book)
print(config["host"])
print(config["port"])
print(len(phone_book))
```

> **Expected Output:**
> ```
> {} <class 'dict'>
> {'Alice': '555-1234', 'Bob': '555-5678', 'Carol': '555-9012'}
> localhost
> 5432
> 3
> ```

### 9.2 Accessing, Adding, and Modifying Entries

```python
# dict_access.py
d = {"name": "Alice", "age": 30}

# Access by key
print(d["name"])

# KeyError if key doesn't exist
try:
    print(d["city"])
except KeyError as e:
    print(f"KeyError: {e}")

# Safe access with .get() — returns None (or a default) if key is missing
print(d.get("city"))           # None
print(d.get("city", "Unknown")) # "Unknown"

# Add a new key
d["city"] = "Paris"
print(d)

# Modify an existing key
d["age"] = 31
print(d)

# Delete a key
del d["city"]
print(d)

# Remove and return a value with .pop()
age = d.pop("age")
print(f"Removed age: {age}, dict: {d}")

# .pop() with default — no KeyError if key missing
val = d.pop("missing_key", "default_value")
print(val)
```

> **Expected Output:**
> ```
> Alice
> KeyError: 'city'
> None
> Unknown
> {'name': 'Alice', 'age': 30, 'city': 'Paris'}
> {'name': 'Alice', 'age': 31, 'city': 'Paris'}
> {'name': 'Alice', 'age': 31}
> Removed age: 31, dict: {'name': 'Alice'}
> default_value
> ```

### 9.3 Dictionary Methods

```python
# dict_methods.py
inventory = {"apples": 50, "bananas": 30, "cherries": 80, "dates": 20}

# .keys(), .values(), .items() — return view objects
print(inventory.keys())
print(inventory.values())
print(inventory.items())

# Iterate over keys
for fruit in inventory:
    print(f"  {fruit}")

# Iterate over values
for qty in inventory.values():
    print(qty, end=" ")
print()

# Iterate over key-value pairs
for fruit, qty in inventory.items():
    print(f"  {fruit}: {qty}")

# .update(): merge another dict in (overwrites on conflict)
extras = {"elderberries": 15, "apples": 60}  # apples already exists
inventory.update(extras)
print(inventory)

# .setdefault(): get value if key exists, else insert key with default
inventory.setdefault("figs", 0)
print(inventory)

# dict.fromkeys(): create dict from keys with a default value
keys = ["x", "y", "z"]
zeroed = dict.fromkeys(keys, 0)
print(zeroed)
```

> **Expected Output:**
> ```
> dict_keys(['apples', 'bananas', 'cherries', 'dates'])
> dict_values([50, 30, 80, 20])
> dict_items([('apples', 50), ('bananas', 30), ('cherries', 80), ('dates', 20)])
>   apples
>   bananas
>   cherries
>   dates
> 50 30 80 20 
>   apples: 50
>   bananas: 30
>   cherries: 80
>   dates: 20
> {'apples': 60, 'bananas': 30, 'cherries': 80, 'dates': 20, 'elderberries': 15}
> {'apples': 60, 'bananas': 30, 'cherries': 80, 'dates': 20, 'elderberries': 15, 'figs': 0}
> {'x': 0, 'y': 0, 'z': 0}
> ```

### 9.4 Merging Dictionaries — The `|` Operator (Python 3.9+)

```python
# dict_merge.py
defaults = {"color": "blue", "size": "medium", "weight": 1.0}
overrides = {"color": "red", "weight": 2.5}

# | creates a new merged dict; values from the right operand win
merged = defaults | overrides
print(merged)

# |= updates in place
defaults |= overrides
print(defaults)

# Equivalent to dict(**a, **b) — also creates a new dict
combined = {**defaults, **overrides}
print(combined)
```

> **Expected Output:**
> ```
> {'color': 'red', 'size': 'medium', 'weight': 2.5}
> {'color': 'red', 'size': 'medium', 'weight': 2.5}
> {'color': 'red', 'size': 'medium', 'weight': 2.5}
> ```

### 9.5 The `collections.Counter` and `collections.defaultdict`

The `collections` module provides powerful dictionary subclasses:

```python
# collections_demo.py
from collections import Counter, defaultdict

# Counter: counts hashable objects
text = "mississippi"
c = Counter(text)
print(c)
print(c.most_common(3))  # 3 most common characters

words = ["apple", "banana", "apple", "cherry", "banana", "apple"]
wc = Counter(words)
print(wc)
print(wc["apple"])   # 3

# Counter supports arithmetic
c1 = Counter(a=3, b=1)
c2 = Counter(a=1, b=2)
print(c1 + c2)   # Counter({'a': 4, 'b': 3})
print(c1 - c2)   # Counter({'a': 2}) — negatives dropped

# defaultdict: missing keys automatically get a default value
dd = defaultdict(int)   # default is int() → 0
for word in ["apple", "banana", "apple", "cherry"]:
    dd[word] += 1       # No KeyError — missing key defaults to 0
print(dict(dd))

# defaultdict with list
groups = defaultdict(list)
for name, dept in [("Alice", "Eng"), ("Bob", "HR"), ("Carol", "Eng")]:
    groups[dept].append(name)
print(dict(groups))
```

> **Expected Output:**
> ```
> Counter({'s': 4, 'i': 4, 'p': 2, 'm': 1})
> [('s', 4), ('i', 4), ('p', 2)]
> Counter({'apple': 3, 'banana': 2, 'cherry': 1})
> 3
> Counter({'a': 4, 'b': 3})
> Counter({'a': 2})
> {'apple': 2, 'banana': 1, 'cherry': 1}
> {'Eng': ['Alice', 'Carol'], 'HR': ['Bob']}
> ```

---

## 🔨 Practice Problem 9.1

Write a program that:

1. Given the string `"the cat sat on the mat"`, use a `Counter` to find the three most common words.
2. Builds a word-frequency dictionary **manually** using a plain `dict` (no `Counter`), with `.get()` and a `for` loop.
3. Inverts a dictionary (swap keys and values) — assume values are unique. For example, `{"a": 1, "b": 2}` → `{1: "a", 2: "b"}`.
4. Given a list of student records as dicts `[{"name": ..., "grade": ...}]`, group students by grade into a `defaultdict(list)`, then print each grade's roster.

---

## Chapter 10: Sets

### 10.1 What Is a Set?

A **set** is an **unordered, mutable collection of unique, hashable elements**. It is backed by a hash table, making membership testing (`in`) an O(1) operation. Sets are ideal for deduplication and mathematical set operations.

```python
# sets_intro.py
empty_set = set()        # NOTE: {} creates a dict, not a set!
nums = {1, 2, 3, 4, 5}
with_dupes = {1, 2, 2, 3, 3, 3, 4}

print(empty_set, type(empty_set))
print(nums)
print(with_dupes)        # Duplicates automatically removed
print(len(with_dupes))   # 4

# Create from any iterable (great for deduplication)
deduped = set([10, 20, 10, 30, 20, 40])
print(deduped)

text = "mississippi"
unique_chars = set(text)
print(unique_chars)
```

> **Expected Output:**
> ```
> set() <class 'set'>
> {1, 2, 3, 4, 5}
> {1, 2, 3, 4}
> 4
> {40, 10, 20, 30}
> {'m', 'i', 's', 'p'}
> ```

*Note: Set output order is not guaranteed — you may see elements in any order.*

### 10.2 Set Operations

```python
# set_ops.py
a = {1, 2, 3, 4, 5}
b = {3, 4, 5, 6, 7}

print(a | b)     # Union: all elements in a or b
print(a & b)     # Intersection: elements in both a and b
print(a - b)     # Difference: elements in a but not b
print(b - a)     # Difference: elements in b but not a
print(a ^ b)     # Symmetric difference: in one but not both

# In-place versions
a |= {8, 9}
print(a)

# Subset and superset tests
x = {1, 2}
y = {1, 2, 3, 4}
print(x.issubset(y))     # True — all of x is in y
print(y.issuperset(x))   # True
print(x.isdisjoint({5, 6, 7}))  # True — no common elements
```

> **Expected Output:**
> ```
> {1, 2, 3, 4, 5, 6, 7}
> {3, 4, 5}
> {1, 2}
> {6, 7}
> {1, 2, 6, 7}
> {1, 2, 3, 4, 5, 8, 9}
> True
> True
> True
> ```

### 10.3 Set Methods

```python
# set_methods.py
s = {10, 20, 30}

s.add(40)
print("add:", s)

s.add(20)      # Adding a duplicate is a no-op
print("add dup:", s)

s.discard(99)  # discard: remove if present, no error if absent
print("discard 99:", s)

try:
    s.remove(99)   # remove: raises KeyError if absent
except KeyError:
    print("remove raised KeyError")

popped = s.pop()   # Remove and return an arbitrary element
print(f"popped: {popped}, remaining: {s}")

s2 = s.copy()
s2.clear()
print("cleared:", s2)
print("original:", s)
```

> **Expected Output:**
> ```
> add: {40, 10, 20, 30}
> add dup: {40, 10, 20, 30}
> discard 99: {40, 10, 20, 30}
> remove raised KeyError
> popped: 40, remaining: {10, 20, 30}
> cleared: set()
> original: {10, 20, 30}
> ```

### 10.4 `frozenset` — The Immutable Set

`frozenset` is the immutable version of `set`. Because it is hashable, it can be used as a dictionary key or stored inside another set.

```python
# frozenset_demo.py
fs = frozenset([1, 2, 3, 4])
print(fs)
print(type(fs))

# Can be used as a dict key
groups = {
    frozenset(["Alice", "Bob"]): "Team A",
    frozenset(["Carol", "Dave"]): "Team B"
}
print(groups[frozenset(["Alice", "Bob"])])

# frozenset supports all read-only set operations
a = frozenset({1, 2, 3})
b = frozenset({2, 3, 4})
print(a & b)   # intersection → frozenset({2, 3})
```

> **Expected Output:**
> ```
> frozenset({1, 2, 3, 4})
> <class 'frozenset'>
> Team A
> frozenset({2, 3})
> ```

---

## 🔨 Practice Problem 10.1

Write a program that:

1. Given two lists of integers (with duplicates in each), find their unique common elements using set intersection.
2. Given a list of words, return a new list with all duplicate words removed but with order preserved (hint: use a `set` to track seen words as you iterate).
3. Given a list of sentences (strings), count how many sentences share at least one word with a reference sentence (use set intersection on the split words).
4. Demonstrates that a `frozenset` can be stored inside a regular `set`, but a regular `set` cannot.

---

## Chapter 11: Comprehensions

### 11.1 List Comprehensions

A **list comprehension** is a concise, one-line way to construct a list. The general form is:

```
[expression for variable in iterable if condition]
```

The `if condition` part is optional. Think of it as: "for each item in the iterable, if the condition is true, evaluate the expression and collect the result."

```python
# list_comp.py

# Without comprehension
squares_loop = []
for x in range(1, 11):
    squares_loop.append(x ** 2)
print(squares_loop)

# With comprehension — same result, one line
squares_comp = [x ** 2 for x in range(1, 11)]
print(squares_comp)

# With a filter condition
even_squares = [x ** 2 for x in range(1, 11) if x % 2 == 0]
print(even_squares)

# Applying a function
words = ["hello", "world", "python", "rocks"]
upper_words = [w.upper() for w in words]
print(upper_words)

# Flattening a nested list
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
flat = [num for row in matrix for num in row]
print(flat)

# Conditional expression (ternary) inside comprehension
labels = ["even" if x % 2 == 0 else "odd" for x in range(1, 8)]
print(labels)
```

> **Expected Output:**
> ```
> [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
> [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
> [4, 16, 36, 64, 100]
> ['HELLO', 'WORLD', 'PYTHON', 'ROCKS']
> [1, 2, 3, 4, 5, 6, 7, 8, 9]
> ['odd', 'even', 'odd', 'even', 'odd', 'even', 'odd']
> ```

**When to use comprehensions:** They are ideal for straightforward transformations and filters. If the logic becomes deeply nested or complex, prefer an explicit `for` loop for readability.

### 11.2 Dictionary Comprehensions

Same syntax, but with `{key_expr: value_expr for ... if ...}`:

```python
# dict_comp.py

# Word-length mapping
words = ["apple", "banana", "cherry", "date"]
length_map = {word: len(word) for word in words}
print(length_map)

# Invert a dictionary
original = {"a": 1, "b": 2, "c": 3}
inverted = {v: k for k, v in original.items()}
print(inverted)

# Filter to only items meeting a condition
inventory = {"apples": 50, "bananas": 5, "cherries": 80, "dates": 3}
low_stock = {item: qty for item, qty in inventory.items() if qty < 10}
print(low_stock)

# Squaring numbers, creating a dict from range
squares = {n: n**2 for n in range(1, 6)}
print(squares)
```

> **Expected Output:**
> ```
> {'apple': 5, 'banana': 6, 'cherry': 6, 'date': 4}
> {1: 'a', 2: 'b', 3: 'c'}
> {'bananas': 5, 'dates': 3}
> {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}
> ```

### 11.3 Set Comprehensions

Same as list comprehensions but with `{}`:

```python
# set_comp.py
words = ["hello", "world", "hello", "python", "world"]

# Unique lengths
unique_lengths = {len(w) for w in words}
print(unique_lengths)

# Unique first letters
first_letters = {w[0] for w in words}
print(first_letters)

# Set of squares of even numbers 1-20
even_squares = {x**2 for x in range(1, 21) if x % 2 == 0}
print(even_squares)
```

> **Expected Output:**
> ```
> {5, 6}
> {'h', 'w', 'p'}
> {4, 16, 36, 64, 100, 144, 196, 256, 324, 400}
> ```

### 11.4 Generator Expressions

A **generator expression** looks like a list comprehension but uses `()`. Unlike a list comprehension (which builds the entire list in memory immediately), a generator expression produces values **lazily** — one at a time, on demand. This makes it much more memory-efficient for large datasets.

```python
# generator_expr.py
import sys

# List comprehension — builds entire list in memory
lst = [x**2 for x in range(1_000_000)]
print(f"List size: {sys.getsizeof(lst):,} bytes")

# Generator expression — tiny memory footprint
gen = (x**2 for x in range(1_000_000))
print(f"Generator size: {sys.getsizeof(gen)} bytes")

# You iterate over a generator the same way as a list
gen_small = (x**2 for x in range(5))
for val in gen_small:
    print(val, end=" ")
print()

# Generators are consumed — once exhausted, they cannot be re-iterated
gen2 = (x for x in range(3))
print(list(gen2))   # [0, 1, 2]
print(list(gen2))   # [] — already exhausted!

# Passing a generator directly to built-in functions (no extra parens needed)
total = sum(x**2 for x in range(1, 6))
print(total)   # 1 + 4 + 9 + 16 + 25 = 55
```

> **Expected Output:**
> ```
> List size: 8,448,728 bytes  (approximately)
> Generator size: 200 bytes   (approximately)
> 0 1 4 9 16 
> [0, 1, 2]
> []
> 55
> ```

---

## 🔨 Practice Problem 11.1

Write the following using comprehensions (no explicit `for` loops with `.append()`):

1. A list of all **Pythagorean triples** `(a, b, c)` where `a`, `b`, `c` are all ≤ 20 and `a² + b² = c²` (use a nested list comprehension with `a < b < c`).
2. A dictionary mapping each number from 1 to 10 to its cube.
3. A set of all unique vowels found in the sentence `"The quick brown fox jumps over the lazy dog"` (lowercase only).
4. Use a generator expression (not a list) to compute the sum of squares of all odd numbers from 1 to 999 — then verify with `sum()`.

---

## Chapter 12: File I/O

### 12.1 Opening and Reading Files

Python's built-in `open()` function opens a file and returns a **file object**. Always use the `with` statement (a context manager) — it guarantees the file is closed even if an exception occurs.

```python
# file_read.py
# First, create a sample file to read
with open("sample.txt", "w") as f:
    f.write("Line one\n")
    f.write("Line two\n")
    f.write("Line three\n")

# Read entire content as one string
with open("sample.txt", "r") as f:
    content = f.read()
    print(repr(content))

# Read line by line — memory-efficient for large files
with open("sample.txt", "r") as f:
    for line in f:
        print(line, end="")   # line already has '\n'

# Read all lines into a list
with open("sample.txt", "r") as f:
    lines = f.readlines()
print(lines)

# Read one line at a time with readline()
with open("sample.txt", "r") as f:
    first  = f.readline()
    second = f.readline()
print(f"First: {repr(first)}")
print(f"Second: {repr(second)}")
```

> **Expected Output:**
> ```
> 'Line one\nLine two\nLine three\n'
> Line one
> Line two
> Line three
> ['Line one\n', 'Line two\n', 'Line three\n']
> First: 'Line one\n'
> Second: 'Line two\n'
> ```

### 12.2 Writing and Appending to Files

```python
# file_write.py

# "w" mode: write (creates file, overwrites if it exists)
with open("output.txt", "w") as f:
    f.write("Hello, file!\n")
    f.write("Second line.\n")
    # writelines: write a list of strings (no auto newline)
    f.writelines(["Third line.\n", "Fourth line.\n"])

# "a" mode: append (adds to end, does not overwrite)
with open("output.txt", "a") as f:
    f.write("Fifth line (appended).\n")

with open("output.txt", "r") as f:
    print(f.read())
```

> **Expected Output:**
> ```
> Hello, file!
> Second line.
> Third line.
> Fourth line.
> Fifth line (appended).
> ```

### 12.3 File Modes

| Mode | Meaning |
|---|---|
| `"r"` | Read (default). File must exist. |
| `"w"` | Write. Creates or truncates. |
| `"a"` | Append. Creates if not exists. |
| `"x"` | Exclusive creation. Fails if file exists. |
| `"r+"` | Read and write. File must exist. |
| `"b"` | Binary mode (combine: `"rb"`, `"wb"`). |
| `"t"` | Text mode (default, combine: `"rt"`). |

```python
# binary_mode.py

# Write and read a binary file
data = bytes([72, 101, 108, 108, 111])  # "Hello" in ASCII bytes
with open("binary_file.bin", "wb") as f:
    f.write(data)

with open("binary_file.bin", "rb") as f:
    raw = f.read()
    print(raw)           # b'Hello'
    print(raw.decode())  # Hello
```

> **Expected Output:**
> ```
> b'Hello'
> Hello
> ```

### 12.4 Working with File Paths — The `pathlib` Module

`pathlib.Path` is the modern, object-oriented way to handle file system paths. It is more readable and cross-platform than string manipulation.

```python
# pathlib_demo.py
from pathlib import Path

# Create Path objects
p = Path("sample.txt")
home = Path.home()

print(p.name)        # sample.txt
print(p.stem)        # sample
print(p.suffix)      # .txt
print(p.is_file())   # True (if the file exists)
print(p.exists())    # True

# Build paths with /  operator (not string concatenation!)
data_dir = Path("data")
csv_file = data_dir / "report" / "results.csv"
print(csv_file)                # data/report/results.csv
print(csv_file.parent)         # data/report
print(csv_file.parent.parent)  # data

# Read and write text directly through Path
p.write_text("Hello from pathlib!\nLine 2.\n")
content = p.read_text()
print(content)

# List files in a directory
for item in Path(".").iterdir():
    print(item)
```

> **Expected Output:**
> ```
> sample.txt
> sample
> .txt
> True
> True
> data/report/results.csv
> data/report
> data
> Hello from pathlib!
> Line 2.
> (current directory contents)
> ```

### 12.5 Working with CSV Files

```python
# csv_demo.py
import csv

# Write CSV
rows = [
    ["Name", "Age", "City"],
    ["Alice", 30, "Paris"],
    ["Bob", 25, "Berlin"],
    ["Carol", 35, "Tokyo"],
]
with open("people.csv", "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerows(rows)

# Read CSV
with open("people.csv", "r") as f:
    reader = csv.reader(f)
    for row in reader:
        print(row)

print()

# DictReader — each row is an OrderedDict keyed by header
with open("people.csv", "r") as f:
    reader = csv.DictReader(f)
    for record in reader:
        print(f"  {record['Name']} lives in {record['City']}")
```

> **Expected Output:**
> ```
> ['Name', 'Age', 'City']
> ['Alice', '30', 'Paris']
> ['Bob', '25', 'Berlin']
> ['Carol', '35', 'Tokyo']
> 
>   Alice lives in Paris
>   Bob lives in Berlin
>   Carol lives in Tokyo
> ```

### 12.6 Working with JSON Files

```python
# json_demo.py
import json

data = {
    "name": "Alice",
    "age": 30,
    "languages": ["Python", "Rust", "Go"],
    "active": True,
    "score": None
}

# Serialize to JSON string
json_str = json.dumps(data, indent=2)
print(json_str)

# Write to file
with open("data.json", "w") as f:
    json.dump(data, f, indent=2)

# Read from file
with open("data.json", "r") as f:
    loaded = json.load(f)

print(type(loaded))
print(loaded["languages"])
print(loaded["active"])
```

> **Expected Output:**
> ```
> {
>   "name": "Alice",
>   "age": 30,
>   "languages": ["Python", "Rust", "Go"],
>   "active": true,
>   "score": null
> }
> <class 'dict'>
> ['Python', 'Rust', 'Go']
> True
> ```

---

## 🔨 Practice Problem 12.1

Write a program that:

1. Creates a file called `grades.csv` with columns `Student,Math,Science,English` and five rows of data (invent the values).
2. Reads the CSV back using `DictReader`, computes each student's average grade, and prints a report.
3. Serializes the report (as a list of dicts) to a JSON file called `grade_report.json`.
4. Reads the JSON file back and prints the name of the student with the highest average.

---

## Chapter 13: Error Handling and Exceptions

### 13.1 What Are Exceptions?

An **exception** is an event that occurs during program execution that disrupts the normal flow of instructions. Python represents exceptions as objects derived from the `BaseException` hierarchy. When an error occurs, Python **raises** an exception — it creates an exception object and propagates it up the call stack until it is **caught** (handled) or it reaches the top level, causing the program to terminate with a traceback.

The distinction between **errors** (programmer mistakes: `SyntaxError`, `IndentationError`) and **exceptions** (runtime problems: `ValueError`, `FileNotFoundError`) is important. Syntax errors are caught before execution begins; exceptions happen at runtime.

### 13.2 The `try` / `except` Block

```python
# exceptions_basic.py

# Without exception handling — program crashes
# print(10 / 0)   # ZeroDivisionError: division by zero

# With exception handling
try:
    result = 10 / 0
except ZeroDivisionError:
    print("Cannot divide by zero!")

# Catching different exception types
def safe_convert(value):
    try:
        return int(value)
    except ValueError:
        print(f"  '{value}' is not a valid integer")
        return None
    except TypeError:
        print(f"  Cannot convert {type(value).__name__} to int")
        return None

for v in ["42", "3.14", "hello", None]:
    result = safe_convert(v)
    print(f"  Result: {result}")
```

> **Expected Output:**
> ```
> Cannot divide by zero!
>   Result: 42
>   '3.14' is not a valid integer
>   Result: None
>   'hello' is not a valid integer
>   Result: None
>   Cannot convert NoneType to int
>   Result: None
> ```

### 13.3 `else`, `finally`, and Accessing the Exception Object

```python
# exceptions_full.py

def divide(a, b):
    try:
        result = a / b
    except ZeroDivisionError as e:
        # 'as e' binds the exception object — you can inspect it
        print(f"  Error: {e}")
        return None
    else:
        # Runs only if NO exception was raised in the try block
        print(f"  Success: {a} / {b} = {result}")
        return result
    finally:
        # ALWAYS runs — with or without an exception
        # Ideal for cleanup (closing files, releasing locks)
        print(f"  Finally block executed")

print(divide(10, 2))
print()
print(divide(10, 0))
```

> **Expected Output:**
> ```
>   Success: 10 / 2 = 5.0
>   Finally block executed
> 5.0
> 
>   Error: division by zero
>   Finally block executed
> None
> ```

**Summary of the four clauses:**
- `try` — code that might raise an exception.
- `except` — handler, runs if the specified exception occurs.
- `else` — runs only if the `try` block completed without an exception.
- `finally` — always runs, exception or not (perfect for cleanup).

### 13.4 The Exception Hierarchy and Catching Multiple Exceptions

```python
# exception_hierarchy.py

# Catching multiple types in one except
def parse_element(lst, idx, divisor):
    try:
        result = lst[idx] / divisor
        return result
    except (IndexError, ZeroDivisionError) as e:
        print(f"  Caught {type(e).__name__}: {e}")
        return None

parse_element([10, 20, 30], 1, 2)   # Success
parse_element([10, 20, 30], 5, 2)   # IndexError
parse_element([10, 20, 30], 1, 0)   # ZeroDivisionError

# Catching a broad base class (use carefully — can hide bugs)
try:
    x = int("oops")
except Exception as e:
    print(f"  {type(e).__name__}: {e}")

# Exception hierarchy (partial):
# BaseException
#   ├── SystemExit
#   ├── KeyboardInterrupt
#   └── Exception
#       ├── ValueError
#       ├── TypeError
#       ├── IndexError
#       ├── KeyError
#       ├── AttributeError
#       ├── FileNotFoundError
#       ├── ZeroDivisionError
#       └── RuntimeError
#           └── RecursionError
```

> **Expected Output:**
> ```
>   Caught IndexError: list index out of range
>   Caught ZeroDivisionError: division by zero
>   ValueError: invalid literal for int() with base 10: 'oops'
> ```

### 13.5 Raising Exceptions

You can raise exceptions yourself using the `raise` statement. This is how you signal error conditions to your callers.

```python
# raising_exceptions.py

def set_age(age):
    if not isinstance(age, int):
        raise TypeError(f"Age must be int, got {type(age).__name__}")
    if age < 0 or age > 150:
        raise ValueError(f"Age {age} is out of realistic range [0, 150]")
    return age

for val in [25, -5, 200, "old"]:
    try:
        result = set_age(val)
        print(f"  Age set to: {result}")
    except (TypeError, ValueError) as e:
        print(f"  {type(e).__name__}: {e}")

# Re-raising an exception
def process():
    try:
        result = 1 / 0
    except ZeroDivisionError:
        print("  Logging the error...")
        raise   # Re-raises the current exception unchanged

try:
    process()
except ZeroDivisionError:
    print("  Caught re-raised exception in caller")
```

> **Expected Output:**
> ```
>   Age set to: 25
>   ValueError: Age -5 is out of realistic range [0, 150]
>   ValueError: Age 200 is out of realistic range [0, 150]
>   TypeError: Age must be int, got str
>   Logging the error...
>   Caught re-raised exception in caller
> ```

### 13.6 Custom Exception Classes

You can define your own exceptions by subclassing `Exception`. This is important for library code — it lets users catch your specific errors without accidentally catching unrelated built-in errors.

```python
# custom_exceptions.py

class BankError(Exception):
    """Base class for bank-related errors."""
    pass

class InsufficientFundsError(BankError):
    def __init__(self, balance, amount):
        self.balance = balance
        self.amount  = amount
        super().__init__(
            f"Cannot withdraw {amount:.2f}: balance is only {balance:.2f}"
        )

class NegativeAmountError(BankError):
    pass

class BankAccount:
    def __init__(self, owner, balance=0.0):
        self.owner   = owner
        self.balance = balance

    def deposit(self, amount):
        if amount <= 0:
            raise NegativeAmountError("Deposit amount must be positive")
        self.balance += amount

    def withdraw(self, amount):
        if amount <= 0:
            raise NegativeAmountError("Withdrawal amount must be positive")
        if amount > self.balance:
            raise InsufficientFundsError(self.balance, amount)
        self.balance -= amount

acc = BankAccount("Alice", 100.0)
acc.deposit(50)
print(f"Balance after deposit: {acc.balance}")

try:
    acc.withdraw(200)
except InsufficientFundsError as e:
    print(f"Caught: {e}")

try:
    acc.deposit(-10)
except NegativeAmountError as e:
    print(f"Caught: {e}")

acc.withdraw(50)
print(f"Final balance: {acc.balance}")
```

> **Expected Output:**
> ```
> Balance after deposit: 150.0
> Caught: Cannot withdraw 200.00: balance is only 150.00
> Caught: Deposit amount must be positive
> Final balance: 100.0
> ```

### 13.7 Context Managers and `with` Statements

A **context manager** is any object that implements `__enter__` and `__exit__`. The `with` statement automatically calls these, ensuring proper setup and teardown even if exceptions occur. You have already seen `with open(...)` — now let's create a custom one.

```python
# context_manager.py
from contextlib import contextmanager
import time

# Method 1: using a class
class Timer:
    """Context manager that measures elapsed time."""
    def __enter__(self):
        self.start = time.perf_counter()
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.elapsed = time.perf_counter() - self.start
        print(f"  Elapsed: {self.elapsed:.4f} seconds")
        return False  # Do not suppress exceptions

with Timer() as t:
    total = sum(range(1_000_000))
print(f"Sum: {total}")

# Method 2: using @contextmanager decorator (simpler)
@contextmanager
def managed_resource(name):
    print(f"  Acquiring {name}")
    try:
        yield name.upper()    # Value bound to 'as' variable
    finally:
        print(f"  Releasing {name}")

with managed_resource("database_connection") as res:
    print(f"  Using resource: {res}")
```

> **Expected Output:**
> ```
>   Elapsed: 0.0XXX seconds
> Sum: 499999500000
>   Acquiring database_connection
>   Using resource: DATABASE_CONNECTION
>   Releasing database_connection
> ```

---

## 🔨 Practice Problem 13.1

Write a program that:

1. Defines a custom exception hierarchy: `ShapeError` (base), `InvalidDimensionError`, and `NegativeDimensionError` (both subclasses of `ShapeError`).
2. Implements a `Rectangle` class with `width` and `height` validation in `__init__` — raises `NegativeDimensionError` for negative values and `InvalidDimensionError` for zero.
3. Wraps object creation in a `try/except/else/finally` block, printing what happens in each clause.
4. Writes a context manager (using `@contextmanager`) that temporarily redirects `sys.stdout` to a string buffer, capturing all printed output.

---

## Chapter 14: Modules and Packages

### 14.1 What Is a Module?

A **module** is simply a Python file (`.py`) containing code — functions, classes, and variables — that can be imported into other files. Modules are Python's primary unit of code organization and reuse.

```python
# math_utils.py  (create this file)
"""Utility functions for mathematical operations."""

PI = 3.141592653589793

def circle_area(radius):
    """Return the area of a circle."""
    return PI * radius ** 2

def circle_circumference(radius):
    """Return the circumference of a circle."""
    return 2 * PI * radius

def is_prime(n):
    """Return True if n is prime."""
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
```

```python
# main.py  (in the same directory)
import math_utils

print(math_utils.PI)
print(math_utils.circle_area(5))
print(math_utils.is_prime(17))
```

> **Expected Output:**
> ```
> 3.141592653589793
> 78.53981633974483
> True
> ```

### 14.2 Import Styles

```python
# import_styles.py

# Style 1: import the whole module
import math
print(math.sqrt(16))     # 4.0

# Style 2: import specific names
from math import sqrt, pi, factorial
print(sqrt(25))           # 5.0
print(pi)                 # 3.141592653589793
print(factorial(6))       # 720

# Style 3: import with alias
import math as m
print(m.floor(3.7))       # 3

from math import ceil as ceiling
print(ceiling(3.2))       # 4

# Style 4: import everything (avoid in production code — pollutes namespace)
# from math import *
```

> **Expected Output:**
> ```
> 4.0
> 5.0
> 3.141592653589793
> 720
> 3
> 4
> ```

**Best practice:** Prefer `import module` or `from module import specific_name`. Avoid `from module import *` — it is unclear which names are imported and can cause silent name collisions.

### 14.3 The Standard Library — Key Modules

Python ships with an enormous standard library. Here are the modules you will use most:

```python
# stdlib_tour.py
import os
import sys
import math
import random
import datetime
import itertools
import functools
import re

# os — operating system interface
print(os.getcwd())               # Current working directory
print(os.path.join("a", "b", "c.txt"))  # OS-appropriate path
print(os.environ.get("HOME", "N/A"))    # Environment variable

# sys — interpreter info
print(sys.version[:6])           # Python version
print(sys.platform)              # 'linux', 'darwin', 'win32'

# math — mathematical functions
print(math.ceil(3.2))            # 4
print(math.floor(3.9))           # 3
print(math.log(math.e))          # 1.0
print(math.gcd(48, 18))          # 6

# random — pseudo-random numbers
random.seed(42)                  # Seed for reproducibility
print(random.randint(1, 10))     # Random int in [1, 10]
print(random.choice(["a","b","c"]))   # Random element
items = [1, 2, 3, 4, 5]
random.shuffle(items)            # Shuffle in place
print(items)
print(random.sample(range(100), 5))   # 5 unique random ints

# datetime
now = datetime.datetime.now()
print(now.strftime("%Y-%m-%d %H:%M"))
birthday = datetime.date(1990, 6, 15)
today    = datetime.date.today()
age_days = (today - birthday).days
print(f"Days since 1990-06-15: {age_days}")

# itertools
for combo in itertools.combinations("ABC", 2):
    print(combo, end=" ")
print()
for perm in itertools.permutations("AB", 2):
    print(perm, end=" ")
print()
print(list(itertools.chain([1,2], [3,4], [5])))

# functools
from functools import lru_cache

@lru_cache(maxsize=None)
def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)

print([fib(i) for i in range(10)])

# re — regular expressions
text = "Contact us at support@example.com or sales@company.org"
emails = re.findall(r"[\w.]+@[\w.]+\.[a-z]{2,}", text)
print(emails)
```

> **Expected Output:**
> ```
> (current directory)
> a/b/c.txt
> (home directory or N/A)
> 3.xx.x
> (platform string)
> 4
> 3
> 1.0
> 6
> 1
> a
> [3, 1, 4, 5, 2]
> (5 random numbers)
> (current datetime)
> (number of days)
> ('A', 'B') ('A', 'C') ('B', 'C') 
> ('A', 'B') ('A', 'B') ('B', 'A') 
> [1, 2, 3, 4, 5]
> [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
> ['support@example.com', 'sales@company.org']
> ```

### 14.4 Creating Packages

A **package** is a directory containing an `__init__.py` file and one or more module files. This lets you organize related modules under a common namespace.

```
mypackage/
    __init__.py          # Makes 'mypackage' a package
    geometry.py          # mypackage.geometry
    statistics.py        # mypackage.statistics
    utils/
        __init__.py
        helpers.py       # mypackage.utils.helpers
```

```python
# mypackage/__init__.py
"""My custom package."""
from .geometry import circle_area     # Expose at package level
VERSION = "1.0.0"
```

```python
# mypackage/geometry.py
def circle_area(r):
    import math
    return math.pi * r ** 2

def rectangle_area(w, h):
    return w * h
```

```python
# Using the package
import mypackage
from mypackage.geometry import rectangle_area

print(mypackage.VERSION)
print(mypackage.circle_area(3))
print(rectangle_area(4, 5))
```

### 14.5 Installing Third-Party Packages with `pip`

```bash
# Install a package
pip install requests

# Install a specific version
pip install requests==2.31.0

# List installed packages
pip list

# Save dependencies to a file
pip freeze > requirements.txt

# Install from requirements file
pip install -r requirements.txt

# Create a virtual environment (isolates project dependencies)
python3 -m venv venv
source venv/bin/activate        # Linux/macOS
# venv\Scripts\activate         # Windows
pip install requests
deactivate
```

**Always use virtual environments** for any project larger than a single script. They prevent version conflicts between projects.

### 14.6 The `__name__ == "__main__"` Guard

When Python imports a module, it executes all top-level code in that module. The `__name__` guard prevents certain code (e.g., test runs) from executing on import.

```python
# mymodule.py
def useful_function():
    return "I am useful"

def another_function():
    return "I am also useful"

if __name__ == "__main__":
    # This block runs ONLY when the file is executed directly,
    # NOT when it is imported by another module.
    print("Running as a script:")
    print(useful_function())
    print(another_function())
```

When run directly: `python3 mymodule.py` → prints the output.
When imported: `import mymodule` → the `if` block is silently skipped.

---

## 🔨 Practice Problem 14.1

1. Create a module `string_tools.py` with three functions: `word_count(text)`, `char_frequency(text)` (returns a Counter), and `is_pangram(text)` (True if the text contains every letter of the alphabet).
2. Create a `main.py` that imports `string_tools` and tests all three functions with the sentence `"The quick brown fox jumps over the lazy dog"`.
3. Add a `if __name__ == "__main__":` block to `string_tools.py` that runs a self-test.
4. Use `datetime` to print today's date formatted as `"Today is Wednesday, 04 May 2026"` (use `strftime` format codes).

---

## Chapter 15: Decorators

### 15.1 What Is a Decorator?

A **decorator** is a function that takes another function as input and returns a new function that wraps (enhances) the original. Decorators let you add behavior to functions without modifying their source code — separating concerns like logging, timing, access control, and caching.

The `@decorator_name` syntax placed above a function definition is **syntactic sugar** for:

```python
def my_func():
    ...
my_func = decorator_name(my_func)
```

### 15.2 Your First Decorator

```python
# decorator_basic.py

def shout(func):
    """A decorator that makes a function's output uppercase."""
    def wrapper(*args, **kwargs):
        result = func(*args, **kwargs)
        if isinstance(result, str):
            return result.upper()
        return result
    return wrapper

@shout
def greet(name):
    return f"Hello, {name}!"

@shout
def farewell(name):
    return f"Goodbye, {name}."

print(greet("Alice"))    # HELLO, ALICE!
print(farewell("Bob"))   # GOODBYE, BOB.

# Without the @ syntax (equivalent):
def plain_greet(name):
    return f"Hello, {name}!"

loud_greet = shout(plain_greet)
print(loud_greet("Carol"))   # HELLO, CAROL!
```

> **Expected Output:**
> ```
> HELLO, ALICE!
> GOODBYE, BOB.
> HELLO, CAROL!
> ```

### 15.3 Preserving Metadata with `functools.wraps`

Without `functools.wraps`, the decorated function loses its original `__name__` and `__doc__`. Always use it in production decorators.

```python
# wraps_demo.py
from functools import wraps

def my_decorator(func):
    @wraps(func)    # Copies __name__, __doc__, __module__, etc. from func
    def wrapper(*args, **kwargs):
        print(f"  Calling {func.__name__}()")
        return func(*args, **kwargs)
    return wrapper

@my_decorator
def add(a, b):
    """Return the sum of a and b."""
    return a + b

print(add(3, 4))
print(add.__name__)   # 'add' — preserved!
print(add.__doc__)    # 'Return the sum...' — preserved!
```

> **Expected Output:**
> ```
>   Calling add()
> 7
> add
> Return the sum of a and b.
> ```

### 15.4 Practical Decorators — Timing, Logging, and Retry

```python
# practical_decorators.py
import time
import functools

# --- Timing decorator ---
def timer(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        start  = time.perf_counter()
        result = func(*args, **kwargs)
        end    = time.perf_counter()
        print(f"  {func.__name__} took {end - start:.4f}s")
        return result
    return wrapper

@timer
def slow_sum(n):
    return sum(range(n))

slow_sum(1_000_000)

# --- Logging decorator ---
def log_calls(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        args_repr = [repr(a) for a in args]
        kwargs_repr = [f"{k}={v!r}" for k, v in kwargs.items()]
        signature = ", ".join(args_repr + kwargs_repr)
        print(f"  CALL: {func.__name__}({signature})")
        result = func(*args, **kwargs)
        print(f"  RETURN: {func.__name__} → {result!r}")
        return result
    return wrapper

@log_calls
def power(base, exp=2):
    return base ** exp

power(3)
power(2, exp=10)

# --- Retry decorator ---
def retry(max_attempts=3, delay=0.1):
    """Decorator factory: retries a function up to max_attempts times."""
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception as e:
                    print(f"  Attempt {attempt} failed: {e}")
                    if attempt < max_attempts:
                        time.sleep(delay)
            raise RuntimeError(f"All {max_attempts} attempts failed")
        return wrapper
    return decorator

@retry(max_attempts=3, delay=0)
def flaky_function(x):
    import random
    random.seed(x)
    if random.random() < 0.6:
        raise ValueError("Random failure!")
    return "Success!"

try:
    print(flaky_function(1))
except RuntimeError as e:
    print(f"  {e}")
```

> **Expected Output:**
> ```
>   slow_sum took 0.0XXXs
>   CALL: power(3)
>   RETURN: power → 9
>   CALL: power(2, exp=10)
>   RETURN: power → 1024
>   (some combination of attempt failures and eventual success or final error)
> ```

### 15.5 Decorator Factories (Decorators with Arguments)

A **decorator factory** is a function that takes arguments and returns a decorator. This requires an extra level of nesting.

```python
# decorator_factory.py
import functools

def repeat(n):
    """Repeat a function's call n times."""
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            results = []
            for _ in range(n):
                results.append(func(*args, **kwargs))
            return results
        return wrapper
    return decorator

@repeat(3)
def say_hello(name):
    print(f"Hello, {name}!")
    return f"Hello, {name}!"

results = say_hello("Alice")
print(results)

# Stacking decorators — applied bottom-up, called top-down
def bold(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        return f"**{func(*args, **kwargs)}**"
    return wrapper

def italic(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        return f"_{func(*args, **kwargs)}_"
    return wrapper

@bold
@italic
def format_text(text):
    return text

# Equivalent to: format_text = bold(italic(format_text))
print(format_text("Hello"))   # **_Hello_**
```

> **Expected Output:**
> ```
> Hello, Alice!
> Hello, Alice!
> Hello, Alice!
> ['Hello, Alice!', 'Hello, Alice!', 'Hello, Alice!']
> **_Hello_**
> ```

### 15.6 Class-Based Decorators

A class can be used as a decorator if it implements `__call__`. This is useful when a decorator needs to maintain state.

```python
# class_decorator.py
import functools

class CallCounter:
    """Counts how many times the decorated function is called."""
    def __init__(self, func):
        functools.update_wrapper(self, func)
        self.func  = func
        self.calls = 0

    def __call__(self, *args, **kwargs):
        self.calls += 1
        print(f"  Call #{self.calls} to {self.func.__name__}")
        return self.func(*args, **kwargs)

@CallCounter
def multiply(a, b):
    return a * b

print(multiply(2, 3))
print(multiply(4, 5))
print(multiply(6, 7))
print(f"Total calls: {multiply.calls}")
```

> **Expected Output:**
> ```
>   Call #1 to multiply
> 6
>   Call #2 to multiply
> 20
>   Call #3 to multiply
> 42
> Total calls: 3
> ```

---

## 🔨 Practice Problem 15.1

Write the following decorators:

1. `@validate_positive` — raises `ValueError` if any positional argument to the decorated function is not a positive number.
2. `@memoize` — caches the return values of a function based on its arguments (implement it from scratch without `lru_cache`).
3. `@rate_limit(calls_per_second)` — a decorator factory that raises `RuntimeError` if the function is called more than `calls_per_second` times within any one-second window.
4. Stack `@timer` and `@log_calls` on a single function, observe the output, and explain in a comment which decorator's `wrapper` runs first when the function is called.

---

## Chapter 16: Generators

### 16.1 What Is a Generator?

A **generator** is a special kind of function that produces values one at a time, **pausing** its execution between each value and resuming exactly where it left off. A generator function uses the `yield` keyword instead of (or in addition to) `return`. When called, a generator function does not execute its body — it returns a **generator object** (an iterator). Each call to `next()` on that object runs the function body until the next `yield`, produces the yielded value, and pauses.

Generators are the foundation of Python's iteration protocol and are the most memory-efficient way to produce large or infinite sequences.

```python
# generators_intro.py

def count_up(start, stop):
    """Generate integers from start to stop (inclusive)."""
    current = start
    while current <= stop:
        yield current         # Pause here, yield value, resume on next()
        current += 1

gen = count_up(1, 5)
print(gen)                    # <generator object count_up at 0x...>
print(type(gen))              # <class 'generator'>

# Manual iteration with next()
print(next(gen))   # 1
print(next(gen))   # 2
print(next(gen))   # 3

# Or just use a for loop (which calls next() internally)
for val in count_up(10, 13):
    print(val, end=" ")
print()

# Generators are consumed once
gen2 = count_up(1, 3)
print(list(gen2))   # [1, 2, 3]
print(list(gen2))   # [] — exhausted!
```

> **Expected Output:**
> ```
> <generator object count_up at 0x...>
> <class 'generator'>
> 1
> 2
> 3
> 10 11 12 13 
> [1, 2, 3]
> []
> ```

### 16.2 Why Generators? Memory Efficiency

```python
# generator_memory.py
import sys

# A regular function that builds a list in memory
def squares_list(n):
    return [i**2 for i in range(n)]

# A generator that produces squares lazily
def squares_gen(n):
    for i in range(n):
        yield i**2

n = 1_000_000

lst = squares_list(n)
gen = squares_gen(n)

print(f"List size:      {sys.getsizeof(lst):>12,} bytes")
print(f"Generator size: {sys.getsizeof(gen):>12,} bytes")

# The values are identical when iterated — only the storage differs
print(next(gen))  # 0
print(next(gen))  # 1
print(next(gen))  # 4
```

> **Expected Output:**
> ```
> List size:       8,448,728 bytes  (approximately)
> Generator size:        200 bytes
> 0
> 1
> 4
> ```

### 16.3 Infinite Generators

Because generators produce values on demand, they can represent **infinite sequences** — something impossible with a list.

```python
# infinite_generators.py

def natural_numbers():
    """Generate 1, 2, 3, 4, ... forever."""
    n = 1
    while True:
        yield n
        n += 1

def fibonacci():
    """Generate the Fibonacci sequence forever."""
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b

# Consume only what you need using itertools.islice
from itertools import islice, takewhile

# First 10 natural numbers
nats = natural_numbers()
print(list(islice(nats, 10)))

# Fibonacci numbers less than 100
print(list(takewhile(lambda x: x < 100, fibonacci())))
```

> **Expected Output:**
> ```
> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
> [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
> ```

### 16.4 Generator Pipelines

Generators can be chained into **pipelines** — each generator pulls data from the previous one lazily. This is a powerful and efficient pattern for data processing.

```python
# generator_pipeline.py

def read_numbers(data):
    """Source: yield each number from a list."""
    for n in data:
        yield n

def filter_even(numbers):
    """Filter: pass only even numbers."""
    for n in numbers:
        if n % 2 == 0:
            yield n

def square(numbers):
    """Transform: yield the square of each number."""
    for n in numbers:
        yield n ** 2

def running_total(numbers):
    """Accumulate: yield running total."""
    total = 0
    for n in numbers:
        total += n
        yield total

# Build the pipeline (nothing executes yet — fully lazy)
data = range(1, 11)
pipeline = running_total(square(filter_even(read_numbers(data))))

# Pull results through the pipeline on demand
for value in pipeline:
    print(value, end=" ")
print()
# Even numbers: 2,4,6,8,10 → squared: 4,16,36,64,100 → running: 4,20,56,120,220
```

> **Expected Output:**
> ```
> 4 20 56 120 220
> ```

### 16.5 `yield from` — Delegating to a Sub-Generator

`yield from` allows a generator to delegate part of its operations to another iterable or generator. It also transparently forwards values, `send()` calls, and exceptions.

```python
# yield_from.py

def chain(*iterables):
    """Equivalent to itertools.chain."""
    for it in iterables:
        yield from it       # Delegates to each iterable

print(list(chain([1, 2], [3, 4], [5])))

def flatten(nested):
    """Recursively flatten a nested list."""
    for item in nested:
        if isinstance(item, list):
            yield from flatten(item)   # Recurse into sub-lists
        else:
            yield item

deep = [1, [2, [3, [4, 5]], 6], 7]
print(list(flatten(deep)))
```

> **Expected Output:**
> ```
> [1, 2, 3, 4, 5]
> [1, 2, 3, 4, 5, 6, 7]
> ```

### 16.6 Sending Values into Generators — Two-Way Communication

Generators can receive values via `generator.send(value)`. This transforms them into **coroutines** — functions that can both produce and consume values. The `send()` method resumes the generator and provides the value as the result of the `yield` expression inside.

```python
# generator_send.py

def accumulator():
    """A generator that accumulates values sent to it."""
    total = 0
    while True:
        value = yield total    # Yield current total; receive next value
        if value is None:
            break
        total += value

gen = accumulator()
next(gen)             # Must call next() or send(None) first to advance to first yield

print(gen.send(10))   # total = 10; yields 10
print(gen.send(20))   # total = 30; yields 30
print(gen.send(5))    # total = 35; yields 35

gen.close()           # Cleanly shut down the generator
```

> **Expected Output:**
> ```
> 10
> 30
> 35
> ```

### 16.7 Generator Expressions Revisited

You have already seen generator expressions in Chapter 11. Here is a deeper look at their interaction with built-in functions:

```python
# gen_expr_advanced.py

data = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]

# All built-in reductions accept generator expressions
total   = sum(x for x in data)
maximum = max(x**2 for x in data)
minimum = min(x for x in data if x > 3)
any_big = any(x > 8 for x in data)
all_pos = all(x > 0 for x in data)

print(f"sum:     {total}")
print(f"max sq:  {maximum}")
print(f"min >3:  {minimum}")
print(f"any >8:  {any_big}")
print(f"all >0:  {all_pos}")

# Chaining generator expressions
import itertools
words  = ["hello", "world", "python"]
chars  = (ch for word in words for ch in word)
vowels = (ch for ch in chars if ch in "aeiou")
print(list(vowels))
```

> **Expected Output:**
> ```
> sum:     44
> max sq:  81
> min >3:  4
> any >8:  True
> all >0:  True
> ['e', 'o', 'o', 'o']
> ```

---

## 🔨 Practice Problem 16.1

Write the following generators and test each one:

1. `primes()` — an infinite generator that yields prime numbers in order (2, 3, 5, 7, 11, ...). Use it with `itertools.islice` to print the first 20 primes.
2. `chunked(iterable, size)` — yields successive non-overlapping chunks of `size` from `iterable`. For example, `list(chunked(range(10), 3))` → `[(0,1,2), (3,4,5), (6,7,8), (9,)]`.
3. `sliding_window(iterable, n)` — yields all contiguous sub-sequences of length `n`. For example, `list(sliding_window([1,2,3,4,5], 3))` → `[(1,2,3), (2,3,4), (3,4,5)]`.
4. A pipeline that reads numbers from `range(1, 101)`, keeps only those divisible by 3 or 5, squares them, and yields only those whose square is greater than 500. Compute the sum of all values that come out of this pipeline using a generator expression passed to `sum()`.

---

## Final Capstone Project

You have now covered the core of Python. To synthesize everything, build the following command-line **Student Grade Tracker**:

### Requirements

1. **Data model:** Each student is a `namedtuple` (or `dataclass`) with fields: `name`, `grades` (a list of floats), and `subject`.

2. **Functions:**
   - `compute_average(grades)` — returns the mean grade.
   - `letter_grade(average)` — maps average → letter (A/B/C/D/F).
   - `load_students(filepath)` — reads a CSV file and returns a list of student objects. Use proper exception handling for `FileNotFoundError` and malformed rows.
   - `save_report(students, filepath)` — writes a JSON report.
   - `top_students(students, n=3)` — returns the top `n` students by average (use `sorted()` with a key).

3. **Processing:** Use list comprehensions and generator expressions for all data transformations (no explicit `for`-loop with `.append()`).

4. **Output:** Print a formatted report table using f-strings. Example:
   ```
   ╔══════════════════════╤═══════╤═══════╗
   ║ Name                 │  Avg  │ Grade ║
   ╠══════════════════════╪═══════╪═══════╣
   ║ Alice                │ 91.3  │   A   ║
   ║ Bob                  │ 74.5  │   C   ║
   ╚══════════════════════╧═══════╧═══════╝
   ```

5. **Decorators:** Apply `@timer` to `load_students` and `@log_calls` to `save_report`.

6. **Modules:** Split the code across at least two files: `grade_tracker.py` (library) and `main.py` (entry point with `if __name__ == "__main__":`).

This project exercises: namedtuples, file I/O, CSV, JSON, exception handling, comprehensions, sorting with keys, f-string formatting, decorators, and the module system — the full breadth of what this guide has taught.

---

*This guide continues to grow. The natural next topics to explore — now that you have the fundamentals — are:*

- *Chapter 17: Object-Oriented Programming (classes, inheritance, dunder methods)*
- *Chapter 18: Type Hints and `mypy`*
- *Chapter 19: Concurrency (threads, async/await, asyncio)*
- *Chapter 20: Testing with `pytest`*
- *Chapter 21: Virtual Environments and Dependency Management*
- *Chapter 22: The Data Model — making your own objects feel native*

*Each of these builds directly on what you have mastered here. Keep going.*
