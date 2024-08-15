#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
    int fd = open("file.txt", O_RDONLY);
    if(fd < 0){
        perror("r1");
        exit(1);
    }

    char *c = (char *) malloc(10 * sizeof(char));
    int sz = read(fd, c, 10);

    c[sz] = '\0';

    printf("%s\n", c);
}