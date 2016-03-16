class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode() {
        isKey = false;
        for (int i=0; i<26; i++)
            children[i] = NULL;
    }
};

class Trie {
private: 
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i=0; i<word.size(); i++) {
            if(node->children[word[i]-'a'] == NULL)
                node->children[word[i]-'a'] = new TrieNode();
            node = node->children[word[i]-'a'];
        }
        node->isKey = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (int i=0; i<word.size(); i++) {
            if (node->children[word[i]-'a'] == NULL)
                return false;
            node = node->children[word[i]-'a'];
        }
        return node->isKey;
    }
    
    bool startWith(string prefix) {
        TrieNode* node = root;
        for (int i=0; i<prefix.size(); i++) {
            if (node->children[prefix[i]-'a'] == NULL)
                return false;
            node = node->children[prefix[i]-'a'];
        }
        // dont check isKey in this case.
        return true;
    }
};

class Solution {
private:
    Trie trie;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // backtracking with Trie data structure.
        vector<string> res;
        int row = board.size();
        if (row==0)
            return res;
        int col = board[0].size();
        for (string s : words) {
            trie.insert(s);
        }
        for (int i=0; i < row; i++) {
            for (int j=0; j < col; j++) {
                vector<vector<bool>> visited(row, vector<bool>(col, false));
                dfs(board, "", i, j, visited, res);
            }
        }
        
        // how to make the solution unique.
        sort(res.begin(), res.end());
        
        // learn the usage of unique here. 
        // quite interesting. unique returns the iterator after the
        // first 
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    
    void dfs(vector<vector<char>>& board, string word, int x, int y, vector<vector<bool>>& visited, vector<string>& res) {
        if (x < 0 || x > board.size()-1)
            return;
        if (y < 0 || y > board[0].size()-1)
            return;
        if (visited[x][y])
            return;
        word.push_back(board[x][y]);
        if (trie.search(word))
            res.push_back(word);
        if (trie.startWith(word)) {
            visited[x][y] = true;
            dfs(board, word, x+1, y, visited, res);
            dfs(board, word, x-1, y, visited, res);
            dfs(board, word, x, y-1, visited, res);
            dfs(board, word, x, y+1, visited, res);
            visited[x][y] = false;
        }
        word.pop_back();
        return;
    }
};
