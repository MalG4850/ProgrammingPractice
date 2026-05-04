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
