#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

#include "structs.h"
#include "prototypes.h"

int main() {
    int userChoice = 0;
    
    initMenu();
    printf("Write your choice here: ");
    scanf("%d", &userChoice);

    switch (userChoice) {
        case 1:
            startGame();
            break;
        case 2:
            printf("Highscores");
            break;
        case 3:
            return 0;
            break;
        default:
            printf("Invalid choice!");
            break;
    }
}

void initMenu() {
    system("cls");
    printf("-- Welcome to PONG! \n");

    printf("1. Start game \n");
    printf("2. View highscore \n");
    printf("3. Exit game \n");
}

void startGame() {
    system("cls");
    srand(time(NULL));
    int random = (rand() % (2 - 1 + 1)) + 1;

    ballCoordinates ballCords;
    mapCoordinates map;
    gameValues values;

    
    if (random == 1) {
        values.side = true;
    } else {
        values.side = false;
    }

    values.gameRunning = true;
    values.userScore = 0;
    values.AIScore = 0;

    map.size_X = 32;
    map.size_Y = 10;

    ballCords.moveUpwards = false;
    ballCords.ball_X = 15;
    ballCords.ball_Y = 5;

    while (values.gameRunning) {
        Sleep(750);
        if (ballCords.ball_X < 0) {
            Score(&values, &ballCords);
        }
        if (ballCords.ball_X == map.size_X + 1) {
            Score(&values, &ballCords);
        }

        if (ballCords.ball_Y >= map.size_Y - 1) {
            ballCords.moveUpwards = true;
        }

        updateMap(map.size_X, map.size_Y, ballCords.ball_X, ballCords.ball_Y);

        if(!ballCords.moveUpwards && values.side == true) {
            ballCords.ball_X+=2;
            ballCords.ball_Y++;
        } else if (ballCords.moveUpwards && values.side == true) {
            ballCords.ball_X+=2;
            ballCords.ball_Y--;
        } else if (!ballCords.moveUpwards && values.side == false) {
            ballCords.ball_X-=2;
            ballCords.ball_Y++;
        } else if (ballCords.moveUpwards && values.side == false) {
            ballCords.ball_X-=2;
            ballCords.ball_Y--;
        }

    }
}

void updateMap(int size_X, int size_Y, int ball_X, int ball_Y) 
{
    system("cls");
    printf("Ball X: %d \n", ball_X);
    printf("Ball Y: %d \n", ball_Y);
    for (int y = 0; y <= size_Y; y++) { // Y
        for (int x = 0; x <= size_X; x++) { // X

            // ball on map
            if(x == ball_X && y == ball_Y) {
                printf("*");
            }

            // paddle local player
            else if (x == 0 && y == size_Y / 2) {
                printf("|");
            }

            // paddle ai
            else if (x == size_X && y == size_Y / 2) {
                printf("|");
            }

            // top & bottom
            else if (y == 0 || y == size_Y) {
                printf("-");
            }

            // walls
            else if (x == 0 || x == size_X) {
                printf(":");
            } else {
                printf(" ");
            }

        }

        printf("\n");
    }
}

void Score(gameValues* values, ballCoordinates* ballCords) {
    if (ballCords->ball_X < 0) 
    {
        srand(time(NULL));
        int random = (rand() % (2 - 1 + 1)) + 1;
        if (random == 1) {
            values->side = true;
        } else {
            values->side = false;
        }

        values->gameRunning = false;
        values->AIScore++;

        system("cls");
        printf("Ai scored!: %d", values->AIScore);
        Sleep(1000);

        ballCords->ball_X = 15;
        ballCords->ball_Y = 5;
        ballCords->moveUpwards = false;
        values->gameRunning = true;
    } else {
        srand(time(NULL));
        int random = (rand() % (2 - 1 + 1)) + 1;
        if (random == 1) {
            values->side = true;
        } else {
            values->side = false;
        }

        values->gameRunning = false;
        values->userScore++;

        system("cls");
        printf("User scored!: %d", values->userScore);
        Sleep(1000);

        ballCords->ball_X = 15;
        ballCords->ball_Y = 5;
        ballCords->moveUpwards = false;
        values->gameRunning = true;
    }
}