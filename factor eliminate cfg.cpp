#include <stdio.h>

// Function to print the original grammar
void printOriginalGrammar() {
    printf("=== Original Grammar ===\n");
    printf("S ? iEtS | iEtSeS | a\n");
    printf("E ? b\n\n");
}

// Function to identify common prefix
void identifyCommonPrefix() {
    printf("=== Step 1: Identify common prefix ===\n");
    printf("For productions: S ? iEtS | iEtSeS\n");
    printf("Common prefix: iEtS\n\n");
}

// Function to apply left factoring
void applyLeftFactoring() {
    printf("=== Step 2: Apply left factoring ===\n");
    printf("S ? iEtS S' | a\n");
    printf("S' ? eS | e\n");
    printf("E ? b\n\n");
}

// Function to print the final left-factored grammar
void printLeftFactoredGrammar() {
    printf("=== Final Left-Factored Grammar ===\n");
    printf("S  ? iEtS S' | a\n");
    printf("S' ? eS | e\n");
    printf("E  ? b\n");
}

int main() {
    printOriginalGrammar();
    identifyCommonPrefix();
    applyLeftFactoring();
    printLeftFactoredGrammar();
    return 0;
}

