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
    let product = multiply(5, 3);
    println!("5 * 3 = {}", product);
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

## Chapter 9: Object-Oriented Programming in Rust

Rust does not follow traditional object-oriented paradigms with classes and inheritance. Instead, it uses **traits** and **structs** to achieve polymorphism, encapsulation, and code reuse. Let's understand how OOP concepts map to Rust.

### 9.1 Encapsulation in Rust

Encapsulation is the bundling of data with the methods that operate on that data. Rust achieves this through structs and impl blocks.

```rust
#[derive(Debug)]
struct BankAccount {
    account_holder: String,
    balance: f64,          // private field convention
}

impl BankAccount {
    // Constructor - associated function
    fn new(holder: &str, initial_balance: f64) -> BankAccount {
        BankAccount {
            account_holder: holder.to_string(),
            balance: initial_balance,
        }
    }

    // Public methods provide controlled access
    fn deposit(&mut self, amount: f64) -> Result<(), String> {
        if amount <= 0.0 {
            return Err("Deposit amount must be positive".to_string());
        }
        self.balance += amount;
        Ok(())
    }

    fn withdraw(&mut self, amount: f64) -> Result<(), String> {
        if amount <= 0.0 {
            return Err("Withdrawal amount must be positive".to_string());
        }
        if amount > self.balance {
            return Err("Insufficient funds".to_string());
        }
        self.balance -= amount;
        Ok(())
    }

    // Read-only accessor
    fn get_balance(&self) -> f64 {
        self.balance
    }

    fn get_holder(&self) -> &str {
        &self.account_holder
    }
}

fn main() {
    let mut account = BankAccount::new("Alice Johnson", 1000.0);

    println!("Account holder: {}", account.get_holder());
    println!("Initial balance: ${:.2}", account.get_balance());

    account.deposit(500.0).unwrap();
    println!("After deposit: ${:.2}", account.get_balance());

    account.withdraw(200.0).unwrap();
    println!("After withdrawal: ${:.2}", account.get_balance());

    // This will fail
    match account.withdraw(2000.0) {
        Ok(_) => println!("Withdrawal successful"),
        Err(e) => println!("Error: {}", e),
    }
}
```

**Expected Output:**
```
Account holder: Alice Johnson
Initial balance: $1000.00
After deposit: $1500.00
After withdrawal: $1300.00
Error: Insufficient funds
```

**Key Points:**
- Fields in structs are private by default within modules
- Methods provide public interfaces (getters, setters, business logic)
- No traditional private/public keywords - module system controls visibility

### 9.2 Traits (Rust's Equivalent to Interfaces)

Traits define behavior that types can implement. They enable **polymorphism** in Rust.

```rust
// Define a trait (like an interface)
trait Speak {
    fn speak(&self) -> String;
    fn describe(&self) -> String {
        format!("I am a {}", std::any::type_name::<Self>())
    }
}

trait Move {
    fn move_(&self) -> String;
}

// Implement trait for a type
struct Dog {
    name: String,
    breed: String,
}

impl Speak for Dog {
    fn speak(&self) -> String {
        format!("{} says Woof!", self.name)
    }
}

impl Move for Dog {
    fn move_(&self) -> String {
        format!("{} runs on four legs", self.name)
    }
}

struct Bird {
    name: String,
    species: String,
}

impl Speak for Bird {
    fn speak(&self) -> String {
        format!("{} says Tweet!", self.name)
    }
}

impl Move for Bird {
    fn move_(&self) -> String {
        format!("{} flies with wings", self.name)
    }
}

// Polymorphic function using trait bounds
fn animal_show<T: Speak>(animal: &T) {
    println!("{}", animal.speak());
    println!("{}", animal.describe());
}

// Multiple trait bounds
fn animal_info<T: Speak + Move>(animal: &T) {
    println!("{}", animal.speak());
    println!("{}", animal.move_());
}

fn main() {
    let dog = Dog {
        name: String::from("Buddy"),
        breed: String::from("Golden Retriever"),
    };

    let bird = Bird {
        name: String::from("Tweety"),
        species: String::from("Canary"),
    };

    println!("--- Dog ---");
    animal_show(&dog);
    println!("\n--- Bird ---");
    animal_show(&bird);

    println!("\n--- Animal Info ---");
    animal_info(&dog);
}
```

**Expected Output:**
```
--- Dog ---
Buddy says Woof!
I am a Dog

--- Bird ---
Tweety says Tweet!
I am a Bird

--- Animal Info ---
Buddy says Woof!
Buddy runs on four legs
```

