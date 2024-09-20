#include <stdio.h>

/* Recursive function to print factors of N */
void findFactors(int N, int i) {
    if (i > N)  // Base case: stop when i exceeds N
        return;

    if (N % i == 0)  // If i is a factor of N
        printf("%d ", i);

    // Recursive call to check the next number
    findFactors(N, i + 1);
}

int main() {
    int N;
    printf("Enter a number to find its factors: ");
    scanf("%d", &N);

    printf("Factors of %d are: ", N);
    findFactors(N, 1);  // Start finding factors from 1

    return 0;
}
