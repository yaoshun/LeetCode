#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution
{
public:
   string longestTwoString(string s)
   {
       if(s.size()<=2)
           return s;

       string res="";
       // two pointer approach to find all the substrings. 
       int i=0;
       int j=0;
       unordered_map<char, int> mp;

       while(j<s.size() && mp.size()<2)
       {
           mp[s[j]]++;
           j++;
       }
       while(j<s.size() && mp.find(s[j])!=mp.end())
       {
           j++;
       }

       if(j==s.size())
           return s;

       int maxStart=0;
       int maxLen=j;

       j--;

       while(j<s.size())
       {
           if(j-i+1 > maxLen)
           {
               maxStart=i;
               maxLen=j-i+1;
           }
           j++;
           if(j==s.size())
               break;
           if(mp.find(s[j])!=mp.end())
           {
               mp[s[j]]++;
               continue;
           }
           else
           {
               while(mp.size()==2)
               {
                   if(mp[s[i]]==1)
                   {
                       mp.erase(s[i]);
                       i++;
                   }
                   else
                   {
                       mp[s[i]]--;
                       i++;
                   }
               }
               mp[s[j]]++;
           }
       }

       return s.substr(maxStart, maxLen);
   }
};

int main()
{
    Solution solution;
    
    cout <<solution.longestTwoString(string("")) <<"\n";
    cout <<solution.longestTwoString(string("eceba")) <<"\n";
    cout <<solution.longestTwoString(string("#ec#ba#abasdf")) <<"\n";
    cout <<solution.longestTwoString("#ec#ba#abasdf") <<"\n";
}
