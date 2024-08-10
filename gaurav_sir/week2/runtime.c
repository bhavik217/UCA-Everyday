#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* timeval :- 
 
 * tv_sec - The number of whole seconds elapsed since the epoch ( for a simple calender Time - 1 january 1970;
 
 * tv_usec - The number of microseconds elapsed since the time given by tv_sec

*/

int main(){
    // Storing Start time
    struct timeval before;
    gettimeofday(&before, NULL);

    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000LL;
    // Above is converting sec to millisec
    // Converting microsec to millisec

    long long sum = 0;

    for(int i=0; i<1000000000; i++){
        sum += i;
    }

    struct timeval after;
    gettimeofday(&after, NULL);

    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000LL;

    printf("Sum - %lld\n", sum);

    printf("\nRuntime - %llu\n", after_millis - before_millis);
}