### 9.3 Inheritance? No, Composition Instead

Rust does not support inheritance. Instead, use **composition** and **trait implementation**.

```rust
trait Vehicle {
    fn start(&self);
    fn stop(&self);
}

struct Car {
    make: String,
    model: String,
    engine_on: bool,
}

impl Car {
    fn new(make: &str, model: &str) -> Car {
        Car {
            make: make.to_string(),
            model: model.to_string(),
            engine_on: false,
        }
    }
}

impl Vehicle for Car {
    fn start(&self) {
        println!("{} {} engine starting...", self.make, self.model);
    }

    fn stop(&self) {
        println!("{} {} engine stopped.", self.make, self.model);
    }
}

// Composition: Car has an Engine
struct Engine {
    horsepower: u32,
    fuel_type: String,
}

impl Engine {
    fn start(&self) {
        println!("Engine with {} HP starting...", self.horsepower);
    }
}

struct CarWithEngine {
    make: String,
    model: String,
    engine: Engine,  // Composition
}

impl CarWithEngine {
    fn new(make: &str, model: &str, hp: u32) -> CarWithEngine {
        CarWithEngine {
            make: make.to_string(),
            model: model.to_string(),
            engine: Engine {
                horsepower: hp,
                fuel_type: "Gasoline".to_string(),
            },
        }
    }

    fn start_car(&self) {
        self.engine.start();
        println!("{} {} is ready to drive!", self.make, self.model);
    }
}

fn main() {
    let car = Car::new("Toyota", "Camry");

    car.start();
    car.stop();

    let car2 = CarWithEngine::new("BMW", "X5", 300);
    car2.start_car();
}
```

**Expected Output:**
```
Toyota Camry engine starting...
Toyota Camry engine stopped.
Engine with 300 HP starting...
BMW X5 is ready to drive!
```

### 9.4 Dynamic Dispatch with Trait Objects

Use `dyn` for runtime polymorphism:

```rust
trait Draw {
    fn draw(&self);
}

struct Circle {
    radius: f64,
}

struct Square {
    side: f64,
}

impl Draw for Circle {
    fn draw(&self) {
        println!("Drawing a circle with radius {:.2}", self.radius);
    }
}

impl Draw for Square {
    fn draw(&self) {
        println!("Drawing a square with side {:.2}", self.side);
    }
}

// Trait object: store different types in same collection
fn render_shapes(shapes: &[&dyn Draw]) {
    for shape in shapes {
        shape.draw();
    }
}

fn main() {
    let circle = Circle { radius: 5.0 };
    let square = Square { side: 4.0 };

    let shapes: Vec<&dyn Draw> = vec![&circle, &square];

    println!("Rendering shapes:");
    render_shapes(&shapes);
}
```

**Expected Output:**
```
Rendering shapes:
Drawing a circle with radius 5.00
Drawing a square with side 4.00
```

### 9.5 Static Dispatch with Generics

Generic functions work at compile-time:

```rust
// Generic function
fn print_pair<T: std::fmt::Display>(a: T, b: T) {
    println!("Pair: ({}, {})", a, b);
}

// Generic struct
struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

// Method only for Point<f64>
impl Point<f64> {
    fn distance_from_origin(&self) -> f64 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

fn main() {
    let int_point = Point { x: 5, y: 10 };
    let float_point = Point { x: 3.0, y: 4.0 };

    print_pair(10, 20);
    print_pair("Hello", "World");

    println!("Integer point x: {}", int_point.x());
    println!("Distance: {:.2}", float_point.distance_from_origin());
}
```

**Expected Output:**
```
Pair: (10, 20)
Pair: (Hello, World)
Integer point x: 5
Distance: 5.00
```

---

## 🔨 Exercise 9.1

Create a `Shape` trait with methods `area()` and `perimeter()`. Implement it for `Circle` (radius) and `Rectangle` (width, height). Write a function that prints area and perimeter for a vector of shapes.

---

## Chapter 10: Exception Handling in Rust

Rust does not have traditional exceptions. Instead, it uses **Result<T, E>** and **panic!** for recoverable and irrecoverable errors.

### 10.1 Recoverable Errors: Result<T, E>

