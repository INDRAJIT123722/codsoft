#include <iostream>
using namespace std;

char board[3][3];  // Game board
char currentPlayer = 'X';


void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

// Display the game board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Switch current player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;  
    }

    board[row][col] = currentPlayer;
    return true;
}

// Check win condition
bool checkWin() {
    // Rows, Columns, Diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}


bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        initializeBoard();
        currentPlayer = 'X';
        bool gameEnded = false;

        while (!gameEnded) {
            displayBoard();
            int move;

            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (!makeMove(move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameEnded = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "The game is a draw!\n";
                gameEnded = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!\n";
    return 0;
}