#include <stdio.h>

char board[3][3];
char player1Symbol, player2Symbol;
char currentPlayerSymbol;

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayerSymbol && board[i][1] == currentPlayerSymbol && board[i][2] == currentPlayerSymbol) return 1;
        if (board[0][i] == currentPlayerSymbol && board[1][i] == currentPlayerSymbol && board[2][i] == currentPlayerSymbol) return 1;
    }
    // Check diagonals
    if (board[0][0] == currentPlayerSymbol && board[1][1] == currentPlayerSymbol && board[2][2] == currentPlayerSymbol) return 1;
    if (board[0][2] == currentPlayerSymbol && board[1][1] == currentPlayerSymbol && board[2][0] == currentPlayerSymbol) return 1;
    return 0;
}

void switchPlayer() {
    currentPlayerSymbol = (currentPlayerSymbol == player1Symbol) ? player2Symbol : player1Symbol;
}

int main() {
    int row, col, moves = 0;
    player1Symbol = 'X';
    player2Symbol = 'O';

    printf("Player 1, choose your symbol (X/O): ");
    scanf(" %c", &player1Symbol);
    player2Symbol = (player1Symbol == 'X') ? 'O' : 'X';

    initializeBoard();
    currentPlayerSymbol = player1Symbol;

    while (1) {
        printBoard();
        printf("Player %c, enter your move (row and column): ", currentPlayerSymbol);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row-1][col-1] = currentPlayerSymbol;
        moves++;

        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayerSymbol);
            break;
        }

        if (moves == 9) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}
