# Lecture 2: Arrays, Strings, and More

## Table of Contents

- [Welcome](#welcome)
- [Reading Levels](#reading-levels)
- [Compiling](#compiling)
- [Debugging](#debugging)
- [Arrays](#arrays)
- [Strings](#strings)
- [String Length](#string-length)
- [Command-Line Arguments](#command-line-arguments)
- [Exit Status](#exit-status)
- [Cryptography](#cryptography)
- [Summing Up](#summing-up)

---

## Welcome

In our previous session, we learned about C, a text-based programming language. This week, we are going to take a deeper look at additional building blocks that will support our goals of learning more about programming from the bottom up.

This course is about problem-solving. By the end, you will use these building blocks to solve a variety of computer science problems.

---

## Reading Levels

One of the real-world problems we will solve is understanding reading levels. We will be quantifying reading levels this week as one of your programming challenges.

---

## Compiling

Encryption is the act of hiding plain text from prying eyes. Decrypting is the act of taking an encrypted piece of text and returning it to a human-readable form.

Recall that last week, you learned about a compiler, a specialized computer program that converts source code into machine code. For example:

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

A compiler will take the above code and turn it into machine code.

**Compiling steps:**

1. **Preprocessing:** Header files (e.g., `#include <cs50.h>`) are copied into your file.
2. **Compiling:** Your program is converted into assembly code.
3. **Assembling:** Assembly code is converted into machine code.
4. **Linking:** Code from included libraries is combined with your code to create the final executable.

You can compile code in VS Code using:

```sh
clang -o hello hello.c
```

Or, for CS50 programs:

```sh
clang -o hello hello.c -lcs50
```

Or simply:

```sh
make hello
```

---

## Debugging

Everyone makes mistakes while coding. Debugging is the process of locating and removing bugs from your code.

**Techniques:**

- Rubber duck debugging: Explain your code to an inanimate object or another person.
- Use `printf` statements to print variable values and trace execution.
- Use a debugger (e.g., `debug50`) to step through code and inspect variables.

**Example of a bug:**

```c
for (int i = 0; i <= 3; i++)
{
    printf("#\n");
}
// Prints 4 blocks instead of 3
```

Fix:

```c
for (int i = 0; i < 3; i++)
{
    printf("#\n");
}
```

---

## Arrays

In Week 0, we discussed data types: `bool`, `int`, `char`, `string`, etc. Each requires a certain amount of memory.

**Memory usage:**

- `bool`: 1 byte
- `int`: 4 bytes
- `long`: 8 bytes
- `float`: 4 bytes
- `double`: 8 bytes
- `char`: 1 byte
- `string`: variable

**Example:**

```c
// Averages three (hardcoded) numbers
#include <stdio.h>
int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;
    printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
}
```

**Using arrays:**

```c
int scores[3];
scores[0] = 72;
scores[1] = 73;
scores[2] = 33;
```

**With a loop:**

```c
for (int i = 0; i < 3; i++)
{
    scores[i] = get_int("Score: ");
}
```

**Helper function for average:**

```c
const int N = 3;
float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
```

---

## Strings

A string is simply an array of characters.

**Examples:**

```c
char c1 = 'H';
char c2 = 'I';
char c3 = '!';
printf("%c%c%c\n", c1, c2, c3);
```

**ASCII values:**

```c
printf("%i %i %i\n", c1, c2, c3);
```

**String as array:**

```c
string s = "HI!";
printf("%c%c%c\n", s[0], s[1], s[2]);
```

**Array of strings:**

```c
string words[2];
words[0] = "HI!";
words[1] = "BYE!";
printf("%s\n", words[0]);
printf("%s\n", words[1]);
```

---

## String Length

To find the length of a string:

```c
int n = 0;
while (name[n] != '\0')
{
    n++;
}
printf("%i\n", n);
```

**With a helper function:**

```c
int string_length(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}
```

**Using the string.h library:**

```c
#include <string.h>
int length = strlen(name);
```

**Uppercasing a string:**

```c
for (int i = 0, n = strlen(s); i < n; i++)
{
    printf("%c", toupper(s[i]));
}
```

---

## Command-Line Arguments

Command-line arguments are passed to your program at the command line.

**Example:**

```c
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
```

**Printing all arguments:**

```c
for (int i = 0; i < argc; i++)
{
    printf("%s\n", argv[i]);
}
```

---

## Exit Status

When a program ends, it returns an exit code. `0` means success, `1` means error.

**Example:**

```c
if (argc != 2)
{
    printf("Missing command-line argument\n");
    return 1;
}
printf("hello, %s\n", argv[1]);
return 0;
```

Check the exit status in the terminal with:

```sh
echo $?
```

---

## Cryptography

Cryptography is the art of ciphering and deciphering a message. With arrays, chars, and strings, you can cipher and decipher messages. The key is a special argument passed to the cipher along with the plaintext.

---

## Summing Up

In this lesson, you learned:

- How a compiler works
- How to debug your code using four methods
- How to utilize arrays within your code
- How arrays store data in back-to-back portions of memory
- How strings are simply arrays of characters
- How to interact with arrays in your code
- How command-line arguments can be passed to your programs
- The basic building blocks of cryptography

---

**End of Lecture 2**
