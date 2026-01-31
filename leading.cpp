#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][10];
char lead[10][10];
int n;

void findLeading(char nt, int row) {
    for (int i = 0; i < n; i++) {
        if (production[i][0] == nt) {
            // Case 1: if RHS starts with a terminal
            if (!isupper(production[i][2]))
                lead[row][strlen(lead[row])] = production[i][2];
            // Case 2: if RHS starts with non-terminal
            else if (isupper(production[i][2])) {
                findLeading(production[i][2], row);
                // Case 3: if RHS starts with '('
            } else if (production[i][2] == '(')
                lead[row][strlen(lead[row])] = '(';
        }
    }
}

int main() {
    int i, j;
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions (use -> format, e.g., E->E+T):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    for (i = 0; i < n; i++)
        lead[i][0] = '\0';

    for (i = 0; i < n; i++) {
        findLeading(production[i][0], i);
    }

    printf("\nLEADING sets:\n");
    for (i = 0; i < n; i++) {
        printf("LEADING(%c) = { ", production[i][0]);
        for (j = 0; j < strlen(lead[i]); j++)
            printf("%c ", lead[i][j]);
        printf("}\n");
    }

    return 0;
}

