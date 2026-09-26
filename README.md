# ft_printf

<p align="center">
  <img src="https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge&logo=42" alt="Score 100/100" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C" />
  <img src="https://img.shields.io/badge/Norminette-Passing-brightgreen?style=for-the-badge" alt="Norminette Passing" />
</p>

## 📌 About The Project

`ft_printf` is a 42 School project where students re-implement the standard C library function `printf()`. 

The objective of this project is to learn and master **variadic functions** in C using `<stdarg.h>`, practice modular code architecture, handle variable types and conversions, and format output accurately while mimicking the exact return values and printed bytes of `printf()`.

---

## 🎯 Supported Conversions

The implementation handles the following conversion specifiers required by the mandatory part of the subject:

| Specifier | Description | Example Input | Example Output |
| :---: | :--- | :--- | :--- |
| `%c` | Prints a single character | `'A'` | `A` |
| `%s` | Prints a string (handles `NULL` gracefully) | `"Hello World"` | `Hello World` |
| `%p` | Prints a `void *` pointer memory address in hex format | `&var` | `0x7ffee23b5ec0` |
| `%d` | Prints a signed decimal integer (base 10) | `-42` | `-42` |
| `%i` | Prints a signed integer in base 10 | `1337` | `1337` |
| `%u` | Prints an unsigned decimal integer (base 10) | `4294967295` | `4294967295` |
| `%x` | Prints a number in lowercase hexadecimal (base 16) | `255` | `ff` |
| `%X` | Prints a number in uppercase hexadecimal (base 16) | `255` | `FF` |
| `%%` | Prints a literal percent sign | N/A | `%` |

> [!NOTE]
> Unlike standard `printf()`, `ft_printf` does not implement buffer management (as defined by the 42 subject requirements). Each character is output directly via `write()` system calls.

---

## 📂 Project Structure

```text
ft_printf/
├── Makefile                # Build automation
├── includes/
│   └── ft_printf.h         # Function prototypes and standard library includes
└── srcs/
    ├── ft_printf.c         # Main function parser and format dispatcher
    ├── ft_putchar.c        # Character writer (%c)
    ├── ft_putstr.c         # String writer (%s)
    ├── ft_putnbr.c         # Signed decimal/integer writer (%d, %i)
    ├── ft_putunbr.c        # Unsigned decimal writer (%u)
    ├── ft_puthex.c         # Hexadecimal writer (%x, %X)
    └── ft_putptr.c         # Pointer address writer (%p)
```

---

## 🛠️ Compilation & Makefile Rules

The project compiles into a static library named `libftprintf.a` using `ar rcs`.

```bash
# Compile library
make

# Remove object (.o) files
make clean

# Remove object files and the compiled archive (libftprintf.a)
make fclean

# Clean re-compilation
make re
```

---

## 🚀 Usage

### 1. Include header and link library
In your C file, include `ft_printf.h`:

```c
#include "ft_printf.h"

int	main(void)
{
	int		count;
	char	*user = "1337 Student";

	count = ft_printf("Hello, %s! Value: %d, Hex: %x, Ptr: %p\n", user, 42, 255, user);
	ft_printf("Printed %d characters.\n", count);
	return (0);
}
```

### 2. Compile your program with `libftprintf.a`
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -I includes -o my_program
./my_program
```

---

## 🧪 Testing

The library has been thoroughly verified against standard `printf` edge cases:
- Extreme values: `0`, `INT_MIN`, `INT_MAX`, `UINT_MAX`.
- Pointers: valid heap/stack memory addresses and `NULL` pointer (`(nil)` output).
- Strings: empty strings `""`, regular strings, and `NULL` string pointers (`(null)` output).
- Percent edge cases: single trailing `%`, multiple unescaped percent signs (`%%%%`).

Tested with modern 42 test suites:
- [Francinette](https://github.com/xicoducosta/francinette)
- [Tripouille / printfTester](https://github.com/Tripouille/printfTester)
