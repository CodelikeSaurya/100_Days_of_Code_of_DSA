#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0;
    int count = 0;

    // Hash table to store frequency of prefix sums
    int hash[2 * MAX + 1] = {0};
    int offset = MAX;   // To handle negative sums

    hash[offset] = 1;   // Prefix sum 0 occurs once

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(hash[prefix + offset] > 0) {
            count += hash[prefix + offset];
        }

        hash[prefix + offset]++;
    }

    printf("%d\n", count);

    return 0;
}