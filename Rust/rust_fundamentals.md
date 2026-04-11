# Rust Fundamentals: A Comprehensive Guide

This tutorial breaks down Rust programming into digestible chunks with detailed explanations and hands-on exercises.

---

## Chapter 1: Variables and Basic Data Types

### 1.1 Understanding Variables in Rust

In Rust, variables are immutable by default. This is a deliberate design choice that prevents accidental data mutations and makes code more predictable. When you declare a variable with `let`, Rust guarantees that its value won't change unless you explicitly mark it as mutable.

```rust
fn main() {
    // This variable cannot be changed
    let age = 25;
    
    // To make it mutable, use 'mut' keyword
    let mut counter = 0;
    counter = counter + 1; // This is allowed
    
    println!("Age: {}, Counter: {}", age, counter);
}
```

**Key Points:**
- Variables declared with `let` are immutable
- Use `let mut` to create mutable variables
- Rust variables follow snake_case convention by convention
- The compiler infers the type automatically (type inference)

### 1.2 Primitive Data Types

Rust provides several primitive data types that form the building blocks of all programs:

**Integer Types:**
- `i8`, `i16`, `i32`, `i64`, `i128` (signed integers)
- `u8`, `u16`, `u32`, `u64`, `u128` (unsigned integers)
- `isize`, `usize` (pointer-sized integers)

**Floating-Point Types:**
- `f32` (single precision)
- `f64` (double precision, default)

**Other Primitives:**
- `bool` (true or false)
- `char` (single Unicode character, 4 bytes)

```rust
fn main() {
    let integer: i32 = -42;
    let unsigned: u32 = 100;
    let float: f64 = 3.14159;
    let is_active: bool = true;
    let letter: char = 'A';
    
    println!("Integer: {}", integer);
    println!("Unsigned: {}", unsigned);
    println!("Float: {}", float);
    println!("Boolean: {}", is_active);
    println!("Character: {}", letter);
}
```

### 1.3 Type Conversion

Rust requires explicit type conversions. You cannot automatically convert between types:

```rust
fn main() {
    let a: i32 = 10;
    let b: f64 = a as f64;  // Explicit conversion using 'as'
    
    println!("Converted: {}", b);
}
```

---

## 🔨 Exercise 1.1

Create a program that converts temperature from Celsius to Fahrenheit. The formula is: `F = (C × 9/5) + 32`. Use a mutable variable to store the result.

---

## Chapter 2: Functions and Control Flow

### 2.1 Defining Functions

Functions in Rust are declared using the `fn` keyword. They can take parameters and return values. The return type is specified after an arrow `->`.

```rust
// Function with parameters and return value
fn add(a: i32, b: i32) -> i32 {
    a + b  // No semicolon means return value
}

// Alternative return syntax
fn multiply(a: i32, b: i32) -> i32 {
    return a * b;  // Explicit return
}

fn main() {
    let result = add(5, 3);
    println!("5 + 3 = {}", result);
}
```

### 2.2 Control Flow: if-else

Rust's conditional statements are straightforward:

```rust
fn main() {
    let number = 7;
    
    if number < 5 {
        println!("Number is less than 5");
    } else if number == 5 {
        println!("Number is exactly 5");
    } else {
        println!("Number is greater than 5");
    }
}
```

**Important:** Unlike some languages, Rust requires the condition to be a `bool`. There's no "truthy" conversion from integers.

### 2.3 Loops

Rust has three types of loops:

**loop** - Infinite loop (use `break` to exit):
```rust
fn main() {
    let mut counter = 0;
    
    loop {
        counter += 1;
        if counter == 5 {
            break;
        }
    }
    println!("Counter: {}", counter);
}
```

**while** - Conditional loop:
```rust
fn main() {
    let mut number = 3;
    
    while number != 0 {
        println!("{}!", number);
        number -= 1;
    }
    println!("LIFTOFF!");
}
```

**for** - Iteration over a range or collection:
```rust
fn main() {
    for i in 0..5 {
        println!("i = {}", i);
    }
}
```

---

## 🔨 Exercise 2.1

Write a function called `calculate_factorial` that takes a non-negative integer `n` and returns its factorial. Use a loop to calculate the result. Test it with n = 5 (should return 120).

---

## Chapter 3: Ownership and Borrowing

### 3.1 What is Ownership?

Ownership is Rust's most distinctive feature. It enables memory safety guarantees without needing a garbage collector. Every value in Rust has a single "owner," and when that owner goes out of scope, the value is dropped.

