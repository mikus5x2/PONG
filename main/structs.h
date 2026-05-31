#pragma once
typedef struct {
    bool gameRunning;
    bool side;
    int userScore;
    int AIScore;
} gameValues;

typedef struct {
    int size_X;
    int size_Y;
} mapCoordinates;

typedef struct {
    int ball_X;
    int ball_Y;
    bool moveUpwards;
} ballCoordinates;

typedef struct {
    int local_paddle_X;
    int local_paddle_Y;

    int ai_paddle_X;
    int ai_paddle_Y;
} paddlesCoordinates;