```rust
use std::fs::File;
use std::io::{self, Read};

fn read_file(filename: &str) -> Result<String, io::Error> {
    let mut file = File::open(filename)?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;
    Ok(contents)
}

fn process_data(data: &str) -> Result<i32, String> {
    if data.is_empty() {
        return Err("Data is empty".to_string());
    }
    let sum: i32 = data
        .split_whitespace()
        .map(|s| s.parse::<i32>())
        .collect::<Result<Vec<_>, _>>()
        .map_err(|_| "Invalid number found")?;
    Ok(sum)
}

fn main() {
    match read_file("data.txt") {
        Ok(contents) => {
            println!("File read successfully:");
            println!("{}", contents);
        }
        Err(e) => println!("Failed to read file: {}", e),
    }

    match process_data("10 20 30") {
        Ok(sum) => println!("Sum: {}", sum),
        Err(e) => println!("Error: {}", e),
    }

    match process_data("10 abc 30") {
        Ok(sum) => println!("Sum: {}", sum),
        Err(e) => println!("Error: {}", e),
    }
}
```

**Expected Output:**
```
Failed to read file: No such file or directory (os error 2)
Sum: 60
Error: Invalid number found
```

### 10.2 Unrecoverable Errors: panic!

```rust
fn main() {
    let values = vec![1, 2, 3];

    // This will panic with index out of bounds
    // println!("{}", values[10]);  // Commented to avoid crash

    // Safe access
    match values.get(10) {
        Some(val) => println!("Value: {}", val),
        None => println!("Index out of bounds!"),
    }

    // Using unwrap (panics if None)
    // let x: Option<i32> = None;
    // x.unwrap();  // This would panic!

    // Using expect with custom message
    let x: Option<i32> = None;
    // x.expect("Value should exist");  // Panics with our message
}
```

**Expected Output:**
```
Index out of bounds!
```

### 10.3 Creating Custom Error Types

```rust
use std::fmt;

// Custom error enum
#[derive(Debug)]
enum PaymentError {
    InsufficientFunds { balance: f64, required: f64 },
    CardDeclined,
    NetworkError(String),
}

impl fmt::Display for PaymentError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            PaymentError::InsufficientFunds { balance, required } => {
                write!(f, "Insufficient funds: have ${:.2}, need ${:.2}", balance, required)
            }
            PaymentError::CardDeclined => write!(f, "Card was declined"),
            PaymentError::NetworkError(msg) => write!(f, "Network error: {}", msg),
        }
    }
}

impl std::error::Error for PaymentError {}

fn process_payment(amount: f64, balance: f64) -> Result<(), PaymentError> {
    if balance < amount {
        return Err(PaymentError::InsufficientFunds {
            balance,
            required: amount,
        });
    }
    println!("Payment of ${:.2} processed successfully", amount);
    Ok(())
}

fn main() {
    match process_payment(150.0, 100.0) {
        Ok(_) => println!("Success!"),
        Err(e) => println!("Error: {}", e),
    }

    match process_payment(50.0, 100.0) {
        Ok(_) => println!("Success!"),
        Err(e) => println!("Error: {}", e),
    }
}
```

**Expected Output:**
```
Error: Insufficient funds: have $100.00, need $150.00
Payment of $50.0 processed successfully
Success!
```

---

## 🔨 Exercise 10.1

Create a function that reads a file and parses its contents as integers. Return a custom error enum with variants `IoError` and `ParseError`. Handle errors gracefully in main.

---

## Chapter 11: Generics (Templates)

Generics allow writing code that works with many types. They're Rust's version of templates.

### 11.1 Generic Functions

```rust
fn largest<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];
    for item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

fn print_pair<T: std::fmt::Display>(a: T, b: T) {
    println!("First: {}, Second: {}", a, b);
}

fn get_max<T: Ord>(a: T, b: T) -> T {
    if a > b { a } else { b }
}

fn main() {
    let numbers = vec![34, 50, 25, 100, 65];
    println!("Largest number: {}", largest(&numbers));

    let chars = ['a', 'z', 'm', 'b'];
    println!("Largest char: {}", largest(&chars));

    print_pair(10, 20);
    print_pair("Hello", "Rust");

    println!("Max of 5 and 10: {}", get_max(5, 10));
    println!("Max of 'x' and 'y': {}", get_max('x', 'y'));
}
```

**Expected Output:**
```
Largest number: 100
Largest char: z
First: 10, Second: 20
First: Hello, Second: Rust
Max of 5 and 10: 10
Max of 'x' and 'y': y
```

### 11.2 Generic Structs and Enums

