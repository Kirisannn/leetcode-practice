#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
                // Check rows and columns
        for (int i = 0; i < 9; i++) {
            int boxRow = 0, boxCol = 0;
            unordered_map<char, int> row, col, box;
            for (int j = 0; j < 9; j++) {
                // Row Check
                if (board[i][j] != '.') {
                    row[board[i][j]]++;
                    if (row[board[i][j]] > 1) {
                        return false;
                    }
                }

                // Column Check
                if (board[j][i] != '.') {
                    col[board[j][i]]++;
                    if (col[board[j][i]] > 1) {
                        return false;
                    }
                }

                boxRow = 3 * (i / 3) + (j / 3);
                boxCol = 3 * (i % 3) + (j % 3);

                // Box check
                if (board[boxRow][boxCol] != '.') {
                    box[board[boxRow][boxCol]]++;
                    if (box[board[boxRow][boxCol]] > 1) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Test 1
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    bool expected = true;
    bool result = sol.isValidSudoku(board);
    cout << "Test 1:\t" << (expected == result ? "Passed" : "Failed") << endl;

    // Test 2
    board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    expected = false;
    result = sol.isValidSudoku(board);
    cout << "Test 2:\t" << (expected == result ? "Passed" : "Failed") << endl;

    // Test 3
    board = {{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
             {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
             {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
             {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
             {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
             {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    expected = false;
    result = sol.isValidSudoku(board);
    cout << "Test 3:\t" << (expected == result ? "Passed" : "Failed") << endl;

    // Test 4
    board = {{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
             {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
             {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
             {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
             {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
             {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
             {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
             {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
    expected = false;
    result = sol.isValidSudoku(board);
    cout << "Test 4:\t" << (expected == result ? "Passed" : "Failed") << endl;

    return 0;
}