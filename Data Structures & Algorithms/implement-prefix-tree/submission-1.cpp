class PrefixTree {
public:

    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;

        for(char ch : word) {
            int index = ch - 'a';

            if(curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for(char ch : word) {
            int index = ch - 'a';

            if(curr->children[index] == nullptr) {
                return false;
            }

            curr = curr->children[index];
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for(char ch : prefix) {
            int index = ch - 'a';

            if(curr->children[index] == nullptr) {
                return false;
            }

            curr = curr->children[index];
        }

        return true;
    }
};