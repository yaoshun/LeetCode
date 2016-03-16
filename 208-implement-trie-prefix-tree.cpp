class TrieNode {
public:
    // represent the key word or not.
    bool iskey;
    TrieNode* children[26];
    // Initialize your data structure here.
    // The string information is actually stored in the 
    // children direction information. 
    TrieNode() {
        iskey = false;
        for (int i=0; i<26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (int i=0; i<word.size();i++) {
            if (node->children[word[i]-'a'] == NULL)
                node->children[word[i]-'a'] = new TrieNode();
            node = node->children[word[i]-'a'];
        }
        // The last node represents that
        // it is actually a valid word. 
        node->iskey = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        
        // by default. even empty stirng
        // will return false in this case. 
        TrieNode* node = root;
        for (int i=0; i<word.size(); i++) {
            if (node != NULL)
                node = node->children[word[i]-'a'];
            else
                break;
        }
        if (node == NULL)
            return false;
        else
            // to prevent which is actually short version of
            // the longer word. 
            // "abcdef" is in the Trie, but "abcd" should return false.
            return node->iskey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        // same as the search for a string. 
        // Notice even when the Trie hasn't been inserted any words. 
        // It should return
        TrieNode* node = root;
        for (int i=0; i<prefix.size(); i++) {
            if(node)
                node = node->children[prefix[i]-'a'];
            else
                break;
        }
        if (!node)
            return false;
        else
            return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
