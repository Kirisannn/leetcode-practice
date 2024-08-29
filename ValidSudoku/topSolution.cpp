#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool rowCheck(char selected, int i, vector<vector<char>>& board) {
        int countSelected = 0;
        for (int j = 0; j < 9; j++) {
            if (selected == board[i][j]) {
                countSelected++;
            }
        }
        if (countSelected > 1) {
            return false;
        } else {
            return true;
        }
    }
    bool columnCheck(char selected, int j, vector<vector<char>>& board) {
        int countSelected = 0;
        for (int i = 0; i < 9; i++) {
            if (selected == board[i][j]) {
                countSelected++;
            }
        }
        if (countSelected > 1) {
            return false;
        } else {
            return true;
        }
    }
    bool gridCheck(char selected, int row, int col, vector<vector<char>>& board) {
        int countSelected = 0;
        int centrilized_i = (row / 3);
        int centrilized_j = (col / 3);
        centrilized_i = 3 * centrilized_i;
        centrilized_j = 3 * centrilized_j;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (selected == board[centrilized_i + i][centrilized_j + j]) {
                    countSelected++;
                }
            }
        }
        if (countSelected > 1) {
            return false;
        } else {
            return true;
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char selected = board[i][j];
                if (selected == '.') {
                    selected = NULL;
                }
                if (!rowCheck(selected, i, board)) {
                    return false;
                }
                if (!columnCheck(selected, j, board)) {
                    return false;
                }
                if (!gridCheck(selected, i, j, board)) {
                    return false;
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