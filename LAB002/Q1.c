#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter size of array:\n");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("Enter value for index %d: ", i);
        scanf("%d", &arr[i]);
    }

    int n;
    printf("Enter window size: ");
    scanf("%d", &n);

    if (n > size) {
        printf("Window size is greater than the array size!\n");
        free(arr);
        return 0;
    }

    float alpha = 2.0 / (n + 1);
    float ema = arr[0]; // Start with the first value as EMA

    for (int i = 1; i < n; i++) {
        ema = (alpha * arr[i]) + (1 - alpha) * ema;
    }

    printf("EMA for last %d days: %.2f\n", n, ema);
    free(arr);
    return 0;
}
