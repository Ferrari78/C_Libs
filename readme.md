# Small C Lib

## Summary

The repo include two libraries:
- [stringLib.h](#StringLib)
- [list.h](#LinkedList)

### StringLib
|  | Param |Link|
|--|--|--|
| countUpperCases | char* string |[countUpperCases](#countUpperCases)|
| countWords| char* string |[countWords](#countWords)|
| mostLetter| char* string |[mostLetter](#mostLetter)|

### countUpperCases

This function count the uppercase letters.


**Input:** The function requires a string to work
**Output:** The output is an integer

    ```C
    char b[255] = "Hello World";
    printf("%c", countUpperCases(b));  // 2
    ```