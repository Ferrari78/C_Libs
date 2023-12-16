# Small C Lib

## Summary

Two libraries are included in the repo:
- [stringLib.h](#stringlib)
- [list.h](#linkedlist)
- [timeoperations.h](#timelib)

### StringLib
|                 | Param        | Link                                |
|-----------------|--------------|-------------------------------------|
| countUpperCases | char* string | [countUpperCases](#countUpperCases) |
| countWords      | char* string | [countWords](#countWords)           |
| mostLetter      | char* string | [mostLetter](#mostLetter)           |

### countUpperCases

This function counts the uppercase letters.


**Input:** The function requires a string to work
**Output:** The output is an integer

```c
    char b[255] = "Hello World";
    printf("%c", countUpperCases(b));   // 2
```

### countWords

This function counts the number of words in the input string.

**Input:** The function requires a string to work
**Output:** The output is an integer

```c
    char b[255] = "Nessie's are cute;
    printf("%c", countWords(b));    // 3
```

### mostLetter

This function returns a struct containing information about the most common letter in the string.

**Input:** The function requires a string to work
**Output:** The output is a struct mostLetter

```c
//Output of the function
typedef struct {
    char letter;
    int size;
} Letter;
```

```c
char b[255] = "Nessie's are cute";
printf("%c", mostLetter(b)->letter);  // e
printf("%d", mostLetter(b)->size);      // 4
```

## LinkedList

## TimeLib