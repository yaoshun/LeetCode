// LeetCode problem
//
// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
//
// For example:
//
// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
//
// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
//
// Hint:
//
// Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
// According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n <= 1)
            return true;
        int m = edges.size();
        // Checking the edges number here.
        // If a tree, m == n - 1.
        if (m != (n - 1)) {
            return false;
        }
        
        // The edges must cover every node, then it is good.
        // Not good enough.
        // Hashset with fixed values can be converted to array.
        vector<int> father(n, 0);
        for (int i = 0; i < n; i++)
            father[i] = i;
        
        for (auto& pair : edges) {
            int x = find(father, pair.first);
            int y = find(father, pair.second);
            
            // If both nodes already belong to the same set,
            // they are already in the same group, which means
            // there is a cycle.
            if (x == y)
                return false;
            
            // In some cases, we compare x and y, set the smaller as
            // as the root/father.
            father[x] = y;
        }
        return true;
    }
    
    // Union find function.
    int find(vector<int>& father, int x) {
        if (father[x] == x) {
            return x;
        } else {
            father[x] = find(father, father[x]);
        }
        return father[x];
    }
};

// Iterative implementation of the find function.
int find(vector<int>& father, int x) {
    if (father[x] == x)
        return x;

    int res = father[x];
    while (res != father[res]) {
        res = father[res];
    }
    // Assign the value along the path.
    while (x != father[x]) {
        int tmp = father[x];
        father[x] = res;
        x = tmp;
    }
    return res;
}
