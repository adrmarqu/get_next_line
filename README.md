# get_next_line - 42 Barcelona

get_next_line is a core algorithmic project from the 42 Barcelona curriculum. The objective is to write a clean, robust C function that reads a single line terminated by a newline character (\n) or end-of-file (EOF) from a file descriptor upon each successive call. The implementation maintains a persistent static buffer across calls to handle variable buffer sizes, arbitrary line lengths, and avoid memory leaks. The bonus implementation extends this capability to simultaneously handle multiple file descriptors without losing reading state.

# Prerequisites

To compile and use get_next_line, ensure you have:

- A C compiler: gcc or clang
- GNU Make or a standard C compilation toolchain
- Standard C library (stdlib.h, unistd.h)
- POSIX-compliant operating system (macOS or Linux)

# Configuration

1. Clone the repository:
```bash
git clone https://github.com/adrmarqu/get_next_line.git
cd get_next_line
```

2. Configuring the buffer size:
The macro BUFFER_SIZE determines how many bytes the read system call retrieves in each operation. It can be overridden at compile time by passing the -D BUFFER_SIZE=<value> flag. If unspecified, it defaults to 5 as defined in the header:
```bash
-D BUFFER_SIZE=42
```

# Execution

### Basic Example (Mandatory Part)

Create a sample test file, for instance main.c:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile and run with your chosen buffer size:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o gnl_test
./gnl_test
```

### Multiple File Descriptors Example (Bonus Part)

The bonus files allow reading from multiple distinct file descriptors alternately without losing position in any stream:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus_test
./gnl_bonus_test
```

# Project Structure

```
get_next_line/
├── get_next_line.c             # Core reading and static remainder management
├── get_next_line.h             # Function declarations and default BUFFER_SIZE macro
├── get_next_line_utils.c       # Helper utilities (ft_strlen, ft_strchr, ft_join, ft_calloc, ft_memset)
├── get_next_line_bonus.c       # Multi-file-descriptor concurrent read logic
├── get_next_line_bonus.h       # Bonus function declarations and definitions
└── get_next_line_utils_bonus.c # Bonus helper utility functions
```

# Features

- Precise Line Delivery: Returns the complete string including the newline character, followed by a null terminator.
- Memory Leak Free: Allocates exactly what is needed for each line and frees leftover buffer fragments appropriately.
- Arbitrary Buffer Sizes: Operates reliably with tiny buffer sizes (such as 1 byte), standard sizes (42 or 4096 bytes), and large buffers (9999999 bytes).
- Bonus Multi-FD Handling: Handles simultaneous reading from files, pipes, and standard input (stdin) concurrently without mixing buffers.

# Author Details

Author: Adrià Márquez Nebot
Github: https://github.com/adrmarqu
LinkedIn: https://www.linkedin.com/in/adria-marquez
Portfolio: https://adrmarqu.github.io
