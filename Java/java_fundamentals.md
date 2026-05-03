# Java Fundamentals: A Comprehensive Guide

This tutorial breaks down Java programming into digestible units with detailed explanations and hands-on exercises: each topic states the idea, shows the syntax, and includes a short program you can type and run, in the textbook rhythm of classic structured-language courses (Balagurusamy-style progression, Kanetkar-style concise examples). You are expected to arrive with solid **C++** coverage—expressions, control flow, classes, templates at the level of everyday use, and typical memory and linkage intuition—so those foundations are not re-taught. Familiar-looking syntax inherited from the broader C family is not treated as proof that Java behaves like C++; everything below is described exactly as the Java language and libraries specify it.

---

## Chapter 1: Variables and Basic Data Types

### 1.1 Understanding Variables in Java

In Java, **local variables** do not receive default values—you must assign before use. A local declared with a type and name is **mutable**: you may assign to it again until it goes out of scope. If you want a variable that cannot be rebound, mark it `final`; after initialization, the compiler rejects further assignment. Using `final` wherever the slot should not change is a useful discipline—it narrows how far you must look when reasoning about the program.

```java
public class Main {
    public static void main(String[] args) {
        int age = 25;           // can be reassigned
        age = 26;

        final int year = 2026; // cannot be reassigned
        // year = 2027;        // compile-time error

        int counter = 0;
        counter = counter + 1;

        System.out.println("Age: " + age + ", Counter: " + counter + ", Year: " + year);
    }
}
```

**Key Points:**

- Local variables must be initialized before read.
- Use `final` when the local must not be reassigned after its first assignment.
- Java naming convention for variables and methods is **camelCase**; classes use **PascalCase**.
- The compiler performs **type checking**; types are explicit at declaration (with limited inference for local variables since Java 10).

### 1.2 Primitive Data Types

Java has eight **primitive** types. Everything else is a **reference type** (object).

**Integer types (all signed except `char` is unsigned 16-bit Unicode):**

- `byte` (8 bits), `short` (16), `int` (32), `long` (64)

**Floating-point:**

- `float` (32 bits, suffix `F` or `f`), `double` (64 bits, default for literals like `3.14`)

**Other primitives:**

- `boolean` (`true` / `false` only—no conversion from integers)
- `char` (single 16-bit UTF-16 code unit; not the same as a full abstract Unicode “character” in all cases)

```java
public class Primitives {
    public static void main(String[] args) {
        int integer = -42;
        long big = 1_000_000_000L;
        double pi = 3.14159;
        float approx = 3.14F;
        boolean active = true;
        char letter = 'A';

        System.out.println("int: " + integer);
        System.out.println("long: " + big);
        System.out.println("double: " + pi);
        System.out.println("float: " + approx);
        System.out.println("boolean: " + active);
        System.out.println("char: " + letter);
    }
}
```

### 1.3 Type Conversion (Widening and Narrowing)

**Widening** conversions (e.g., `int` → `long`, `int` → `double`) are allowed implicitly when there is no loss of magnitude information in the usual sense. **Narrowing** (e.g., `long` → `int`, `double` → `int`) requires an explicit **cast**, because precision or range may be lost.

```java
public class Conversions {
    public static void main(String[] args) {
        int a = 10;
        double b = a;          // widening: int to double

        double x = 9.7;
        int y = (int) x;       // narrowing: truncates toward zero → 9

        System.out.println("b = " + b);
        System.out.println("y = " + y);
    }
}
```

**Caution:** Narrowing casts can silently produce surprising values if the value is out of range for the target type.

---

## 🔨 Exercise 1.1

Write a program that converts temperature from **Celsius to Fahrenheit** using the formula \(F = (C \times 9 / 5) + 32\). Store Celsius in a variable, compute Fahrenheit in another, and print both. Use a `final` for the conversion factor \(9/5\) if you express it as separate constants—explain in a one-line comment why `final` is appropriate there.

---

## Chapter 2: Methods and Control Flow

### 2.1 Defining Methods

A **method** belongs to a class. `static` methods belong to the class itself and can be called without an instance—handy for `main` and small learning examples.

