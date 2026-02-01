#include <stdio.h>

int main() {
    int n, pos, x, i;
    int a[50];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &pos);
    scanf("%d", &x);

    // shift elements to the right
    for (i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    // insert element
    a[pos - 1] = x;

    // print array
    for (i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
