#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define SIZE 4
#define WIN_CONDITION 2048

void printBoard(int board[SIZE][SIZE], int score, int k, int ok);
int checkLoss(int board[SIZE][SIZE]);
void spawnRandom(int board[SIZE][SIZE]);
int moveTiles(int board[SIZE][SIZE], char direction, int* score);
void mergeTiles(int* tile1, int* tile2, int* moveMade, int* score);
void playGame();

int main() {
    playGame();
    return 0;
}

void playGame() {
    int board[SIZE][SIZE] = {0};
    int score = 0, k = 0, lose = 0, moveMade = 0, ok = 0;
    char input;

    srand(time(NULL));

    while (1) {
        spawnRandom(board);
        system("cls");
        printBoard(board, score, k, ok);

        if (checkLoss(board) && k == SIZE * SIZE) {
            printf("\n\n                                                (+_+) YOU LOSE (+_+)\n");
            break;
        }

        input = _getch();
        if (input == 'e') {
            system("cls");
            return;
        } else if (input == 'n') {
            system("cls");
            playGame();  // Restart game
        } else {
            moveMade = moveTiles(board, input, &score);
            if (!moveMade) continue;  // Skip if no valid move
        }
    }
}

void spawnRandom(int board[SIZE][SIZE]) {
    int emptyCells = 0, i, j;
    
    // Count empty cells
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) emptyCells++;
        }
    }

    if (emptyCells == 0) return;  // No space to spawn

    // Find a random empty cell and spawn a 2 or 4
    int randomCell = rand() % emptyCells;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                if (randomCell == 0) {
                    board[i][j] = (rand() % 10 == 0) ? 4 : 2;
                    return;
                }
                randomCell--;
            }
        }
    }
}

void printBoard(int board[SIZE][SIZE], int score, int k, int ok) {
    printf("\n                                                    YOUR SCORE : %d\n", score);
    printf("                                                ");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 203, 205, 205, 205, 205, 203, 205, 205, 205, 205, 203, 205, 205, 205, 205, 187);
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("                                                %c", 186);
            if (board[i][j] == 0) {
                printf("    ");
            } else {
                printf("%-4d", board[i][j]);
            }
        }
        printf("%c\n", 186);
        if (i < SIZE - 1) {
            printf("                                                ");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 206, 205, 205, 205, 205, 206, 205, 205, 205, 205, 206, 205, 205, 205, 205, 185);
        }
    }
    printf("                                                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 202, 205, 205, 205, 205, 202, 205, 205, 205, 205, 202, 205, 205, 205, 205, 188);
    
    printf("                                                Press N to start a new game\n");
    printf("                                                Press E to exit\n");
}

int checkLoss(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) return 0;  // Still have space
            if (i > 0 && board[i][j] == board[i - 1][j]) return 0;  // Merge possible vertically
            if (j > 0 && board[i][j] == board[i][j - 1]) return 0;  // Merge possible horizontally
        }
    }
    return 1;  // No moves left
}

int moveTiles(int board[SIZE][SIZE], char direction, int* score) {
    int moveMade = 0;
    int rotatedBoard[SIZE][SIZE] = {0};

    // Rotate board based on the move direction (L, R, U, D)
    if (direction == 75) {  // Left
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                rotatedBoard[i][j] = board[i][j];
            }
        }
    } else if (direction == 77) {  // Right
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                rotatedBoard[i][SIZE - 1 - j] = board[i][j];
            }
        }
    } else if (direction == 72) {  // Up
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                rotatedBoard[j][i] = board[i][j];
            }
        }
    } else if (direction == 80) {  // Down
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                rotatedBoard[SIZE - 1 - j][i] = board[i][j];
            }
        }
    } else {
        return 0;  // Invalid input
    }

    // Process the movement
    for (int i = 0; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            if (rotatedBoard[i][j] != 0) {
                for (int k = j - 1; k >= 0; k--) {
                    if (rotatedBoard[i][k] == 0) {
                        rotatedBoard[i][k] = rotatedBoard[i][k + 1];
                        rotatedBoard[i][k + 1] = 0;
                        moveMade = 1;
                    } else if (rotatedBoard[i][k] == rotatedBoard[i][k + 1]) {
                        mergeTiles(&rotatedBoard[i][k], &rotatedBoard[i][k + 1], &moveMade, score);
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    // Restore board back to original orientation
    if (direction == 75) {  // Left
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = rotatedBoard[i][j];
            }
        }
    } else if (direction == 77) {  // Right
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = rotatedBoard[i][SIZE - 1 - j];
            }
        }
    } else if (direction == 72) {  // Up
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = rotatedBoard[j][i];
            }
        }
    } else if (direction == 80) {  // Down
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = rotatedBoard[SIZE - 1 - j][i];
            }
        }
    }

    return moveMade;
}

void mergeTiles(int* tile1, int* tile2, int* moveMade, int* score) {
    *tile1 += *tile2;
    *tile2 = 0;
    *score += *tile1;
    *moveMade = 1;
}
