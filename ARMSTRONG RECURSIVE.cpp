#include <stdio.h>
#include <math.h>

int numDigits(int num) {
    int digits = 0;
    while (num != 0) {
        num /= 10;
        digits++;
    }
    return digits;
}

int armstrongSum(int num, int n) {
    if (num == 0) {
        return 0;
    } else {
        int remainder = num % 10;
        return pow(remainder, n) + armstrongSum(num / 10, n);
    }
}

int main() {
    int num, n, result;
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    n = numDigits(num);
    result = armstrongSum(num, n);
    
    if (result == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    
    return 0;
}