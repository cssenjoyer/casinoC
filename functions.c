#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void clearScreen() {
    system("cls");
}

void drawFrame() {
    printf("\n+---------------------+\n");
    printf("|   SLOT-MACHINE      |\n");
    printf("+---------------------+\n");
}

int displayMenu() {
    int position = 1;
    char input;
    while (1) {
        clearScreen();
        drawFrame();
        printf("| %s 1. Play          |\n", position == 1 ? "->" : "  ");
        printf("| %s 2. Rules         |\n", position == 2 ? "->" : "  ");
        printf("| %s 3. Exit          |\n", position == 3 ? "->" : "  ");
        printf("+---------------------+\n");
        printf("Use arrows up/down, Enter to choose\n");

        input = _getch();
        if (input == 72 && position > 1) {
            position--;
        } else if (input == 80 && position < 3) {
            position++;
        } else if (input == 13) {
            return position;
        }
    }
}

void showRules() {
    clearScreen();
    drawFrame();
    printf("| Rules:             |\n");
    printf("| 1. Three symbols   |\n");
    printf("| 2. BINGO = MAX WIN |\n");
    printf("| Symbols: |, L, 7, Sun |\n");
    printf("| - Stake: 10 coins  |\n");
    printf("| - Big Win (2 + Multiplier): 50 x Multiplier |\n");
    printf("| - MAX WIN (3 identical): 100 coins |\n");
    printf("| Multipliers: x2, x3, x5, x10, x25 |\n");
    printf("+---------------------+\n");
    printf("Press Enter...");
    _getch();
}

void playGame(int *balance) {
    char* symbols[] = {"7", "BAR", "Sun", "MAX"};
    char* multipliers[] = {"x2", "x3", "x5", "x10", "x25"};
    int reel1, reel2, reel3;
    int multiplier_index = -1;
    int multiplier_value = 1;

    if (*balance < 10) {
        clearScreen();
        drawFrame();
        printf("| Insufficient balance! |\n");
        printf("| Add coins or Exit.   |\n");
        printf("+---------------------+\n");
        for (int i = 0; i < 2000000000; i++);
        return;
    }

    *balance -= 10;

    clearScreen();
    drawFrame();
    printf("| Balance: %d coins    |\n", *balance);
    printf("| Spinning...          |\n");
    printf("+---------------------+\n");
    printf("\n+-------+-------+-------+\n");


    srand(time(NULL));
    reel1 = rand() % 4;
    reel2 = rand() % 4;

    if (reel1 == reel2) {
        multiplier_index = rand() % 5;
        switch (multiplier_index) {
            case 0: multiplier_value = 2; break;
            case 1: multiplier_value = 3; break;
            case 2: multiplier_value = 5; break;
            case 3: multiplier_value = 10; break;
            case 4: multiplier_value = 25; break;
        }
        reel3 = -1;
    } else {
        reel3 = rand() % 4;
    }


    for (int i = 0; i < 5; i++) {
        printf("| %-5s | %-5s | %-5s |\n", symbols[rand() % 4], "|", "|");
        printf("+-------+-------+-------+\n");
        for (int j = 0; j < 50000000; j++);
        clearScreen();
        drawFrame();
        printf("| Balance: %d coins    |\n", *balance);
        printf("| Spinning...          |\n");
        printf("+---------------------+\n");
        printf("\n+-------+-------+-------+\n");
    }
    printf("| %-5s | %-5s | %-5s |\n", symbols[reel1], "|", "|");
    printf("+-------+-------+-------+\n");


    for (int i = 0; i < 5; i++) {
        printf("| %-5s | %-5s | %-5s |\n", symbols[reel1], symbols[rand() % 4], "|");
        printf("+-------+-------+-------+\n");
        for (int j = 0; j < 50000000; j++);
        clearScreen();
        drawFrame();
        printf("| Balance: %d coins    |\n", *balance);
        printf("| Spinning...          |\n");
        printf("+---------------------+\n");
        printf("\n+-------+-------+-------+\n");
    }
    printf("| %-5s | %-5s | %-5s |\n", symbols[reel1], symbols[reel2], "|");
    printf("+-------+-------+-------+\n");


    for (int i = 0; i < 5; i++) {
        printf("| %-5s | %-5s | %-5s |\n", symbols[reel1], symbols[reel2], (reel3 == -1) ? multipliers[rand() % 5] : symbols[rand() % 4]);
        printf("+-------+-------+-------+\n");
        for (int j = 0; j < 50000000; j++);
        clearScreen();
        drawFrame();
        printf("| Balance: %d coins    |\n", *balance);
        printf("| Spinning...          |\n");
        printf("+---------------------+\n");
        printf("\n+-------+-------+-------+\n");
    }

    clearScreen();
    drawFrame();
    printf("| Balance: %d coins    |\n", *balance);
    printf("| Results:             |\n");
    printf("+---------------------+\n");
    printf("\n+-------+-------+-------+\n");
    printf("| %-5s | %-5s | %-5s |\n", symbols[reel1], symbols[reel2], (reel3 == -1) ? multipliers[multiplier_index] : symbols[reel3]);
    printf("+-------+-------+-------+\n");

    if (reel1 == reel2 && reel2 == reel3 && reel3 != -1) {
        printf("\n|     MAX WIN!!!    |\n");
        *balance += 100;
    } else if (reel1 == reel2 && reel3 == -1) {
        printf("\n|     BIG WIN!!!    |\n");
        *balance += 50 * multiplier_value;
    } else {
        printf("\n|     Try again     |\n");
    }
    printf("+---------------------+\n");

    for (int i = 0; i < 2000000000; i++);
}
