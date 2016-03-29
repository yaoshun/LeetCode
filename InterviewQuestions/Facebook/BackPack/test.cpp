#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        // using the first few items of A
        sort(A.begin(), A.end());
        int n=A.size();
        
        // two D array dp[i][j]
        // use the first j number item to represents i
        vector<vector<int>> dp(m+1, vector<int>(n+1, false));
        
        for(int i=0;i<=n;i++)
            dp[0][i]=1;
        for(int i=1;i<=m;i++)
            dp[i][0]=0;
        
        // DP[i][j] = DP[i-A[j-1]][j-1] || DP[i][j-1]
        // column wise transfer. 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(dp[j][i-1] || (j-A[i-1]>=0 && dp[j-A[i-1]][i-1]))
                    dp[j][i]=1;
                else
                    dp[j][i]=0;
            }
        }
        
        for(int i=m;i>=0;i--)
        {
            if(dp[i][n])
                return i;
        }
    }
};

int main()
{

    Solution solution;
    vector<int> a={3,4,8,5};
    cout <<solution.backPack(10, a) <<"\n";
    return 0;
}