```java
public class Calculator {

    public static int add(int a, int b) {
        return a + b;
    }

    public static int multiply(int a, int b) {
        return a * b;
    }

    public static void main(String[] args) {
        int sum = add(5, 3);
        int product = multiply(5, 3);
        System.out.println("5 + 3 = " + sum);
        System.out.println("5 * 3 = " + product);
    }
}
```

**Key Points:**

- Return type appears before the method name; `void` means no value returned.
- Java is **pass-by-value**: for primitives, the value is copied; for references, the reference value is copied (so mutating the object through the reference affects the shared object).

### 2.2 Control Flow: if–else

Conditions must be of type `boolean`. There is no truthiness for integers or references.

```java
public class Branching {
    public static void main(String[] args) {
        int number = 7;

        if (number < 5) {
            System.out.println("Number is less than 5");
        } else if (number == 5) {
            System.out.println("Number is exactly 5");
        } else {
            System.out.println("Number is greater than 5");
        }
    }
}
```

### 2.3 Loops: while, for, enhanced for

Java provides `while`, `do-while`, traditional `for`, and the **enhanced for** loop for iterating over arrays and `Iterable` collections.

```java
public class Loops {
    public static void main(String[] args) {
        // while
        int n = 3;
        while (n != 0) {
            System.out.println(n + "!");
            n--;
        }
        System.out.println("LIFTOFF!");

        // traditional for
        for (int i = 0; i < 5; i++) {
            System.out.println("i = " + i);
        }

        // enhanced for over an array
        int[] values = {10, 20, 30};
        for (int v : values) {
            System.out.println("value: " + v);
        }
    }
}
```

---

## 🔨 Exercise 2.1

Write a **static** method `long factorial(int n)` that returns the factorial of a non-negative integer \(n\) using a loop. For invalid input (\(n < 0\)), return `-1` to signal error, or document that you only support \(n \geq 0\). In `main`, test with `n = 5` and print the result (expect `120`).

---

## Chapter 3: Objects, References, and Memory

### 3.1 Reference Types and the Heap

When you write `String s = new String("hello");`, the variable `s` holds a **reference** to an object on the **heap**. Java manages memory with a **garbage collector**; you do not manually `free` objects. When no live references can reach an object, it becomes eligible for collection.

```java
public class References {
    public static void main(String[] args) {
        String a = new String("hello");
        String b = a;              // b points to the same object as a
        System.out.println(a == b); // true: same reference

        String c = new String("hello");
        System.out.println(a == c); // false: different objects
        System.out.println(a.equals(c)); // true: same character content
    }
}
```

**Key Points:**

- Use `==` for reference identity (same object) or primitive equality.
- Use `.equals(...)` for **value equality** on objects like `String`.

### 3.2 Pass-by-Value Illustrated

```java
public class PassByValue {

    static void bump(int x) {
        x = x + 1; // only the copy changes
    }

    static void appendHello(StringBuilder sb) {
        sb.append("hello"); // mutates the object through the copied reference
    }

    public static void main(String[] args) {
        int k = 1;
        bump(k);
        System.out.println("k after bump: " + k); // still 1

        StringBuilder builder = new StringBuilder();
        appendHello(builder);
        System.out.println("builder: " + builder); // hello
    }
}
```

### 3.3 `null` and Defensive Habits

Reference variables can hold `null`. Dereferencing `null` causes a `NullPointerException` at runtime. Prefer **null-hostile APIs** (return empty collections, use `Optional` where appropriate) and validate inputs in larger programs.

---

## 🔨 Exercise 3.1

Write a method `static int max(int[] values)` that returns the largest element in a non-empty array. Do **not** modify the array contents. Document the behavior if the array is empty (throw an exception, return a sentinel, or require non-empty—pick one and state it in a comment).

---

## Chapter 4: Classes, Records, and Enums

### 4.1 Classes and Objects

A **class** is a blueprint; an **object** is an instance. **Fields** hold state; **methods** implement behavior. **Constructors** initialize new instances.

