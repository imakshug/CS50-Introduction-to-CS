# Lecture 3: Algorithms

## Table of Contents

- [Welcome](#welcome)
- [Linear Search](#linear-search)
- [Binary Search](#binary-search)
- [Running Time](#running-time)
- [Linear Search in C](#linear-search-in-c)
- [Linear Search for Strings](#linear-search-for-strings)
- [Phonebook Example](#phonebook-example)
- [Structs](#structs)
- [Sorting](#sorting)
- [Bubble Sort](#bubble-sort)
- [Recursion](#recursion)
- [Merge Sort](#merge-sort)
- [Summing Up](#summing-up)

---

## Welcome

In week zero, we introduced the idea of an algorithm: a black box that may take an input and create an output. This week, we expand on algorithms, pseudocode, and efficiency. We'll focus on algorithm design and how to measure efficiency.

---

## Linear Search

Arrays are blocks of consecutive memory. Imagine an array as a row of lockers:

- The leftmost is position 0, the rightmost is position n-1.
- To find if 50 is in the array, check each locker one by one.

**Pseudocode:**

```
For each door from left to right
    If 50 is behind door
        Return true
Return false
```

Or, more code-like:

```
For i from 0 to n-1
    If 50 is behind doors[i]
        Return true
Return false
```

---

## Binary Search

If the array is sorted, we can use binary search:

**Pseudocode:**

```
If no doors left
    Return false
If 50 is behind middle door
    Return true
Else if 50 < middle door
    Search left half
Else if 50 > middle door
    Search right half
```

Or, in code-like terms:

```
If no doors left
    Return false
If 50 is behind doors[middle]
    Return true
Else if 50 < doors[middle]
    Search doors[0] through doors[middle - 1]
Else if 50 > doors[middle]
    Search doors[middle + 1] through doors[n - 1]
```

---

## Running Time

Running time is analyzed using **Big O notation**.

- O(n²)
- O(n log n)
- O(n)
- O(log n)
- O(1)

**Linear search:** O(n) (worst-case: n steps)

**Binary search:** O(log n) (worst-case: log n steps)

- Ω (Omega): best-case
- Θ (Theta): when best and worst-case are the same

---

## Linear Search in C

```c
// Implements linear search for integers
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

---

## Linear Search for Strings

```c
// Implements linear search for strings
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

- Use `strcmp` for string comparison (not `==`).

---

## Phonebook Example

```c
// Implements a phone book without structs
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Yuliia", "David", "John"};
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

- Arrays must be kept in sync manually.

---

## Structs

C allows you to create your own data types with `struct`:

```c
typedef struct
{
    string name;
    string number;
} person;
```

**Improved phonebook:**

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[3];
    people[0].name = "Yuliia";
    people[0].number = "+1-617-495-1000";
    people[1].name = "David";
    people[1].number = "+1-617-495-1000";
    people[2].name = "John";
    people[2].number = "+1-949-468-2750";
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

---

## Sorting

Sorting is the act of taking an unsorted list and transforming it into a sorted one. Binary search only works on sorted lists.

**Selection Sort (pseudocode):**

```
For i from 0 to n–1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
```

- Steps: (n - 1) + (n - 2) + ... + 1 = n(n-1)/2 = O(n²)

---

## Bubble Sort

Bubble sort repeatedly swaps elements to "bubble" larger elements to the end.

**Pseudocode:**

```
Repeat n-1 times
    For i from 0 to n–2
        If numbers[i] and numbers[i+1] out of order
            Swap them
    If no swaps
        Quit
```

- Worst-case: O(n²)
- Best-case: Ω(n)

---

## Recursion

Recursion is when a function calls itself.

**Binary search (recursive):**

```
If no doors left
    Return false
If number behind middle door
    Return true
Else if number < middle door
    Search left half
Else if number > middle door
    Search right half
```

**Pyramid example (iteration):**

```c
void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```

**Pyramid example (recursion):**

```c
void draw(int n)
{
    if (n <= 0)
    {
        return;
    }
    draw(n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
```

---

## Merge Sort

Merge sort is a very efficient, recursive sort algorithm.

**Pseudocode:**

```
If only one number
    Quit
Else
    Sort left half of number
    Sort right half of number
    Merge sorted halves
```

- Worst-case: O(n log n)
- Best-case: Ω(n log n)
- Θ(n log n) overall

---

## Summing Up

In this lesson, you learned:

- Algorithms and algorithmic thinking
- Big O notation
- Linear and binary search
- Sorting algorithms: bubble, selection, merge sort
- Recursion

---

**End of Lecture 3**
