#include <stdio.h>
#include <ctype.h> // Required for tolower() function

int main() {
    char str[150];
    int i;
    int vowels = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        for (i = 0; str[i] != '\0'; ++i) {
            char ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            }
        }
        printf("Number of vowels: %d\n", vowels);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
