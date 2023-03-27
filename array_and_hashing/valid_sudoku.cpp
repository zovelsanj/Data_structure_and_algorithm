/* 36. VALID SUDOKU
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
Eg: Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class validSudoku {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_map<int, unordered_set<char>> rows, columns, boxes;
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                if (board[i][j] == '.')
                    continue;

                if (rows[i].find(board[i][j]) != rows[i].end() || columns[j].find(board[i][j]) != columns[j].end() || boxes[3*(i/3)+(j/3)].find(board[i][j]) != boxes[3*(i/3)+(j/3)].end())
                    return false;

                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                boxes[3*(i/3)+(j/3)].insert(board[i][j]);
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>>board;
    board={{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};
    validSudoku vs;
    cout<<vs.isValidSudoku(board)<<endl;
}
