# Hotrace

## <a name="introduction-en">📖 Introduction ##

A fast-paced competition on effective programming techniques and algorithms.
The program goal is to answer the fastest in a competition. It will be benchmarked and tested.
It needs to be completely implemented (in C) by the team and not use any extern library.

## 📋 Table of Contents ##

* [📖 Introduction](#introduction-en)
* [⚙️ Requirements](#requirements-en)
* [🔧 Architecture](#arch-en)
* [🚀 How to use](#use-en)

## <a name="requirements-en">⚙️ Requirements ##

The project uses `cc` (clang) compiler, and needs to fully comply to the 42 Norm v4.

Use only the following `C functions` :

* `read`
* `write`
* `malloc`
* `free`
* `strerror`
* The compiler directive: `__asm__`

## <a name="arch-en">🔧 Architecture ##

The project uses a custom hashmap. The hashmap uses open indexing to find the index in case of a collision. 
A collision occures when a key is already registered at an index, and another key wants to place it's value at the same place. There is a lot of methods to solve it, like linked chains, resizing... All theses methods can be 'slow' at runtime and are more complicated to implement. We are using open indexing, which are pretty simple, if a collision occurs, we try the next index. And so on until we make a loop, if it's a loop, it means the hashmap is FULL. There is no resizing in this project so it will just reject all new key.

The hash function is `FNV1A`, it's best for small strings and can be slow for long strings.

To avoid leaks, we are using a pretty basic garbage collector that takes key and values from stdin and keeps it until the programs ends. It's only free'd at the end so the programs grows indefinitely. It's a bad idea but it's AMAZINGLY fast to accept the trade-of.

The goal is to run the fastest possible, so we are using all optimizations flags possible for SPEED. For even faster results, you can redirect the output to `/dev/null` or even not printing with the macro `NO_PRINT`.

## <a name="use-en">🚀 How to use ##

The program is in two steps :
 * First, store the key-value in the program
 * Then, search the key and print the value associated

Example given in the subject :
```sh
$>cat -e example.htr
keyword-1$
value-1$
keyword-2$
value-2$

keyword-1$
keyword-2$
```

```sh
$>./hotrace < example.htr
value-1
value-2
```

Or for manual input :

```sh
$>./hotrace
keyword-1
value-1
keyword-2
value-2

keyword-3
keyword-3: Not found.
keyword-1
value-1
```

---
