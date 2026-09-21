#include <stdio.h>

int main() {
    int n, i, j, key;
    int shifts = 0;

    printf("Enter number of marks: ");
    scanf("%d", &n);

    int marks[n];

    printf("Enter the marks:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    // Insertion Sort
    for (i = 1; i < n; i++) {
        key = marks[i];
        j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && marks[j] > key) {
            marks[j + 1] = marks[j];
            j--;
            shifts++;
        }

        marks[j + 1] = key;

        // Display array after each pass
        printf("After pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", marks[k]);
        }
        printf("\n");
    }

    // Final sorted array
    printf("\nFinal sorted list: ");
    for (i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    printf("\nTotal number of shifts: %d\n", shifts);

    return 0;
}