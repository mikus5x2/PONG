#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

struct Scores {
    int userScore;
    int AIScore;
};

struct mapCoordinates {
    int size_X;
    int size_Y;
};

struct ballCoordinates {
    int ball_X;
    int ball_Y;
};


void initMenu();
void startGame();
void updateMap(int size_X, int size_Y, int ball_X, int ball_Y);
void gameOver();

int main() {

    int userChoice = 0;
    bool gameRunning = false;

    initMenu();

    printf("Write your choice here: ");
    scanf("%d", &userChoice);

    switch (userChoice) {
        case 1:
            startGame();
            gameRunning = true;
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
    struct ballCoordinates ballCords;
    struct mapCoordinates map;
    map.size_X = 32;
    map.size_Y = 10;

    //default
    bool moveUpwards = false;
    ballCords.ball_X = 15; // 15 because 0 and 32 is wall
    ballCords.ball_Y = 5;

    while (true) {
        sleep(1);
        if (ballCords.ball_X == map.size_X + 1) {
            gameOver();
            break;
        }

        if (ballCords.ball_Y >= map.size_Y - 1) {
            moveUpwards = true;
        }

        if(!moveUpwards) {
            ballCords.ball_X+=2;
            ballCords.ball_Y++;
        } else {
            ballCords.ball_X+=2;
            ballCords.ball_Y--;
        }

        updateMap(map.size_X, map.size_Y, ballCords.ball_X, ballCords.ball_Y);
    }
}

void updateMap(int size_X, int size_Y, int ball_X, int ball_Y) 
{
    system("cls");
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

    printf("Ball X: %d \n", ball_X);
    printf("Ball Y: %d \n", ball_Y);
}

void gameOver() {
    system("cls");
    printf("Game over!");
}