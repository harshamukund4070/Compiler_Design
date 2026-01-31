#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char expr[MAX];
int tempCount = 1;

// Function to create a new temporary variable
void newTemp(char *t) {
    sprintf(t, "t%d", tempCount++);
}

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Apply operator and generate TAC
void applyOp(char valStack[MAX][10], int *topVal, char opStack[MAX], int *topOp) {
    char right[10], left[10], temp[10];

    strcpy(right, valStack[(*topVal)--]);
    strcpy(left, valStack[(*topVal)--]);

    newTemp(temp);
    printf("%s = %s %c %s\n", temp, left, opStack[(*topOp)--], right);

    strcpy(valStack[++(*topVal)], temp);
}

// Convert infix to TAC
void generateTAC(char *exp) {
    char opStack[MAX], valStack[MAX][10];
    int topOp = -1, topVal = -1;
    int i, n = strlen(exp);

    for (i = 0; i < n; i++) {
        if (isspace(exp[i])) continue;

        if (isalpha(exp[i])) {
            char str[2] = {exp[i], '\0'};
            strcpy(valStack[++topVal], str);
        }
        else if (exp[i] == '(') {
            opStack[++topOp] = exp[i];
        }
        else if (exp[i] == ')') {
            while (topOp >= 0 && opStack[topOp] != '(')
                applyOp(valStack, &topVal, opStack, &topOp);
            topOp--; // pop '('
        }
        else { // operator
            while (topOp >= 0 && precedence(opStack[topOp]) >= precedence(exp[i]))
                applyOp(valStack, &topVal, opStack, &topOp);
            opStack[++topOp] = exp[i];
        }
    }

    while (topOp >= 0)
        applyOp(valStack, &topVal, opStack, &topOp);
}

int main() {
    printf("Enter arithmetic expression: ");
    scanf("%s", expr);

    printf("\n--- Three Address Code ---\n");
    generateTAC(expr);

    return 0;
}