```rust
// Generic struct
struct Point<T> {
    x: T,
    y: T,
}

// Generic with multiple type parameters
struct Rectangle<T, U> {
    width: T,
    height: U,
}

// Generic enum (like Option and Result)
enum MyOption<T> {
    Some(T),
    None,
}

// Generic method implementation
impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

// Implementation only for Point<f64>
impl Point<f64> {
    fn distance_from_origin(&self) -> f64 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

fn main() {
    let integer_point = Point { x: 5, y: 10 };
    let float_point = Point { x: 1.5, y: 2.5 };

    println!("Integer point: ({}, {})", integer_point.x, integer_point.y);
    println!("Float point x: {:.2}", float_point.x());

    let rect = Rectangle {
        width: 30,
        height: 40.5,
    };
    println!("Rectangle: {} x {:.1}", rect.width, rect.height);

    let some_value: MyOption<String> = MyOption::Some("Hello".to_string());
    match some_value {
        MyOption::Some(val) => println!("Value: {}", val),
        MyOption::None => println!("No value"),
    }
}
```

**Expected Output:**
```
Integer point: (5, 10)
Float point x: 1.50
Rectangle: 30 x 40.5
Value: Hello
```

### 11.3 Trait Bounds and Where Clause

```rust
use std::fmt::Display;

// Multiple trait bounds with where clause
fn print_all<T, U>(a: T, b: U)
where
    T: Display + std::fmt::Debug,
    U: Display + Clone,
{
    println!("A: {} {:?}", a, a);
    println!("B: {}", b);
    let b_clone = b.clone();
    println!("B clone: {}", b_clone);
}

// Using trait bounds with generic struct
struct Container<T: Display + Clone> {
    value: T,
}

impl<T: Display + Clone> Container<T> {
    fn show(&self) {
        println!("Value: {}", self.value);
    }
}

fn main() {
    print_all("Hello", 42);
    let container = Container { value: "data".to_string() };
    container.show();
}
```

**Expected Output:**
```
A: Hello "Hello"
B: 42
B clone: 42
Value: data
```

---

## 🔨 Exercise 11.1

Write a generic function `swap` that takes two mutable references and swaps their values. Test with integers, strings, and a custom struct.

---

## Chapter 12: File Handling in Rust

Rust provides safe and efficient file operations through the `std::fs` and `std::io` modules.

### 12.1 Reading Files

```rust
use std::fs;
use std::io::{self, Read, Write, Seek, SeekFrom};
use std::path::Path;

fn read_entire_file(filename: &str) -> io::Result<String> {
    let contents = fs::read_to_string(filename)?;
    Ok(contents)
}

fn read_bytes(filename: &str) -> io::Result<Vec<u8>> {
    let data = fs::read(filename)?;
    Ok(data)
}

fn main() {
    // First, create a sample file
    let sample_data = "Hello, Rust File I/O!\nThis is line 2.\nLine 3 here.";
    fs::write("sample.txt", sample_data).expect("Failed to create file");

    // Read the file
    match read_entire_file("sample.txt") {
        Ok(contents) => println!("File contents:\n{}", contents),
        Err(e) => println!("Error: {}", e),
    }

    // Read as bytes
    match read_bytes("sample.txt") {
        Ok(bytes) => println!("Bytes read: {}", bytes.len()),
        Err(e) => println!("Error: {}", e),
    }

    // Clean up
    fs::remove_file("sample.txt").unwrap();
}
```

**Expected Output:**
```
File contents:
Hello, Rust File I/O!
This is line 2.
Line 3 here.
Bytes read: 55
```

### 12.2 Writing Files

```rust
use std::fs::{self, File};
use std::io::Write;

fn write_text_file(filename: &str, content: &str) -> io::Result<()> {
    fs::write(filename, content)
}

fn append_to_file(filename: &str, content: &str) -> io::Result<()> {
    let mut file = File::options().append(true).open(filename)?;
    file.write_all(content)?;
    Ok(())
}

fn write_binary_file(filename: &str, data: &[u8]) -> io::Result<()> {
    fs::write(filename, data)
}

fn main() {
    // Write text file
    fs::write("log.txt", "Application started\n").unwrap();

    // Append
    append_to_file("log.txt", "User logged in\n").unwrap();
    append_to_file("log.txt", "Data processed\n").unwrap();

    // Read and display
    let contents = fs::read_to_string("log.txt").unwrap();
    println!("Log file:\n{}", contents);

    // Binary data
    let binary_data: Vec<u8> = (0..256).collect();
    fs::write("data.bin", &binary_data).unwrap();
    println!("Binary file created with {} bytes", binary_data.len());

    // Cleanup
    fs::remove_file("log.txt").unwrap();
    fs::remove_file("data.bin").unwrap();
}
```

