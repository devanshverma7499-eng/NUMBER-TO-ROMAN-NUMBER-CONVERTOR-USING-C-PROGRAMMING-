#include <stdio.h>
#include <string.h>

void convertToRoman(unsigned long long num) {

    if (num == 0) {
        printf("N");
        return;
    }

    if (num >= 4000) {
        convertToRoman(num / 1000);
        printf(" (overline x1000) ");
        num %= 1000;
    }

    int values[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    char *symbols[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            printf("%s", symbols[i]);
            num -= values[i];
        }
    }
}

int main() {

    unsigned long long num;

    printf("===== ROMAN NUMBER CONVERTER =====\n");

    printf("Enter any positive number: ");

    if (scanf("%llu", &num) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("\nRoman Numeral: ");

    convertToRoman(num);

    printf("\n");

    return 0;
}