```java
public class User {
    private final String username;
    private final String email;
    private boolean active;
    private long signInCount;

    public User(String username, String email) {
        this.username = username;
        this.email = email;
        this.active = true;
        this.signInCount = 1;
    }

    public String getUsername() {
        return username;
    }

    public String getEmail() {
        return email;
    }

    public boolean isActive() {
        return active;
    }

    public void setActive(boolean active) {
        this.active = active;
    }

    public long getSignInCount() {
        return signInCount;
    }

    public void incrementSignIn() {
        signInCount++;
    }
}
```

**Encapsulation:** `private` fields with **accessors** (`getX`, `setX`) is the conventional Java idiom (JavaBeans style), though modern code sometimes uses **records** for simple data carriers.

### 4.2 Records (Java 16+)

A **record** is a compact, immutable-by-default data aggregate: the compiler generates constructor, accessors, `equals`, `hashCode`, and `toString`.

```java
public record Point(int x, int y) {
    public double distanceFromOrigin() {
        return Math.hypot(x, y);
    }
}
```

### 4.3 Enums

An **enum** is a type-safe fixed set of constants. Enum constants can have fields, constructors, and methods.

```java
public enum Message {
    QUIT,
    MOVE,
    WRITE,
    CHANGE_COLOR
}

public class EnumDemo {
    public static void describe(Message m) {
        switch (m) {
            case QUIT -> System.out.println("Quit");
            case MOVE -> System.out.println("Move");
            case WRITE -> System.out.println("Write");
            case CHANGE_COLOR -> System.out.println("Change color");
        }
    }

    public static void main(String[] args) {
        describe(Message.MOVE);
    }
}
```

---

## 🔨 Exercise 4.1

Define a `Circle` **class** with a private `double radius`, a constructor, and methods `getRadius()`, `area()` (\(\pi r^2\)), and `circumference()` (\(2\pi r\)). Then define an enum `ShapeKind { CIRCLE, RECTANGLE }` and a **record** `ShapeData(ShapeKind kind, double a, double b)` where for a circle `a` is radius and `b` is ignored, and for a rectangle `a` and `b` are width and height. Write a method `static double area(ShapeData s)` that returns the area for either kind.

---

## Chapter 5: `switch` and Pattern Matching (Modern Java)

### 5.1 `switch` Statements and Expressions

Since Java 14, **`switch` can be an expression** that yields a value. Combined with arrow labels `->`, fall-through bugs are reduced.

```java
public class SwitchExpr {
    enum Coin { PENNY, NICKEL, DIME, QUARTER }

    public static int cents(Coin c) {
        return switch (c) {
            case PENNY -> 1;
            case NICKEL -> 5;
            case DIME -> 10;
            case QUARTER -> 25;
        };
    }

    public static void main(String[] args) {
        System.out.println(cents(Coin.DIME));
    }
}
```

### 5.2 Exhaustiveness

With `switch` on an `enum`, the compiler can verify that **all constants are handled** (when not using `default`). Omitting a branch is then a compile-time error, which makes `enum`-centric control flow safer than loosely typed alternatives.

### 5.3 Pattern Matching for `switch` (Preview/Standard in recent JDKs)

Depending on your JDK version, **pattern matching in `switch`** allows type patterns and guarded cases. Consult your JDK release notes; the idea is to replace chains of `if (x instanceof T)` casts with a single clear `switch`.

```java
public class PatternSwitchDemo {
    public static String asString(Object o) {
        return switch (o) {
            case null -> "null";
            case Integer i -> "Integer: " + i;
            case String s -> "String: " + s;
            default -> "Other: " + o;
        };
    }

    public static void main(String[] args) {
        System.out.println(asString(42));
        System.out.println(asString("hi"));
    }
}
```

*Note:* Pattern `switch` on `Object` requires a recent Java version (21+ for many patterns in production). If your compiler rejects this example, treat it as a preview of style and use classic `instanceof` until you upgrade.

---

## 🔨 Exercise 5.1

Write a method `static String gradeDescription(String grade)` where `grade` is one of `"A"`, `"B"`, `"C"`, `"D"`, `"F"` (use `String`, not `char`, for simplicity). Map each to a short description (e.g., `"A"` → `"Excellent"`). Use a **`switch` expression**. Return `"Unknown"` for any other input.

---

## Chapter 6: `Optional` and Basic Error Handling

### 6.1 `Optional<T>`

