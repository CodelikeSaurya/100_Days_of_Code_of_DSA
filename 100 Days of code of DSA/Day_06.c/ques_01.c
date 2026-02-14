#include <stdio.h>

int main() {
    int n, i, j = 0;
    int a[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Remove duplicates
    for (i = 1; i < n; i++) {
        if (a[i] != a[j]) {
            j++;
            a[j] = a[i];
        }
    }

    // Print unique elements
    for (i = 0; i <= j; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
