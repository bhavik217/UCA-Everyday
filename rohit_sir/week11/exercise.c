// Code-1
// Take input from user with spaces

// #include<stdio.h>
// int main(){
//     char inp[100];

//     if(fgets(inp, sizeof(inp), stdin) != NULL){
//         printf("You have entered %s\n", inp);
//     }
//     else printf("Error while taking input\n");
// }



// Code-2
// Read text from a file with spaces

// #include <stdio.h>
// int main(){
//     FILE *ptr = fopen("file.txt", "r");
//     if(ptr == NULL){
//         printf("Error opening file\n");
//         return 0;
//     }

//     char inp[100];
//     if(fgets(inp, sizeof(inp), ptr) != NULL){
//         printf("%s", inp);
//     }
//     else printf("Error while taking input\n");
// }



// Code-3
// Write to terminal without printf()

// #include <stdio.h>
// int main() {
//     int num = 42;
//     double pi = 3.14159;
//     char str[] = "Hello, stdout!";

//     fprintf(stdout, "%d\n", num);
//     fprintf(stdout, "%u\n", pi);
//     fprintf(stdout, "%s\n", str);
//     return 0;
// }



// Code-4
// Write to a file

// #include <stdio.h>
// int main() {
//     FILE *ptr = fopen("output.txt", "w");
//     if(ptr == NULL){
//         printf("Error opening file\n");
//         return 0;
//     }

//     int num = 42;
//     double pi = 3.14159;
//     char str[] = "Hello, stdout!";

//     fprintf(ptr, "%d\n", num);
//     fprintf(ptr, "%u\n", pi);
//     fprintf(ptr, "%s\n", str);

//     fclose(ptr);
// }