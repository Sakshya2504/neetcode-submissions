class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word,
                int i, int j, int k) {

        if (k == word.size())
            return true;

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size())
            return false;

        if (board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool ans = helper(board, word, i + 1, j, k + 1) ||
                   helper(board, word, i - 1, j, k + 1) ||
                   helper(board, word, i, j + 1, k + 1) ||
                   helper(board, word, i, j - 1, k + 1);

        board[i][j] = temp;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {
                    if (helper(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};