**Expected Output:**
```
Log file:
Application started
User logged in
Data processed
Binary file created with 256 bytes
```

### 12.3 Reading Line by Line

```rust
use std::fs::File;
use std::io::{self, BufRead, BufReader, Write};

fn count_lines(filename: &str) -> io::Result<u64> {
    let file = File::open(filename)?;
    let reader = BufReader::new(file);
    let count = reader.lines().count() as u64;
    Ok(count)
}

fn process_csv(filename: &str) -> io::Result<()> {
    let file = File::open(filename)?;
    let reader = BufReader::new(file);

    println!("Processing CSV:");
    for (index, line) in reader.lines().enumerate() {
        let line = line?;
        if index == 0 {
            println!("Header: {}", line);
        } else {
            let fields: Vec<&str> = line.split(',').collect();
            println!("Row {}: {:?}", index, fields);
        }
    }
    Ok(())
}

fn main() {
    let csv_data = "Name,Age,City\nAlice,25,NYC\nBob,30,LA\nCharlie,35,SF";
    fs::write("data.csv", csv_data).unwrap();

    let line_count = count_lines("data.csv").unwrap();
    println!("Total lines: {}", line_count);

    process_csv("data.csv").unwrap();

    fs::remove_file("data.csv").unwrap();
}
```

**Expected Output:**
```
Total lines: 4
Processing CSV:
Header: Name,Age,City
Row 1: ["Alice", "25", "NYC"]
Row 2: ["Bob", "30", "LA"]
Row 3: ["Charlie", "35", "SF"]
```

### 12.4 Random Access and Seeking

```rust
use std::fs::File;
use std::io::{self, Seek, SeekFrom, Read, Write};

fn read_at_position(filename: &str, pos: u64, length: usize) -> io::Result<String> {
    let mut file = File::open(filename)?;
    file.seek(SeekFrom::Start(pos))?;
    let mut buffer = vec![0u8; length];
    file.read_exact(&mut buffer)?;
    Ok(String::from_utf8_lossy(&buffer).to_string())
}

fn write_at_end(filename: &str, data: &str) -> io::Result<()> {
    let mut file = File::options().append(true).open(filename)?;
    file.write_all(data.as_bytes())?;
    Ok(())
}

fn main() {
    fs::write("seek_test.txt", "0123456789ABCDEF").unwrap();

    // Read bytes 5-10
    let chunk = read_at_position("seek_test.txt", 5, 5).unwrap();
    println!("Bytes at position 5: {}", chunk);

    // Seek from end
    let mut file = File::open("seek_test.txt").unwrap();
    file.seek(SeekFrom::End(-5)).unwrap();
    let mut buf = [0u8; 5];
    file.read_exact(&mut buf).unwrap();
    println!("Last 5 bytes: {}", String::from_utf8_lossy(&buf));

    fs::remove_file("seek_test.txt").unwrap();
}
```

**Expected Output:**
```
Bytes at position 5: 56789
Last 5 bytes: BCDEF
```

---

## 🔨 Exercise 12.1

Write a program that copies the contents of one file to another. Implement it twice: once using `fs::copy` and once using manual read/write loops. Compare performance for large files.

---

## Chapter 13: Data Structures: Stack and List

While Rust has standard library collections, understanding how to implement data structures manually teaches ownership and pointer concepts.

### 13.1 Stack (LIFO) Implementation

```rust
#[derive(Debug)]
struct Stack<T> {
    data: Vec<T>,
}

impl<T> Stack<T> {
    fn new() -> Stack<T> {
        Stack { data: Vec::new() }
    }

    fn push(&mut self, item: T) {
        self.data.push(item);
    }

    fn pop(&mut self) -> Option<T> {
        self.data.pop()
    }

    fn peek(&self) -> Option<&T> {
        self.data.last()
    }

    fn is_empty(&self) -> bool {
        self.data.is_empty()
    }

    fn size(&self) -> usize {
        self.data.len()
    }
}

fn reverse_string(input: &str) -> String {
    let mut stack = Stack::new();
    for ch in input.chars() {
        stack.push(ch);
    }

    let mut result = String::new();
    while let Some(ch) = stack.pop() {
        result.push(ch);
    }
    result
}

fn main() {
    let mut stack = Stack::new();

    println!("Pushing 1, 2, 3 onto stack");
    stack.push(1);
    stack.push(2);
    stack.push(3);

    println!("Stack size: {}", stack.size());
    println!("Top element: {:?}", stack.peek());

    println!("Popping: {:?}", stack.pop());
    println!("Popping: {:?}", stack.pop());
    println!("Stack size after pops: {}", stack.size());

    println!("\nReversing 'Hello': {}", reverse_string("Hello"));
    println!("Reversing 'Rust': {}", reverse_string("Rust"));
}
```

