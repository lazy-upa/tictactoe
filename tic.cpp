#include <iostream>
#include <cctype>
#include <string>

using namespace std;

class Board {
private:
    int row, col, moves = 0;
    char alucross[3][3] = {{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};

public:
    void drawBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << alucross[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "---------\n";
        }
    }

    bool checkWin(char player) {
        for (int i = 0; i < 3; i++) {
            if (alucross[i][0] == player && alucross[i][1] == player && alucross[i][2] == player) {
                return true;
            }
            if (alucross[0][i] == player && alucross[1][i] == player && alucross[2][i] == player) {
                return true;
            }
        }
        if (alucross[0][0] == player && alucross[1][1] == player && alucross[2][2] == player) {
            return true;
        }
        if (alucross[0][2] == player && alucross[1][1] == player && alucross[2][0] == player) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        return moves == 9;
    }

    bool gameLogic(char &player) {
        while (true) {
            string input;
            cout << "Player " << player << ", enter row (1-3) and column (1-3) or press 'q' to quit: ";
            cin >> input;

            if (tolower(input[0]) == 'q') {
                cout << "Goodbye! Thanks for playing!\n";
                exit(0);
            }

            if (input.length() == 1 && isdigit(input[0])) {
                row = input[0] - '0';
                cin >> col;

                if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && alucross[row - 1][col - 1] == ' ') {
                    alucross[row - 1][col - 1] = player;
                    moves++;
                    break;
                } else {
                    cout << "Invalid input, Try again.\n";
                }
            } 
        }

        drawBoard();

        if (checkWin(player)) {
            return true;
        }
        return false;
    }
};

int main() {
    Board b;
    char t1;

    cout << "---------------------------" << endl;
    cout << "Welcome to Tic Tac Toe game\n";
    cout << "---------------------------\n\n";

    cout << "Player 1, pick (X/O): ";
    cin >> t1;
    t1 = toupper(t1);

    while (t1 != 'X' && t1 != 'O') {
        cout << "Invalid choice! Player 1, pick (X/O): ";
        cin >> t1;
        t1 = toupper(t1);
    }

    char currentPlayer = t1;

    b.drawBoard();

    while (true) {
        if (b.gameLogic(currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!!\n";
            break;
        } else if (b.checkDraw()) {
            cout << "It's a DRAW!!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
