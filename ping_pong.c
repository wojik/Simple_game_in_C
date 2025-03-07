#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

int ballX, ballY;
int paddle1Y, paddle2Y;
int score1, score2;
int ballDirX, ballDirY;
int currentPlayer;
int gameOver;

void setup();
void draw();
void input();
void logic();
void resetBallPosition();
void printScoreboard();

void setup() {
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    paddle1Y = HEIGHT / 2 - 2;
    paddle2Y = HEIGHT / 2 - 2;
    score1 = 0;
    score2 = 0;
    ballDirX = -1;
    ballDirY = 1;
    currentPlayer = 1;
    gameOver = 0;
}

void draw() {
    system("cls");

    int i, j;

    for (i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");
            if (i == ballY && j == ballX)
                printf("O");
            else if (i >= paddle1Y && i < paddle1Y + 4 && j == 2)
                printf("|");
            else if (i >= paddle2Y && i < paddle2Y + 4 && j == WIDTH - 3)
                printf("|");
            else
                printf(" ");
            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Player 1: %d\nPlayer 2: %d\n", score1, score2);
}

void input() {
    if (GetAsyncKeyState('W') & 0x8000 && paddle1Y > 0)
        paddle1Y--;
    if (GetAsyncKeyState('S') & 0x8000 && paddle1Y < HEIGHT - 4)
        paddle1Y++;
    if (GetAsyncKeyState('I') & 0x8000 && paddle2Y > 0)
        paddle2Y--;
    if (GetAsyncKeyState('K') & 0x8000 && paddle2Y < HEIGHT - 4)
        paddle2Y++;

    if (GetAsyncKeyState('Q') & 0x8000)
        gameOver = 1;
}

void logic() {
    ballX += ballDirX;
    ballY += ballDirY;

    if (ballY <= 0 || ballY >= HEIGHT - 1)
        ballDirY = -ballDirY;

    if (ballX <= 2 && ballY >= paddle1Y && ballY < paddle1Y + 4) {
        ballDirX = -ballDirX;
        currentPlayer = 1;
    }
    if (ballX >= WIDTH - 3 && ballY >= paddle2Y && ballY < paddle2Y + 4) {
        ballDirX = -ballDirX;
        currentPlayer = 2;
    }

    if (ballX < 2) {
        score2++;
        if (score2 == 5)
            gameOver = 1;
        else
            resetBallPosition();
    }
    if (ballX >= WIDTH - 2) {
        score1++;
        if (score1 == 5)
            gameOver = 1;
        else
            resetBallPosition();
    }
}

void resetBallPosition() {
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    ballDirX = -ballDirX;
    currentPlayer = (currentPlayer == 1) ? 2 : 1;

    paddle1Y = HEIGHT / 2 - 2;
    paddle2Y = HEIGHT / 2 - 2;

    Sleep(1000); // Opoźnienie 1 sekundy przed wznowieniem gry
}

void printScoreboard() {
    printf("Scoreboard\n");
    printf("Player 1: %d\n", score1);
    printf("Player 2: %d\n", score2);
}

int main() {        
    printf("-----WELCOME TO PING GAME----- \n\nControls:\n\nq - quit the game\n\nPlayer 1:\nw - to move up\ns - to move down\n\nPlayer 2:\ni - to move up\nk - to move down\n\n-----THE GOAL OF THE GAME-----\nFirst to reach 5 points wins, so keep hitting the ball.");
    printf("\n\nPRESS c to start the game\n");
    while (1) {
        if (GetAsyncKeyState('C') & 0x8000)
        {
            break;
        }
    }
    setup();

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(5);
    }

    system("cls");
    printf("-----Game Over-----\n\n");
    printScoreboard();
    if (score1 > score2)
        printf("\nPlayer 1 won!\n");
    else
        printf("\nPlayer 2 won!\n");
    Sleep(1500);
    return 0;
}
