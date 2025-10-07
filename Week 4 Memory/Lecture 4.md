# Lecture 4: Memory

## Table of Contents
- Pixel Art
- Hexadecimal
- Memory
- Pointers
- Strings
- Pointer Arithmetic
- String Comparison
- Copying and malloc
- Valgrind
- Garbage Values
- Pointer Fun with Binky
- Swapping
- Overflow
- scanf
- File I/O
- Summary

---

## Welcome
- Today: deeper look at how computers store and access data in memory.
- Focus: pixels, hexadecimal, pointers, strings, memory management, file I/O.

---

## Pixel Art
- Images are made of pixels (small squares of color on a grid).
- Each pixel can be represented by bits (0 = black, 1 = white).

---

## Hexadecimal
- RGB (Red, Green, Blue) values represent color intensity.
- Hexadecimal (base-16) uses digits 0-9 and A-F (A=10, F=15).
- Example conversions:
  - 0 = 00
  - 1 = 01
  - 9 = 09
  - 10 = 0A
  - 15 = 0F
  - 16 = 10
  - 255 = FF
- Hex numbers often use `0x` prefix (e.g., `0xFF`).
- Hex is compact and useful for memory addresses.

---

## Memory
- Memory is organized in blocks, often visualized in hex.
- Example: storing an integer in memory

```c
#include <stdio.h>
int main(void) {
    int n = 50;
    printf("%i\n", n);
}
```
- The value is stored at a specific memory address.

---

## Pointers
- `&` operator: gets the address of a variable.
- `*` operator: accesses the value at a memory address.
- Example: printing an integer's address

```c
#include <stdio.h>
int main(void) {
    int n = 50;
    printf("%p\n", &n);
}
```
- Pointers store addresses in memory.
- Example: pointer to an integer

```c
int n = 50;
int *p = &n;
printf("%p\n", p);
```
- Dereferencing a pointer:

```c
printf("%i\n", *p);
```

---

## Strings
- Strings are arrays of characters, stored in memory.
- A string variable points to the first character's address.
- Example:

```c
#include <cs50.h>
#include <stdio.h>
int main(void) {
    string s = "HI!";
    printf("%s\n", s);
}
```
- Printing addresses of each character:

```c
printf("%p\n", s);
printf("%p\n", &s[0]);
printf("%p\n", &s[1]);
printf("%p\n", &s[2]);
printf("%p\n", &s[3]);
```
- In raw C, a string is a `char *`:

```c
char *s = "HI!";
printf("%s\n", s);
```
- CS50's `string` type is a typedef for `char *`.

---

## Pointer Arithmetic
- You can do math on pointers to access different memory locations.
- Example: print each character

```c
char *s = "HI!";
printf("%c\n", s[0]);
printf("%c\n", s[1]);
printf("%c\n", s[2]);
```
- Using pointer arithmetic:

```c
printf("%c\n", *s);
printf("%c\n", *(s + 1));
printf("%c\n", *(s + 2));
```
- Print substrings:

```c
printf("%s\n", s);
printf("%s\n", s + 1);
printf("%s\n", s + 2);
```

---

## String Comparison
- Comparing integers: `==` compares values.
- Comparing strings: `==` compares addresses, **not** contents.
- Use `strcmp` to compare string contents.

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void) {
    char *s = get_string("s: ");
    char *t = get_string("t: ");
    if (strcmp(s, t) == 0) {
        printf("Same\n");
    } else {
        printf("Different\n");
    }
}
```

---

## Copying and malloc
- Assigning one string to another copies the address, **not** the contents.
- To copy a string, allocate memory and copy each character.
- Example:

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);
    strcpy(t, s);
    t[0] = toupper(t[0]);
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    free(t);
}
```
- Always check for `NULL` when using `get_string` or `malloc`.

---

## Valgrind
- Valgrind checks for memory leaks and errors.
- Example: forgetting to free memory

```c
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *x = malloc(3 * sizeof(int));
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
    // free(x); // Uncomment to fix memory leak
}
```
- Always free memory you allocate.

---

## Garbage Values
- Uninitialized memory may contain garbage values.
- Example:

```c
#include <stdio.h>
int main(void) {
    int scores[1024];
    for (int i = 0; i < 1024; i++) {
        printf("%i\n", scores[i]);
    }
}
```
- Best practice: initialize memory before use.

---

## Pointer Fun with Binky
- Stanford video helps visualize pointers.

---

## Swapping
- Swapping values requires passing by reference (using pointers).
- Example: swap two integers

```c
#include <stdio.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(void) {
    int x = 1, y = 2;
    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}
```

---

## Overflow
- Heap overflow: writing past allocated memory.
- Stack overflow: too many function calls.
- Both are buffer overflows.

---

## scanf
- `scanf` can get user input, but is less safe than CS50's `get_int`/`get_string`.
- Example: get an int

```c
#include <stdio.h>
int main(void) {
    int n;
    printf("n: ");
    scanf("%i", &n);
    printf("n: %i\n", n);
}
```
- Getting a string is unsafe unless memory is pre-allocated:

```c
char s[4];
printf("s: ");
scanf("%s", s);
printf("s: %s\n", s);
```
- Using `malloc`:

```c
char *s = malloc(4);
if (s == NULL) return 1;
printf("s: ");
scanf("%s", s);
printf("s: %s\n", s);
free(s);
```
- Danger: user input longer than allocated memory causes errors.

---

## File I/O
- Files can be read/written using pointers.
- Example: save names and numbers to a CSV file

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void) {
    FILE *file = fopen("phonebook.csv", "a");
    if (!file) return 1;
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");
    fprintf(file, "%s,%s\n", name, number);
    fclose(file);
}
```
- Example: copy a file

```c
#include <stdio.h>
#include <stdint.h>
typedef uint8_t BYTE;
int main(int argc, char *argv[]) {
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");
    BYTE b;
    while (fread(&b, sizeof(b), 1, src) != 0) {
        fwrite(&b, sizeof(b), 1, dst);
    }
    fclose(dst);
    fclose(src);
}
```

---

## Summary
- Pointers let you access and manipulate data at specific memory locations.
- Key topics:
  - Pixel art
  - Hexadecimal
  - Memory
  - Pointers
  - Strings
  - Pointer arithmetic
  - String comparison
  - Copying
  - malloc and Valgrind
  - Garbage values
  - Swapping
  - Overflow
  - scanf
  - File I/O

---

See you next time!
