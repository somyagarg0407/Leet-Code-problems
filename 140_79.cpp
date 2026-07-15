#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool solve(int i, int j, int index,
               vector<vector<char>>& board,
               const string& word,
               vector<vector<bool>>& visited) {

        if (index == word.size()) {
            return true;
        }

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            visited[i][j] ||
            board[i][j] != word[index]) {
            return false;
        }

        visited[i][j] = true;

        bool found =
            solve(i + 1, j, index + 1, board, word, visited) ||
            solve(i - 1, j, index + 1, board, word, visited) ||
            solve(i, j + 1, index + 1, board, word, visited) ||
            solve(i, j - 1, index + 1, board, word, visited);

        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        vector<vector<bool>> visited(
            board.size(),
            vector<bool>(board[0].size(), false)
        );

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {

                    if (solve(i, j, 0, board, word, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    Solution obj;

    if (obj.exist(board, word))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}