`Optional` models an object that may or may not be present. It is intended as a **return type**, not a field type, for APIs that might “find nothing.” Avoid `Optional.get()` without `isPresent`; prefer `orElse`, `orElseThrow`, `ifPresent`, or functional-style methods.

```java
import java.util.Optional;

public class OptionalDemo {
    public static Optional<String> findUser(int id) {
        if (id == 1) {
            return Optional.of("Alice");
        }
        return Optional.empty();
    }

    public static void main(String[] args) {
        findUser(1).ifPresent(name -> System.out.println("Found: " + name));

        String guest = findUser(999).orElse("Guest");
        System.out.println("Name: " + guest);
    }
}
```

### 6.2 Exceptions: Checked and Unchecked

Java uses **exceptions** for many failure paths. **Checked** exceptions (subtypes of `Exception` but not `RuntimeException`) must be declared or handled. **Unchecked** exceptions (`RuntimeException` and its subclasses) do not require `throws` on every caller.

```java
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class ReadFileDemo {
    public static String readAll(Path path) throws IOException {
        return Files.readString(path);
    }

    public static void main(String[] args) {
        try {
            String content = readAll(Path.of("example.txt"));
            System.out.println(content);
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}
```

### 6.3 try-with-resources

For types implementing `AutoCloseable`, **try-with-resources** closes them reliably.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class TryWithResources {
    public static void main(String[] args) throws IOException {
        Path p = Path.of("lines.txt");
        try (BufferedReader reader = Files.newBufferedReader(p)) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        }
    }
}
```

---

## 🔨 Exercise 6.1

Write a method `static double divide(double a, double b)` that returns `a / b`. If `b == 0`, **throw** an `IllegalArgumentException` with the message `"divisor is zero"`. In `main`, call it inside a `try`/`catch` and print a friendly message when the exception occurs.

---

## Chapter 7: Collections Framework

### 7.1 `List` and `ArrayList`

The `List` interface describes ordered sequences. `ArrayList` is a resizable-array implementation—amortized \(O(1)\) append at the end, \(O(n)\) insert in the middle.

```java
import java.util.ArrayList;
import java.util.List;

public class ListDemo {
    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);

        int third = numbers.get(2);
        System.out.println("Third element: " + third);

        for (int n : numbers) {
            System.out.println(n);
        }
    }
}
```

### 7.2 `Map` and `HashMap`

A **map** associates keys to values. `HashMap` provides average \(O(1)\) get/put for good hash functions.

```java
import java.util.HashMap;
import java.util.Map;

public class MapDemo {
    public static void main(String[] args) {
        Map<String, Integer> scores = new HashMap<>();
        scores.put("Blue", 10);
        scores.put("Yellow", 50);

        Integer blue = scores.get("Blue");
        System.out.println("Blue team: " + blue);

        for (Map.Entry<String, Integer> e : scores.entrySet()) {
            System.out.println(e.getKey() + ": " + e.getValue());
        }
    }
}
```

### 7.3 `Set`

A `Set` holds unique elements. `HashSet` is a common implementation.

```java
import java.util.HashSet;
import java.util.Set;

public class SetDemo {
    public static void main(String[] args) {
        Set<String> names = new HashSet<>();
        names.add("Ann");
        names.add("Bob");
        names.add("Ann");
        System.out.println(names.size()); // 2
    }
}
```

---

## 🔨 Exercise 7.1

Write a program that counts how many times each **word** appears in a sentence. Split on whitespace, normalize case if you wish, and store counts in a `Map<String, Integer>`. Print each word and its count.

---

## Chapter 8: Generics

### 8.1 Generic Classes and Methods

**Generics** let you parameterize types: `List<String>` is a list of strings; the compiler prevents adding `Integer` by mistake. At runtime, most generic type information is **erased** (type erasure)—reflection and some APIs require awareness of this limitation.

```java
import java.util.List;

public class GenericMethod {
    public static <T> void printFirst(List<T> items) {
        if (!items.isEmpty()) {
            System.out.println(items.get(0));
        }
    }

