#include <stdio.h>
#include "functions.h"

int main() {
    int balance = 100;
    int choice;
    do {
        clearScreen();
        drawFrame();
        printf("| Balance: %d coins    |\n", balance);
        printf("+---------------------+\n");
        choice = displayMenu();
        switch (choice) {
            case 1:
                playGame(&balance);
                break;
            case 2:
                showRules();
                break;
            case 3:
                clearScreen();
                printf("Goodbye!\n");
                break;
        }
    } while (choice != 3);
    return 0;
}