**Expected Output:**
```
Pushing 1, 2, 3 onto stack
Stack size: 3
Top element: Some(3)
Popping: Some(3)
Popping: Some(2)
Stack size after pops: 1

Reversing 'Hello': olleH
Reversing 'Rust': tsuR
```

### 13.2 Singly Linked List

```rust
#[derive(Debug)]
struct ListNode<T> {
    data: T,
    next: Option<Box<ListNode<T>>>,
}

impl<T> ListNode<T> {
    fn new(data: T) -> ListNode<T> {
        ListNode { data, next: None }
    }
}

#[derive(Debug)]
struct LinkedList<T> {
    head: Option<Box<ListNode<T>>>,
    size: usize,
}

impl<T> LinkedList<T> {
    fn new() -> Self {
        LinkedList { head: None, size: 0 }
    }

    fn push_front(&mut self, data: T) {
        let new_node = Box::new(ListNode {
            data,
            next: self.head.take(),
        });
        self.head = Some(new_node);
        self.size += 1;
    }

    fn push_back(&mut self, data: T) {
        let new_node = Box::new(ListNode::new(data));
        match &mut self.head {
            None => self.head = Some(new_node),
            Some(mut current) => {
                while let Some(ref mut next) = current.next {
                    current = next;
                }
                current.next = Some(new_node);
            }
        }
        self.size += 1;
    }

    fn pop_front(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            self.size -= 1;
            node.data
        })
    }

    fn len(&self) -> usize {
        self.size
    }

    fn is_empty(&self) -> bool {
        self.size == 0
    }

    fn print(&self) {
        let mut current = &self.head;
        print!("List: ");
        while let Some(node) = current {
            print!("{:?} -> ", node.data);
            current = &node.next;
        }
        println!("None");
    }
}

fn main() {
    let mut list = LinkedList::new();

    println!("Pushing to front: 1, 2, 3");
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.print();
    println!("List size: {}", list.len());

    println!("\nPushing to back: 4, 5");
    list.push_back(4);
    list.push_back(5);
    list.print();

    println!("\nPopping front: {:?}", list.pop_front());
    list.print();
    println!("Size after pop: {}", list.len());
}
```

**Expected Output:**
```
Pushing to front: 1, 2, 3
List: 3 -> 2 -> 1 -> None
List size: 3

Pushing to back: 4, 5
List: 3 -> 2 -> 1 -> 4 -> 5 -> None

Popping front: Some(3)
List: 2 -> 1 -> 4 -> 5 -> None
Size after pop: 4
```

### 13.3 Doubly Linked List (Using std::collections)

Rust standard library provides efficient collections:

```rust
use std::collections::{LinkedList, VecDeque};

fn main() {
    // std::collections::LinkedList
    let mut list = LinkedList::new();
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);

    println!("LinkedList contents:");
    for (i, val) in list.iter().enumerate() {
        println!("  Index {}: {}", i, val);
    }

    // VecDeque - double-ended queue (efficient at both ends)
    let mut deque = VecDeque::new();
    deque.push_front("A");
    deque.push_back("B");
    deque.push_front("C");

    println!("\nVecDeque:");
    println!("Front: {:?}", deque.front());
    println!("Back: {:?}", deque.back());
    println!("All elements: {:?}", deque);
}
```

**Expected Output:**
```
LinkedList contents:
  Index 0: 0
  Index 1: 1
  Index 2: 2

VecDeque:
Front: Some("C")
Back: Some("B")
All elements: ["C", "A", "B"]
```

---

## 🔨 Exercise 13.1

Implement a stack that tracks the minimum element in O(1) time. Your `MinStack` should have `push`, `pop`, `top`, and `get_min` methods. Test with pushing 5, 3, 7, 2, 8 and verify min changes correctly.

