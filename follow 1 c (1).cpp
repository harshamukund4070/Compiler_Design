#include <stdio.h>
#include <string.h>

int main() {
    // FOLLOW sets as strings (to store terminals and $ for end of input)
    char FOLLOW_S[10] = "$"; // Start symbol contains $
    char FOLLOW_A[10] = "";
    char FOLLOW_B[10] = "";

    // S ? AaAb | BbBa
    // FOLLOW(A):
    // In S ? AaAb: A is followed by 'a' ? include 'a'
    // Also, second A is followed by 'b' ? include 'b'
    strcat(FOLLOW_A, "ab");

    // FOLLOW(B):
    // In S ? BbBa: B is followed by 'b' ? include 'b'
    // Also, second B is followed by 'a' ? include 'a'
    strcat(FOLLOW_B, "ba");

    // FOLLOW(S) already contains '$'

    // Print FOLLOW sets
    printf("FOLLOW(S) = { %s }\n", FOLLOW_S);
    printf("FOLLOW(A) = { %s }\n", FOLLOW_A);
    printf("FOLLOW(B) = { %s }\n", FOLLOW_B);

    return 0;
}

