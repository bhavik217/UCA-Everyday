#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(){
    // if file does not have in directory then file foo.txt is created.
    int fd = open("foo.txt", O_RDONLY | O_CREAT);

    // Path :-
    // * absolute path with "/" when not working in same directory as file
    // * relative path when working in same directory


    // Flags :-
    // O_RDONLY Opens the file in read-only mode.
    // O_WRONLY Opens the file in write-only mode.
    // O_RDWR Opens the file in read and write mode.
    // O_CREAT Create a file if it doesn’t exist.


    if(fd == -1){
        // print which type of error have in a code
        printf("Error Number % d\n", errno);

        // print program detail "Success or failure"
        perror("Program");
    }
}