---

## Chapter 14: Debugging in Rust

Rust has excellent debugging tools built into the language and compiler.

### 14.1 Using println! for Debugging

```rust
#[derive(Debug)]
struct Person {
    name: String,
    age: u32,
    email: Option<String>,
}

fn process_person(person: &Person) -> Result<String, String> {
    // Debug print the entire struct
    println!("[DEBUG] Processing person: {:?}", person);

    // Pretty-print with debug
    println!("[DEBUG] Pretty print:\n{:#?}", person);

    // Check optional field
    match &person.email {
        Some(email) => println!("[DEBUG] Email found: {}", email),
        None => println!("[DEBUG] No email provided"),
    }

    if person.age < 18 {
        return Err("Person must be 18 or older".to_string());
    }

    Ok(format!("{} is {} years old", person.name, person.age))
}

fn main() {
    let alice = Person {
        name: "Alice".to_string(),
        age: 25,
        email: Some("alice@example.com".to_string()),
    };

    let bob = Person {
        name: "Bob".to_string(),
        age: 17,
        email: None,
    };

    println!("=== Processing Alice ===");
    match process_person(&alice) {
        Ok(msg) => println!("Result: {}", msg),
        Err(e) => println!("Error: {}", e),
    }

    println!("\n=== Processing Bob ===");
    match process_person(&bob) {
        Ok(msg) => println!("Result: {}", msg),
        Err(e) => println!("Error: {}", e),
    }
}
```

**Expected Output:**
```
=== Processing Alice ===
[DEBUG] Processing person: Person { name: "Alice", age: 25, email: Some("alice@example.com") }
[DEBUG] Pretty print:
Person {
    name: "Alice",
    age: 25,
    email: Some(
        "alice@example.com",
    ),
}
[DEBUG] Email found: alice@example.com
Result: Alice is 25 years old

=== Processing Bob ===
[DEBUG] Processing person: Person { name: "Bob", age: 17, email: None }
[DEBUG] Pretty print:
Person {
    name: "Bob",
    age: 17,
    email: None,
}
[DEBUG] No email provided
Error: Person must be 18 or older
```

### 14.2 Debugging Macros: dbg! and assert!

```rust
fn complex_calculation(a: i32, b: i32) -> i32 {
    let intermediate = a * b;
    dbg!(intermediate);  // Prints with file and line number

    let result = intermediate + 10;
    dbg!(result);

    result
}

fn main() {
    println!("=== Using dbg! macro ===");
    let x = complex_calculation(5, 3);
    println!("Final result: {}", x);

    println!("\n=== Using assert! ===");
    let values = vec![1, 2, 3, 4, 5];
    assert!(values.len() > 0, "Vector should not be empty");
    assert_eq!(values[0], 1, "First element should be 1");

    println!("All assertions passed!");

    // This would panic:
    // assert!(values.len() > 10, "This will fail!");
}
```

**Expected Output:**
```
=== Using dbg! macro ===
[src/main.rs:6] intermediate = 15
[src/main.rs:10] result = 25
Final result: 25

=== Using assert! ===
All assertions passed!
```

### 14.3 Debugging with GDB/LLDB

Rust generates debug symbols by default in debug builds:

```bash
# Compile with debug info
cargo build

# Run with GDB
gdb target/debug/your_program

# Or use LLDB on macOS
lldb target/debug/your_program
```

Common GDB commands:
- `break main` - Set breakpoint at main
- `run` - Start program
- `next` - Step over
- `step` - Step into
- `print variable` - Inspect variable
- `backtrace` - Show call stack
- `continue` - Resume execution

### 14.4 Using Rust's Built-in Testing for Debugging

```rust
fn add(a: i32, b: i32) -> i32 {
    a + b
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_add_positive() {
        assert_eq!(add(2, 3), 5);
    }

    #[test]
    fn test_add_negative() {
        assert_eq!(add(-2, -3), -5);
    }

    #[test]
    fn test_add_zero() {
        assert_eq!(add(0, 0), 0);
    }

    #[test]
    fn test_add_mixed() {
        assert_eq!(add(10, -5), 5);
    }
}

fn main() {
    println!("Run tests with: cargo test");
}
```

**Running Tests:**
```bash
$ cargo test
running 4 tests
test tests::test_add_negative ... ok
test tests::test_add_positive ... ok
test tests::test_add_zero ... ok
test tests::test_add_mixed ... ok

test result: ok. 4 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

### 14.5 Conditional Compilation for Debug Logging

```rust
#[derive(Debug)]
struct DataProcessor {
    data: Vec<i32>,
    processed_count: u32,
}