```rust
fn main() {
    let s1 = String::from("hello");  // s1 owns the String
    let s2 = s1;  // ownership moves to s2
    
    // println!("{}", s1);  // ERROR: s1 no longer valid
    println!("{}", s2);  // This works
}
```

**Three Ownership Rules:**
1. Each value has exactly one owner
2. When the owner goes out of scope, the value is dropped
3. When you assign a value to another variable, ownership moves

### 3.2 Borrowing

Instead of transferring ownership, you can "borrow" a reference:

```rust
fn main() {
    let s1 = String::from("hello");
    
    // Borrow s1 without taking ownership
    let len = calculate_length(&s1);
    
    println!("Length of '{}' is {}", s1, len);
}

fn calculate_length(s: &String) -> usize {
    s.len()
}
```

**Key Concepts:**
- `&T` - Immutable reference (borrowed)
- `&mut T` - Mutable reference

You can have either:
- One mutable reference, OR
- Any number of immutable references

But not both at the same time.

### 3.3 Mutable References

```rust
fn main() {
    let mut s = String::from("hello");
    
    change(&mut s);
    println!("{}", s);
}

fn change(some_string: &mut String) {
    some_string.push_str(", world");
}
```

---

## 🔨 Exercise 3.1

Write a function that takes a vector of integers and returns the largest number. Use borrowing to avoid taking ownership of the vector. Test with vec![3, 7, 2, 9, 1].

---

## Chapter 4: Structs and Enums

### 4.1 Structs

Structs allow you to group related data together. They're similar to classes in object-oriented languages but without inheritance.

```rust
struct User {
    username: String,
    email: String,
    active: bool,
    sign_in_count: u64,
}

fn main() {
    // Create an instance of User
    let user1 = User {
        username: String::from("alice"),
        email: String::from("alice@example.com"),
        active: true,
        sign_in_count: 1,
    };
    
    println!("User: {}", user1.username);
    println!("Email: {}", user1.email);
}
```

**Methods on Structs:**

```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    // Method (has access to self)
    fn area(&self) -> u32 {
        self.width * self.height
    }
    
    // Associated function (no self)
    fn square(size: u32) -> Rectangle {
        Rectangle {
            width: size,
            height: size,
        }
    }
}

fn main() {
    let rect = Rectangle {
        width: 30,
        height: 50,
    };
    
    println!("Area: {}", rect.area());
    
    let sq = Rectangle::square(10);
    println!("Square area: {}", sq.area());
}
```

### 4.2 Enums

Enums represent types that can be one of several variants:

```rust
enum Message {
    Quit,                      // No data
    Move { x: i32, y: i32 },  // Named fields like structs
    Write(String),            // Single tuple
    ChangeColor(i32, i32, i32), // Multiple values
}

impl Message {
    fn call(&self) {
        // Match on the variant
        match self {
            Message::Quit => println!("Quit"),
            Message::Move { x, y } => println!("Move to ({}, {})", x, y),
            Message::Write(text) => println!("Write: {}", text),
            Message::ChangeColor(r, g, b) => println!("RGB: {}, {}, {}", r, g, b),
        }
    }
}

fn main() {
    let m = Message::Move { x: 10, y: 20 };
    m.call();
}
```

---

## 🔨 Exercise 4.1

Create a `Circle` struct with a `radius` field. Add a method `area()` that returns the area (π × r²). Also create a `Shape` enum that can be either a Circle or a Rectangle, and write a function that calculates the area of any Shape.

---

## Chapter 5: Pattern Matching with match

### 5.1 Basic match Expressions

The `match` operator allows you to compare a value against a series of patterns and execute code based on which pattern matches:

```rust
fn main() {
    let coin = Coin::Penny;
    
    let value = match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter => 25,
    };
    
    println!("Value: {}", value);
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}
```

### 5.2 Matching with Ranges

```rust
fn main() {
    let number = 13;
    
    match number {
        1 => println!("One!"),
        2 | 3 | 5 | 7 | 11 => println!("Prime"),
        13..=19 => println!("Teens"),
        _ => println!("Something else"),
    }
}
```

### 5.3 Pattern Matching in Enums

```rust
enum Option<T> {
    Some(T),
    None,
}

fn main() {
    let x = Some(5);
    
    match x {
        Some(n) => println!("Got value: {}", n),
        None => println!("No value"),
    }
    
    // Using if let for simple cases
    if let Some(n) = x {
        println!("Value exists: {}", n);
    }
}
```

---

## 🔨 Exercise 5.1

Write a function that takes an enum representing a grade (A, B, C, D, F) and returns a description. For example, A = "Excellent", B = "Good", etc. Use a match expression.

---

## Chapter 6: Error Handling

### 6.1 Option<T>

