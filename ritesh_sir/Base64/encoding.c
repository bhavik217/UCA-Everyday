#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "include_files/to_bin8.h"   // to_bin.h will convert ascii to binary

char *encoding(char *s){
    const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int n = strlen(s);

    char *bin_8block = (char *) malloc((8 * n + 1) * sizeof(char));
    bin_8block[8 * n] = '\0';

    int idx = 0;
    for(int i=0; i<n; i++){
        char *str = to_bin8(s[i]);
        for(int j=0; j<8; j++){
            bin_8block[idx++] = str[j];
        }
        free(str);
    }
    // Now bin_8block have binaryData of inp str

    int m = strlen(bin_8block);

    int encoded_length = 4 * ((n + 2) / 3);
    char *encoded_str = malloc(sizeof(char) * (encoded_length + 1));

    int c = 5;
    int sum = 0;
    int idx2 = 0;

    for(int i=0; i < m; i++){
        sum += pow(2, c--) * (bin_8block[i] - '0');
        if((i+1) % 6 == 0) {
            encoded_str[idx2++] = base64_chars[sum];
            c = 5;
            sum = 0;
        }
    }
    
    encoded_str[idx2++] = base64_chars[sum];

    while(idx2 < encoded_length) encoded_str[idx2++] = '=';

    encoded_str[idx2] = '\0';

    free(bin_8block);

    return encoded_str;
}