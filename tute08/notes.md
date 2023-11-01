# Week 08 Tutorial
 
Unix files - ~everying~ is a file

1. Looking at the given diagram:

    1. What is the full pathname of COMP1521's web directory?
    - /home/cs1521/web

    2. Which directory is ~jas/../..?
    - /

    3. Links to the children of a given directory are stored as entries in the directory structure. Where is the link to the parent directory stored?
    - ..

    4. What kind of filesystem object is cat?
    - regular file, executable

    5. What kind of filesystem object is home?
    - directory

    6. What kind of filesystem object is tty0?
    - represents a device (character special file)

    7. What kind of filesystem object is a symbolic link? What value does it contain?
    - contains another file 

    8. Symbolic links change the filesystem from a tree structure to a graph structure. How do they do this? 
```
    a     b -> c then we have   a
   / \                         / \
  b   c                       b - c
```

2. Write a C program, fgrep.c, which is given 1+ command-line arguments which is a string to search for.

> If there is only 1 command-line argument it should read lines from stdin and print them to stdout iff they contain the string specified as the first command line argument.

> If there are 2 or more command line arguments, it should treat arguments after the first as filenames and print any lines they contain which contain the string specified as the first command line arguments.

> When printing lines your program should prefix them with a line number.

> It should print suitable error messages if given an incorrect number of arguments or if there is an error opening a file.

3. What does fopen do? What are its parameters?
- opens a file: `FILE *fopen('/home/jas/work', 'r')`
- mode options `r`, `a`, `w`

4. What are some circumstances when fopen returns NULL?
- file doesn't exist
- no permission
- invalid mode

5. How do you print the specific reason that caused fopen to return NULL? 
- `errno`, indicates error
- errno.h

6. *Write a C program, first_line.c, which is given one command-line argument, the name of a file, and which prints the first line of that file to stdout. If given an incorrect number of arguments, or if there was an error opening the file, it should print a suitable error message.

7. *Write a C program, write_line.c, which is given one command-line argument, the name of a file, and which reads a line from stdin, and writes it to the specified file; if the file exists, it should be overwritten.

8. *Write a C program, append_line.c, which is given one command-line argument, the name of a file, and which reads a line from stdin and appends it to the specified file.

9. Why should you not use fgets or fputs with binary data? 
- '\0' `0`
- instead fgetc/fputc

10. *`printf ("%c%c%c%c%c%c", 72, 101, 0x6c, 108, 111, 0x0a);` displays?

11. How many different values can fgetc return?
- 256 (2^8)

12. Why are the names of fgetc, fputc, getc, putc, putchar, and getchar misleading? 
- they operate on a byte

13. For each of the following calls to the `fopen()` library function, give an `open()` system call that has equivalent semantics relative to the state of the file.

    1. `fopen(FilePath, "r")` - `open(FilePath, O_RDONLY)`
    2. `fopen(FilePath, "a")` - `open(FilePath, O_WRONLY | O_APPEND | O_CREAT)`
    3. `fopen(FilePath, "w")` - `open(FilePath, O_WRONLY | O_CREAT | O_TRUNC)`
    4. `fopen(FilePath, "r+")` - `open(FilePath, O_RDWR)`
    5. `fopen(FilePath, "w+")` - `open(FilePath, O_RDWR | O_CREAT | O_TRUNC)`

> Obviously, `fopen()` returns a `FILE*`, and `open()` returns an integer file descriptor. Ignore this for the purposes of the question; focus on the state of the open file. 

14. Consider the lseek(fd, offset, whence) function.
    1. What is its purpose?
    - move file pointer
    2. When would it be useful?
    - reading through files at a known pos
    3. What does its return value represent? 
    - file position

15. Consider a file of size 10000 bytes, open for reading on file descriptor fd, initially positioned at the start of the file (offset 0). What will be the file position after each of these calls to lseek()? Assume that they are executed in sequence, and one will change the file state that the next one deals with.

    1. `lseek(fd, 0, SEEK_END);`     10000 (end position of file)
    2. `lseek(fd, -1000, SEEK_CUR);` move back 1000 from 10000, result is offset 9000
    3. `lseek(fd, 0, SEEK_SET);`     move start of file, offset
    4. `lseek(fd, -100, SEEK_SET);`  remain unchanged
    5. `lseek(fd, 1000, SEEK_SET);`  position 1000
    6. `lseek(fd, 1000, SEEK_CUR);`  1000 + 1000 = 2000

16. *If a file `xyz` contains 2500 bytes, and it is scanned using the following code: 

```
int fd;         // open file descriptor
int nb;         // # bytes read
int ns = 0;     // # spaces
char buf[BUFSIZ]; // input buffer

fd = open ("xyz", O_RDONLY);
assert (fd >= 0);
while ((nb = read (fd, buf, 1000)) > 0) {
    for (int i = 0; i < nb; i++)
        if (isspace (buf[i]))
            ns++;
}
close (fd);
```
> Assume that all of the relevant `#include`'s are done.

How many calls with be made to the `read()` function, and what is the value of `nb` after each call? 