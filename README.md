# sorting_algorithms

![Logo](https://github.com/RamzyAR7/simple_shell/blob/main/Images/11ownload.jpeg)

This project implements various sorting algorithms in the C programming language. The implemented algorithms include Bubble Sort, Insertion Sort, Selection Sort, and Quick Sort.

## Table of Contents

1. [Introduction](#introduction)
2. [How to Use](#how-to-use)
3. [File Structure](#file-structure)
4. [Compilation](#compilation)
5. [Testing](#testing)
6. [Developeres](#Developeres)

## Introduction

This project is part of the curriculum for the course 0x1B. C - Sorting algorithms & Big O. It is meant to be done in teams of two people, and it focuses on implementing and understanding various sorting algorithms, as well as analyzing their time complexities using Big O notation.

## How to Use

To use the sorting algorithms implemented in this project, follow these steps:

1. Clone this repository to your local machine.
2. Compile the source files using the provided Makefile.
3. Run the compiled executable to test the sorting algorithms with different inputs.
4. Refer to the individual source files for documentation and implementation details of each sorting algorithm.

## File Structure

The project directory contains the following files:

- **sort.h**: Header file containing function prototypes for sorting algorithms.
- **print_array.c**: File containing the `print_array` function to print arrays.
- **print_list.c**: File containing the `print_list` function to print linked lists.
- **0-bubble_sort.c**: Implementation of Bubble Sort algorithm.
- **0-O**: File containing Big O notation for Bubble Sort.
- **1-insertion_sort_list.c**: Implementation of Insertion Sort for doubly linked lists.
- **1-O**: File containing Big O notation for Insertion Sort.
- **2-selection_sort.c**: Implementation of Selection Sort algorithm.
- **2-O**: File containing Big O notation for Selection Sort.
- **3-quick_sort.c**: Implementation of Quick Sort algorithm.
- **3-O**: File containing Big O notation for Quick Sort.
- **main.c**: Main file to test sorting algorithms (not provided in the repository but mentioned in the project requirements).
- **README.md**: This file, providing an overview of the project.

## Compilation

To compile the source files, use the provided Makefile. Here's how to compile the project:

```bash
make all

## Running Tests
```

To run tests, run the following command

```bash
gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 0-bubble_sort.c 0-main.c print_array.c -o bubble
```

## Developeres

- [@Ahmed Ramzy](https://www.github.com/RamzyAR7)
- [@Mahmoud Metwalli](https://github.com/MahmoudMetwalli)
