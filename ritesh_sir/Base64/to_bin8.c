#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *to_bin8(int num){
    char *str = (char *) malloc(9 * (sizeof(char)));

    for(int i=0; i<8; i++) str[i] = '0';
    str[8] = '\0';
    
    int size = 7;
    while(num){
        int ld = num % 2;
        num /= 2;
        
        str[size--] = '0' + ld;
    }
    return str;
}