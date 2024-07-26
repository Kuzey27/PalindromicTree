# Palindromic Tree Implementation

This repository contains an implementation of a Palindromic Tree (Eertree) in C++. A Palindromic Tree is a data
structure used to find and manage all palindromic substrings of a given string efficiently.

## Features

- Builds a Palindromic Tree for a given string.
- Efficiently finds and manages all palindromic substrings.
- Outputs the longest palindromic suffix for every prefix of the given string.

## Getting Started

### Prerequisites

- A C++ compiler supporting C++23 or later.

### Compilation

To compile the code, you can use the following steps:

1. Compile using a C++ compiler:
    ```sh
    g++ -std=c++23 -o palindromic_tree main.cpp
    ```

2. Alternatively, you can use CMake:
    ```sh
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

### Usage

1. Run the compiled program:
    ```sh
    ./palindromic_tree
    ```

2. Input the string for which you want to build the Palindromic Tree.

### Example

```sh
$ ./palindromic_tree
abbabb
1 : a
2 : b
3 : bb
4 : abba
5 : bab
6 : bbabb
```

## Code Explanation

The implementation consists of two main structures:

### `PalindromicNode`

Represents a node in the Palindromic Tree:

- `length`: The length of the palindromic substring represented by this node.
- `suffix`: A pointer to the suffix link node.
- `children`: An array of pointers to the children nodes for each character (a-z).

### `PalindromicTree`

Handles the construction and management of the Palindromic Tree:

- `s`: The input string.
- `rootQ` and `root0`: Pointers to the root nodes with lengths -1 and 0, respectively.
- `last_suffix`: The last added suffix node.
- `palindrome_suffixes`: A vector to store the palindromic suffixes.

### `parse_letter(char c)`

Adds a new character to the Palindromic Tree, updating the nodes and suffix links accordingly.

### `main()`

Reads input, constructs the Palindromic Tree, and outputs each palindromic suffix for every character in the input
string.

## References

- The concept of Eertrees is based on research from the
  paper: ["Efficient computation of longest common subsequence in massive data"](https://www.sciencedirect.com/science/article/pii/S0195669817301294).
- For a simple explanation, refer to
  this [blog post](https://web.archive.org/web/20180303234127/http://adilet.org/blog/25-09-14/).

_

Feel free to explore, use, and contribute to this project!