The `Option<T>` enum is used when a value might be present or absent:

```rust
fn find_user(id: u32) -> Option<String> {
    if id == 1 {
        Some(String::from("Alice"))
    } else {
        None
    }
}

fn main() {
    let user = find_user(1);
    
    // Using match
    match user {
        Some(name) => println!("Found: {}", name),
        None => println!("User not found"),
    }
    
    // Using unwrap_or for default values
    let name = find_user(999).unwrap_or(String::from("Guest"));
    println!("Name: {}", name);
}
```

### 6.2 Result<T, E>

The `Result<T, E>` enum is used for operations that can fail:

```rust
use std::fs::File;
use std::io::Read;

fn read_file_contents(path: &str) -> Result<String, std::io::Error> {
    let mut file = File::open(path)?;  // ? operator returns early on error
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;
    Ok(contents)
}

fn main() {
    match read_file_contents("example.txt") {
        Ok(contents) => println!("File contents: {}", contents),
        Err(e) => println!("Error reading file: {}", e),
    }
}
```

**The `?` Operator:**
- Works like a `match` that returns the `Err` variant on failure
- Can only be used in functions that return `Result` or `Option`

---

## 🔨 Exercise 6.1

Write a function that divides two numbers and returns `Result<f64, String>`. Handle the case where the divisor is zero by returning an error message.

---

## Chapter 7: Collections

### 7.1 Vectors

Vectors are growable arrays:

```rust
fn main() {
    // Create a vector
    let v: Vec<i32> = Vec::new();
    
    // Using vec! macro
    let v2 = vec![1, 2, 3, 4, 5];
    
    // Accessing elements
    let third = v2[2];  // Panics if out of bounds
    let third_safe = v2.get(2);  // Returns Option
    
    // Iterating
    for i in &v2 {
        println!("{}", i);
    }
    
    // Mutable iteration
    let mut v3 = vec![1, 2, 3];
    for i in &mut v3 {
        *i *= 2;  // Dereference to modify
    }
}
```

### 7.2 Strings

Rust has two string types: `String` (owned, growable) and `&str` (string slice, borrowed):

```rust
fn main() {
    // String - owned
    let mut s = String::from("hello");
    s.push_str(" world");
    
    // &str - borrowed reference
    let slice: &str = "hello";
    
    // Combining strings
    let s1 = String::from("Hello, ");
    let s2 = String::from("world!");
    let s3 = s1 + &s2;  // s1 is moved here
    
    println!("{}", s3);
}
```

### 7.3 HashMaps

Key-value storage:

```rust
use std::collections::HashMap;

fn main() {
    let mut scores = HashMap::new();
    
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);
    
    // Accessing values
    let team_name = String::from("Blue");
    let score = scores.get(&team_name);  // Returns Option<&v>
    
    // Iterating
    for (key, value) in &scores {
        println!("{}: {}", key, value);
    }
}
```

---

## 🔨 Exercise 7.1

Create a program that counts the frequency of each word in a given sentence. Use a HashMap where the key is the word (String) and the value is the count (u32).

---

## Chapter 8: Lifetimes

### 8.1 Why Lifetimes?

Lifetimes ensure that references are valid for as long as they're used. The compiler needs to know that references passed to functions will remain valid:

```rust
// Without lifetime annotation, compiler doesn't know
// if x or y will be valid when returned
fn longest(x: &str, y: &str) -> &str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}
```

### 8.2 Lifetime Annotations

```rust
// 'a represents the lifetime of both references
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn main() {
    let string1 = String::from("long string is long");
    let result;
    {
        let string2 = String::from("xyz");
        result = longest(&string1, &string2);
    }
    // string2 is out of scope, but result only lives as long as string1
    println!("Longest: {}", result);
}
```

**Key Points:**
- Lifetime annotations describe relationships between lifetimes
- They don't change how long values live - they help the compiler verify references
- Only needed when returning references from functions

---

## 🔨 Exercise 8.1

Write a function that takes two string slices and returns the shorter one. Use lifetime annotations to ensure the returned reference is valid as long as both input references are valid.

---

## Summary

You've learned the fundamental concepts of Rust:
1. Variables, mutability, and basic data types
2. Functions and control flow (if-else, loops)
3. Ownership and borrowing - Rust's memory safety system
4. Structs and enums for custom data types
5. Pattern matching with match expressions
6. Error handling with Option and Result
7. Collections: Vec, String, HashMap
8. Lifetimes for reference validation

**Next Steps:**
- Install Rust and practice these concepts
- Explore the standard library documentation
- Build small projects to reinforce learning
- Learn about traits, generics, and advanced error handling
