//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note:
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
//
class Solution {
    // Check whether a vector contains duplicate characther other than .
    bool check(const vector<char> &v) {
        char a[9] = {0};
        for (auto c : v) {
            if (c >= '1' && c <= '9') {
                int k = c - '1';
                if (a[k] == 0)
                    a[k] = 1;
                else
                    return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows;
        for (int i = 0; i < 9; ++i) {
            if (!check(board[i]))
                return false;
        }
        // check columns;
        for (int i = 0; i < 9; ++i) {
            vector<char> col(9, '.');
            for (int j = 0; j < 9; ++j)
               col[j] = board[j][i];

            if (!check(col))
                return false;
        }
        // check square;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                vector<char> square(9, '.');
                square[0] = board[3 * j + 0][3 * i + 0];
                square[1] = board[3 * j + 0][3 * i + 1];
                square[2] = board[3 * j + 0][3 * i + 2];
                square[3] = board[3 * j + 1][3 * i + 0];
                square[4] = board[3 * j + 1][3 * i + 1];
                square[5] = board[3 * j + 1][3 * i + 2];
                square[6] = board[3 * j + 2][3 * i + 0];
                square[7] = board[3 * j + 2][3 * i + 1];
                square[8] = board[3 * j + 2][3 * i + 2];
                if (!check(square))
                    return false;
            }
        }
        return true;
    }
};

     int row[9][9] = {0};
     int col[9][9] = {0};
     int box[9][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.')
                continue;

            if (c < '0' || c > '9')
                return false;

            int number = c - '1';
            if (row[i][number] || col[j][number] || box[(i / 3) * 3 + j / 3][number])
                return false;

            row[i][number] = 1;
            col[j][number] = 1;
            box[(i / 3) * 3 + j / 3][number] = 1;
        }
    }
    return true;
