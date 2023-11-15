# Week 10 Tutorial
 
processes, threads and concurrency

## preface
- How is the assignment going?
- myExperience

- Processes
    - task manager/activity monitor/top/ps
    - we can run processes within our programs using `posix_spawn` via `spawn.h`
    - (deprecated) we can also create processes with fork/exec. this is essentially what `posix_spawn` does
- Paralellism vs concurrency
    - 1 server at a cafe vs
    - several servers
- How can we make concurrent programs?
    - POSIX threads via `pthreads.h`
    - make sure to link the library when compiling by using the `-pthread` flag
- Race conditions
    - [deadlock empire](https://deadlockempire.github.io/)

## questions

1. Write a program `now.c` which prints the following:
    The current date.
    The current time.
    The current user.
    The current hostname.
    The current working directory.

2. Write a C program that creates a thread that infinitely prints some message provided by main (eg. "Hello\n"), while the main (default) thread infinitely prints a different message (eg. "there!\n"). 

3. The program `thread_hello.c` attempts (and fails) to say hello from another thread:
Why? And how do we fix it?

4. Write a C program that creates a thread which infinitely prints the message `"feed me input!\n"` once per second, while the main (default) thread continuously reads in lines of input, and prints those lines back out to stdout with the prefix: `"you entered: "`. 

5. `race.c`
- mutex and atomic types