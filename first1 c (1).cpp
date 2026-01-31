#include <stdio.h>
#include <string.h>

#define MAX 10

// Function to add a symbol to the FIRST set if not already present
void addToFirst(char first[], char symbol) {
    if (strchr(first, symbol) == NULL) {
        int len = strlen(first);
        first[len] = symbol;
        first[len + 1] = '\0';
    }
}

int main() {
    // Grammar:
    // S ? AaAb | BbBa
    // A ? e
    // B ? e

    char FIRST_S[MAX] = "";
    char FIRST_A[MAX] = "";
    char FIRST_B[MAX] = "";

    // A ? e
    addToFirst(FIRST_A, 'e');

    // B ? e
    addToFirst(FIRST_B, 'e');

    // S ? AaAb | BbBa
    // Since A and B are epsilon-producing, FIRST(S) includes FIRST(AaAb) and FIRST(BbBa)
    // First symbol of first production: A ? e, next symbol is 'a' ? include 'a'
    addToFirst(FIRST_S, 'a');
    // First symbol of second production: B ? e, next symbol is 'b' ? include 'b'
    addToFirst(FIRST_S, 'b');

    // Print FIRST sets
    printf("FIRST(A) = { %s }\n", FIRST_A);
    printf("FIRST(B) = { %s }\n", FIRST_B);
    printf("FIRST(S) = { %s }\n", FIRST_S);

    return 0;
}

