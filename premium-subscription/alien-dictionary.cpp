// LeetCode hard problem
//
// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
//
// For example,
// Given the following words in dictionary,
//
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// The correct order is: "wertf".
//
// Note:
// You may assume all letters are in lowercase.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return any one of them is fine.

// Solution: Build a graph and do corresponding topoSort.
// 
// The key to efficient topoSort is to use the incoming degrees as the selecting criteria.
// In this way we can efficiently remove the node from the graph.
// If we use outcoming degrees as the selecting criteria, we will need to traverse the graph
// to remove one node.
//
// Here we used unordered_set<char> to efficiently store the edge.
// If we know the dictionary is 26 long, we can also use array to replace the hash here.
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> mp;
        buildGraph(words, graph, mp);
        string res = topoSort(graph, mp);
        return res;
    }
    
    void buildGraph(vector<string>& words, unordered_map<char, unordered_set<char>>& graph, unordered_map<char, int>& mp) {
        // Get char set and store it into st.
        for (string& word : words) {
            for (char& c : word) {
                mp[c] = 0;
            }
        }
        
        // Compare the adjacent ordering determination.
        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < min(words[i - 1].size(), words[i].size()); j++) {
                if (words[i - 1][j] != words[i][j]) {
                    // We insert an edge from words[i - 1][j] to words[i][j].
                    graph[words[i - 1][j]].insert(words[i][j]);
                    break;
                }
            }
        }
        
        // Traverse the graph once to get the count hash.
        for (auto& pair : graph) {
            for (auto& c : pair.second) {
                mp[c]++;
            }
        }
    }
    
    string topoSort(unordered_map<char, unordered_set<char>>& graph, unordered_map<char, int>& mp) {
        // For chars without any incoming edges, we output it as the start of the string.
        string res = "";
        while (!mp.empty()) {
            bool found = false;
            
            for (auto& pair : mp) {
                if (pair.second == 0) {
                    res.push_back(pair.first);
                    for (auto& nn : graph[pair.first]) {
                        mp[nn]--;
                    }
                    graph.erase(pair.first);
                    mp.erase(pair.first);
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                res.clear();
                return res;
            }
        }
        return res;
    }
};
