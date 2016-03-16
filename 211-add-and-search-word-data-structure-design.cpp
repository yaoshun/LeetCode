class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode () {
        isKey = false;
        for (int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
};

class WordDictionary {

private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->children[word[i]-'a'])
                node->children[word[i]-'a'] = new TrieNode();
            node = node->children[word[i]-'a'];
        }
        
        node->isKey=true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search2(word, 0, root);
    }
    
    // helper function to consider the wild card case.
    // if any of them wildcard is true return true;
    bool search2(string& word, int pos, TrieNode *node) {
        if (pos == word.size()) {
            return node->isKey;
        } else {
            if (word[pos] == '.') {
                for (int i=0; i<26; i++) {
                    if (node->children[i]) {
                        if(search2(word, pos+1, node->children[i]))
                            return true;
                    }
                }
            } else {
                if (node->children[word[pos]-'a']) {
                    return search2(word, pos+1, node->children[word[pos]-'a']);
                } else {
                    return false;
                }
            }
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
