# Go Fundamentals: A Comprehensive Mastery Guide

This guide is structured to take you from the basics of Go (Golang) to advanced concepts like concurrency and interfaces. Every concept is explained with theory, working code, expected output, and a practice problem.

---

## Chapter 1: Introduction to Go

### 1.1 What is Go?

Go is an open-source programming language developed by Google. It is designed for simplicity, efficiency, and reliability. Key features include strong typing, garbage collection, and first-class support for concurrency.

### 1.2 Hello World

Go programs are organized into packages. The `main` package and the `main` function are the entry point.

```go
package main

import "fmt"

func main() {
    fmt.Println("Hello, Go!")
}
```

> **Expected Output:**
> ```
> Hello, Go!
> ```

---

## 🔨 Practice Problem 1.1
Create a file named `hello.go` that prints "Welcome to Go!" followed by your name on a new line.

---

## Chapter 2: Variables and Constants

### 2.1 Variable Declaration

Go offers several ways to declare variables. The `var` keyword is used for explicit declaration, and the `:=` operator is used for short-hand declaration inside functions.

```go
package main

import "fmt"

func main() {
    // Explicit declaration
    var x int = 10
    
    // Type inference
    var y = 20
    
    // Short-hand declaration (inside functions only)
    z := 30
    
    fmt.Println(x, y, z)
}
```

> **Expected Output:**
> ```
> 10 20 30
> ```

### 2.2 Constants

Constants are declared with the `const` keyword and cannot be changed once set.

```go
const PI = 3.14159
```

---

## 🔨 Practice Problem 2.1
Declare a constant for the name of your favorite programming language and a mutable variable for the number of years you've been coding. Print them both.

---

## Chapter 3: Basic Data Types

### 3.1 Numeric, Boolean, and String Types

Go has standard types like `int`, `float64`, `bool`, and `string`.

```go
package main

import "fmt"

func main() {
    var i int = 42
    var f float64 = 3.14
    var b bool = true
    var s string = "Golang"
    
    fmt.Printf("%T: %v\n", i, i)
    fmt.Printf("%T: %v\n", f, f)
    fmt.Printf("%T: %v\n", b, b)
    fmt.Printf("%T: %v\n", s, s)
}
```

> **Expected Output:**
> ```
> int: 42
> float64: 3.14
> bool: true
> string: Golang
> ```

---

## 🔨 Practice Problem 3.1
Declare one variable of each basic type (`int`, `float64`, `bool`, `string`) and print their values using `fmt.Println`.

---

## Chapter 4: Control Flow

### 4.1 If-Else and Switch

Go's `if` statements don't need parentheses around conditions but require braces.

```go
package main

import "fmt"

func main() {
    num := 10
    if num > 0 {
        fmt.Println("Positive")
    } else {
        fmt.Println("Negative")
    }

    // Switch statement
    day := "Monday"
    switch day {
    case "Monday":
        fmt.Println("Start of the week")
    default:
        fmt.Println("Another day")
    }
}
```

> **Expected Output:**
> ```
> Positive
> Start of the week
> ```

### 4.2 For Loops

The `for` loop is the only looping construct in Go.

```go
for i := 0; i < 3; i++ {
    fmt.Println(i)
}
```

---

## 🔨 Practice Problem 4.1
Write a `for` loop that prints all even numbers from 0 to 10 inclusive.

---

## Chapter 5: Collections: Slices and Maps

### 5.1 Slices

Slices are dynamic arrays. They are more flexible and common than fixed-size arrays.

```go
package main

import "fmt"

func main() {
    // Creating a slice
    nums := []int{1, 2, 3}
    nums = append(nums, 4) // Dynamic growth
    
    fmt.Println(nums)
    fmt.Println("Length:", len(nums))
}
```

> **Expected Output:**
> ```
> [1 2 3 4]
> Length: 4
> ```

### 5.2 Maps

Maps are key-value pairs (hash tables).

```go
m := make(map[string]int)
m["Alice"] = 25
fmt.Println(m["Alice"])
```

---

## 🔨 Practice Problem 5.1
Create a slice of three strings (your favorite fruits). Append a fourth fruit to the slice and print the result.

---

## Chapter 6: Functions

### 6.1 Multiple Return Values

Go functions can return multiple values, which is often used for returning errors.

