#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include_files/to_bin8.h"
#include "include_files/encoding.h"

int main(){
    char s[100];
    scanf("%[^\n]", s);

    char *encoded_str = encoding(s);
    printf("%s", encoded_str);
}