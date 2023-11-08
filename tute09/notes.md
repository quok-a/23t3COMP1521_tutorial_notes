# Week 08 Tutorial
 
more files, permissions and environment variables

## preface

the following are some examples of environment variables
- `$PATH`
- `$HOME`
- `$LANG`
- `$PWD`

why does running the command `python3`, or `dcc` work? how does the os know what it is?

why do we need to prefix programs with `./` when running our own compiled programs?

when we run `ls -l` we get something like the following
```
- rwx rwx rwx (num links - hard) (owner) (group) (size - bytes) (latest modification) (file name)
|  |   |   |
|  |   |   others permissions (public)
|  |   group permissions
|  owner permissions
file type : `-` for regular file, `d` for a directory 
```
under the hood this is written as binary flags for each permission which can also be read off 
as an octal number, the above would be 777 for example
0b111 111 111


## questions

1. Write a C program, `print_diary.c`, which prints the contents of the file `$HOME/.diary` to stdout
The lecture example `getstatus.c` shows how to get the value of an environment variable.

> snprintf is a convenient function for constructing the pathname of the diary file.

2. The `stat()` and `lstat()` functions both take an argument which is a pointer to a struct stat object, and fill it with the meta-data for a named file.

On Linux, a struct stat contains the following fields (among others, which have omitted for simplicity):
```
struct stat {
    ino_t st_ino;         /* inode number */
    mode_t st_mode;       /* protection */              e.g. S_IRUSR, 0100644
    uid_t st_uid;         /* user ID of owner */        e.g. 516
    gid_t st_gid;         /* group ID of owner */       e.g. 36820
    off_t st_size;        /* total size, in bytes */    e.g. 1855
    blksize_t st_blksize; /* blocksize for filesystem I/O */ e.g. 512, 1024
    blkcnt_t st_blocks;   /* number of 512B blocks allocated */ often in 2^n, 8 blocks 4096 bytes
    time_t st_atime;      /* time of last access */     last time file was read/written, ls -lu
    time_t st_mtime;      /* time of last modification */ 
    time_t st_ctime;      /* time of last status change */ ls -lc e.g. metadata change/file conetents change
    - times calculated as num seconds sincs midnight jan 1 1970
};
```
Explain what each of the fields represents (in more detail than given in the comment!) and give a typical value for a regular file which appears as follows:
```
ls -ls stat.c
8 -rw-r--r--  1 jas  cs1521  1855  Sep  9 14:24 stat.c
```
> Assume that jas has user id 516, and the cs1521 group has group id 36820.

3. Consider the following (edited) output from the command `ls -l ~cs1521`:
```
drwxr-x--- 11 cs1521 cs1521 4096 Aug 27 11:59 17s2.work
drwxr-xr-x  2 cs1521 cs1521 4096 Aug 20 13:20 bin
-rw-r-----  1 cs1521 cs1521   38 Jul 20 14:28 give.spec
drwxr-xr-x  3 cs1521 cs1521 4096 Aug 20 13:20 lib
drwxr-x--x  3 cs1521 cs1521 4096 Jul 20 10:58 public_html
drwxr-xr-x 12 cs1521 cs1521 4096 Aug 13 17:31 spim
drwxr-x---  2 cs1521 cs1521 4096 Sep  4 15:18 tmp
lrwxrwxrwx  1 cs1521 cs1521   11 Jul 16 18:33 web -> public_html
```

    1. Who can access the 17s2.work directory?
    - owner has full perms, grp can write and executre
    2. What operations can a typical user perform on the public_html directory?
    - typical usr not member of grp, execute only
    3. What is the file web?
    - symlink
    4. What is the difference between stat("web", &info) and lstat("web", &info)?
    (where info is an object of type (struct stat))
    - stat follows symlink, gives data on public_html
    - lstat gives data on symlink - web



4. Write a C program, `chmod_if_public_write.c`, which is given 1+ command-line arguments which are the pathnames of files or directories
If the file or directory is publically-writeable, it should change it to be not publically-writeable, leaving other permissions unchanged.
It also should print a line to stdout as in the example below

```
$ dcc chmod_if_public_write.c -o chmod_if_public_write
$ ls -ld file_modes.c file_modes file_sizes.c file_sizes
-rwxr-xrwx 1 z5555555 z5555555 116744 Nov  2 13:00 file_sizes
-rw-r--r-- 1 z5555555 z5555555    604 Nov  2 12:58 file_sizes.c
-rwxr-xr-x 1 z5555555 z5555555 222672 Nov  2 13:00 file_modes
-rw-r--rw- 1 z5555555 z5555555   2934 Nov  2 12:59 file_modes.c

$ ./file_modes file_modes file_modes.c file_sizes file_sizes.c
removing public write from file_sizes
file_sizes.c is not publically writable
file_modes is not publically writable
removing public write from file_modes.c

$ ls -ld file_modes.c file_modes file_sizes.c file_sizes
-rwxr-xr-x 1 z5555555 z5555555 116744 Nov  2 13:00 file_sizes
-rw-r--r-- 1 z5555555 z5555555    604 Nov  2 12:58 file_sizes.c
-rwxr-xr-x 1 z5555555 z5555555 222672 Nov  2 13:00 file_modes
-rw-r--r-- 1 z5555555 z5555555   2934 Nov  2 12:59 file_modes.c
```

5. .Write a C program, `print_file_bits.c`, which given as a command line arguments the name of a file contain 32-bit hexadecimal numbers, one per line, prints the low (least significant) bytes of each number as a signed decimal number (-128..127).
