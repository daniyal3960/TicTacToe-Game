#include <iostream>
using namespace std;

class TicTacToe {
private:
    int board[3][3];

public:
    TicTacToe() {
        // Initialize the board with empty squares
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = 0;
            }
        }
    }

    // Display the current state of the board
  const  void displayBoard() {
        cout << "  1 2 3" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    cout << "_ ";
                }
                else if (board[i][j] == 1) {
                    cout << "X ";
                }
                else {
                    cout << "O ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    // Check if the game has been won
   const int checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0) {
                return board[i][0];
            }
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0) {
                return board[0][i];
            }
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
            return board[0][0];
        }
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != 0) {
            return board[0][2];
        }

        // Check for a draw
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    return -1; // Game is not over yet
                }
            }
        }
        return 0; // It's a draw
    }

    // Make a move on the board
    bool makeMove(int row, int col, int player) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != 0) {
            return false; // Invalid move
        }
        board[row][col] = player;
        return true;
    }
};

int main() {
    TicTacToe game;
    int currentPlayer = 1;

    cout << "Let's play Tic-Tac-Toe!" << endl;
    cout << "Player 1: X, Player 2: O" << endl;
    cout << "Enter row and column numbers to make your move." << endl;

    int row, col;
    while (true) {
        game.displayBoard();
        cout << "Player " << currentPlayer << ", enter row and column numbers (1-3): ";
        cin >> row >> col;
        row--;
        col--;

        if (game.makeMove(row, col, currentPlayer)) {
            int result = game.checkWin();
            if (result == 1) {
                cout << "Player 1 (X) wins!" << endl;
                break;
            }
            else if (result == 2) {
                cout << "Player 2 (O) wins!" << endl;
                break;
            }
            else if (result == 0) {
                cout << "It's a draw!" << endl;
                break;
            }
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
        else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    return 0;
}
