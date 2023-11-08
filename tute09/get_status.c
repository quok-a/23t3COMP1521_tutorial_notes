/*

$ dcc get_status.c -o get_status
$ STATUS=ok ./get_status
Environment variable 'STATUS' has value 'ok'
$

*/

#include <stdio.h>
#include <stdlib.h>

// simple example of accessing an environment variable
int main(void) {
    // print value of environment variable STATUS
    char *value = getenv("STATUS");
    printf("Environment variable 'STATUS' has value '%s'\n", value);
    return 0;
}