#include <stdio.h>

int main() {
    int m, n;
    int a[20][20];
    int i, j;
    int isToeplitz = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the matrix elements:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 1; i < m; i++) {
        for(j = 1; j < n; j++) {
            if(a[i][j] != a[i-1][j-1]) {
                isToeplitz = 0;
                break;
            }
        }
        if(isToeplitz == 0)
            break;
    }

    if(isToeplitz == 1)
        printf("Matrix is Toeplitz");
    else
        printf("Matrix is not Toeplitz");

    return 0;
}