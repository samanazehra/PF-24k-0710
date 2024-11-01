#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int binaryToDecimal(int number) {
    int decimal = 0;
    int base = 1;
    while (number > 0) {
        int lastDigit = number % 10;
        decimal += lastDigit * base;
        base *= 2;
        number /= 10;
    }
    return decimal;
}

int decimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        int lastDigit = number % 2;
        binary += lastDigit * base;
        base *= 10;
        number /= 2;
    }
    return binary;
}

void decimalToHexadecimal(int number) {
    if (number < 0) {
        printf("Invalid input. Please enter a non-negative decimal number.\n");
        return;
    }
    char hex[20];
    int index = 0;
    while (number > 0) {
        int remainder = number % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = remainder - 10 + 'A';
        }
        number /= 16;
    }
    hex[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - 1 - i];
        hex[index - 1 - i] = temp;
    }
    printf("Hexadecimal: %s\n", hex);
}

int hexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0;
    for (int i = 0; hexNumber[i] != '\0'; i++) {
        char currentChar = toupper(hexNumber[i]);
        int value;
        if (currentChar >= '0' && currentChar <= '9') {
            value = currentChar - '0';
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            value = currentChar - 'A' + 10;
        } else {
            printf("Invalid hexadecimal input.\n");
            return -1;  // Return -1 to indicate an error
        }
        decimal = decimal * 16 + value;
    }
    return decimal;
}

void binaryToHexadecimal(int number) {
    int decimal = binaryToDecimal(number);
    decimalToHexadecimal(decimal);
}

void hexadecimalToBinary(char hexNumber[]) {
    int decimal = hexadecimalToDecimal(hexNumber);
    if (decimal >= 0) {
        printf("Binary: %d\n", decimalToBinary(decimal));
    }
}

int main() {
    int choice, decimal, binary;
    char hexNumber[20];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &binary);
                printf("Decimal: %d\n", binaryToDecimal(binary));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("Binary: %d\n", decimalToBinary(decimal));
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("Decimal: %d\n", hexadecimalToDecimal(hexNumber));
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &binary);
                binaryToHexadecimal(binary);
                break;
            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                hexadecimalToBinary(hexNumber);
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
