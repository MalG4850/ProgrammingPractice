# Advanced Java: Beyond the Fundamentals

This guide picks up where a systematic Java fundamentals course leaves off: concurrency APIs, the memory model, modular builds, reflection boundaries, I/O and persistence patterns, and tooling awareness. Each chapter presents the concept, shows idiomatic library usage, and ends with a focused exercise. The pacing follows the same textbook rhythm—structured exposition first, short runnable sketches second—without assuming knowledge outside mainstream Java SE APIs beyond core syntax and collections.

**Prerequisite:** You should already write confident Java using classes, interfaces, generics, exceptions, streams (`java.util.stream`), and file basics (`java.nio.file`). Familiarity with your IDE’s debugger and a build tool (`javac` plus manual classpath is enough to start; Maven or Gradle helps later projects).

---

## Chapter 1: Threads and the Executor Framework

### 1.1 Creating and Starting Threads

The low-level `Thread` type maps one-to-one with an OS thread (implementation-dependent details aside). Prefer higher-level executors for server-style workloads.

```java
public class ThreadBasics {
    public static void main(String[] args) throws InterruptedException {
        Thread worker = new Thread(() -> {
            System.out.println("worker: " + Thread.currentThread().getName());
        }, "demo-worker");
        worker.start();
        worker.join();
    }
}
```

**Key Points:**

- Never call `run()` directly if you intend asynchronous execution—use `start()`.
- Prefer passing `Runnable` (or `Callable` via executor) over subclassing `Thread`.

### 1.2 ExecutorService

**Executors** decouple task submission from thread lifecycle management.

```java
import java.util.concurrent.*;

public class ExecutorDemo {
    public static void main(String[] args) throws Exception {
        ExecutorService pool = Executors.newFixedThreadPool(2);
        try {
            Future<Integer> future = pool.submit(() -> {
                TimeUnit.MILLISECONDS.sleep(100);
                return 42;
            });
            System.out.println("result: " + future.get());
        } finally {
            pool.shutdown();
            if (!pool.awaitTermination(5, TimeUnit.SECONDS)) {
                pool.shutdownNow();
            }
        }
    }
}
```

Shutdown hygiene matters: `shutdown()` stops accepting new tasks; `awaitTermination` waits for running tasks; `shutdownNow` attempts interruption.

### 1.3 Callable vs Runnable

`Runnable` returns `void` and cannot throw checked exceptions from the lambda boundary without wrapping. `Callable<V>` returns `V` and allows throwing checked exceptions that surface via `Future.get()`.

---

## 🔨 Exercise 1.1

Create a fixed pool of size **4**. Submit **10** `Callable` tasks that each sleep a random duration (under 500 ms), return their sequence number, and collect results in submission order using `invokeAll` or individual `Future`s. Shut down the pool cleanly and print all returned integers.

---

## Chapter 2: CompletableFuture and Asynchronous Pipelines

### 2.1 Composing Async Steps

`CompletableFuture<T>` expresses asynchronous computation with composition operators (`thenApply`, `thenCompose`, `thenCombine`, etc.).

```java
import java.util.concurrent.*;

public class CfDemo {
    public static void main(String[] args) throws Exception {
        ExecutorService pool = Executors.newCachedThreadPool();
        try {
            CompletableFuture<String> cf = CompletableFuture
                    .supplyAsync(() -> fetchSlow(), pool)
                    .thenApply(String::toUpperCase);

            System.out.println(cf.get());
        } finally {
            pool.shutdown();
        }
    }

    static String fetchSlow() {
        try {
            TimeUnit.MILLISECONDS.sleep(50);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        return "hello";
    }
}
```

### 2.2 Error Handling

Use `exceptionally`, `handle`, or `whenComplete` to recover or observe failures without blocking prematurely.

```java
CompletableFuture<Integer> safe = CompletableFuture
        .supplyAsync(() -> { throw new IllegalStateException("boom"); })
        .exceptionally(ex -> -1);
```

### 2.3 Timing Caution

Async pipelines shift exceptions across threads—always decide where failures are logged or surfaced to callers.

---

## 🔨 Exercise 2.1

Write a method `CompletableFuture<Double> averageRemote(List<String> endpoints)` that (stubbed) calls each endpoint sequentially in async steps with `supplyAsync`, parses a string double from each (simulate with fixed strings), and combines them into an arithmetic mean using `thenCombine` / `thenCompose`. Use a shared executor and handle parse failures by substituting `0.0`.

---

## Chapter 3: Locks, Conditions, and Concurrent Collections

### 3.1 ReentrantLock

`ReentrantLock` offers explicit locking with optional fairness and condition variables—use when you need `tryLock`, timed lock attempts, or structured condition signaling beyond `wait`/`notify`.

```java
import java.util.concurrent.locks.*;

public class CounterLocked {
    private final Lock lock = new ReentrantLock();
    private int count;

    public void increment() {
        lock.lock();
        try {
            count++;
        } finally {
            lock.unlock(); // always unlock in finally
        }
    }

    public int get() {
        lock.lock();
        try {
            return count;
        } finally {
            lock.unlock();
        }
    }
}
```

