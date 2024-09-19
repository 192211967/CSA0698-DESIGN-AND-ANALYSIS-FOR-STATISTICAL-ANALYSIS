#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num, int divisor) {
    if (num <= 2) return num == 2;
    if (num % divisor == 0) return false;
    if (divisor * divisor > num) return true;
    return isPrime(num, divisor + 1);
}

void printPrimes(int num) {
    if (num < 2) return;
    if (isPrime(num, 2)) {
        printPrimes(num - 1);
        printf("%d ", num);
    } else {
        printPrimes(num - 1);
    }
}

int main() {
    int limit;
    
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);
    
    printf("Prime numbers up to %d are:\n", limit);
    printPrimes(limit);
    printf("\n");
    
    return 0;
}