    public static void main(String[] args) {
        printFirst(List.of("a", "b", "c"));
        printFirst(List.of(1, 2, 3));
    }
}
```

### 8.2 Bounded Type Parameters

You can constrain `T` to extend a class or implement interfaces.

```java
public class Bounded {
    public static <T extends Comparable<T>> T max(T a, T b) {
        return a.compareTo(b) >= 0 ? a : b;
    }

    public static void main(String[] args) {
        System.out.println(max("apple", "banana"));
        System.out.println(max(10, 20));
    }
}
```

### 8.3 Wildcards (`? extends`, `? super`)

**PECS** mnemonic: **Producer `extends`**, **Consumer `super`**. Use `? extends T` when you only read `T` out; use `? super T` when you write `T` in (e.g., sorting into a `Comparator`).

---

## 🔨 Exercise 8.1

Write a generic method `static <T> void swap(T[] arr, int i, int j)` that swaps two indices in an array. Test with `Integer[]` and `String[]`. Explain in a comment why you cannot use primitive `int[]` with this method without overloads or arrays of wrappers.

---

## Chapter 9: Object-Oriented Programming in Java

### 9.1 Encapsulation and Access Control

Java supports **packages** and access modifiers: `public`, `protected`, package-private (no modifier), and `private`. Typical beans hide fields and expose methods.

```java
public class BankAccount {
    private final String accountHolder;
    private double balance;

    public BankAccount(String accountHolder, double initialBalance) {
        this.accountHolder = accountHolder;
        this.balance = initialBalance;
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            throw new IllegalArgumentException("Deposit amount must be positive");
        }
        balance += amount;
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            throw new IllegalArgumentException("Withdrawal amount must be positive");
        }
        if (amount > balance) {
            throw new IllegalStateException("Insufficient funds");
        }
        balance -= amount;
    }

    public double getBalance() {
        return balance;
    }

    public String getAccountHolder() {
        return accountHolder;
    }
}
```

### 9.2 Interfaces and Polymorphism

An **interface** declares behavior without implementation (except `default` and `static` methods since Java 8). A class **implements** one or more interfaces.

```java
interface Speak {
    String speak();

    default String describe() {
        return "I am a " + getClass().getSimpleName();
    }
}

interface Move {
    String move();
}

final class Dog implements Speak, Move {
    private final String name;

    Dog(String name) {
        this.name = name;
    }

    @Override
    public String speak() {
        return name + " says Woof!";
    }

    @Override
    public String move() {
        return name + " runs on four legs";
    }
}

final class Bird implements Speak, Move {
    private final String name;

    Bird(String name) {
        this.name = name;
    }

    @Override
    public String speak() {
        return name + " says Tweet!";
    }

    @Override
    public String move() {
        return name + " flies with wings";
    }
}

public class PolymorphismDemo {
    public static void animalShow(Speak animal) {
        System.out.println(animal.speak());
        System.out.println(animal.describe());
    }

    public static void main(String[] args) {
        animalShow(new Dog("Buddy"));
        animalShow(new Bird("Tweety"));
    }
}
```

### 9.3 Inheritance vs Composition

Java supports **class inheritance** with `extends` (single inheritance). Favor **composition** (an object has-a helper) when behavior sharing would create fragile hierarchies.

```java
interface Vehicle {
    void start();

    void stop();
}

final class Car implements Vehicle {
    private final String make;
    private final String model;

    Car(String make, String model) {
        this.make = make;
        this.model = model;
    }

    @Override
    public void start() {
        System.out.println(make + " " + model + " engine starting...");
    }

    @Override
    public void stop() {
        System.out.println(make + " " + model + " engine stopped.");
    }
}

final class Engine {
    private final int horsepower;

    Engine(int horsepower) {
        this.horsepower = horsepower;
    }

    void start() {
        System.out.println("Engine with " + horsepower + " HP starting...");
    }
}

final class CarWithEngine {
    private final String make;
    private final String model;
    private final Engine engine;

    CarWithEngine(String make, String model, int hp) {
        this.make = make;
        this.model = model;
        this.engine = new Engine(hp);
    }

