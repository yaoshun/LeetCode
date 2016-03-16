// Leetcode two sum solution.

class Solution 
{
public:
    vector<int> twoSum(vector<int> &number, int target)
    {
        vector<int> res;
        if(number.size() == 0)
            return res;
        // Hashmap to store the scanned numbers.
        unordered_map<int, int> mp;
        for(int i = 0; i < number.size(); i++)
        {
            if(mp.find(target - number[i]) != mp.end())
            {
                return vector<int>{mp[target - number[i]] + 1, i + 1};
            }
            else
                mp[number[i]] = i;
        }
        // Here the result is empty pair.
        return res;
    }
};

