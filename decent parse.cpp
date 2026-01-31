#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];   // input string
int i = 0;         // current position in input
int error = 0;     // error flag

// Function prototypes
void E();
void Eprime();
void T();
void Tprime();
void F();

// Match function: checks if current symbol matches expected
void match(char expected) {
    if (input[i] == expected) {
        i++;
    } else {
        error = 1;
    }
}

// E ? T E’
void E() {
    T();
    Eprime();
}

// E’ ? + T E’ | e
void Eprime() {
    if (input[i] == '+') {
        match('+');
        T();
        Eprime();
    }
    // else e ? do nothing
}

// T ? F T’
void T() {
    F();
    Tprime();
}

// T’ ? * F T’ | e
void Tprime() {
    if (input[i] == '*') {
        match('*');
        F();
        Tprime();
    }
    // else e ? do nothing
}

// F ? (E) | id
void F() {
    if (input[i] == '(') {
        match('(');
        E();
        if (input[i] == ')')
            match(')');
        else
            error = 1;
    } else if (isalpha(input[i])) {  // id ? single letter
        match(input[i]);
    } else {
        error = 1;
    }
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);

    E();

    // check if parsing finished without error and consumed all input
    if (error == 0 && input[i] == '\0')
        printf("Parsing successful!\n");
    else
        printf("Parsing failed!\n");

    return 0;
}

