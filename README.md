*This project has been created as part of the 42 curriculum by melmbaz.*

# Libft


## Description

Libft is the first project in the 42 curriculum, where students create their own C library by recoding standard C library functions from scratch. This library serves as a foundation for future 42 projects and provides a deep understanding of:

- How standard library functions work internally
- Memory management in C
- String manipulation and parsing
- Data structures (linked lists)
- Low-level programming concepts

The goal is to rebuild essential functions without using the standard library (except for `malloc`, `free`, and `write`), gaining mastery over C fundamentals and creating a reusable personal library for subsequent projects.

## Instructions

### Compilation

The project uses a Makefile with the following rules:
```bash
make        # Compiles the library (libft.a)
make clean  # Removes object files
make fclean # Removes object files and the library
make re     # Rebuilds everything from scratch
```

## Library Functions

### Part 1 - Libc Functions

These functions replicate standard C library behavior:

**Character checks:**
- `ft_isalpha` - checks if character is alphabetic
- `ft_isdigit` - checks if character is a digit
- `ft_isalnum` - checks if character is alphanumeric
- `ft_isascii` - checks if character is ASCII
- `ft_isprint` - checks if character is printable

**String manipulation:**
- `ft_strlen` - calculates string length
- `ft_strlcpy` - copies string with size limit
- `ft_strlcat` - concatenates strings with size limit
- `ft_strchr` - locates character in string
- `ft_strrchr` - locates character in string (from end)
- `ft_strncmp` - compares strings up to n bytes
- `ft_strnstr` - locates substring in string
- `ft_strdup` - duplicates a string

**Memory operations:**
- `ft_memset` - fills memory with a constant byte
- `ft_bzero` - zeros out memory
- `ft_memcpy` - copies memory area
- `ft_memmove` - copies memory area (handles overlap)
- `ft_memchr` - scans memory for a character
- `ft_memcmp` - compares memory areas

**Character conversion:**
- `ft_toupper` - converts to uppercase
- `ft_tolower` - converts to lowercase
- `ft_atoi` - converts string to integer

**Memory allocation:**
- `ft_calloc` - allocates and zeros memory

### Part 2 - Additional Functions

Custom functions not in standard library:

- `ft_substr` - extracts substring from string
- `ft_strjoin` - concatenates two strings (with malloc)
- `ft_strtrim` - trims characters from start/end of string
- `ft_split` - splits string into array of strings by delimiter
- `ft_itoa` - converts integer to string
- `ft_strmapi` - applies function to each character (with index)
- `ft_striteri` - applies function to each character (in-place)

**File descriptor functions:**
- `ft_putchar_fd` - outputs character to file descriptor
- `ft_putstr_fd` - outputs string to file descriptor
- `ft_putendl_fd` - outputs string + newline to file descriptor
- `ft_putnbr_fd` - outputs integer to file descriptor

### Part 3 - Linked List Functions

Data structure operations for singly linked lists:

**Structure:**
```c
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
```

**Functions:**
- `ft_lstnew` - creates new list node
- `ft_lstadd_front` - adds node at beginning of list
- `ft_lstadd_back` - adds node at end of list
- `ft_lstsize` - counts number of nodes
- `ft_lstlast` - returns last node
- `ft_lstdelone` - deletes single node
- `ft_lstclear` - deletes all nodes from a point
- `ft_lstiter` - applies function to each node's content
- `ft_lstmap` - creates new list with function applied to each node

## Technical Details

**Compilation flags:** `-Wall -Wextra -Werror`

**Allowed functions:** `malloc`, `free`, `write`

**Norm compliance:** All code follows the 42 Norm (Norminette v3)

**Memory management:** All dynamically allocated memory is properly freed, with no memory leaks

## Resources

### Documentation
- [man command](https://linux.die.net/man/) - Use `man <function_name>` in terminal (e.g., `man strcpy`, `man malloc`) for detailed function specifications
- [C Standard Library Reference](https://www.cplusplus.com/reference/clibrary/)
- [man pages](https://man7.org/linux/man-pages/) - For understanding original function behavior
- [42 Norm](https://github.com/42School/norminette) - Coding standards
- [W3Schools C Tutorial](https://www.w3schools.com/c/) - C programming basics and syntax reference

### Tutorials & Articles
- [GeeksforGeeks - C Programming](https://www.geeksforgeeks.org/c-programming-language/) - Comprehensive C tutorials and examples
- [GeeksforGeeks - Linked Lists](https://www.geeksforgeeks.org/data-structures/linked-list/) - Understanding linked list data structure
- [GeeksforGeeks - Memory Management](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/) - Dynamic memory allocation in C
- [Stack Overflow](https://stackoverflow.com/questions/tagged/c) - Community Q&A for specific C programming problems
- [Makefiles Tutorial](https://makefiletutorial.com/)
### AI Usage

**Claude AI (Anthropic) was used as an architectural consultant throughout this project:**

**Tasks AI assisted with:**
- **Debugging logic:** Asking questions to help identify logical errors in implementations
- **Makefile structure:** Learning compilation workflows and dependency management
- **Edge case identification:** Thinking through boundary conditions and error handling
**README documentation:** Structuring and writing this README file, including formatting, organization, and content presentation

**AI was NOT used for:**
- Writing actual function implementations
- Providing direct code solutions
- Completing assignments without understanding

**Methodology:** The AI acted as a Socratic teacher, asking guiding questions and helping develop problem-solving skills rather than providing answers. All code was written independently based on conceptual understanding developed through discussion.

## Project Structure
```
libft/
├── Makefile
├── libft.h
├── README.md
├── ft_*.c (function implementations)
└── (object files generated during compilation)
```

## Author

**melmbaz** - 42 Istanbul

---

*This library was created as part of the learning process at 42 School, emphasizing understanding of low-level programming, memory management, and algorithmic thinking.*