```go
package main

import "fmt"

func swap(x, y string) (string, string) {
    return y, x
}

func main() {
    a, b := swap("hello", "world")
    fmt.Println(a, b)
}
```

> **Expected Output:**
> ```
> world hello
> ```

---

## 🔨 Practice Problem 6.1
Write a function `divide(a, b float64) (float64, bool)` that returns the result of the division and `true` if successful, or `0, false` if the divisor is zero.

---

## Chapter 7: Pointers

### 7.1 Using Pointers

Pointers hold the memory address of a value. Use `&` to get an address and `*` to dereference.

```go
package main

import "fmt"

func main() {
    x := 10
    ptr := &x
    
    fmt.Println("Address:", ptr)
    fmt.Println("Value:", *ptr)
    
    *ptr = 20 // Change value through pointer
    fmt.Println("New x:", x)
}
```

> **Expected Output:**
> ```
> Address: 0x... (some address)
> Value: 10
> New x: 20
> ```

---

## 🔨 Practice Problem 7.1
Write a function `zero(xptr *int)` that sets the value of the integer pointed to by `xptr` to 0.

---

## Chapter 8: Structs and Methods

### 8.1 Structs

Structs are collections of fields.

```go
type Person struct {
    Name string
    Age  int
}
```

### 8.2 Methods (Receiver Functions)

Methods are functions with a special receiver argument.

```go
package main

import "fmt"

type Circle struct {
    Radius float64
}

func (c Circle) Area() float64 {
    return 3.14 * c.Radius * c.Radius
}

func main() {
    c := Circle{Radius: 5}
    fmt.Println("Area:", c.Area())
}
```

> **Expected Output:**
> ```
> Area: 78.5
> ```

---

## 🔨 Practice Problem 8.1
Define a struct `Rectangle` with `Width` and `Height`. Add a method `Area()` that returns the area of the rectangle.

---

## Chapter 9: Interfaces

### 9.1 Defining and Implementing Interfaces

Interfaces are sets of method signatures. A type implements an interface by implementing its methods—no explicit `implements` keyword is needed.

```go
package main

import "fmt"

type Shape interface {
    Area() float64
}

type Square struct {
    Side float64
}

func (s Square) Area() float64 {
    return s.Side * s.Side
}

func printArea(s Shape) {
    fmt.Println("Area:", s.Area())
}

func main() {
    sq := Square{Side: 4}
    printArea(sq)
}
```

> **Expected Output:**
> ```
> Area: 16
> ```

---

## 🔨 Practice Problem 9.1
Define an interface `Speaker` with a method `Speak() string`. Implement it for a `Dog` struct (returns "Woof") and a `Cat` struct (returns "Meow").

---

## Chapter 10: Error Handling

### 10.1 The `error` Type

In Go, errors are values. Functions often return an `error` as the last return value.

```go
package main

import (
    "errors"
    "fmt"
)

func checkAge(age int) error {
    if age < 18 {
        return errors.New("Too young")
    }
    return nil
}

func main() {
    err := checkAge(15)
    if err != nil {
        fmt.Println("Error:", err)
    }
}
```

> **Expected Output:**
> ```
> Error: Too young
> ```

---

## 🔨 Practice Problem 10.1
Modify your division function from Practice Problem 6.1 to return an `error` instead of a `bool` when the divisor is zero.

---

## Chapter 11: Concurrency (Goroutines and Channels)

### 11.1 Goroutines

A goroutine is a lightweight thread managed by the Go runtime. Use the `go` keyword.

### 11.2 Channels

Channels are the pipes that connect concurrent goroutines. You can send values from one goroutine into channels and receive those values into another goroutine.

```go
package main

import "fmt"

func sum(s []int, c chan int) {
    total := 0
    for _, v := range s {
        total += v
    }
    c <- total // Send total to channel c
}

func main() {
    s := []int{7, 2, 8, -9, 4, 0}
    c := make(chan int)
    
    go sum(s[:len(s)/2], c)
    go sum(s[len(s)/2:], c)
    
    x, y := <-c, <-c // Receive from c
    
    fmt.Println(x, y, x+y)
}
```

> **Expected Output:**
> ```
> -5 17 12
> ```

---

## 🔨 Practice Problem 11.1
Create a channel and a goroutine that sends the string "Done" into the channel. In the main function, wait for the string and print it.

---
*Go Fundamentals Mastery Guide*