### 3.2 Concurrent Collections

`ConcurrentHashMap`, `CopyOnWriteArrayList`, and queues from `java.util.concurrent` are tuned for concurrent access patterns—prefer them over wrapping ordinary collections with coarse synchronization unless profiling suggests otherwise.

### 3.3 Atomics

`AtomicInteger`, `AtomicReference`, etc., provide lock-free primitives suitable for counters and state machines when contention patterns fit.

---

## 🔨 Exercise 3.1

Implement a **bounded buffer** (capacity `N`) using `ReentrantLock` and **two** `Condition`s (`notFull`, `notEmpty`). Provide `void put(T item)` and `T take()` blocking semantics. Write a small harness with multiple producers and consumers.

---

## Chapter 4: The Java Memory Model and `volatile`

### 4.1 Visibility and Ordering

Without synchronization, one thread may observe stale field values due to caching and instruction reordering. The **Java Memory Model** defines **happens-before** rules: actions ordered by synchronization, lock release/acquire, `volatile` reads/writes, and thread lifecycle edges.

### 4.2 `volatile`

Marking a field `volatile` ensures writes are visible to subsequent reads by other threads (with specified ordering constraints relative to other volatile and synchronization actions). It does **not** make compound updates atomic—`count++` still races unless guarded.

```java
public class StopFlag {
    private volatile boolean stopped;

    public void stop() {
        stopped = true;
    }

    public boolean isStopped() {
        return stopped;
    }
}
```

### 4.3 Safe Publication

Constructors complete before references escape unless unsafe publication lets another thread observe partially constructed state—avoid leaking `this` from constructors to alien threads.

---

## 🔨 Exercise 4.1

Demonstrate a **visibility bug**: two threads sharing a non-volatile `boolean` flag without synchronization—under load, the reader thread may loop forever on some JVMs. Fix it using `volatile` and explain which happens-before edges guarantee termination.

---

## Chapter 5: Advanced Streams and Collectors

### 5.1 Collectors

`Collectors.groupingBy`, `partitioningBy`, `mapping`, `joining`, and downstream collectors compose reporting pipelines.

```java
import java.util.*;
import java.util.stream.*;

record Sale(String region, String product, int amount) {}

public class CollectorsDemo {
    public static void main(String[] args) {
        List<Sale> sales = List.of(
                new Sale("EU", "A", 10),
                new Sale("US", "B", 20),
                new Sale("EU", "B", 5));

        Map<String, IntSummaryStatistics> byRegion = sales.stream()
                .collect(Collectors.groupingBy(
                        Sale::region,
                        Collectors.summarizingInt(Sale::amount)));

        byRegion.forEach((r, stats) ->
                System.out.println(r + " sum=" + stats.getSum()));
    }
}
```

### 5.2 Parallel Streams—Use Sparingly

Parallel streams fork tasks on the common `ForkJoinPool`. They help only when workloads are CPU-heavy, splittable, and side-effect-free; otherwise they add contention and obscure bugs.

---

## 🔨 Exercise 5.1

Given `List<Employee>` with fields `department` and `salary`, produce a `Map<String, Double>` of **average salary per department** using streams and `Collectors`, ignoring empty departments.

---

## Chapter 6: The Java Platform Module System (JPMS)

### 6.1 Modules and `module-info.java`

Java 9 introduced **modules**: named units that declare exported packages and required modules, enabling stronger encapsulation than classpath alone.

```java
module com.example.app {
    requires java.net.http;
    exports com.example.api;
}
```

### 6.2 Migration Reality

Legacy libraries may be unnamed modules on the classpath; mixing module path and classpath requires planning (`requires transitive`, qualified exports, etc.).

---

## 🔨 Exercise 6.1

Create a tiny multi-module Maven or Gradle layout: an `api` module exporting one package, an `impl` module providing a service, and an `app` module with `main`. Write minimal `module-info.java` files so `app` runs with `--module-path`.

---

## Chapter 7: Reflection—Power and Pitfalls

### 7.1 Core Reflection API

`Class`, `Method`, `Field`, and `Constructor` introspect types at runtime—useful for frameworks (serialization, DI, ORMs) but brittle across refactorings.

```java
import java.lang.reflect.*;

public class ReflectDemo {
    public static void main(String[] args) throws Exception {
        Method m = String.class.getMethod("length");
        Object len = m.invoke("hello");
        System.out.println(len);
    }
}
```

### 7.2 Access Checks

Strong encapsulation (modules, JDK internals warnings) limits reflective access—prefer official APIs or method handles where performance matters.

---

## 🔨 Exercise 7.1

Write a utility `static <T> T mergeDefaults(Class<T> type)` that instantiates `T` (assume a no-arg constructor), scans writable bean-like `void set*(...)` methods or records’ accessors, and fills defaults from a hard-coded map—**document clearly why production code should prefer codegen or libraries instead.**

---