impl DataProcessor {
    fn new() -> Self {
        DataProcessor {
            data: Vec::new(),
            processed_count: 0,
        }
    }

    fn process(&mut self, value: i32) {
        #[cfg(debug_assertions)]
        println!("[DEBUG] Processing value: {}", value);

        self.data.push(value);
        self.processed_count += 1;
    }

    fn summary(&self) -> String {
        format!("Processed {} items", self.processed_count)
    }
}

fn main() {
    let mut processor = DataProcessor::new();

    for i in 1..=5 {
        processor.process(i);
    }

    println!("{}", processor.summary());

    // Compile with --release to remove debug prints
    // cargo build --release
}
```

**Expected Output (debug build):**
```
[DEBUG] Processing value: 1
[DEBUG] Processing value: 2
[DEBUG] Processing value: 3
[DEBUG] Processing value: 4
[DEBUG] Processing value: 5
Processed 5 items
```

---

## 🔨 Exercise 14.1

Create a function with a bug (e.g., off-by-one error). Use `dbg!` macro to trace variable values and find the bug. Document what the bug was and how you found it.

---

## Chapter 15: Advanced Topics Quick Reference

### 15.1 Smart Pointers

```rust
// Box<T> - heap allocation
let boxed_int = Box::new(5);
println!("Boxed value: {}", boxed_int);

// Rc<T> - reference counting (multiple owners, single-threaded)
use std::rc::Rc;
let shared_data = Rc::new("Shared string");
let ref1 = Rc::clone(&shared_data);
let ref2 = Rc::clone(&shared_data);
println!("Strong count: {}", Rc::strong_count(&shared_data));

// Arc<T> - atomic reference counting (thread-safe)
use std::sync::Arc;
let arc_data = Arc::new(vec![1, 2, 3]);
```

**Expected Output:**
```
Boxed value: 5
Shared string
Shared string
Strong count: 3
```

### 15.2 Closures and Iterators

```rust
fn main() {
    let numbers = vec![1, 2, 3, 4, 5];

    // Closure
    let add_one = |x: i32| x + 1;
    println!("Using closure: {:?}", numbers.iter().map(add_one).collect::<Vec<_>>());

    // Iterator adapters
    let sum: i32 = numbers.iter().sum();
    println!("Sum: {}", sum);

    let evens: Vec<_> = numbers.iter().filter(|x| *x % 2 == 0).collect();
    println!("Even numbers: {:?}", evens);
}
```

**Expected Output:**
```
Using closure: [2, 3, 4, 5, 6]
Sum: 15
Even numbers: [2, 4]
```

### 15.3 Concurrency with Threads

```rust
use std::thread;
use std::time::Duration;

fn main() {
    let handle = thread::spawn(|| {
        for i in 1..10 {
            println!("From thread: {}", i);
            thread::sleep(Duration::from_millis(100));
        }
    });

    for i in 1..5 {
        println!("From main: {}", i);
        thread::sleep(Duration::from_millis(150));
    }

    handle.join().unwrap();
    println!("Both threads finished!");
}
```

**Expected Output (interleaved):**
```
From main: 1
From thread: 1
From thread: 2
From main: 2
From main: 3
From thread: 3
From thread: 4
From main: 4
From thread: 5
...
Both threads finished!
```

---

## Summary of Key Concepts

1. **OOP in Rust**: Use traits for polymorphism, structs for data, no inheritance
2. **Error Handling**: `Result<T, E>` for recoverable, `panic!` for unrecoverable
3. **Generics**: Write reusable code that works with multiple types
4. **File I/O**: `std::fs` for file operations, `BufReader` for efficient reading
5. **Data Structures**: Implement custom (Stack, LinkedList) or use std collections
6. **Debugging**: `println!`, `dbg!`, `assert!`, unit tests, `cargo test`
7. **Ownership**: Every value has a single owner, borrow with references
8. **Lifetimes**: Ensure references remain valid

---

## Project Ideas to Practice

1. **Todo List App** - File handling + Structs
2. **Calculator** - Enums + Pattern matching + Error handling
3. **Bank Account System** - Encapsulation + Traits
4. **Stack-Based Expression Evaluator** - Stack data structure
5. **Text Analyzer** - File I/O + Collections + Generics
