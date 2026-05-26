# coding guidelines

the coding guidelines apply to Application/, vendor code is to be kept as close to original when modified

1. indentation is 4 characters long
2. the limit on the length of lines is 96 characters (including space/indentation)
3. use stdint.h standard types
4. \r before \n when using printf
5. use K&R indentation style, unless statement is followed by only one line, then avoid using braces
6. use snake_case whenever possible
7. defines must be uppercase
8. resort to static const variables in place of defines whenever possible
9. do not comment unless necessary
10. prefer static inline functions over macros