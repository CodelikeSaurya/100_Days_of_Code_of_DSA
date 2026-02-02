#include <stdio.h>

int main() {
    int n, pos, i;
    int arr[100];

    // Ask user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Ask user to enter array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask user for position to delete (1-based index)
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    // Check whether position is valid
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements to the left to overwrite the deleted element
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Display the updated array
    printf("Array after deletion:\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}