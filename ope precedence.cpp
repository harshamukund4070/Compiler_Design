#include <stdio.h>
#include <string.h>

char stack[50];
char input[50];
int top = -1;

// Function to return precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    int i = 0;
    printf("Enter the input string (use i for identifiers, end with $): ");
    scanf("%s", input);

    stack[++top] = '$';

    printf("\n%-15s%-15s%-15s\n", "STACK", "INPUT", "ACTION");
    printf("---------------------------------------------\n");

    while (1) {
        if (stack[top] == '$' && input[i] == '$') {
            printf("%-15s%-15sAccepted\n", stack, input + i);
            break;
        }

        if (input[i] == 'i') {
            stack[++top] = 'E'; // Treat 'i' as an expression
            printf("%-15s%-15sShift i, Reduce to E\n", stack, input + i);
            i++;
        }
        else if (isOperator(input[i])) {
            // Check precedence of top operator and current operator
            if (isOperator(stack[top]) && precedence(stack[top]) >= precedence(input[i])) {
                // Reduce E op E -> E
                stack[top - 2] = 'E';
                stack[top - 1] = '\0';
                top -= 2;
                printf("%-15s%-15sReduce E op E -> E\n", stack, input + i);
            } else {
                stack[++top] = input[i];
                printf("%-15s%-15sShift %c\n", stack, input + i, input[i]);
                i++;
            }
        }
        else if (input[i] == '$') {
            if (top >= 2 && stack[top - 2] == 'E' && isOperator(stack[top - 1]) && stack[top] == 'E') {
                stack[top - 2] = 'E';
                stack[top - 1] = '\0';
                top -= 2;
                printf("%-15s%-15sReduce E op E -> E\n", stack, input + i);
            } else {
                i++;
            }
        }
        else {
            printf("Error: Invalid symbol %c\n", input[i]);
            break;
        }
    }

    return 0;
}

