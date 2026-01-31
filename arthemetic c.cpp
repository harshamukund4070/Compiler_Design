#include <stdio.h>

int main() {
    char ch;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &ch);

    switch (ch) {
        case '+':
            printf("Valid OPERATOR: + (Addition)\n");
            break;
        case '-':
            printf("Valid OPERATOR: - (Subtraction)\n");
            break;
        case '*':
            printf("Valid OPERATOR: * (Multiplication)\n");
            break;
        case '/':
            printf("Valid OPERATOR: / (Division)\n");
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }

    return 0;
}

