// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <errno.h>

// int main(){
//     int fd = open("file1.txt", O_RDONLY | O_CREAT);

//     if(fd == -1){
//         perror("c1");
//         exit(1);
//     }
//     printf("Opened the file fd = %d\n", fd);


//     write();

//     if(close(fd) == -1){
//         perror("c1");
//         exit(1);
//     }
//     printf("File closed\n");


//     // Return Value
//     // 0 on success.
//     // -1 on error

//     // Destroy file table entry referenced by element fd of the file descriptor table – As long as no other process is pointing to it!
//     // Set element fd of file descriptor table to NULL
// }