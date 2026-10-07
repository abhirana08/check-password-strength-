#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, score = 0;
    int upper = 0, lower = 0, digit = 0, special = 0;

    printf("=================================\n");
    printf("     PASSWORD STRENGTH CHECKER\n");
    printf("=================================\n");

    printf("Enter your password: ");
    scanf("%99s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            upper = 1;
        else if (islower(password[i]))
            lower = 1;
        else if (isdigit(password[i]))
            digit = 1;
        else
            special = 1;
    }

    if (length >= 8)
        score++;

    if (upper)
        score++;

    if (lower)
        score++;

    if (digit)
        score++;

    if (special)
        score++;

    printf("\nPassword Analysis:\n");
    printf("Length: %d characters\n", length);

    printf("Uppercase letter: %s\n", upper ? "Yes" : "No");
    printf("Lowercase letter: %s\n", lower ? "Yes" : "No");
    printf("Number: %s\n", digit ? "Yes" : "No");
    printf("Special character: %s\n", special ? "Yes" : "No");

    printf("\nStrength: ");

    if (score <= 2)
        printf("WEAK\n");
    else if (score <= 4)
        printf("MEDIUM\n");
    else
        printf("STRONG\n");

    return 0;
}