    void startCar() {
        engine.start();
        System.out.println(make + " " + model + " is ready to drive!");
    }
}
```

### 9.4 Polymorphism at Runtime

Use **interface types** or **superclass types** for parameters and fields so implementations can vary.

---

## 🔨 Exercise 9.1

Define an interface `Shape` with methods `double area()` and `double perimeter()`. Implement `Circle` and `Rectangle`. Write a method `static void printSummaries(List<Shape> shapes)` that prints area and perimeter for each shape. Store different shapes in one `ArrayList<Shape>`.

---

## Chapter 10: Exceptions in Depth

### 10.1 try / catch / finally

**`finally`** runs after `try` whether or not an exception occurred (almost always—see JVM spec for edge cases). Prefer try-with-resources for closables instead of manual `close()` in `finally` when possible.

```java
public class FinallyDemo {
    public static int parseAndSum(String data) {
        int sum = 0;
        for (String token : data.trim().split("\\s+")) {
            sum += Integer.parseInt(token);
        }
        return sum;
    }

    public static void main(String[] args) {
        try {
            System.out.println(parseAndSum("10 20 30"));
            System.out.println(parseAndSum("10 abc 30"));
        } catch (NumberFormatException e) {
            System.out.println("Invalid number: " + e.getMessage());
        }
    }
}
```

### 10.2 Custom Exceptions

Model domain failures with your own types. Checked vs unchecked is a design choice: libraries often prefer unchecked for programming errors and checked for recoverable conditions—modern APIs increasingly use unchecked + rich error types.

```java
public class PaymentException extends Exception {
    public PaymentException(String message) {
        super(message);
    }
}

public final class PaymentProcessor {
    public static void pay(double amount, double balance) throws PaymentException {
        if (balance < amount) {
            throw new PaymentException(
                    "Insufficient funds: have $" + balance + ", need $" + amount);
        }
        System.out.println("Payment of $" + amount + " processed successfully");
    }

