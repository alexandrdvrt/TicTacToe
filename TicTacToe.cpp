#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char player;

public:
    TicTacToe() {
        board.resize(3, vector<char>(3, ' '));
        player = 'X';
    }

    void display_board() {
        cout << "  1 2 3" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool check_move(int row, int col) {
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Error. Row and column should be between 1 and 3." << endl;
            return false;
        }
        if (board[row - 1][col - 1] != ' ') {
            cout << "Error. This square is already occupied." << endl;
            return false;
        }
        return true;
    }

    bool check_win() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true;
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true;
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }
        return false;
    }

    void play() {
        cout << "Let's play Tic Tac Toe!" << endl;
        while (true) {
            display_board();
            cout << "It's " << player << "'s turn." << endl;
            int row, col;
            cout << "Enter row and column: ";
            cin >> row >> col;
            if (check_move(row, col)) {
                board[row - 1][col - 1] = player;
                if (check_win()) {
                    display_board();
                    cout << player << " won!" << endl;
                    break;
                }
                if (player == 'X') {
                    player = 'O';
                }
                else if (player == 'O') {
                    player = 'X';
                }
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
