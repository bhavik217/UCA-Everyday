// Create calloc using malloc

#include <stdio.h>
#include <stdlib.h>

void *callocc(int n){
   
    char *arr = (char *) malloc(n);

    for(int i = 0; i < n; i++) arr[i] = EOF;

    for(int i = 0; i < n; i++) printf("%c ", arr[i]);

    return (void *)arr;
}

int main(){
    int n;
    scanf("%d", &n);

    void *ptr = callocc(n);
}



#include <stdio.h>

int main(){
    char *str1 = "HEllo woRlD";
    str1[1] = '@';      // We can't change string which is defined with a pointer(It is basically Read Only memory, Compiler read it as code and it becomes constant)

    printf("%s\n", str1);
}

int main(){
    char str2[] = "hellO wOrLd";
    str2[2] = 'j';      // We can change string declared as char array

    printf("%s\n", str2);
}