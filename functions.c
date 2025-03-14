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
    printf("| - Small Win (2): 20 coins |\n");
    printf("| - MAX WIN (3): 100 coins |\n");
    printf("+---------------------+\n");
    printf("Press Enter...");
}

void playGame(int *balance) {
    char* symbols[] = {"|", "L", "7", "Sun"};
    int reel1, reel2, reel3;

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
    printf("|   |   |   |   |   |   |\n");
    printf("+-------+-------+-------+\n");


    for (int i = 0; i < 1000000000; i++);


    srand(time(NULL));
    reel1 = rand() % 4;
    reel2 = rand() % 4;
    reel3 = rand() % 4;


    clearScreen();
    drawFrame();
    printf("| Balance: %d coins    |\n", *balance);
    printf("| Results:             |\n");
    printf("+---------------------+\n");
    printf("\n+-------+-------+-------+\n");
    printf("| %-5s | %-5s | %-5s |\n", symbols[reel1], symbols[reel2], symbols[reel3]);
    printf("+-------+-------+-------+\n");


    if (reel1 == reel2 && reel2 == reel3) {
        printf("\n|     MAX WIN!!!    |\n");
        *balance += 100;
    } else if (reel1 == reel2 || reel2 == reel3 || reel1 == reel3) {
        printf("\n|     Small Win!    |\n");
        *balance += 20;
    } else {
        printf("\n|     Try again     |\n");
    }
    printf("+---------------------+\n");

    for (int i = 0; i < 2000000000; i++);
}
