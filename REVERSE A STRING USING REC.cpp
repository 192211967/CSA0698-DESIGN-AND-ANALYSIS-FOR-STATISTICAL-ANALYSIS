#include <stdio.h>
void reverseString(char *str) 
{
    if (*str == '\0') 
	{
        return;
    }
    reverseString(str + 1);
    printf("%c", *str);
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str);
    printf("Reversed string: ");
    reverseString(str);
    printf("\n");
    return 0;
}
