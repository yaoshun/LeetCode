#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

class Solution
{
public:
    bool isContained(string s, int a, int k)
    {
        unordered_set<string> set;
        int fullsize=fullSize(a, k);
        if(k<=0)
            return true;
        if(a<2 || a>10)
            return false;
        for(int i=0;i<=s.size()-k;i++)
        {
            string temp=s.substr(i, k);
            int j;
            for(j=0;j<k;j++)
            {
                if(temp[j]<'0' || temp[j]>=('0'+a))
                    break;
            }
            if(j==k)
            {
                if(set.find(temp)!=set.end())
                {
                    continue;
                }
                else
                {
                    set.insert(temp);
                    if(set.size()==fullsize)
                        return true;
                }
            }
        }
        return false;
    }

private:
    int fullSize(int a, int k)
    {
        int temp=k;
        int res=1;
        while(temp)
        {
            res *= a;
            temp--;
        }
        return res;
    }
};

int main()
{

    Solution solution;
    cout <<solution.isContained("00110", 2, 2) <<"\n";
    cout <<solution.isContained("*#00110", 2, 2) <<"\n";
    cout <<solution.isContained("*#01021120220", 3, 2) <<"\n";
    cout <<solution.isContained("*#010211202200", 3, 2) <<"\n";
    return 0;
}
