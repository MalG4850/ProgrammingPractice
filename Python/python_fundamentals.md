# Python Fundamentals: A Comprehensive Guide

This tutorial introduces Python in digestible units with explanations and exercises at the end of each chapter: concept first, syntax second, then short scripts you can run in the REPL or save as `.py` files. The rhythm follows classic structured-language textbooks (Balagurusamy-style sequencing of topics, Kanetkar-style compact examples). You are expected to understand general programming ideas—variables, control flow, functions, and basic data structures—in **some** language already; prior exposure to **C++** is enough context so loops and objects are not mysterious. This material states how Python behaves on its own terms rather than mapping every feature to another dialect.

---

## Chapter 1: Getting Started and Indentation

### 1.1 Running Python

Python source lives in text files executed by the interpreter. Many installations expose `python` or `python3`; examples below assume **Python 3.10+** for modern syntax (`match`, union types with `|`). Verify with:

```bash
python3 --version
```

### 1.2 Significant Indentation

Blocks are defined by **indentation** (typically four spaces), not braces. Colons introduce suites (`if`, `for`, `def`, etc.).

```python
def greet(name: str) -> None:
    if name:
        print(f"Hello, {name}")
    else:
        print("Hello, world")


if __name__ == "__main__":
    greet("Ada")
```

Mixing tabs and spaces provokes `TabError`—configure your editor to insert spaces only.

### 1.3 Comments and Docstrings

`#` begins a line comment. Triple-quoted strings immediately after a definition become **docstrings** (`help()`, tooling).

---

## 🔨 Exercise 1.1

Write a script `hello_unit.py` defining `main()` that prints your name and the Python version (`import sys; print(sys.version)`). Guard invocation with `if __name__ == "__main__": main()` so importing the file does not auto-print.

---

## Chapter 2: Variables, Types, and Dynamic Semantics

### 2.1 Names Bind to Objects

Python variables are **names** bound to objects. Assignment never copies objects implicitly— it rebinds the name.

```python
a = [1, 2]
b = a
b.append(3)
print(a)  # [1, 2, 3] — same list object
```

### 2.2 Dynamic Typing

A name may bind to values of different types over its lifetime; static verification is optional (Chapter 13 introduces hints).

### 2.3 Basic Built-in Types

`int` (arbitrary precision), `float`, `complex`, `bool`, `str`, `bytes`, `NoneType` (`None`).

```python
count = 10
pi = 3.14159
label = "demo"
flag = True
nothing = None
```

---

## 🔨 Exercise 2.1

Create two lists `x = [1]` and `y = x`. Assign `y = [1]` (rebind `y` only). Predict and verify what `x` contains afterward. Write a one-line comment explaining **aliasing** versus **rebinding**.

---

## Chapter 3: Operators, Control Flow, and Truthiness

### 3.1 Operators

Arithmetic (`+ - * / // % **`), comparisons, logical `and`, `or`, `not`, identity `is`, equality `==`. Prefer `is` / `is not` only with singletons like `None`.

### 3.2 Conditionals

```python
score = 82
if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
else:
    grade = "C or lower"
```

### 3.3 Truthiness

Empty containers and zero-like numbers act **false** in boolean contexts; most objects are **true** by default via `__bool__` / `__len__`.

```python
values = [0, "", [], {}, None, "hi"]
for v in values:
    print(v, "->", bool(v))
```

### 3.4 Loops

`while` and `for` (iteration protocol). `break`, `continue`, optional `else` on loops (runs if loop not broken).

```python
for i in range(3):
    print(i)
else:
    print("completed without break")
```

---

## 🔨 Exercise 3.1

Print **FizzBuzz** for integers `1..50`: multiples of 3 → `Fizz`, of 5 → `Buzz`, of both → `FizzBuzz`, else the number. Use a single loop.

---

## Chapter 4: Functions

### 4.1 Definition and Return

```python
def add(a: int, b: int) -> int:
    return a + b
```

Functions without `return` implicitly return `None`.

### 4.2 Argument Passing—Call by Assignment

Arguments bind names to passed objects; mutating a mutable argument affects the caller’s object.

### 4.3 Default Arguments—Evaluation Once

Defaults are evaluated **at function definition time**, not each call—avoid mutable defaults.

```python
# Wrong pattern
def append_bad(item, bucket=[]):
    bucket.append(item)
    return bucket


# Preferred
def append_good(item, bucket=None):
    if bucket is None:
        bucket = []
    bucket.append(item)
    return bucket
```

### 4.4 `*args` and `**kwargs`

Collect positional and keyword extras:

```python
def demo(*args, **kwargs):
    print(args, kwargs)


demo(1, 2, x=3)
```

---

## 🔨 Exercise 4.1

Implement `clamp(value, low, high)` returning `value` bounded to `[low, high]`. Implement `stats(*numbers)` returning `(count, minimum, maximum, average)` using built-ins (`len`, `min`, `max`, `sum`). Handle empty input with `ValueError`.

---

## Chapter 5: Lists and Tuples

