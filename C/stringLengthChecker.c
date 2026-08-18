#include <stdio.h>

int main(void) {
    int i = 0;
    char str[50];
    printf("Enter a string to check its length: ");
    scanf("%s",str);
    while (str[i] != 0){
        i++;
    }
    printf("The size of the given string is %d characters.",i);
    return 0;
}