    public static void main(String[] args) {
        try {
            pay(150.0, 100.0);
        } catch (PaymentException e) {
            System.out.println("Error: " + e.getMessage());
        }

        try {
            pay(50.0, 100.0);
        } catch (PaymentException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```

### 10.3 Chaining and Stack Traces

Use `initCause` or constructor `super(cause)` to **chain** exceptions, preserving context for logs.

---

## 🔨 Exercise 10.1

Write a method that reads **all lines** from a text file, splits each line on commas, and parses each field as `int`, accumulating a running total across all lines. Define a **custom checked** exception `DataParseException` for bad input and wrap underlying `IOException` appropriately. Handle errors in `main` and print clear messages.

---

## Chapter 11: Generics: Wildcards and API Design

### 11.1 Reading vs Writing with Wildcards

```java
import java.util.ArrayList;
import java.util.List;

public class WildcardDemo {
    public static double sumNumbers(List<? extends Number> numbers) {
        double total = 0.0;
        for (Number n : numbers) {
            total += n.doubleValue();
        }
        return total;
    }

    public static void addIntegers(List<? super Integer> sink) {
        sink.add(1);
        sink.add(2);
        sink.add(3);
    }

    public static void main(String[] args) {
        List<Integer> ints = new ArrayList<>();
        addIntegers(ints);
        System.out.println("Sum: " + sumNumbers(ints));
    }
}
```

### 11.2 Type Erasure and Bridge Methods

The compiler inserts **bridge methods** to preserve polymorphism after erasure. You rarely write these by hand, but stack traces may mention them.

---

## 🔨 Exercise 11.1

Implement a small generic **pair** class `Pair<A, B>` with `A first()` and `B second()` accessors. Write a static method `static <A, B> Pair<B, A> swap(Pair<A, B> p)` that returns a new pair with components reversed. Test with `Pair<String, Integer>`.

---

## Chapter 12: File Handling in Java

### 12.1 `java.nio.file.Files` (Modern Style)

The `java.nio.file` API is the preferred starting point for simple file operations.

```java
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class FilesReadWrite {
    public static void main(String[] args) throws IOException {
        Path path = Path.of("sample.txt");
        String data = "Hello, Java File I/O!\nThis is line 2.\nLine 3 here.";
        Files.writeString(path, data);

        String content = Files.readString(path);
        System.out.println("File contents:\n" + content);

        byte[] bytes = Files.readAllBytes(path);
        System.out.println("Bytes read: " + bytes.length);

        Files.deleteIfExists(path);
    }
}
```

### 12.2 Appending and Buffered I/O

For large files or line-oriented processing, combine `BufferedReader` / `BufferedWriter` with channels or streams as appropriate.

```java
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;

public class AppendDemo {
    public static void main(String[] args) throws IOException {
        Path log = Path.of("log.txt");
        Files.writeString(log, "Application started\n", StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING);

        try (BufferedWriter w = Files.newBufferedWriter(log, StandardCharsets.UTF_8,
                StandardOpenOption.CREATE, StandardOpenOption.APPEND)) {
            w.write("User logged in\n");
            w.write("Data processed\n");
        }

        System.out.println(Files.readString(log));
        Files.deleteIfExists(log);
    }
}
```

### 12.3 Walking Lines

```java
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class LineCount {
    public static long countLines(Path path) throws IOException {
        return Files.lines(path).count();
    }

    public static void main(String[] args) throws IOException {
        Path csv = Path.of("data.csv");
        Files.writeString(csv, "Name,Age,City\nAlice,25,NYC\nBob,30,LA\n");
        System.out.println("Lines: " + countLines(csv));
        Files.deleteIfExists(csv);
    }
}
```

---

## 🔨 Exercise 12.1

Write a program that **copies** one file to another using `Files.copy(...)`. Write a second version that copies using a manual loop with `InputStream` / `OutputStream` (or `newInputStream` / `newOutputStream`) and a byte buffer. Delete temporary files after the demo.

---

## Chapter 13: Data Structures: Stack and Linked List

### 13.1 Stack (LIFO) with `Deque`

The Java collections library offers `ArrayDeque`, which implements `Deque` and is an excellent **stack** (prefer it over legacy `Stack` class).

```java
import java.util.ArrayDeque;
import java.util.Deque;

public class StackDemo {
    public static String reverse(String input) {
        Deque<Character> stack = new ArrayDeque<>();
        for (char ch : input.toCharArray()) {
            stack.push(ch);
        }
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Deque<Integer> s = new ArrayDeque<>();
        s.push(1);
        s.push(2);
        s.push(3);
        System.out.println("pop: " + s.pop());
        System.out.println("peek: " + s.peek());
        System.out.println(reverse("Hello"));
    }
}
```

### 13.2 Linked List

`LinkedList` implements both `List` and `Deque`. It shines when you frequently add/remove at both ends; random access by index is \(O(n)\).

```java
import java.util.LinkedList;
import java.util.List;

public class LinkedListDemo {
    public static void main(String[] args) {
        List<String> list = new LinkedList<>();
        list.add("A");
        list.add("B");
        list.addFirst("Z"); // Deque method on LinkedList
        System.out.println(list);
    }
}
```

### 13.3 When to Choose Which

- Frequent indexed access: `ArrayList`.
- Frequent middle inserts with iterator: sometimes `LinkedList`; often still `ArrayList` wins in practice—**measure**.
- Stack/queue semantics: `ArrayDeque`.

---

## 🔨 Exercise 13.1

Implement a class `MinStack` supporting `push(int)`, `pop()`, `top()`, and `getMin()` in **amortized \(O(1)\)** time each. You may use an auxiliary stack or store pairs. Push the sequence `5, 3, 7, 2, 8` and print `getMin()` after relevant operations to show it updates correctly.

---

## Chapter 14: Debugging and Testing

### 14.1 Logging with `java.util.logging`

For learning and small apps, the platform logger is enough; larger systems often use SLF4J + Logback.

```java
import java.util.logging.Logger;

public class LoggingDemo {
    private static final Logger LOG = Logger.getLogger(LoggingDemo.class.getName());

    public static void main(String[] args) {
        LOG.info("Application start");
        int x = 42;
        LOG.fine("x = " + x); // may not show unless level configured
    }
}
```

### 14.2 Assertions

Enable assertions with `java -ea ...`. Use for **internal invariants**, not for user input validation.

```java
public class AssertDemo {
    public static int sumPositive(int a, int b) {
        assert a > 0 && b > 0 : "arguments must be positive";
        return a + b;
    }

    public static void main(String[] args) {
        System.out.println(sumPositive(2, 3));
    }
}
```

### 14.3 JUnit Basics (JUnit 5)

```java
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class CalculatorTest {
    @Test
    void addsTwoNumbers() {
        assertEquals(5, Calculator.add(2, 3));
    }
}
```

*Setup:* Add JUnit 5 to your build tool (`Maven`/`Gradle`) or IDE project. Run tests from the IDE or `./mvnw test` / `gradle test`.

### 14.4 IDE Debugger

Set **breakpoints**, **step over** (`F8` in many IDEs), **step into** (`F7`), inspect **variables** and the **call stack**, and use **conditional breakpoints** for rare cases.

---

## 🔨 Exercise 14.1

Write a method that is **intentionally wrong** (e.g., returns the average of an `int[]` using integer division incorrectly). Add logging or temporary prints to trace intermediate values, find the bug, fix it, and convert the checks into a **JUnit** test that would have failed before the fix.

---

## Chapter 15: Advanced Topics Quick Reference

### 15.1 Lambdas and Functional Interfaces

A **functional interface** has exactly one abstract method (e.g., `Runnable`, `Comparator`, `java.util.function.Predicate`).

```java
import java.util.List;
import java.util.function.Predicate;

public class LambdaDemo {
    public static void main(String[] args) {
        List<Integer> nums = List.of(1, 2, 3, 4, 5);
        Predicate<Integer> even = n -> n % 2 == 0;
        nums.stream().filter(even).forEach(System.out::println);
    }
}
```

### 15.2 Streams (java.util.stream)

**Streams** support declarative bulk operations. Prefer **side-effect-free** stream pipelines; collect results with `toList()` / `collect(...)`.

```java
import java.util.List;

public class StreamDemo {
    public static void main(String[] args) {
        List<Integer> nums = List.of(1, 2, 3, 4, 5);
        int sum = nums.stream().mapToInt(Integer::intValue).sum();
        System.out.println("sum: " + sum);
    }
}
```

### 15.3 Concurrency Teaser

`Thread` represents a thread of execution. `start()` begins asynchronous execution; `join()` waits for completion. Checked `InterruptedException` must be handled or declared.

```java
public class ThreadDemo {
    public static void main(String[] args) throws InterruptedException {
        Thread worker = new Thread(() -> {
            for (int i = 1; i < 5; i++) {
                System.out.println("worker: " + i);
            }
        });
        worker.start();
        for (int i = 1; i < 5; i++) {
            System.out.println("main: " + i);
        }
        worker.join();
        System.out.println("done");
    }
}
```

**Common mistake:** writing `main(String[] throws InterruptedException`—`throws` belongs after the parameter list, not inside it.

---

## 🔨 Exercise 15.1

Modify `ThreadDemo` so the worker thread calls `Thread.sleep` for a short duration (for example 50 ms) inside its loop, while the main thread also sleeps with a different delay. Keep `join()` at the end. Run several times and observe how scheduling makes the output **non-deterministic** across runs.

---

## Summary of Key Concepts

1. **Primitives vs references**: eight primitives; everything else is an object reference subject to GC.
2. **Equality**: `==` vs `.equals`.
3. **OOP**: classes, interfaces, inheritance, composition; enums and records for modeling.
4. **Exceptions**: checked vs unchecked; try-with-resources; custom types.
5. **Collections**: `List`, `Map`, `Set`; choose implementations for access patterns.
6. **Generics**: type safety at compile time; erasure at runtime; wildcards (PECS).
7. **File I/O**: `java.nio.file.Files` for common tasks; buffered APIs for scale.
8. **Data structures**: `Deque` for stack; `LinkedList` when it fits.
9. **Debugging**: logging, assertions, JUnit, IDE debugger.
10. **Modern Java**: lambdas, streams, enhanced `switch`, records.

---

## Project Ideas to Practice

1. **Todo list** — serialize tasks to a file; load on startup (`List` + `Files`).
2. **Calculator** — parse input strings; use `enum` for operators and `switch` expressions.
3. **Bank accounts** — encapsulation, interfaces for interest policies, unit tests.
4. **Expression evaluator** — `MinStack` or classic two-stack algorithm.
5. **Text analyzer** — word frequency maps, streams, and reporting.
