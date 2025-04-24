# Holbertonschool-Printf

## Description
The `_printf` command uses multiple functions to handle several types of arguments, allowing user to give almost any type of them
in the form of a string and to print it in the standard output. User must specify the type of argument, using a special identifier character in this format : `%id`.

| Identifier | Function | Stdout |
| :-----:   |:--------- | :------|
|%  |printpercent, prints a percent symbol  |%  |
|%c |printcharacter, prints a simple character  |a, p, ...  |
|%s |printstring, prints a string of character  |"Jeffrey"  |
|%d, %i |printint, prints an integer    |-42 |
|%b |printbinary, prints a binary number    |1010   |
|%u |printunsigned, prints an unsigned int  |42 |
|%o |printoctal, prints an octal number    |52  |
|%x |print_hex_low, prints an hexadecimal in lowercase  |2a |
|%X |print_hex_upper, prints an hexadecimal in uppercase    |2A |
 
### Requierments
    * Allowed editors: vi, vim, emacs
    * All files must be compiled on Ubuntu 20.04 using gcc
    * All files should end with a new line
    * A README.md file is mandatory
    * The code used must respect Betty style
    * Global variables are not allowed
    * There should not be more than 5 functions per file
    * Prototypes of all used functions must be included in an header file named main.h
    * All the headers should be include guarded

### Authorized functions
* write
* malloc
* free
* va_start
* va_end
* va_copy
* va_arg

### Compilation
Be sure to have all of these files :
* \_puchar.c
* function.c
* get_function.c
* \_printf.c
* main.h

Then execute the following command :
```
$ gcc -Wal -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```
## Code snippets
Core file of the function, "\_printf.c"
```
 int _printf(const char *format, ...)
{
         va_list args; /* declares the va_list of arguments */
         int length = 0;
         if (format == NULL)
                 return (-1);

        va_start(args, format);

        length = get_function(format, args);
        va_end(args);
        return (length);
}
```
Function to find and execute the right "print", get_function.c

```
int get_function(const char *format, va_list args)
{
        int i = 0, j, length = 0;
/* create a structure associating identifiers and print functions*/
        function_t function[] = {
                {'c', printchar}, {'b', printbinary},
                {'s', printstring}, {'o', printoctal},
                {'%', printpercent}, {'u', printunsigned},
                {'i', printint}, {'x', print_hex_low},
                {'d', printint}, {'X', print_hex_upper},
                {'\0', NULL}
        };
        while (format[i]) /*reads argument*/
        {
                if (format[i] == '%') /*checks the condition to "print" functions*/
                {
                        if (format[i + 1] == '\0')
                                return (-1);
                        j = 0;
                        while (function[j].id)
/*browses the list of functions then calls the associated function*/
                        {
                                if (format[i + 1] == function[j].id)
                                {
                                        length += function[j].fptr(args);
                                        i += 2;
                                        break;
                                }
                                j++;
                        }
                        if (function[j].id == '\0') /* if no corresponding id, prints the string */
                        {
                                _putchar(format[i]), _putchar(format[i + 1]);
                                length += 2, i += 2;                                                }
                }
                else
                {
                        _putchar(format[i]), i++, length++;
                }
        }
        return (length);
}
```
Exemple of one of the printf functions, printstring
```
int printstring(va_list args)
{
        char *str = va_arg(args, char *);
        int length = 0;

        if (str == NULL)
                str = "(null)";
        while (*str) /*until *str == '\0'*/
        {
                _putchar(*str++); /*prints the string character by character*/
                length++;
        }
        return (length);
}
```
## Exemples
Header :
```
#include "main.h"
```
exemple :
```
int main(void)
{
    int age = 25;
    char name[] = "Alice";

    _printf("%c%c ! My name is %s, I'm %d years old\n", 'H', 'i', name, age);

    return (0);
}
```
output :
```
Hi ! My name is Alice, I'm 25 years old
```

## Testing method
To test the \_printf function, you can add the following main.c to the compilation and run the given executable program
```
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	/* test %c %s %% and observe if there is a correct output */
	 _printf("%c", 'S');
	 _printf("%c", '\0');
	 printf("css%ccs%scscscs", 'T', "Test");
	 printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	 _printf("%%");
	 _printf("%!\n");

	 /* test %d %i */
	 _printf("%d == %i\n", 1024, 1024);
	 _printf("iddi%diddiiddi\n", 1024);
	 _printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));

	 /* test %b %o %u %x %X*/

	 _printf("%b", UINT_MAX);
	 _printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);
	 
    return (0);
}
```
When executed, the program should print the following in the standard out :
```
ScssTcsTestcscscsLoading ... 99% Please wait
%%!
1024 == 1024
iddi1024iddiiddi
-2147483648 + 2147483647 = -1
111111111111111111111111111111111024 == 2000 == 400 == 400
```
Memory allocation check
![valgrind_printf](https://github.com/Ancelin-31/holbertonschool-printf/blob/Jeff/screen_valgrind.png)
## Man printf
To read the man page, you can also use the command 
```man -l man_3_printf.3```
![man_printf_3](https://github.com/Ancelin-31/holbertonschool-printf/blob/test/man_printf.png)
## Flowchart

![flowchart_printf](https://github.com/Ancelin-31/holbertonschool-printf/blob/test/flowchart.jpg)
## Authors
This command has been written by Jeffrey BASSET and Ancelin CHEVALLIER.
