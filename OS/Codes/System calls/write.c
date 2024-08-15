#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(){
    int fd = open("file.txt", O_WRONLY);

    if(fd < 0){
        perror("r1");
        exit(1);
    }

    int sz = write(fd, "bhavik sharma\n", strlen("bhavik sharma\n"));
    printf("%d", sz);

    close(fd);
}