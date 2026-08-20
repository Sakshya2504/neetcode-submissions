class Solution {
public:

    struct Node {
        Node* child[26];
        string word;

        Node() {
            word = "";
            for(int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root = new Node();

    void insert(string word) {
        Node* curr = root;

        for(char ch : word) {
            int idx = ch - 'a';
            if(curr->child[idx] == nullptr) {
                curr->child[idx] = new Node();
            }
            curr = curr->child[idx];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             Node* node,
             vector<string>& ans) {

        if(r < 0 || r >= board.size() ||
           c < 0 || c >= board[0].size()) {
            return;
        }

        char ch = board[r][c];

        if(ch == '#') {
            return;
        }
        int idx = ch - 'a';
        if(node->child[idx] == nullptr) {
            return;
        }
        Node* next = node->child[idx];

        if(next->word != "") {
            ans.push_back(next->word);
            next->word = "";
        }

        board[r][c] = '#';
        dfs(board, r - 1, c, next, ans);
        dfs(board, r + 1, c, next, ans);
        dfs(board, r, c - 1, next, ans);
        dfs(board, r, c + 1, next, ans);
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for(string word : words) {
            insert(word);
        }
        vector<string> ans;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {

                dfs(board, i, j, root, ans);

            }
        }

        return ans;
    }
};