## Chapter 8: Custom Annotations and Processing (Overview)

### 8.1 Declaring Annotations

Annotations attach metadata to declarations; retention policies control visibility (`SOURCE`, `CLASS`, `RUNTIME`).

```java
import java.lang.annotation.*;

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
public @interface Timed {
}
```

### 8.2 Annotation Processors

Compile-time (`javac` plugin) processors generate sources—patterns behind frameworks like validation and mapping mappers.

---

## 🔨 Exercise 8.1

Define a `@Retry(int times)` runtime annotation and implement a small proxy or wrapper using `InvocationHandler` that retries interface calls catching `IOException`. Demonstrate with a fake flaky service interface.

---

## Chapter 9: Networking and HTTP

### 9.1 `java.net.http.HttpClient` (Java 11+)

Modern HTTP client with synchronous and asynchronous request APIs.

```java
import java.net.URI;
import java.net.http.*;

public class HttpGetDemo {
    public static void main(String[] args) throws Exception {
        HttpClient client = HttpClient.newHttpClient();
        HttpRequest req = HttpRequest.newBuilder(URI.create("https://example.com"))
                .GET()
                .build();
        HttpResponse<String> res = client.send(req, HttpResponse.BodyHandlers.ofString());
        System.out.println(res.statusCode());
    }
}
```

### 9.2 Timeouts and Errors

Always configure connect/request timeouts; handle redirects explicitly when security matters.

---

## 🔨 Exercise 9.1

Write an async pipeline using `HttpClient.sendAsync` that fetches three URLs concurrently and aggregates the first line of each response into a single delimited string with `CompletableFuture.allOf`.

---

## Chapter 10: JDBC Essentials

### 10.1 Connections and Try-with-Resources

```java
import java.sql.*;

public class JdbcSketch {
    public static void main(String[] args) throws SQLException {
        String url = "jdbc:postgresql://localhost/demo";
        try (Connection c = DriverManager.getConnection(url, "user", "pass");
             PreparedStatement ps = c.prepareStatement("SELECT id,name FROM users WHERE id=?")) {
            ps.setLong(1, 1L);
            try (ResultSet rs = ps.executeQuery()) {
                while (rs.next()) {
                    System.out.println(rs.getLong("id") + " " + rs.getString("name"));
                }
            }
        }
    }
}
```

### 10.2 Pooling and Layers

Production systems use **connection pools** (HikariCP, etc.) and often ORMs or query builders— JDBC remains the portable foundation.

---

## 🔨 Exercise 10.1

Implement `List<User> findUsersOlderThan(Connection c, int minAge)` using **only** JDBC (`PreparedStatement`, `ResultSet`). Map rows into a simple `record User(long id, String name, int age)`.

---

## Chapter 11: Serialization and Data Exchange

### 11.1 Java Native Serialization Risks

Built-in serialization is convenient but fragile for long-lived data and security—prefer explicit formats (JSON with Jackson, protobuf, etc.) for service boundaries.

### 11.2 Versioning and Compatibility

If you must use native serialization, plan `serialVersionUID` and field evolution carefully.

---

## 🔨 Exercise 11.1

Define a `record Config(String env, int timeoutMs)` and serialize/deserialize it using **JSON** via a small library (Jackson, Gson, or similar—the JDK does not include a general-purpose JSON binding API) instead of `ObjectOutputStream`. Explain why JSON is easier to evolve across languages.

---

## Chapter 12: Tooling and Observability

### 12.1 Flight Recorder and Mission Control

JDK Mission Control plus Java Flight Recorder provides low-overhead profiling—learn basics before optimizing blindly.

### 12.2 Structured Logging

Migrate ad hoc `System.out` debugging to SLF4J with markers and MDC for correlation IDs in services.

---

## 🔨 Exercise 12.1

Create a micro-benchmark using **JMH** (or document manual pitfalls if JMH unavailable) comparing `StringBuilder` concatenation in a loop versus naive `+` in a loop for large counts—report methodology caveats (warmup, GC, dead-code elimination).

---

## Summary

1. Prefer **executors** over raw thread spawning for scalability.
2. Compose async work with **`CompletableFuture`**, always planning error paths.
3. Use **locks and concurrent collections** thoughtfully; understand **JMM** guarantees.
4. Treat **parallel streams** as an optimization with prerequisites.
5. **Modules** clarify large-system boundaries; reflection bypasses should stay narrow.
6. **HTTP** and **JDBC** underpin many enterprise stacks—master timeouts and resource hygiene.
7. Choose **serialization formats** with interoperability and security in mind.
8. Profile with **JDK tooling** before micro-optimizing.

---

## Project Ideas

1. **Download manager** — async HTTP with retries, disk persistence, checksum verification.
2. **Mini message broker** — blocking queues, multiple consumers, graceful shutdown.
3. **CSV analytics service** — streams + collectors reporting over large files with memory-aware chunking.
4. **Plugin host** — JPMS layers loading implementations behind exported interfaces.
5. **Rate limiter** — token bucket using atomics or locks with simulation harness.
