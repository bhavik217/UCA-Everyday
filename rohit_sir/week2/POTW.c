#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // Consume the newline character after the integer input
    getchar();  // NECESSARY

    char *arr = (char *)malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &arr[i]);
    }

    int freq[26] = {0};
    int dist_chars = 0;

    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (freq[arr[i] - 'a'] == 0) dist_chars++;
        freq[arr[i] - 'a']++;

        while (dist_chars > 2) {
            freq[arr[j] - 'a']--;
            if (freq[arr[j] - 'a'] == 0) dist_chars--;
            j++;
        }
        if (i - j + 1 > ans) ans = i - j + 1;
    }
    printf("%d\n", ans);

    free(arr);
}
