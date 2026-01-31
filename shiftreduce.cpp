#include <stdio.h>
#include <string.h>

char input[100], stack[100];
int i = 0, top = -1;

// Function to check and reduce
void check() {
    if (top >= 1 && stack[top] == 'd' && stack[top - 1] == 'i') {
        stack[top - 1] = 'E';
        stack[top] = '\0';
        top--;
        printf("Reduce: E -> id\n");
    }
    else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
        stack[top - 2] = 'E';
        stack[top - 1] = '\0';
        stack[top] = '\0';
        top -= 2;
        printf("Reduce: E -> E+E\n");
    }
}

int main() {
    printf("Enter input string (example: id+id): ");
    scanf("%s", input);

    printf("\nSHIFT-REDUCE PARSING PROCESS\n");
    printf("---------------------------------\n");

    while (input[i] != '\0') {
        stack[++top] = input[i];
        stack[top + 1] = '\0';
        printf("Shift: %s\n", stack);
        i++;
        check();  // try to reduce after every shift
    }

    // Final check
    if (strcmp(stack, "E") == 0)
        printf("\nAccepted: The input is valid as per grammar.\n");
    else
        printf("\nRejected: The input is invalid.\n");

    return 0;
}