### 5.1 Lists—Mutable Sequences

```python
nums = [10, 20, 30]
nums.append(40)
nums[1] = 99
last = nums.pop()
```

Slicing creates shallow copies of slices: `nums[1:3]`, `nums[:]`.

### 5.2 Tuples—Immutable Sequences

```python
point = (3, 4)
x, y = point  # unpacking
```

Tuples containing mutable objects remain mutable **through** those inner objects.

---

## 🔨 Exercise 5.1

Given `words = ["Python", "java", "PYTHON", "rust"]`, produce a **sorted** case-insensitive unique list using sorting + comprehension or `set` with care about ordering—choose either stable sorted uniqueness (`dict.fromkeys` trick) or document why you sort after `set`.

---

## Chapter 6: Dictionaries and Sets

### 6.1 Dicts—Mapping Keys to Values

Insertion-ordered since Python 3.7 (language guarantee 3.7+).

```python
scores = {"Ann": 92, "Bob": 81}
scores["Cal"] = 88
for name, value in scores.items():
    print(name, value)
```

### 6.2 Dict Methods

`get(key, default)`, `setdefault`, comprehensions:

```python
squares = {n: n * n for n in range(5)}
```

### 6.3 Sets—Unique Elements

```python
a = {1, 2, 3}
b = {2, 3, 4}
print(a & b, a | b, a - b)
```

---

## 🔨 Exercise 6.1

Count word frequencies in a paragraph string (split on whitespace, lowercase words). Store counts in a `dict[str, int]` and print the five most common words using `sorted` with a `key`—no imports beyond stdlib.

---

## Chapter 7: Strings and Formatting

### 7.1 Strings are Immutable Sequences of Unicode Code Points

Methods return new strings: `.lower()`, `.strip()`, `.replace()`, `.split()`, `.join()`.

### 7.2 f-strings

```python
name = "Ada"
version = 3.12
print(f"{name=} uses Python {version:.2f}")
```

### 7.3 Raw and Bytes Literals

`r"C:\path"` suppresses escapes; `b"data"` builds immutable `bytes`.

---

## 🔨 Exercise 7.1

Write `slugify(text: str) -> str`: lowercase, replace whitespace runs with single `-`, strip non-alphanumeric except hyphen using `str.isalnum` loop or comprehension—keep behavior documented if you allow underscores.

---

## Chapter 8: Comprehensions and Generators

### 8.1 List and Dict Comprehensions

```python
evens = [n for n in range(10) if n % 2 == 0]
rev_index = {s: i for i, s in enumerate(["a", "b", "c"])}
```

### 8.2 Generator Expressions—Lazy

Parentheses instead of brackets—iterate once, memory-friendly:

```python
squares_gen = (n * n for n in range(1_000_000))
```

### 8.3 Generator Functions—`yield`

```python
def count_up(n):
    i = 0
    while i < n:
        yield i
        i += 1
```

---

## 🔨 Exercise 8.1

Implement `read_numbers(path)` as a **generator** yielding integers parsed line-by-line from a text file (skip blanks). Without loading the whole file into a list, compute the sum of squares of all numbers using one pass.

---

## Chapter 9: Modules and Packages

### 9.1 Import Semantics

```python
import math
from pathlib import Path
```

Modules cache in `sys.modules`; circular imports require careful structure.

### 9.2 `if __name__ == "__main__"`

Separates library usage from script execution.

### 9.3 Packages

Directories with `__init__.py` (optional since namespace packages) group submodules; prefer absolute imports within projects.

---

## 🔨 Exercise 9.1

Create package layout `pkg/` with `math_util.py` exposing `square` and `__init__.py` re-exporting it. From parent directory, run `python -m pkg.demo` where `demo.py` prints `square(7)`. Document `PYTHONPATH` or editable install briefly in comments if needed.

---

## Chapter 10: Object-Oriented Programming

### 10.1 Classes and Instances

```python
class BankAccount:
    def __init__(self, holder: str, balance: float = 0.0):
        self.holder = holder
        self._balance = balance

    def deposit(self, amount: float) -> None:
        if amount <= 0:
            raise ValueError("amount must be positive")
        self._balance += amount

    def balance(self) -> float:
        return self._balance
```

`_balance` is conventionally “internal”—not enforced privacy.

### 10.2 Special Methods

`__str__`, `__repr__`, `__eq__`, rich comparisons, context managers (`__enter__`, `__exit__`), iterators (`__iter__`, `__next__`).

### 10.3 Inheritance and `super()`

```python
class Savings(BankAccount):
    def __init__(self, holder: str, balance: float, rate: float):
        super().__init__(holder, balance)
        self.rate = rate
```

---

## 🔨 Exercise 10.1

Model a `Shape` ABC conceptually with subclasses `Rectangle(w,h)` and `Circle(r)` implementing `area()` and `perimeter()` (use `math.pi`). Store mixed shapes in a list and print total area—use `typing.Protocol` or an informal duck-typing contract with clear docstrings.

---

## Chapter 11: Exceptions

