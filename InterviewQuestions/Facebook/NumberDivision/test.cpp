#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string number_division(int a, int b)
    {
        string res;
        int q,r;
        q=a/b;
        r=a-b*q;
        res += to_string((long long)q);

        // digital part
        unordered_map<int, int> mp;
        string digits;
        int idx=0;
        while(r>0)
        {
            // r*10 as the unordered map
            a=r*10;
            q=a/b;
            r=a-b*q;
            if(mp.find(a)==mp.end())
            {
                mp[a]=idx;
                digits.push_back(q+'0');
                idx++;
            }
            else
            {
                int oldidx=mp[a];
                res.push_back('.');
                res.append(digits.substr(0, oldidx));
                res.push_back('(');
                res.append(digits.substr(oldidx, idx-oldidx));
                res.push_back(')');
                return res;
            }
        }
        res.append('.'+digits);
        return res;
    }
};

int main()
{

    Solution solution;

    cout <<solution.number_division(15, 2);
    cout <<"\n";
    cout <<solution.number_division(17, 6);
    cout <<"\n";
    cout <<solution.number_division(16, 17);
    cout <<"\n";
}
