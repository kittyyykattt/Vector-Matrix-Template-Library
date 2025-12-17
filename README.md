# Vector-Matrix-Template-Library
Vector &amp; Matrix Template Library (C++)

Overview

This repository contains a C++ implementation of a generic vector container and its application in a two-dimensional matrix library.

The project closely mirrors the design and behavior of std::vector, with full support for iterators, dynamic resizing, copy/move semantics, and operator overloading. The custom Vector container is then used as the underlying data structure for a matrix template that supports standard matrix operations.


Features

Vector Class Template (Vector<T>)

A dynamically resizing container implemented from scratch with the following capabilities:

Generic programming using templates
Dynamic memory management
Copy constructor and copy assignment
Move constructor and move assignment
Iterator and const_iterator support
Bounds-checked access via at()
STL-style interface:
push_back, pop_back
insert, erase
resize, reserve
clear, empty
Operator overloading:
operator[]
operator==, operator!=
operator<<


Matrix Class Template (matrix<T>)

A two-dimensional matrix container implemented using Vector<Vector<T>>

Supported features:

Dynamic matrix creation with specified rows and columns
Element access via operator[]
Matrix printing
Value initialization for all entries
Standard matrix multiplication (operator*)
Stream output operator (operator<<)