### 11.1 try / except / else / finally

```python
try:
    value = int(input("Enter int: "))
except ValueError as e:
    print("Not an integer:", e)
else:
    print("Parsed:", value)
finally:
    print("cleanup always runs")
```

### 11.2 Raising and Chaining

```python
raise RuntimeError("failed") from cause
```

### 11.3 Custom Exceptions

Subclass `Exception`; keep hierarchies shallow unless domains demand depth.

---

## 🔨 Exercise 11.1

Write `safe_divide(a, b)` returning `float` normally but converting `ZeroDivisionError` into `ValueError("division by zero")` with chaining preserved (`raise ... from`). Demonstrate catching `ValueError` in caller.

---

## Chapter 12: Files and Context Managers

### 12.1 Path Objects—`pathlib`

```python
from pathlib import Path

text = Path("data.txt").read_text(encoding="utf-8")
```

### 12.2 Classic File Objects

```python
with open("data.txt", encoding="utf-8") as f:
    for line in f:
        process(line)
```

The `with` statement invokes context manager protocol—files close reliably.

### 12.3 Implementing Context Managers

```python
from contextlib import contextmanager

@contextmanager
def tag(name):
    print(f"<{name}>")
    yield
    print(f"</{name}>")
```

---

## 🔨 Exercise 12.1

Write `merge_logs(*paths, output)` copying lines from multiple UTF-8 text inputs into `output`, prefixing each line with `[filename]` derived from the source path. Use `pathlib` and `with` blocks; propagate `FileNotFoundError` with a helpful message.

---

## Chapter 13: Type Hints, Dataclasses, and `match`

### 13.1 Gradual Typing

Annotations document intent; runtime ignores them unless tooling reads them.

```python
def lengths(words: list[str]) -> list[int]:
    return [len(w) for w in words]
```

### 13.2 Dataclasses—Boilerplate Reduction

```python
from dataclasses import dataclass

@dataclass
class Point:
    x: float
    y: float

    def norm(self) -> float:
        return (self.x ** 2 + self.y ** 2) ** 0.5
```

### 13.3 Structural Pattern Matching—`match`

```python
def describe(value):
    match value:
        case int(x) if x < 0:
            return "negative int"
        case str(s):
            return f"string len {len(s)}"
        case _:
            return "something else"
```

---

## 🔨 Exercise 13.1

Define `@dataclass` `Book(title: str, pages: int)` and a function `catalog_summary(books: list[Book]) -> dict[str, int]` returning **total pages per first letter** of title (`title[0].upper()`). Use type hints throughout.

---

## Chapter 14: Standard Library Highlights

### 14.1 `collections`

`deque`, `Counter`, `defaultdict`, `namedtuple`—reach for them before reinventing.

### 14.2 `itertools`

`chain`, `groupby`, `islice`, infinite iterators—compose memory-efficient pipelines.

### 14.3 `functools`

`partial`, `reduce`, `lru_cache`—document caching assumptions (`lru_cache`).

---

## 🔨 Exercise 14.1

Using `collections.Counter`, read whitespace-split tokens from stdin until EOF (hint: `sys.stdin.read()`) and print the top **10** tokens with counts aligned in columns.

---

## Chapter 15: Testing and Tooling Overview

### 15.1 `unittest`

```python
import unittest

class TestMath(unittest.TestCase):
    def test_add(self):
        self.assertEqual(1 + 2, 3)

if __name__ == "__main__":
    unittest.main()
```

### 15.2 Virtual Environments

Use `python -m venv .venv`, activate, then `pip install` project deps—keeps projects isolated.

### 15.3 Linters and Formatters

Optional `ruff`, `black`, `mypy` tighten quality—introduce incrementally.

---

## 🔨 Exercise 15.1

Package `clamp` and `stats` from Chapter 4 into `stats_util.py` with `unittest` cases covering normal behavior, boundary clamps, and empty-input `ValueError`. Run with `python -m unittest`.

---

## Summary of Key Concepts

1. **Indentation** defines structure—respect it strictly.
2. **Names bind to objects**; aliasing vs copying matters for mutables.
3. **Truthiness** simplifies conditions but demands awareness.
4. **Defaults** evaluate once—never use mutable literals as defaults.
5. **Comprehensions and generators** balance clarity and efficiency.
6. **Protocols** power iteration, contexts, and duck typing.
7. **Exceptions** replace error codes for exceptional paths.
8. **`pathlib` + `with`** modernizes file handling.
9. **Type hints** improve maintainability without changing runtime semantics alone.
10. **stdlib batteries** (`collections`, `itertools`, `unittest`) reward familiarity.

---

## Project Ideas to Practice

1. **CLI todo manager** — JSON file persistence, argparse.
2. **Log merger / analyzer** — exercise files + counters.
3. **Quiz app** — dataclasses + random sampling + scoring.
4. **Markdown snippet extractor** — strings, parsing discipline.
5. **Concurrent downloader sketch** — introduce `asyncio` later after mastering synchronous core.
