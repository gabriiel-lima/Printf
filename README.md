*This project has been created as part of the 42 curriculum by garodri2*

# ft_printf

# Description

The **ft_printf** project consists of recreating the original `printf()` function from the C standard library.

The main goal of this project is to understand how formatted output works internally in C, while also learning how variadic functions operate using the `stdarg.h` library.

This project focuses on several important low-level programming concepts such as:

- Variadic arguments
- String and character output
- Integer conversion
- Hexadecimal conversion
- Pointer formatting
- Recursive algorithms
- Memory and buffer handling
- Low-level writing with the `write()` system call

The recreated function behaves similarly to the original `printf()` by parsing format specifiers inside a string and printing the corresponding arguments in the correct format.

## Supported Conversions

| Specifier | Description |
|------------|-------------|
| `%c` | Prints a character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address |
| `%d` | Prints a decimal integer |
| `%i` | Prints an integer |
| `%u` | Prints an unsigned integer |
| `%x` | Prints hexadecimal in lowercase |
| `%X` | Prints hexadecimal in uppercase |
| `%%` | Prints the percent symbol |

---

# Project Structure

The project is divided into multiple helper functions responsible for handling specific conversion types.

## Character and String Functions

```c
ft_putchar -> Prints a single character
ft_putstr  -> Prints a string
```

These functions directly use `write()` to output characters to the terminal.

---

## Integer Conversion Functions

```c
ft_putnbr      -> Prints signed integers
ft_putunsigned -> Prints unsigned integers
```

These functions convert numerical values into printable characters.

The conversion is usually done recursively by dividing the number by 10 until reaching a single digit.

---

## Hexadecimal Functions

```c
ft_puthex -> Prints numbers in hexadecimal format
```

This function converts numbers to base 16 representation and supports both lowercase and uppercase formatting.

---

## Pointer Function

```c
ft_putptr -> Prints memory addresses
```

Pointers are printed in hexadecimal format prefixed with `0x`.

---

## Main Function

```c
ft_printf -> Main formatted output function
```

The function parses the format string character by character.

When encountering `%`, it identifies the conversion specifier and dispatches the argument to the appropriate helper function.

The function also counts and returns the total number of printed characters, reproducing the original behavior of `printf()`.

---

# Algorithm and Data Structure Choices

## Parsing Algorithm

The project uses a sequential parsing algorithm to analyze the format string.

The algorithm works by:

1. Reading the format string character by character
2. Printing normal characters directly
3. Detecting `%` symbols
4. Identifying the following conversion specifier
5. Calling the corresponding conversion function
6. Updating the printed character counter

This approach was chosen because:

- It is simple and efficient
- It closely mirrors the behavior of the original `printf`
- It minimizes unnecessary memory allocation
- It allows easy extension for additional specifiers

### Complexity

- **Time Complexity:** `O(n)` where `n` is the size of the format string
- **Space Complexity:** `O(1)` excluding recursion stack usage

---

## Recursive Number Conversion

Recursive algorithms were chosen for integer and hexadecimal printing.

Example logic:

```c
if (n >= 10)
    ft_putnbr(n / 10);
ft_putchar((n % 10) + '0');
```

### Advantages of recursion

- Cleaner implementation
- Easier digit ordering
- Reduced temporary buffer usage

This approach is especially useful for:

- Decimal conversion
- Unsigned integer conversion
- Hexadecimal conversion

---

## Data Structures Used

This project does not require complex data structures such as linked lists or trees.

The main structures used are:

- Character arrays (`char *`)
- Integer variables
- Variadic argument lists (`va_list`)

The `va_list` structure from `stdarg.h` is essential because it allows access to a variable number of arguments dynamically.

---

# Instructions

## Compilation

To compile the project, run:

```bash
make
```

This generates the static library:

```bash
libftprintf.a
```

---

## Cleaning Object Files

```bash
make clean
```

Removes all object files generated during compilation.

---

## Full Cleanup

```bash
make fclean
```

Removes:

- Object files
- Compiled library

---

## Recompile Everything

```bash
make re
```

Performs:

1. Full cleanup
2. Complete recompilation

---

# Usage

Include the header file in your project:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lftprintf
```

## Example

```c
ft_printf("Name: %s\n", "Marcio");
ft_printf("Number: %d\n", 42);
ft_printf("Hex: %x\n", 255);
```

### Output

```bash
Name: Marcio
Number: 42
Hex: ff
```

---

# Technical Choices

Several technical decisions were made during development to keep the project efficient and compatible with the original `printf()` behavior.

## Use of `write()`

The project exclusively uses the `write()` system call for output because it is the only allowed output function in the project rules.

---

## Modular Design

Each conversion type was separated into independent helper functions.

### Advantages

- Easier debugging
- Better code organization
- Improved readability
- Simpler maintenance

---

## No Dynamic Allocation When Unnecessary

Most conversions are performed recursively without allocating temporary strings.

This reduces:

- Memory usage
- Risk of memory leaks
- Complexity

---

# Resources

During the development of this project, several references and learning resources were used.

## Documentation

### Linux Manual Pages

The Linux manual pages (`man`) were heavily used to study:

- `printf`
- `write`
- `stdarg`

They were essential for understanding expected behavior and function prototypes.

---

## University of São Paulo (USP)

Reference:

https://www.ime.usp.br/~pf/algoritmos/index.html#C-language

This material helped reinforce concepts related to:

- Algorithms
- Recursion
- Pointers
- Base conversion
- C syntax

---

## Tutorials and Videos

YouTube tutorials were used for:

- Variadic function explanations
- Hexadecimal conversion
- Recursive printing
- Debugging techniques

---

## Artificial Intelligence Usage

Artificial Intelligence tools, specifically ChatGPT, were used as learning support during the project.

AI assistance was used for:

- Clarifying variadic function concepts
- Understanding edge cases
- Reviewing recursive logic
- Improving code organization
- Explaining formatting behavior
- Helping document the project

AI was not used to generate the entire project automatically. Its role was primarily educational and supportive during problem-solving and debugging.

---

# Notes

- All functions follow the **42 Norminette** coding standard
- The project recreates the original `printf()` behavior as closely as possible
- The implementation uses only allowed functions
- Memory handling was carefully managed
- The function returns the exact number of printed characters like the original `printf()`