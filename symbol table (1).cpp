#include <stdio.h>
#include <string.h>

#define SIZE 20   // maximum number of symbols

// Structure to hold symbol details
struct Symbol {
    char name[20];
    char type[10];
} table[SIZE];

int count = 0;  // number of symbols

// Function to insert a symbol
void insert(const char name[], const char type[]) {
    if (count >= SIZE) {
        printf("Symbol Table Full!\n");
        return;
    }
    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    count++;
    printf("Inserted: %s (%s)\n", name, type);
}

// Function to search a symbol
void search(const char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Found: %s (%s)\n", table[i].name, table[i].type);
            return;
        }
    }
    printf("%s not found!\n", name);
}

// Function to display all symbols
void display() {
    int i;
    if (count == 0) {
        printf("Symbol Table Empty!\n");
        return;
    }
    printf("\nSymbol Table:\n");
    printf("Name\tType\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%s\n", table[i].name, table[i].type);
    }
}

int main() {
    // insert some symbols
    insert("x", "int");
    insert("y", "float");
    insert("sum", "function");

    // display symbol table
    display();

    // search symbols
    search("y");
    search("z");

    return 0;
}

